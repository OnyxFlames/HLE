#pragma once

/*
	Color definitions

*/

#include <SFML/Graphics/Color.hpp>

namespace hle
{
	namespace color
	{
#define hle_sfml_color(name, r, g, b) const static sf::Color name = sf::Color(r, g, b)

		// reds
		hle_sfml_color(IndianRed, 205, 92, 92);
		hle_sfml_color(LightCoral, 240, 128, 128);
		hle_sfml_color(Salmon, 250, 128, 114);
		hle_sfml_color(DarkSalmon, 233, 150, 122);
		hle_sfml_color(LightSalmon, 255, 160, 122);
		hle_sfml_color(Crimson, 220, 20, 60);
		hle_sfml_color(Red, 255, 0, 0);
		hle_sfml_color(FireBrick, 178, 34, 34);
		hle_sfml_color(DarkRed, 139, 0, 0);

		// pinks
		hle_sfml_color(Pink, 255, 192, 203);
		hle_sfml_color(LightPink, 255, 182, 193);
		hle_sfml_color(HotPink, 255, 105, 193);
		hle_sfml_color(DeepPink, 255, 20, 147);
		hle_sfml_color(MediumVioletRed, 199, 21, 133);
		hle_sfml_color(PaleVioletRed, 219, 112, 147);

		// oranges
		/* hle_sfml_color(LightSalmon, 255, 160, 122);  defined in reds */
		hle_sfml_color(Coral, 255, 127, 80);
		hle_sfml_color(Tomato, 255, 99, 71);
		hle_sfml_color(OrangeRed, 255, 69, 0);
		hle_sfml_color(DarkOrange, 255, 140, 0);
		hle_sfml_color(Orange, 255, 165, 0);

		// yellows
		hle_sfml_color(Gold, 255, 215, 0);
		hle_sfml_color(Yellow, 255, 255, 0);
		hle_sfml_color(LightYellow, 255, 255, 224);
		hle_sfml_color(LemonChiffon, 255, 250, 205);
		hle_sfml_color(LightGoldenRodYellow, 250, 250, 210);
		hle_sfml_color(PapayaWhip, 255, 239, 213);
		hle_sfml_color(Moccasin, 255, 228, 181);
		hle_sfml_color(PeachPuff, 255, 218, 185);
		hle_sfml_color(PaleGoldenRod, 238, 232, 170);
		hle_sfml_color(Khaki, 240, 230, 140);
		hle_sfml_color(DarkKhaki, 189, 183, 107);

		// purples
		hle_sfml_color(Lavender, 230, 230, 250);
		hle_sfml_color(Thistle, 216, 191, 216);
		hle_sfml_color(Plum, 221, 160, 221);
		hle_sfml_color(Violet, 238, 130, 238);
		hle_sfml_color(Orchid, 218, 112, 214);
		hle_sfml_color(Fuchsia, 255, 0, 255);
		hle_sfml_color(Magenta, 255, 0, 255);
		hle_sfml_color(MediumOrchid, 186, 85, 211);
		hle_sfml_color(MediumPurple, 147, 112, 219);
		hle_sfml_color(RebeccaPurple, 102, 51, 153);
		hle_sfml_color(BlueViolet, 138, 43, 226);
		hle_sfml_color(DarkViolet, 148, 0, 211);
		hle_sfml_color(DarkOrchid, 153, 50, 204);
		hle_sfml_color(DarkMagenta, 139, 0, 139);
		hle_sfml_color(Purple, 128, 0, 128);
		hle_sfml_color(Indigo, 75, 0, 130);
		hle_sfml_color(SlateBlue, 106, 90, 205);
		hle_sfml_color(DarkSlateBlue, 72, 61, 139);
		hle_sfml_color(MediumSlateBlue, 123, 104, 238);

		// green
		hle_sfml_color(GreenYellow, 173, 255, 47);
		hle_sfml_color(Chartreuse, 127, 255, 0);
		hle_sfml_color(LawnGreen, 124, 252, 0);
		hle_sfml_color(Lime, 0, 255, 0);
		hle_sfml_color(LimeGreen, 50, 205, 50);
		hle_sfml_color(PaleGreen, 152, 251, 152);
		hle_sfml_color(LightGreen, 144, 238, 144);
		hle_sfml_color(MediumSpringGreen, 0, 250, 154);
		hle_sfml_color(SpringGreen, 0, 255, 127);
		hle_sfml_color(MediumSeaGreen, 60, 179, 113);
		hle_sfml_color(SeaGreen, 46, 139, 87);
		hle_sfml_color(ForestGreen, 34, 139, 34);
		hle_sfml_color(Green, 0, 128, 0);
		hle_sfml_color(DarkGreen, 0, 100, 0);
		hle_sfml_color(YellowGreen, 154, 205, 50);
		hle_sfml_color(OliveDrab, 107, 142, 35);
		hle_sfml_color(Olive, 128, 128, 0);
		hle_sfml_color(DarkOliveGreen, 85, 107, 47);
		hle_sfml_color(MediumAquamarine, 102, 205, 170);
		hle_sfml_color(DarkSeaGreen, 143, 188, 139);
		hle_sfml_color(LightSeaGreen, 32, 178, 170);
		hle_sfml_color(DarkCyan, 0, 139, 139);
		hle_sfml_color(Teal, 0, 128, 128);

