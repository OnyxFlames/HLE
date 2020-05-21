#include "Application.hpp"

#include <SFML/Window/Event.hpp>

#include "../Common.hpp"

#include "../time/FramerateClock.hpp"

#include "../vector/Vector2.hpp"

namespace hle
{

	const sf::Time Application::TimePerFrame = sf::seconds(1.f / 144.f);

	Application::Application()
		: mWindow(sf::VideoMode(1280, 960), "HLE - Hierarch Labs Engine")
		, mWorld(mWindow)
	{
#if defined(DEBUG_FPS_INFO)
		mDebugFont.loadFromFile("../resources/fonts/Kenney Future.ttf");
		mFPSText.setFont(mDebugFont);
		mFPSText.setScale({0.5f, 0.4f});
#endif
	}

	void Application::run()
	{
		sf::Clock runtime;
		sf::Time lastUpdate = sf::Time::Zero;
#if defined(DEBUG_FPS_INFO)
		hle::time::FramerateClock mFrameClock;
#endif
		while (mWindow.isOpen())
		{
			processEvents();
			lastUpdate += runtime.restart();
#if defined(DEBUG_FPS_INFO)
			if (mFrameClock.update())
				mFPSText.setString("FPS: " + std::to_string(mFrameClock.getFramerate()));
#endif
			while (lastUpdate > TimePerFrame)
			{
				lastUpdate -= TimePerFrame;
				processEvents();
				if (!mIsPaused)
					update(TimePerFrame);
			}
			render();
		}
	}

	void Application::processEvents()
	{
		CommandQueue& commands = mWorld.getCommandQueue();

		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			mPlayer.handleEvent(e, commands);
			switch (e.type)
			{
			case sf::Event::Closed: mWindow.close(); break;
			case sf::Event::KeyPressed:
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape: 
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) 
					 || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
						mWindow.close();
					else
						mIsPaused = !mIsPaused;
					break;
				}
				break;
			}
			case sf::Event::LostFocus:
				// if paused before focus lost
				if (!mIsPaused)
				{
					mIsPaused = true;
					mPausedFromLostFocus = true;
				}
				break;
			case sf::Event::GainedFocus:
				// if paused from user
				if (mPausedFromLostFocus)
				{
					mIsPaused = false;
					mPausedFromLostFocus = false;
				}
				break;
			}

		}
		mPlayer.handleRealtimeInput(commands);
	}

	void Application::update(sf::Time dt)
	{
		mWorld.update(dt);
	}

	void Application::render()
	{
		mWindow.clear();
		mWorld.draw();
		mWindow.setView(mWindow.getDefaultView());

#if defined(DEBUG_FPS_INFO)
		mWindow.draw(mFPSText);
#endif
		mWindow.display();
	}

} // hle