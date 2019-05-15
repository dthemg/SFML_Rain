#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Drop {
public:
	int dropX = 0;
	int dropY = -length;
	float velocity = 0;
	int length = 50;

	Drop() {
		// Default constructor
	}

	Drop(int dropVelocity, int startX, int startY) {
		velocity = dropVelocity;
		dropY = startY;
		dropX = startX;
	}

	void drawDrop(sf::RenderWindow &window) {	
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(dropX, dropY)),
			sf::Vertex(sf::Vector2f(dropX, dropY + length))
		};

		window.draw(line, 2, sf::Lines);
	}

	void dropFall() {
		dropY += velocity;
	}
	
};

