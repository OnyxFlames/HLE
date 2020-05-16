#pragma once

#include <stdexcept>

#include "../ResourceManager.hpp"

namespace hle
{
	template<typename Resource, typename Identifer>
	inline void ResourceManager<Resource, Identifer>::load(Identifer id, const std::string& filename)
	{
		std::unique_ptr<Resource> resource(new Resource());
		if (!resource->loadFromFile(filename))
			throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

		auto& inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

		assert(inserted.second);
	}

	template<typename Resource, typename Identifer>
	template<typename Parameter>
	inline void ResourceManager<Resource, Identifer>::load(Identifer id, const std::string& filename, const Parameter& param)
	{
		std::unique_ptr<Resource> resource(new Resource());
		if (!resource->loadFromFile(filename, param))
			throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

		auto& inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

		assert(inserted.second);
	}


	template<typename Resource, typename Identifer>
	inline Resource& ResourceManager<Resource, Identifer>::get(Identifer id)
	{
		auto& found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}

	template<typename Resource, typename Identifer>
	inline const Resource& ResourceManager<Resource, Identifer>::get(Identifer id) const
	{
		auto& found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}
}