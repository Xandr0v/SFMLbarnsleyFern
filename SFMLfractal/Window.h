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

	struct {
		bool k1, k2, k3, k4;
		bool a, b, c, d, e, f, p;
		bool mousePressed, mouseReleased;
		bool r, q;
		bool any;
	}keyP;

	struct {
		bool ctrl;
	}keyH;
	Window(int x, int y, std::string title, int FPS);
	void update();
	
	sf::Vector2f getMousePos();

	
	
	
};
	


