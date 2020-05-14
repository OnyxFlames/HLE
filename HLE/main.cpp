
#include "Utility.hpp"

#include "Color.hpp"

#include <SFML/Window/VideoMode.hpp>
#include "VideoMode.hpp"
#include "Vector2.hpp"
#include "Math.hpp"
#include <SFML/System/Vector2.hpp>

int main()
{
	sf::Vector2f vec(16, 32);
	for (size_t i = 0; i < 100; ++i)
	{
		vec = hle::step_to(sf::Vector2f(i, i * 2), sf::Vector2f(64, 128));
		std::printf("Move: %s\n",
			hle::to_string(hle::step_to(vec, sf::Vector2f(64, 128))).c_str());

	}

	return 0;
}