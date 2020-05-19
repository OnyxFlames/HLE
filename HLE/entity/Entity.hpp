#pragma once

#include <SFML/System/Vector2.hpp>

#include "../scene/SceneNode.hpp"

namespace hle
{
	class Entity : public SceneNode
	{
	public:
		typedef size_t ID;
	private:
		static ID mIDCounter;
		const ID mID;
	protected:
		sf::Vector2f mVelocity;
	public:
		Entity();

		void setVelocity(float vx, float vy);
		void setVelocity(sf::Vector2f velocity);

		const sf::Vector2f getVelocity() const;

		const size_t getID() const;
	private:
		virtual void updateCurrent(sf::Time dt);
	};
}