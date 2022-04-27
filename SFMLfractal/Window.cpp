#include "Window.h"

Window::Window(int width, int height, std::string title, int FPS)
{

	

	//window creating
	window.create(sf::VideoMode(width, height), title);
	window.setFramerateLimit(FPS);

	sf::Event event;
	sf::Clock clock;
}




void Window::update()
{
	isPressed = false;
	isReleased = false;


	//displaying and clock
	window.display();
	window.clear();
	clock.restart();

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) { window.close(); }
		if (event.type == sf::Event::MouseButtonPressed) { isPressed = true; }
		if (event.type == sf::Event::MouseButtonReleased) { isReleased = true; }
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)	{ window.close(); }
		}
	}
}



sf::Vector2f Window::getMousePos()
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2f wpos = window.mapPixelToCoords(pos);
	return wpos;
}
