#include "View.hpp"

#include <sstream>

#include "vector/Vector2.hpp"

namespace hle
{
	std::string to_string(const sf::View& view)
	{
		std::stringstream oss;

		oss << to_string(view.getCenter())
			<< " "
			<< to_string(view.getSize())
			<< " "
			<< view.getRotation();

		return oss.str();
	}
}