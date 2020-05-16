#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

namespace hle
{

	class Application
	{
	public:
		static const sf::Time TimePerFrame;


		Application();
		void run();

	private:
		void processEvents();
		void update(sf::Time dt);
		void render();

	private:
		sf::RenderWindow mWindow;
	};

}