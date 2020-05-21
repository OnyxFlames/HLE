#pragma once

#include "Common.hpp"

#include <unordered_set>
#include <vector>
#include <string>
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

		std::string as_lower(const std::string& string);
		std::string as_upper(const std::string& string);

		void to_lower(std::string& string);
		void to_upper(std::string& string);

		// Checks to see if a dynamic_cast<To*>(&from) is valid

		template<typename To, typename From>
		bool castable_to(From& from);

	}
}

#include "Utility.inl"