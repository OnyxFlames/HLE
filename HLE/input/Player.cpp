#include "Player.hpp"

#include "../entity/Spaceship.hpp"
#include "../command/Command.hpp"

#include "../vector/Vector2.hpp"

namespace hle
{
	void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
		{
			Command output;
			output.category = Category::ByID;
			output.action = [](SceneNode& s, sf::Time)
			{
				printf("Player Pos: %s\n", to_string(s.getPosition()).c_str());
			};
			output.id = 0;
			commands.push(output);
		}
	}
	void Player::handleRealtimeInput(CommandQueue& commands)
	{
		const float playerSpeed = 1000.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Command moveUp;
			moveUp.category = Category::Player;
			moveUp.action = derivedFunction<Spaceship>(SpaceshipMover(0.f, -playerSpeed));
			commands.push(moveUp);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Command moveDown;
			moveDown.category = Category::Player;
			moveDown.action = derivedFunction<Spaceship>(SpaceshipMover(0.f, playerSpeed));
			commands.push(moveDown);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Command moveLeft;
			moveLeft.category = Category::Player;
			moveLeft.action = derivedFunction<Spaceship>(SpaceshipMover(-playerSpeed, 0.f));
			commands.push(moveLeft);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Command moveRight;
			moveRight.category = Category::Player;
			moveRight.action = derivedFunction<Spaceship>(SpaceshipMover(playerSpeed, 0.f));
			commands.push(moveRight);
		}
	}
}