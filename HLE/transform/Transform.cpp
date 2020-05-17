#include "Transform.hpp"

#include <cmath>

namespace hle
{
	void center_origin(sf::Sprite& sprite)
	{
		const sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin({ 
			std::floor((bounds.left + bounds.width) / 2.f), 
			std::floor((bounds.top + bounds.height) / 2.f)});
	}
	void center_origin(sf::Text& text)
	{
		const sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin({ 
			std::floor((bounds.left + bounds.width) / 2.f), 
			std::floor((bounds.top + bounds.height) / 2.f) });
	}
	void center_origin(sf::Shape& shape)
	{
		const sf::FloatRect bounds = shape.getLocalBounds();
		shape.setOrigin({
			std::floor((bounds.left + bounds.width) / 2.f),
			std::floor((bounds.top + bounds.height) / 2.f) });
	}
}