#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Common.hpp"

#include <string>
#include <vector>

namespace hle
{
	namespace color
	{
		enum class ColorFilter : uint32_t
		{
			Red =		1 << 0,
			Pink =		1 << 1,
			Orange =	1 << 2,
			Yellow =	1 << 3,
			Purple =	1 << 4,
			Green =		1 << 5,
			Blue =		1 << 6,
			Brown =		1 << 7,
			White =		1 << 8,
			Gray =		1 << 9,

		};

		uint32_t operator&(ColorFilter lhs, ColorFilter rhs);

		uint32_t operator|(ColorFilter lhs, ColorFilter rhs);

		std::vector<sf::Color> getColors(uint32_t colors);

		sf::Color byName(const std::string name);
	}
}
