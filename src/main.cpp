#include <iostream>
#include <conio.h>
#include <vector>
#include "algorithms/TV.h" 
#include "algorithms/Footballer.h"
#include "algorithms/Coach.h"
#include "algorithms/Manager.h"
#include "algorithms/Player.h"
#include "algorithms/Club.h"
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