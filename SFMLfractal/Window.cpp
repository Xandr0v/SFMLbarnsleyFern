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
	keyP = {};
	keyH.ctrl = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);

	//displaying and clock
	window.display();
	window.clear();
	clock.restart();

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: window.close(); break;
		case sf::Event::MouseButtonPressed: keyP.mousePressed = true; break;
		case sf::Event::MouseButtonReleased: keyP.mouseReleased = true; break;
		case sf::Event::KeyPressed:
			keyP.any = true;
			switch (event.key.code)
			{
			case sf::Keyboard::Escape: window.close(); break;
			case sf::Keyboard::Num1: keyP.k1 = true; break;
			case sf::Keyboard::Num2: keyP.k2 = true; break;
			case sf::Keyboard::Num3: keyP.k3 = true; break;
			case sf::Keyboard::Num4: keyP.k4 = true; break;
			case sf::Keyboard::A: keyP.a = true; break;
			case sf::Keyboard::B: keyP.b = true; break;
			case sf::Keyboard::C: keyP.c = true; break;
			case sf::Keyboard::D: keyP.d = true; break;
			case sf::Keyboard::E: keyP.e = true; break;
			case sf::Keyboard::F: keyP.f = true; break;
			case sf::Keyboard::P: keyP.p = true; break;
			case sf::Keyboard::R: keyP.r = true; break;
			case sf::Keyboard::Q: keyP.q = true; break;
			}
			break;
		}
	}
}





sf::Vector2f Window::getMousePos()
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2f wpos = window.mapPixelToCoords(pos);
	return wpos;
}
