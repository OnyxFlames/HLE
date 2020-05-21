#include "Utility.hpp"

namespace hle
{
	std::string util::as_lower(const std::string& string)
	{
		std::string ret = string;

		to_lower(ret);

		return ret;
	}

	std::string util::as_upper(const std::string& string)
	{
		std::string ret = string;

		to_upper(ret);

		return ret;
	}

	void util::to_lower(std::string& string)
	{
		for (auto& c : string)
			c = std::tolower(c);
	}

	void util::to_upper(std::string& string)
	{
		for (auto& c : string)
			c = std::toupper(c);
	}

}

