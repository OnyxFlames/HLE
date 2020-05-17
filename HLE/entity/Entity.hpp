#pragma once

#include <SFML/System/Vector2.hpp>

namespace hle
{
	class Entity
	{
	private:
		static size_t mIDCounter;
		const size_t mID;
		sf::Vector2f mVelocity;
	public:
		Entity();

		void setVelocity(float vx, float vy);
		void setVelocity(sf::Vector2f velocity);

		const sf::Vector2f getVelocity() const;

		const size_t getID() const;
	};
}