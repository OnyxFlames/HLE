#include "Entity.hpp"

namespace hle
{
	Entity::ID Entity::mIDCounter = 0;
	Entity::Entity()
		:	mID(mIDCounter++)
	{
	}
	void Entity::setVelocity(float vx, float vy)
	{
		mVelocity = { vx, vy };
	}
	void Entity::setVelocity(sf::Vector2f velocity)
	{
		mVelocity = velocity;
	}
	const sf::Vector2f Entity::getVelocity() const
	{
		return mVelocity;
	}
	const size_t Entity::getID() const
	{
		return mID;
	}
	void Entity::updateCurrent(sf::Time dt)
	{
		move(mVelocity * dt.asSeconds());
	}
}