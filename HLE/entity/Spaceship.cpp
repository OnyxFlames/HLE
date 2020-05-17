#include "Spaceship.hpp"

#include <string>

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
	{
	}
	void Spaceship::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}