#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Sprite {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u pos;
	size_t size;
	const unsigned char* c_data;
public:
	Sprite();
	Sprite(const unsigned char* c_data, size_t size);
	//Getters
	sf::Sprite* get_sprite();
	const unsigned char* get_data();
	//Setters
	void set_data(const unsigned char* c_data, size_t size);
	void set_pos(float x, float y);
	void set_central_pos();
	//Methods
};

class Entry {
private:
	int x = 0;
	int y = 0;
	int size = 0;
public:
	Entry();
	//Setters
};

class Engine {
private:
	sf::RenderWindow window;
	vector<Sprite*> sprites;
public:
	Engine();
	//Setters
	void set_title(string title);
	// Methods
	void remove_sprite(const unsigned char* c_data);
	void draw_sprites();
};