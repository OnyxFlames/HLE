#pragma once

#include <functional>
#include <SFML/System/Time.hpp>

#include "../scene/SceneNode.hpp"

#include "Category.hpp"

#include <cassert>

namespace hle
{
	struct Command
	{
		Command();
		std::function<void(SceneNode&, sf::Time)> action;
		Category::Type category;
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