#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "../Debug.hpp"

#if defined(DEBUG_FPS_INFO)
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#endif

namespace hle
{

	class Application
	{
	public:
		static const sf::Time TimePerFrame;

		Application();
		void run();
#if defined(DEBUG_FPS_INFO)
		sf::Font mDebugFont;
		sf::Text mFPSText;
#endif
	private:
		void processEvents();
		void update(sf::Time dt);
		void render();

	private:
		sf::RenderWindow mWindow;
	};

}