#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics>

class Tile : public sf::Drawable, public sf::Transformable
{
	//not yet implemented, but a tile object will need to be able to reference a tile within a tile map
	//tile will also contain metadata for that tile, mainly for the purposes of things like ground collision detection.
}
#endif