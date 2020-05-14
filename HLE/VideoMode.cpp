#include "VideoMode.hpp"

#include <sstream>

std::string hle::to_string(const sf::VideoMode& mode, bool bpp)
{
	std::ostringstream oss;
	if (bpp)
		oss << mode.width << "x" << mode.height << " - " << mode.bitsPerPixel << " bpp";
	else
		oss << mode.width << "x" << mode.height;

	return oss.str();
}
