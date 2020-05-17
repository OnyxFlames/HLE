#pragma once

#include "Entity.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include "../core/ResourceManager.hpp"

namespace hle
{
	class Spaceship : public Entity
	{
	public:
		enum class Type
		{
			UnknownShip = -1,

			// friendly
			FriendlyBlue_1,
			FriendlyGreen_1,
			FriendlyOrange_1,
			FriendlyRed_1,
			FriendlyBlue_2,
			FriendlyGreen_2,
			FriendlyOrange_2,
			FriendlyRed_2,
			FriendlyBlue_3,
			FriendlyGreen_3,
			FriendlyOrange_3,
			FriendlyRed_3,
			FriendlyBlue_4,
			FriendlyGreen_4,
			FriendlyOrange_4,
			FriendlyRed_4,
			// hostile
			HostileBlack_1,
			HostileBlue_1,
			HostileGreen_1,
			HostileRed_1,
			HostileBlack_2,
			HostileBlue_2,
			HostileGreen_2,
			HostileRed_2,
			HostileBlack_3,
			HostileBlue_3,
			HostileGreen_3,
			HostileRed_3,
			HostileBlack_4,
			HostileBlue_4,
			HostileGreen_4,
			HostileRed_4,
			HostileBlack_5,
			HostileBlue_5,
			HostileGreen_5,
			HostileRed_5,

			TypeCount,
		};

	public:
		explicit Spaceship(Type type, const hle::TextureManager& textures);


		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		Type mType;
		sf::Sprite mSprite;
	};
}
