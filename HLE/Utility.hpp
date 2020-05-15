#pragma once

#include "Common.hpp"

#include <unordered_set>
#include <vector>
#include <map>

namespace hle
{
	namespace util
	{

		template<typename T>
		bool contains(const std::vector<T>& vec, const T& val);

		template <typename T, typename U>
		bool contains(const std::map<T, U>& map, const T& key);

		template <typename T, typename U>
		bool contains(const std::map<T, U>& map, const U& val);

		template <typename T>
		bool swap_remove(std::vector<T>& vec, const size_t idx);

		template <typename T>
		std::vector<T> remove_duplicates(const std::vector<T>& vec);


	}
}

#include "Utility.inl"