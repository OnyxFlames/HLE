#pragma once

#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "StateIdentifiers.hpp"
#include "../input/Player.hpp"
#include "../core/ResourceManager.hpp"

namespace hle
{
	class StateStack;

	class State
	{
	public:
		typedef std::unique_ptr<State> Ptr;
		struct Context
		{
			Context(
				sf::RenderWindow& window,
				TextureManager& textures,
				FontManager& fonts,
				Player& player);

			sf::RenderWindow* window;
			TextureManager* textures;
			FontManager* fonts;
			Player* player;
		};
	public:
		State(StateStack& stack, Context context);
		virtual ~State();

		virtual void draw() = 0;
		virtual bool update(sf::Time dt) = 0;
		virtual bool handleEvent(const sf::Event& event) = 0;

	protected:
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();

		Context getContext() const;

	private:
		StateStack* mStack;
		Context mContext;
	};
}


