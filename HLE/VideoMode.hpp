#pragma once

#include <string>
#include <SFML/Window/VideoMode.hpp>

namespace hle
{
	std::string to_string(const sf::VideoMode& mode, bool bpp = true);
}