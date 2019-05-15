#include <SFML/Graphics.hpp>
#include <iostream>
#include <Drop.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

/*
Rain simulation
Let's do this by drawing thin white lines

Step 1: Make a single raindrop fall

Make a raindrop class? I'm on it!

*/

using namespace std;

int generateRandomNumber(int lowerLim, int upperLim);


int main()
{

	/* Initialize random seed */
	srand(time(NULL));
	
	const int height = 800;
	const int width = 800;
	const int numDrops = 100;

	sf::RenderWindow window(sf::VideoMode(height, width), "Rain");
	window.setFramerateLimit(100);

	int velocity = 10;

	/* Initialize all raindrops */
	vector<Drop> dropList(numDrops);

	for (int i = 0; i < numDrops; i++) {
		int startX = generateRandomNumber(0, width);
		int startY = generateRandomNumber(0, height);
		dropList[i] = Drop(velocity, startX, startY);
	}

	sf::Clock clock;

	/* Main loop */
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		for (int i = 0; i < numDrops; i++) {
			Drop & d = dropList[i];
			d.dropFall();
			if (d.dropY > height) {
				d.dropY = -d.length;
				d.dropX = generateRandomNumber(0, width);
			}
			d.drawDrop(window);
		}

		window.display();
	}

	return 0;
}


int generateRandomNumber(int lowerLim, int upperLim)
{
	int randNum = rand() % (upperLim - lowerLim + 1) + lowerLim;
	return randNum;
}
