#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "../Debug.hpp"

#include "../World.hpp"
#include "../input/Player.hpp"

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
		World mWorld;
		Player mPlayer;
	private:
		void processEvents();
		void update(sf::Time dt);
		void render();

	private:
		sf::RenderWindow mWindow;
		bool mIsPaused = false, mPausedFromLostFocus = false;
	};

}