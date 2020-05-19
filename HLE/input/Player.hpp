#pragma once

#include <SFML/Window/Event.hpp>
#include "../command/CommandQueue.hpp"

namespace hle
{
	class Player 
	{
	public:
		void handleEvent(const sf::Event& event, CommandQueue& commands);
		void handleRealtimeInput(CommandQueue& commands);
	};
}

