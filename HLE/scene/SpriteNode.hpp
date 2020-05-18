#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "SceneNode.hpp"

namespace hle
{
	class SpriteNode : public SceneNode
	{
	public:
		explicit SpriteNode(const sf::Texture& texture);
		SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);
	private:

		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite mSprite;
	};
}