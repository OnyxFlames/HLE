#include "Color.hpp"

#include <map>
#include <string>

#include "Utility.hpp"

#include "Colordef.hpp"

namespace hle
{
	namespace color
	{
		uint32_t operator&(uint32_t lhs, ColorFilter rhs)
		{
			return lhs & static_cast<uint32_t>(rhs);
		}
		uint32_t operator|(uint32_t lhs, ColorFilter rhs)
		{
			return lhs | static_cast<uint32_t>(rhs);
		}

		uint32_t operator&(ColorFilter lhs, ColorFilter rhs)
		{
			return static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs);
		}

		uint32_t operator|(ColorFilter lhs, ColorFilter rhs)
		{
			return static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs);
		}

		sf::Color inverted(const sf::Color& color)
		{
			return sf::Color
			(
				255 - color.r,
				255 - color.g,
				255 - color.b,
				color.a
			);
		}

		sf::Color contrasted(const sf::Color& color)
		{
			float r = color.r / 255.f, g = color.g / 255.f, b = color.b / 255.f;
			return sf::Color
			(
				static_cast<uint8_t>(std::fmod(r + 0.5f, 1.0f) * 255),
				static_cast<uint8_t>(std::fmod(g + 0.5f, 1.0f) * 255),
				static_cast<uint8_t>(std::fmod(b + 0.5f, 1.0f) * 255),
				color.a
			);
		}

		std::vector<sf::Color> getColors(uint32_t colors)
		{
			std::vector<sf::Color> ret;

#define add(c) ret.push_back(c)

			if (colors & ColorFilter::Red)
			{
				add(IndianRed);
				add(LightCoral);
				add(Salmon);
				add(DarkSalmon);
				add(LightSalmon);
				add(Crimson);
				add(Red);
				add(FireBrick);
				add(DarkRed);
			}
			if (colors & ColorFilter::Pink)
			{
				add(Pink);
				add(LightPink);
				add(HotPink);
				add(DeepPink);
				add(MediumVioletRed);
				add(PaleVioletRed);
			}
			if (colors & ColorFilter::Orange)
			{
				add(LightSalmon);
				add(Coral);
				add(Tomato);
				add(OrangeRed);
				add(DarkOrange);
				add(Orange);
			}
			if (colors & ColorFilter::Yellow)
			{
				add(Gold);
				add(Yellow);
				add(LightYellow);
				add(LemonChiffon);
				add(LightGoldenRodYellow);
				add(PapayaWhip);
				add(Moccasin);
				add(PeachPuff);
				add(PaleGoldenRod);
				add(Khaki);
				add(DarkKhaki);
			}
			if (colors & ColorFilter::Purple)
			{
				add(Lavender);
				add(Thistle);
				add(Plum);
				add(Violet);
				add(Orchid);
				add(Fuchsia);
				add(Magenta);
				add(MediumOrchid);
				add(MediumPurple);
				add(RebeccaPurple);
				add(BlueViolet);
				add(DarkViolet);
				add(DarkOrchid);
				add(DarkMagenta);
				add(Purple);
				add(Indigo);
				add(SlateBlue);
				add(DarkSlateBlue);
				add(MediumSlateBlue);
			}
			if (colors & ColorFilter::Green)
			{
				add(GreenYellow);
				add(Chartreuse);
				add(LawnGreen);
				add(Lime);
				add(LimeGreen);
				add(PaleGreen);
				add(LightGreen);
				add(MediumSpringGreen);
				add(SpringGreen);
				add(MediumSeaGreen);
				add(SeaGreen);
				add(ForestGreen);
				add(Green);
				add(DarkGreen);
				add(YellowGreen);
				add(OliveDrab);
				add(Olive);
				add(DarkOliveGreen);
				add(MediumAquamarine);
				add(DarkSeaGreen);
				add(LightSeaGreen);
				add(DarkCyan);
				add(Teal);
			}
			if (colors & ColorFilter::Blue)
			{
				add(Aqua);
				add(Cyan);
				add(LightCyan);
				add(PaleTurquoise);
				add(Aquamarine);
				add(Turquoise);
				add(MediumTurquoise);
				add(DarkTurquoise);
				add(CadetBlue);
				add(SteelBlue);
				add(LightSteelBlue);
				add(PowderBlue);
				add(LightBlue);
				add(SkyBlue);
				add(LightSkyBlue);
				add(DeepSkyBlue);
				add(DodgerBlue);
				add(CornflowerBlue);
				add(MediumSlateBlue);
				add(RoyalBlue);
				add(Blue);
				add(MediumBlue);
				add(DarkBlue);
				add(Navy);
				add(MidnightBlue);
			}
			if (colors & ColorFilter::Brown)
			{
				add(CornSilk);
				add(BlanchedAlmond);
				add(Bisque);
				add(NavajoWhite);
				add(Wheat);
				add(Burlywood);
				add(Tan);
				add(RosyBrown);
				add(SandyBrown);
				add(GoldenRod);
				add(DarkGoldenRod);
				add(Peru);
				add(Chocolate);
				add(SaddleBrown);
				add(Sienna);
				add(Brown);
				add(Maroon);
			}
			if (colors & ColorFilter::White)
			{
				add(White);
				add(Snow);
				add(HoneyDew);
				add(MintCream);
				add(Azure);
				add(AliceBlue);
				add(GhostWhite);
				add(WhiteSmoke);
				add(Seashell);
				add(Biege);
				add(Oldlace);
				add(FloralWhite);
				add(Ivory);
				add(AntiqueWhite);
				add(Linen);
				add(LavenderBlush);
				add(MistyRose);
			}
			if (colors & ColorFilter::Gray)
			{
				add(Gainsboro);
				add(LightGray);
				add(Silver);
				add(DarkGray);
				add(Gray);
				add(DimGray);
				add(LightSlateGray);
				add(SlateGray);
				add(DarkSlateGray);
				add(Black);
			}
#undef add
			return ret;
		}

		sf::Color byName(const std::string name)
		{
			if (detail::_color_map.empty())
				detail::populate_color_map();

			if (hle::util::contains(detail::_color_map, name))
				return detail::_color_map[name];
			else
				return sf::Color();
		}

	}
}

