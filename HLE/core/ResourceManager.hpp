#pragma once

#include <map>
#include <string>
#include <memory>

namespace hle
{

	template <typename Resource, typename Identifer>
	class ResourceManager
	{
	public:
		void load(Identifer id, const std::string& filename);

		template <typename Parameter>
		void load(Identifer id, const std::string& filename, const Parameter& param);

		Resource& get(Identifer id);
		const Resource& get(Identifer id) const;

	private:
		std::map<Identifer, std::unique_ptr<Resource>> mResourceMap;
	};


}

#include "detail/ResourceManager.inl"