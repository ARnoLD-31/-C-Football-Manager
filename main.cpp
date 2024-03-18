#include <iostream>
#include <conio.h>
#include <vector>
#include "TV.h" 
#include "Footballer.h"
#include "Coach.h"
#include "Manager.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	initialize_all();
	RenderWindow window(VideoMode(1500, 1000), "FOOTBALL MANAGER");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Blue);
		window.display();
	}

	return 0;
}