		// blues
		hle_sfml_color(Aqua, 0, 255, 255);
		hle_sfml_color(Cyan, 0, 255, 255);
		hle_sfml_color(LightCyan, 224, 255, 255);
		hle_sfml_color(PaleTurquoise, 175, 238, 238);
		hle_sfml_color(Aquamarine, 127, 255, 212);
		hle_sfml_color(Turquoise, 64, 224, 208);
		hle_sfml_color(MediumTurquoise, 72, 209, 204);
		hle_sfml_color(DarkTurquiose, 0, 206, 209);
		hle_sfml_color(CadetBlue, 95, 158, 160);
		hle_sfml_color(SteelBlue, 70, 130, 180);
		hle_sfml_color(LightSteelBlue, 176, 196, 222);
		hle_sfml_color(PowderBlue, 176, 224, 230);
		hle_sfml_color(LightBlue, 173, 216, 230);
		hle_sfml_color(SkyBlue, 135, 206, 235);
		hle_sfml_color(LightSkyBlue, 135, 206, 250);
		hle_sfml_color(DeepSkyBlue, 0, 191, 255);
		hle_sfml_color(DodgerBlue, 30, 144, 255);
		hle_sfml_color(CornflowerBlue, 100, 149, 237);
		//hle_sfml_color(MediumSlateBlue, 123, 104, 238);
		hle_sfml_color(RoyalBlue, 65, 105, 225);
		hle_sfml_color(Blue, 0, 0, 255);
		hle_sfml_color(MediumBlue, 0, 0, 205);
		hle_sfml_color(DarkBlue, 0, 0, 139);
		hle_sfml_color(Navy, 0, 0, 128);
		hle_sfml_color(MidnightBlue, 25, 25, 112);

		// browns
		hle_sfml_color(CornSilk, 255, 248, 220);
		hle_sfml_color(BlanchedAlmond, 255, 235, 205);
		hle_sfml_color(Bisque, 255, 228, 196);
		hle_sfml_color(NavajoWhite, 255, 222, 173);
		hle_sfml_color(Wheat, 245, 222, 179);
		hle_sfml_color(Burlywood, 222, 184, 135);
		hle_sfml_color(Tan, 210, 180, 140);
		hle_sfml_color(RosyBrown, 188, 143, 143);
		hle_sfml_color(SandyBrown, 244, 164, 96);
		hle_sfml_color(GoldenRod, 218, 165, 32);
		hle_sfml_color(DarkGoldenRod, 184, 134, 11);
		hle_sfml_color(Peru, 205, 133, 63);
		hle_sfml_color(Chocolate, 210, 105, 30);
		hle_sfml_color(SaddleBrown, 139, 69, 19);
		hle_sfml_color(Sienna, 160, 82, 45);
		hle_sfml_color(Brown, 165, 42, 42);
		hle_sfml_color(Maroon, 128, 0, 0);

		// whites
		hle_sfml_color(White, 255, 255, 255);
		hle_sfml_color(Snow, 255, 250, 250);
		hle_sfml_color(HoneyDew, 240, 255, 240);
		hle_sfml_color(MintCream, 245, 255, 250);
		hle_sfml_color(Azure, 240, 255, 255);
		hle_sfml_color(AliceBlue, 240, 248, 255);
		hle_sfml_color(GhostWhite, 248, 248, 255);
		hle_sfml_color(WhiteSmoke, 245, 245, 245);
		hle_sfml_color(Seashell, 255, 245, 238);
		hle_sfml_color(Biege, 245, 245, 220);
		hle_sfml_color(Oldlace, 253, 245, 230);
		hle_sfml_color(FloralWhite, 255, 250, 240);
		hle_sfml_color(Ivory, 255, 255, 240);
		hle_sfml_color(AntiqueWhite, 250, 235, 215);
		hle_sfml_color(Linen, 250, 240, 230);
		hle_sfml_color(LavenderBlush, 255, 240, 245);
		hle_sfml_color(MistyRose, 255, 228, 225);

		// greys
		hle_sfml_color(Gainsboro, 220, 220, 200);
		hle_sfml_color(LightGray, 211, 211, 211);
		hle_sfml_color(Silver, 192, 192, 192);
		hle_sfml_color(DarkGray, 169, 169, 169);
		hle_sfml_color(Gray, 128, 128, 128);
		hle_sfml_color(DimGray, 105, 105, 105);
		hle_sfml_color(LightSlateGray, 119, 136, 153);
		hle_sfml_color(SlateGray, 112, 128, 144);
		hle_sfml_color(DarkSlateGray, 47, 79, 79);
		hle_sfml_color(Black, 0, 0, 0);
	}
}
