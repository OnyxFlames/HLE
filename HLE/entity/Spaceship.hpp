#pragma once

#include "Entity.hpp"

namespace hle
{
	class Spaceship : public Entity
	{
	public:
		enum class Type
		{
			// friendly
			PlayerBlue_1,
			PlayerGreen_1,
			PlayerOrange_1,
			PlayerRed_1,
			PlayerBlue_2,
			PlayerGreen_2,
			PlayerOrange_2,
			PlayerRed_2,
			PlayerBlue_3,
			PlayerGreen_3,
			PlayerOrange_3,
			PlayerRed_3,
			PlayerBlue_4,
			PlayerGreen_4,
			PlayerOrange_4,
			PlayerRed_4,
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
		explicit Spaceship(Type type);

	private:
		Type mType;
	};
}
