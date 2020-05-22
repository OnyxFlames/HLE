#pragma once


#include <map>
#include <string>

#include <SFML/Window/Event.hpp>

#include "../command/Command.hpp"
#include "../command/CommandQueue.hpp"

namespace hle
{
	class Player 
	{
	public:
		// TODO: refactor to use a string type, and typedef Action to std::string
		enum Action
		{
			MoveLeft,
			MoveRight,
			MoveUp,
			MoveDown,
			ShowPos,
			ActionCount,
		};

		// todo: add joystick and mouse actions as well, allow handleEvent() to delegate to other event handling functions to be cleaner
		enum ActionType
		{
			Unknown,
			KeyPress,
			KeyRelease,
			KeyHold,
			ActionTypeCount,
		};

	public: /* functions */

		Player();

		void assignKey(const Action& action, const sf::Keyboard::Key key, const ActionType actiontype);
		sf::Keyboard::Key getAssignedKey(const Action& action) const;

		void assignAction(const Action& action, const Command& command);

		void handleEvent(const sf::Event& event, CommandQueue& commands);
		void handleRealtimeInput(CommandQueue& commands);

	private: /* functions */
		bool isRealtimeAction(const Action action);
		void initializeDefaultKeybindings();


	private: /* members */
		std::map<sf::Keyboard::Key, Action> mKeyBinding;
		std::map<Action, Command> mActionBinding;
		std::map<Action, ActionType> mActionType; // press, realtime?

		const float mPlayerSpeed = 1000.f;
	};
}

