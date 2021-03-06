#include <SFML\Graphics.hpp>	//classes and data types from the SFML library are included through the graphics header
#include <TileMap.hpp>				//TileMap, while based off the tutorial on the SFML site, is implemented by the coder

//main method for game, containing game loop
int main ()
{
	//various objects and data used in running the game are created in this block of code. 
	//-----------------------------------------------------------------------------------------------------
	sf::RenderWindow window(sf::VideoMode(300, 200), "Game Project");	//window object is created with the desired dimensions
	window.setFramerateLimit(45);
	sf::View camera(sf::FloatRect(0, 0, 300, 200));		//a view object is used to create a movable view of the whole stage
	sf::Clock stopwatch;
	int movement = 0;
	
	const int level[] =
	{
		68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		68, 68, 64, 65, 66, 67, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		68, 68, 76, 77, 78, 79, 80, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14
	};				//an array is used to describe the location of the desired tiles in the image file. numbering starts at zero and is read left to right from the image

	TileMap stage;		//an object representing the stage is created here, but no information about the stage has been provided yet. that is given to the object
								//in the following if statement, so that any errors will cause the program to terminate
	if (!stage.load("genericplatformertiles.png", sf::Vector2u(32, 32), level, 24, 8))
		return 1;
	//---------------------------------------------------------------------------------------------------------
	
	
	//game loop is contained in this block of code
	//----------------------------------------------------------------------------------------------------------
	while(window.isOpen())		//loop runs while window is open
	{
		sf::Event event;	//event object exists to receive events. in this case, only the window closing event is handled

		while(window.pollEvent(event))		//inner while loop exists to handle events
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//these lines determine how to move the view of the image
		movement = 100 * stopwatch.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			camera.move(-movement, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			camera.move(movement, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			camera.move(0, -movement);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			camera.move(0, movement);
		
		window.clear();
		window.setView(camera);
		window.draw(stage);	//currently, only the stage is being drawn
		window.display();
	}
	//-----------------------------------------------------------------------------------------------------------
	
	return 0;
}