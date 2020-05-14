#pragma once

#include <SFML/System/Vector2.hpp>

#include <string>

namespace hle
{
	// Reference:
	// https://github.com/Bromeon/Thor/blob/master/include/Thor/Vectors/VectorAlgebra2D.hpp
	template <typename T>
	T length(const sf::Vector2<T>& vec);

	template <typename T>
	T lengthSquared(const sf::Vector2<T>& vec);

	template <typename T>
	void setLength(sf::Vector2<T>& vec, T length);

	template <typename T>
	sf::Vector2<T> unitVector(const sf::Vector2<T>& vec);

	template <typename T>
	T polarAngle(const sf::Vector2<T>& vec);

	template <typename T>
	void setPolarAngle(sf::Vector2<T>& vec, T angle);

	template <typename T>
	void rotate(sf::Vector2<T>& vec, T angle);

	template <typename T>
	sf::Vector2<T> rotatedVector(const sf::Vector2<T>& vec, T angle);

	template <typename T>
	sf::Vector2<T> perpendicularVector(const sf::Vector2<T>& vec);

	template <typename T>
	T signedAngle(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs);

	template <typename T>
	T dotProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs);

	template <typename T>
	T crossProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs);

	template <typename T>
	sf::Vector2<T> cwiseProduct(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs);

	template <typename T>
	sf::Vector2<T> cwiseQuotient(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs);

	template <typename T>
	sf::Vector2<T> projectedVector(const sf::Vector2<T>& vec, const sf::Vector2<T>& axis);

	template <typename T>
	sf::Vector2<T> normalize(const sf::Vector2<T>& vec);

	template <typename T>
	bool is_normalized(const sf::Vector2<T>& vec);

	template <typename T>
	sf::Vector2<T> step_to(const sf::Vector2<T>& from, const sf::Vector2<T>& to);

	template <typename T>
	sf::Vector2<T> move_toward(const sf::Vector2<T>& from, const sf::Vector2<T>& to, const T delta);

	template <typename T>
	std::string to_string(const sf::Vector2<T>& vec);

	

}

#include "Vector2.inl"