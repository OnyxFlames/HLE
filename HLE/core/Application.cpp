#include "Application.hpp"

#include <SFML/Window/Event.hpp>

#include "../Common.hpp"

#include "../time/FramerateClock.hpp"

namespace hle
{

	const sf::Time Application::TimePerFrame = sf::seconds(1.f / 1.44f);

	Application::Application()
		: mWindow(sf::VideoMode(640, 480), "HLE - Hierarch Labs Engine")
	{
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
			if (mFrameClock.update())
				printf("FPS: %d\n", mFrameClock.getFramerate());
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

		mWindow.display();
	}

} // hle