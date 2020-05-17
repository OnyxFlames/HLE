#include "Application.hpp"

#include <SFML/Window/Event.hpp>

#include "../Common.hpp"

#include "../time/FramerateClock.hpp"

#include "../vector/Vector2.hpp"

namespace hle
{

	const sf::Time Application::TimePerFrame = sf::seconds(1.f / 144.f);

	Application::Application()
		: mWindow(sf::VideoMode(720, 640), "HLE - Hierarch Labs Engine")
	{
#if defined(DEBUG_FPS_INFO)
		mDebugFont.loadFromFile("../resources/fonts/Kenney Future.ttf");
		mFPSText.setFont(mDebugFont);
		mFPSText.setScale({0.45f, 0.45f});
#endif
	}

	void Application::run()
	{
		sf::Clock runtime;
		sf::Time lastUpdate = sf::Time::Zero;
		hle::time::FramerateClock mFrameClock;
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
				update(TimePerFrame);
			}
			render();
		}
	}

	void Application::processEvents()
	{
		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed: mWindow.close(); break;
			case sf::Event::KeyPressed:
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape: mWindow.close(); break;
				}
				break;
			}
			}

		}
	}

	void Application::update(sf::Time dt)
	{

	}

	void Application::render()
	{
		mWindow.clear();

#if defined(DEBUG_FPS_INFO)
		mWindow.draw(mFPSText);
#endif
		mWindow.display();
	}

} // hle