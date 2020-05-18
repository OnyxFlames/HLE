#pragma once

#include <array>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "entity/Entity.hpp"
#include "core/ResourceManager.hpp"
#include "scene/SceneNode.hpp"

namespace hle
{
	class World : public sf::NonCopyable
	{
	public:
		explicit World(sf::RenderWindow& window);
		void update(sf::Time dt);
		void draw();
	private:
		void loadTextures();
		void buildScene();
	private:
		sf::RenderWindow& mWindow;
		sf::View mWorldView;
		TextureManager mTextures;
		SceneNode mSceneGraph;
		std::array<SceneNode*, SceneLayer::LayerCount> mSceneLayers;

		sf::FloatRect mWorldBounds;
		sf::Vector2f mSpawnPosition;
		float mScrollSpeed;
		Entity* mPlayer;
	};
}

