#pragma once

#include "../Common.hpp"

namespace hle
{
	namespace Category
	{
		enum Type : uint64_t
		{
			None =		0,
			Scene =		1 << 0,
			Player =	1 << 1,
			Ally =		1 << 2,
			Enemy =		1 << 3,
		};
	}
}