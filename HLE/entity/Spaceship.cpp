#include "Spaceship.hpp"

#include <string>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../transform/Transform.hpp"

namespace hle
{

	const std::string toTextureID(Spaceship::Type type)
	{
		switch (type)
		{
		case Spaceship::Type::FriendlyBlue_1: return "BlueShip1";
		case Spaceship::Type::FriendlyGreen_1: return "GreenShip1";
		case Spaceship::Type::FriendlyOrange_1: return "OrangeShip1";
		case Spaceship::Type::FriendlyRed_1: return "RedShip1";

		case Spaceship::Type::HostileBlack_1: return "EnemyBlackShip1";
		case Spaceship::Type::HostileBlue_1: return "EnemyBlueShip1";
		case Spaceship::Type::HostileGreen_1: return "EnemyGreenShip1";
		case Spaceship::Type::HostileRed_1: return "EnemyRedShip1";
		
		default: return "Unknown";

		}
	}
	Spaceship::Spaceship(Type type, const hle::TextureManager& textures)
		:	mType(type)
		,	mSprite(textures.get(toTextureID(type)))
	{
		center_origin(mSprite);
	}
	void Spaceship::accelerate(const sf::Vector2f velocity)
	{
		mVelocity += velocity;
	}
	Category::Type Spaceship::getCategory() const
	{
		switch (mType)
		{
		case Spaceship::Type::FriendlyBlue_1: return Category::Player;
		case Spaceship::Type::FriendlyGreen_1:
		case Spaceship::Type::FriendlyOrange_1:
		case Spaceship::Type::FriendlyRed_1:
			return Category::Ally;
		default: return Category::Enemy;
		}
	}
	void Spaceship::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(mSprite, states);
	}
}