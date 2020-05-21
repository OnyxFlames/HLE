#include "SceneNode.hpp"

#include <cassert>

#include "../command/Command.hpp"
#include "../Utility.hpp"

namespace hle
{
	SceneNode::SceneNode()
		:	mParent(nullptr)
		,	mChildren()
	{
	}

	void SceneNode::attachChild(Ptr child)
	{
		child->mParent = this;
		mChildren.push_back(std::move(child));
	}

	SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
	{
		auto found = std::find_if(
			mChildren.begin(),
			mChildren.end(),
			[&](Ptr& p) -> bool
			{
				return p.get() == &node;
			});
		assert(found != mChildren.end());

		Ptr result = std::move(*found);
		result->mParent = nullptr;
		mChildren.erase(found);
		return result;
	}
	void SceneNode::update(sf::Time dt)
	{
		updateCurrent(dt);
		updateChildren(dt);
	}
	sf::Vector2f SceneNode::getWorldPosition() const
	{
		return getWorldTransform() * sf::Vector2f();
	}
	sf::Transform SceneNode::getWorldTransform() const
	{
		// TODO: Cache world transforms if we can detect it being altered?
		sf::Transform transform;

		for (	const SceneNode* node = this;
				node != nullptr;
				node = node->mParent)
		{
			transform = node->getTransform() * transform;
		}

		return transform;
	}
	Category::Type SceneNode::getCategory() const
	{
		return Category::Scene;
	}
	void SceneNode::onCommand(const Command& command, sf::Time dt)
	{
		if (command.category & getCategory())
			command.action(*this, dt);

		if (command.category == Category::ByID && util::castable_to<Entity>(*this))
		{
			// prevent invalid casts
			if (static_cast<Entity&>(*this).getID() == command.id)
				command.action(*this, dt);
		}

		for (Ptr& child : mChildren)
			child->onCommand(command, dt);
	}
	void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		drawCurrent(target, states);

		for (const Ptr& itr : mChildren)
		{
			itr->draw(target, states);
		}
	}
	void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
	void SceneNode::updateCurrent(sf::Time dt)
	{
	}
	void SceneNode::updateChildren(sf::Time dt)
	{
		for (Ptr& child : mChildren)
			child->update(dt);
	}
}