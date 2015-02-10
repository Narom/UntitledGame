#include <TileMap.hpp>

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	//this block of code prepares information used for texturing. the image file is loaded and a vertex array is set up as a grid for tiling
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (!mapTileset.loadFromFile(tileset))		//load texture set, or return false if unable
		return false;

	map.setPrimitiveType(sf::Quads);
	map.resize(width * height * 4);
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------

	
	
	// this block of code actually creates the image, by texturing each tile.
	//------------------------------------------------------------------------------------------------------------------------------------------
	for (unsigned int i = 0; i < width; ++i)				//outer loop goes through columns, and inner loop through rows
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[i + j * width];		// get the current tile number

			// find its position in the tileset texture
			int tu = tileNumber % (mapTileset.getSize().x / tileSize.x);
			int tv = tileNumber / (mapTileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &map[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
		//--------------------------------------------------------------------------------------------------------------------------------------

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{ 
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &mapTileset;

	// draw the vertex array
	target.draw(map, states);
}