#pragma once

#include <vector>
#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>

#include "../command/Category.hpp"

namespace hle
{
	struct Command;


	enum SceneLayer
	{
		Background,
		Air,
		LayerCount,
	};

	class SceneNode
		: public sf::Transformable
		, public sf::Drawable
		, private sf::NonCopyable
	{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

	public:
		SceneNode();

		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

		void update(sf::Time dt);

		sf::Vector2f getWorldPosition() const;
		sf::Transform getWorldTransform() const;

		virtual Category::Type getCategory() const;
		void onCommand(const Command& command, sf::Time dt);
	private:
		std::vector<Ptr> mChildren;
		SceneNode* mParent;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual void updateCurrent(sf::Time dt);
		void updateChildren(sf::Time dt);
	};
}
