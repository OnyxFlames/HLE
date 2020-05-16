#pragma once

#include <map>
#include <string>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace hle
{

	template <typename Resource, typename Identifier>
	class ResourceManager
	{
	public:
		typedef Resource ResourceType;
		typedef Identifier IdentifierType;
	public:
		void load(Identifier id, const std::string& filename);

		template <typename Parameter>
		void load(Identifier id, const std::string& filename, const Parameter& param);

		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;

	private:
		std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
	};

	typedef ResourceManager<sf::Texture, const std::string> TextureManager;
	typedef ResourceManager<sf::Font, const std::string> FontManager;

}

#include "detail/ResourceManager.inl"