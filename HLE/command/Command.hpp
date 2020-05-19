#pragma once

#include <functional>
#include <SFML/System/Time.hpp>

#include "Category.hpp"
#include "../scene/SceneNode.hpp"
#include "../entity/Entity.hpp"

#include <cassert>

namespace hle
{
	struct Command
	{
		Command();
		std::function<void(SceneNode&, sf::Time)> action;
		Category::Type category;
		Entity::ID id;
	};


	template <typename GameObject, typename Function>
	std::function<void(SceneNode&, sf::Time)> derivedFunction(const Function& fn);

	template<typename GameObject, typename Function>
	inline std::function<void(SceneNode&, sf::Time)> derivedFunction(const Function& fn)
	{
		return [=](SceneNode& node, sf::Time dt)
		{
			assert(dynamic_cast<GameObject*>(&node) != nullptr);

			fn(static_cast<GameObject&>(node), dt);
		};
	}

}