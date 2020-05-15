#pragma once

#include <cassert>
#include <sstream>
#include "Vector2.hpp"

#include "Math.hpp"

namespace hle
{
	template<typename T>
	inline std::string to_string(const sf::Vector2<T>& vec)
	{
		std::ostringstream oss;
		oss << "{ " << vec.x << ", " << vec.y << " }";

		return oss.str();
	}

	template<typename T>
	inline T length(const sf::Vector2<T>& vec)
	{
		return std::sqrt(lengthSquared<T>(vec));
	}

	template<typename T>
	inline T lengthSquared(const sf::Vector2<T>& vec)
	{
		return dotProduct(vec, vec);
	}

	template<typename T>
	inline void setLength(sf::Vector2<T>& vec, T length)
	{
		assert(vec != sf::Vector2<T>());
		vec *= length / length(vec);
	}

	template<typename T>
	inline sf::Vector2<T> unitVector(const sf::Vector2<T>& vec)
	{
		assert(vec != sf::Vector2<T>());
		return vec / length(vec);
	}

	template<typename T>
	inline T polarAngle(const sf::Vector2<T>& vec)
	{
		assert(vec != sf::Vector2<T>());
		return std::atan2(static_cast<T>(vec.x), static_cast<T>(vec.y));
	}

	template<typename T>
	inline void setPolarAngle(sf::Vector2<T>& vec, T angle)
	{
		const T len = length(vec);

		vec.x = len * std::cos(static_cast<T>(angle));
		vec.y = len * std::sin(static_cast<T>(angle));
	}

	template<typename T>
	inline void rotate(sf::Vector2<T>& vec, T angle)
	{
		const T cos = std::cos(static_cast<T>(angle));
		const T sin = std::sin(static_cast<T>(angle));

		vec = sf::Vector2<T>(
			cos * vec.x - sin * vec.y,
			sin * vec.x + cos * vec.y);
	}

	template<typename T>
	inline sf::Vector2<T> rotatedVector(const sf::Vector2<T>& vec, T angle)
	{
		sf::Vector2<T> ret = vec;
		rotate(ret, angle);

		return ret;
	}

	template<typename T>
	inline sf::Vector2<T> perpendicularVector(const sf::Vector2<T>& vec)
	{
		return sf::Vector2<T>(-vec.y, vec.x);
	}

	template<typename T>
	inline T signedAngle(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
	{
		assert(lhs != sf::Vector2<T>() && rhs != sf::Vector2<T>);
		return std::atan2(crossProduct<T>(lhs, rhs), dotProduct<T>(lhs, rhs));
	}

	template<typename T>
	inline T dotProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	template<typename T>
	inline T crossProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	template<typename T>
	inline sf::Vector2<T> cwiseProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
	{
		return sf::Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
	}

	template<typename T>
	inline sf::Vector2<T> cwiseQuotient(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
	{
		assert(rhs.x != static_cast<T>(0) && rhs.y != static_cast<T>(0));
		return sf::Vector2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
	}

	template<typename T>
	inline sf::Vector2<T> projectedVector(const sf::Vector2<T>& vec, const sf::Vector2<T>& axis)
	{
		assert(axis != sf::Vector2<T>());
		return dotProduct(vec, axis) / lengthSquared(axis) * axis;
	}

	template<typename T>
	sf::Vector2<T> normalize(const sf::Vector2<T>& vec)
	{
		return unitVector<T>(vec);
	}
	template<typename T>
	bool is_normalized(const sf::Vector2<T>& vec)
	{
		return math::is_approx_equal(lengthSquared(vec), static_cast<T>(1.0));
	}
	template<typename T>
	sf::Vector2<T> step_to(const sf::Vector2<T>& from, const sf::Vector2<T>& to)
	{
		return sf::Vector2<T>
			(
				math::step(from.x, to.x),
				math::step(from.y, to.y)
			);
	}

	// https://github.com/godotengine/godot/blob/master/core/math/vector2.cpp#L180

	template<typename T>
	sf::Vector2<T> move_toward(const sf::Vector2<T>& from, const sf::Vector2<T>& to, const T delta)
	{
		const sf::Vector2<T> diff = to - from;

		const T len = length(diff);

		return (len <= delta || len < CMP_TOLERANCE) ? to : from + diff / len * delta;

	}
}