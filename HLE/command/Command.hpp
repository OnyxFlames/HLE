#pragma once

#include <functional>
#include <SFML/System/Time.hpp>

#include "Category.hpp"
#include "../scene/SceneNode.hpp"
#include "../entity/Entity.hpp"

#include <cassert>

#include "../Utility.hpp"

namespace hle
{
	struct Command
	{
		typedef std::function<void(SceneNode&, sf::Time)> Action;
		Command();
		Command(Category::Type _type, Action _action);
		Command(Category::Type _type, Action _action, Entity::ID id);
		Category::Type category;
		Action action;
		Entity::ID id;

		inline bool operator==(const Command& other)
		{
			return (category == other.category /*&& action == other.action*/ && id == other.id);
		}
	};


	template <typename GameObject, typename Function>
	std::function<void(SceneNode&, sf::Time)> derivedFunction(const Function& fn);

	template<typename GameObject, typename Function>
	inline std::function<void(SceneNode&, sf::Time)> derivedFunction(const Function& fn)
	{
		return [=](SceneNode& node, sf::Time dt)
		{
			//assert(util::castable_to<GameObject>(node));

			fn(static_cast<GameObject&>(node), dt);
		};
	}

}