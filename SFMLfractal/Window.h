#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

struct Window
{
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	bool isPressed;
	bool isReleased;
	Window(int x, int y, std::string title, int FPS);
	void update();
	sf::Vector2f getMousePos();

	
	
	
};
	


