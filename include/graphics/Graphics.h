#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Sprite {
private:
	string name;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u pos;
	size_t size;
	const unsigned char* c_data;
public:
	Sprite();
	Sprite(string name, const unsigned char* c_data, size_t size);
	//Getters
	sf::Sprite* get_sprite();
	sf::Texture* get_texture();
	string get_name();
	sf::Vector2f get_pos();
	const unsigned char* get_data();
	//Setters
	void set_name(string name);
	void set_texture(sf::Texture* texture);
	void set_sprite(sf::Sprite* sprite);
	void set_data(const unsigned char* c_data, size_t size);
	void set_pos(float x, float y);
	void set_central_pos();
	//Methods
	void event_handler(sf::Event event);
};

class ShowClock {
private:
	sf::Clock* clock;
	sf::Text text;
	sf::Font font;
public:
	ShowClock(sf::Clock* clock);
	//Getters
	sf::Time get_elapsed_time();
	sf::Text* get_text();
};

class Engine {
private:
	string name;
	sf::RenderWindow window;
	vector<Sprite*> sprites;
public:
	Engine();
	//Setters
	void set_title(string title);
	//Getters
	Sprite* get_pointer(string name);
	//Methods
	void remove_sprite(string name);
	void draw_sprites();
	void event_handler(sf::Event event);
};