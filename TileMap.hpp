#ifndef TILEMAP_HPP
#define TILEMAP_HPP
#include <SFML\Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
	sf::VertexArray map;
    sf::Texture mapTileset;
	
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif