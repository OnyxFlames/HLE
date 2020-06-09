#include "Player.hpp"

#include "../entity/Spaceship.hpp"
#include "../command/Command.hpp"

#include "../vector/Vector2.hpp"

#include "../time/Time.hpp"

namespace hle
{

	Player::Player()
	{
		initializeDefaultKeybindings();
	}
	void Player::assignKey(const Action& action, const sf::Keyboard::Key key, const ActionType actiontype = ActionType::KeyHold)
	{
		for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end();)
		{
			if (itr->second == action)
				mKeyBinding.erase(itr++);
			else
				++itr;
		}
		mKeyBinding[key] = action;
		//  TODO: See if we can move this elsewhere?
		mActionType[action] = actiontype;
	}
	sf::Keyboard::Key Player::getAssignedKey(const Action& action) const
	{
		for (auto& pair : mKeyBinding)
		{
			if (pair.second == action)
				return pair.first;
		}
		return sf::Keyboard::Unknown;
	}

	void Player::assignAction(const Action& action, const Command& command)
	{
		for (auto itr = mActionBinding.begin(); itr != mActionBinding.end();)
		{
			if (itr->first == action)
				mActionBinding.erase(itr++);
			else
				++itr;
		}
		mActionBinding[action] = command;
	}
	void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
	{
		if (!util::contains(mKeyBinding, event.key.code))
			return;

		const auto found = mKeyBinding[event.key.code];

		if (!util::contains(mActionType, found))
			return;

		const auto type = mActionType[found];
	
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			{
				if (type == ActionType::KeyPress)
					commands.push(mActionBinding[found]);
			}
			break;
			case sf::Event::KeyReleased:
			{
				if (type == ActionType::KeyRelease)
					commands.push(mActionBinding[found]);
			}
			break;
		}

	}
	void Player::handleRealtimeInput(CommandQueue& commands)
	{
		for (auto& pair : mKeyBinding)
		{
			const auto& key = pair.first;
			const auto& action = pair.second;

			if (sf::Keyboard::isKeyPressed(key) && isRealtimeAction(action))
				commands.push(mActionBinding[action]);
		}
	}
	bool Player::isRealtimeAction(const Action action)
	{
		return (util::contains(mActionType, action) && (mActionType[action] == ActionType::KeyHold));
	}
	void Player::initializeDefaultKeybindings()
	{
		mKeyBinding[sf::Keyboard::A] = MoveLeft;
		mKeyBinding[sf::Keyboard::D] = MoveRight;
		mKeyBinding[sf::Keyboard::W] = MoveUp;
		mKeyBinding[sf::Keyboard::S] = MoveDown;
		mKeyBinding[sf::Keyboard::P] = ShowPos;

		for (int i = 0; i < Action::ActionCount; ++i)
			mActionType[static_cast<Action>(i)] = ActionType::KeyPress;

		mActionBinding[MoveLeft].action = derivedFunction<Spaceship>(SpaceshipMover(-mPlayerSpeed, 0.f));
		mActionBinding[MoveRight].action = derivedFunction<Spaceship>(SpaceshipMover(mPlayerSpeed, 0.f));
		mActionBinding[MoveUp].action = derivedFunction<Spaceship>(SpaceshipMover(0.f, -mPlayerSpeed));
		mActionBinding[MoveDown].action = derivedFunction<Spaceship>(SpaceshipMover(0.f, mPlayerSpeed));

		mActionBinding[ShowPos].action = [](SceneNode& node, sf::Time dt) 
		{ 
			printf("Pos: %s Vel %s Time: %s\n", 
				to_string(node.getPosition()).c_str(), 
				to_string(reinterpret_cast<Entity*>(&node)->getVelocity()).c_str(),
				time::format_time(sf::seconds(1), hle::time::TimeFormat::Minutes).c_str());  
		};

		// assigned actions get an ActionType, do while setting Category to player to be efficient with this loop
		for (auto& pair : mActionBinding)
		{
			pair.second.category = Category::Player;
			// keypress actions by default
			mActionType[pair.first] = ActionType::KeyHold;
		}

		// to showcase KeyRelease actions
		mActionType[ShowPos] = ActionType::KeyRelease;
	}
}