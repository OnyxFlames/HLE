
#include "Utility.hpp"

#include "Color.hpp"

#include <SFML/Window/VideoMode.hpp>
#include "VideoMode.hpp"
#include "vector/Vector2.hpp"
#include "math/Math.hpp"
#include <SFML/System/Vector2.hpp>

int main()
{
	float f = 1.f;
	for (size_t i = 0; i < 32; ++i)
	{
		f *= 1.25f;
		printf("%g - %g\n", f, hle::math::snap_to<float>(f, 8, 128));
	}

	return 0;
}