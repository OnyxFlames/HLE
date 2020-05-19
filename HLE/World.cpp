#include "World.hpp"

#include <cassert>

#include "scene/SpriteNode.hpp"
#include "entity/Spaceship.hpp"

#include "vector/Vector2.hpp"
#include "View.hpp"

namespace hle
{
	World::World(sf::RenderWindow& window)
		:	mWindow(window)
		//,	mWorldView(window.getDefaultView()) // leaving this line will cause the View to be offset and nothing being rendered properly
		,	mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
		,	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
		,	mScrollSpeed(-50.f)
		,	mPlayer(nullptr)
	{
		loadTextures();
		buildScene();
		mWorldView.setCenter(mSpawnPosition);
		mWorldView.setSize(1000, 1000);

		assert(mPlayer && "Player entity is not valid");
	}
	void World::update(sf::Time dt)
	{
#if defined(DEBUG_WORLD_VIEW_BUG)
		printf("Player: %s ", to_string(mPlayer->getPosition()).c_str());
		printf("World Bounds: Pos: %s Size: %s\n",
			to_string(sf::Vector2f{ mWorldBounds.left, mWorldBounds.top }).c_str(),
			to_string(sf::Vector2f{ mWorldBounds.width, mWorldBounds.height }).c_str());
		printf("Spawn: %s ", to_string(mSpawnPosition).c_str());
		printf("View: Center: %s Size: %s\n",
			to_string(mWorldView.getCenter()).c_str(),
			to_string(mWorldView.getSize()).c_str());
		printf("Window Default View: Size: %s Center: %s\n",
			to_string(mWindow.getDefaultView().getSize()).c_str(),
			to_string(mWindow.getDefaultView().getCenter()).c_str());
#endif
		mPlayer->setVelocity({ 0.f, 0.f });

		while (!mCommandQueue.empty())
			mSceneGraph.onCommand(mCommandQueue.pop(), dt);

		mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

		auto vel = mPlayer->getVelocity();

		if (vel.x != 0.f && vel.y != 0.f)
			mPlayer->setVelocity(vel / std::sqrt(2.f));

		reinterpret_cast<Spaceship*>(mPlayer)->accelerate({ 0.f, mScrollSpeed });

		mSceneGraph.update(dt);
	}
	void World::draw()
	{
		mWindow.setView(mWorldView);
		mWindow.draw(mSceneGraph);
	}
	CommandQueue& World::getCommandQueue()
	{
		return mCommandQueue;
	}
	void World::loadTextures()
	{
		mTextures.load("BlueShip1", "../resources/textures/ships/friendly/playerShip1_blue.png");
		mTextures.load("PurpleSpace", "../resources/textures/space/purple.png");
	}
	void World::buildScene()
	{
		for (size_t i = 0; i < SceneLayer::LayerCount; ++i)
		{
			SceneNode::Ptr layer(new SceneNode());
			mSceneLayers[i] = layer.get();

			mSceneGraph.attachChild(std::move(layer));
		}

		sf::Texture& texture = mTextures.get("PurpleSpace");
		sf::IntRect textureRect(mWorldBounds);
		texture.setRepeated(true);

		std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
		backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
		mSceneLayers[SceneLayer::Background]->attachChild(std::move(backgroundSprite));

		std::unique_ptr<Spaceship> leader(new Spaceship(Spaceship::Type::FriendlyBlue_1, mTextures));
		mPlayer = leader.get();
		mPlayer->setPosition(mSpawnPosition);
		mPlayer->setVelocity(0.f, mScrollSpeed);
		mSceneLayers[SceneLayer::Air]->attachChild(std::move(leader));
	}
}