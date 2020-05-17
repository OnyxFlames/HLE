#pragma once

#include <SFML/System/Time.hpp>

namespace hle
{
	namespace time
	{
		const static sf::Time Minute = sf::seconds(60.f);
		const static sf::Time Hour = sf::seconds(Minute.asSeconds() * 60.f);
		const static sf::Time Day = sf::seconds(Hour.asSeconds() * 24.f);

		sf::Time minutes(float mins);
		sf::Time hours(float hours);
		sf::Time days(float days);
	}
}