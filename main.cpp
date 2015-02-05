#include <SFML\Graphics.hpp>
#include <TileMap.hpp>

//main method for game, containing game loop
int main ()
{
	//window object is created with size and window title
	sf::RenderWindow window(sf::VideoMode(160, 96), "Game Project");
	
	//if (!call())
		//return -1;
	
	const int level[] =
	{
		2, 2, 2, 2, 2,
		14, 14, 14, 14, 14,
		14, 14, 14, 14, 14
	};

	TileMap stage;
	//bool call();
	if (!stage.load("genericplatformertiles.png", sf::Vector2u(32, 32), level, 5, 3))
		return 1;
	
	//loop displays until window is closed
	while(window.isOpen())
	{
		sf::Event event;	//event object exists to receive events
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(stage);	//draw will contain things to be drawn. currently not created
		window.display();
	}
	
	return 0;
}