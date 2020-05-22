#include "Utility.hpp"
#pragma once


namespace hle
{
	namespace util
	{
		template<typename T>
		inline bool contains(const std::vector<T>& vec, const T& val)
		{
			for (auto& it : vec)
				if (it == val)
					return true;

			return false;
		}

		template<typename T, typename U>
		inline bool contains(const std::map<T, U>& map, const T& key)
		{
			return map.find(key) != map.end();
		}

		template<typename T, typename U>
		inline bool contains(const std::map<T, U>& map, const U& val)
		{
			for (auto& it : map)
				if (it == val)
					return true;
			return false;
		}

		template<typename T>
		inline bool swap_remove(std::vector<T>& vec, const size_t idx)
		{
			if (idx < vec.size())
			{
				std::swap(vec[idx], vec[vec.size() - 1]);
				vec.pop_back();
				return true;
			}
			else
				return false;
		}

		template<typename T>
		inline std::vector<T> remove_duplicates(const std::vector<T>& vec)
		{
			std::vector<T> ret;

			for (auto& it : vec)
				if (!contains<T>(ret, it))
					ret.push_back(it);

			return ret;
		}
		template<typename To, typename From>
		constexpr bool castable_to(From& from)
		{
			return (dynamic_cast<To*>(&from) != nullptr);
		}

	}
}