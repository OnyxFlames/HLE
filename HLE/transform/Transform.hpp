#pragma once

#include <SFML/Graphics/Transformable.hpp>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace hle
{
	void center_origin(sf::Sprite& sprite);
	void center_origin(sf::Text& text);
	void center_origin(sf::Shape& shape);
}