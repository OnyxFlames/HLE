#pragma once

#include "../Common.hpp"

namespace hle
{
	namespace Category
	{
		enum Type : uint64_t
		{
			None =		0ULL,
			Scene =		1ULL << 0,
			Player =	1ULL << 1,
			Ally =		1ULL << 2,
			Enemy =		1ULL << 3,

			// Only apply to specific ID
			ByID =		1ULL << 63,
		};
	}
}