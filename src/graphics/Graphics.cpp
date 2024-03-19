#include "graphics/Graphics.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "graphics/resources/background.h"
#include "graphics/resources/background_blurred.h"
#include "graphics/resources/table.h"
#include "Globals.h"

Sprite::Sprite() {}
Sprite::Sprite(const unsigned char* c_data, size_t size) {
	this->c_data = c_data;
	this->size = size;
	this->texture.loadFromMemory(c_data, size);
	this->sprite.setTexture(this->texture);
}

void Sprite::set_data(const unsigned char* c_data, size_t size) { 
	this->c_data = c_data; 
	this->size = size;
}
void Sprite::set_pos(float x, float y) {
	this->sprite.setPosition(x, y);
}
void Sprite::set_central_pos() {
	pos = this->texture.getSize();
	float x = (screen_x - pos.x) / 2;
	float y = (screen_y - pos.y) / 2;
	this->sprite.setPosition(x, y);
}
sf::Sprite* Sprite::get_sprite() { return &this->sprite; }
const unsigned char* Sprite::get_data() { return this->c_data; }

Engine::Engine() : window(sf::VideoMode(1500, 1000), "FOOTBALL MANAGER") {
	Sprite s_background(background, background_len);
	Sprite s_background_blurred(background_blurred, background_blurred_len);
	Sprite s_table(table, table_len);
	s_table.set_central_pos();
	this->sprites.push_back(&s_background);
	this->sprites.push_back(&s_background_blurred);
	this->sprites.push_back(&s_table);
	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				this->window.close();
		}
		Engine::draw_sprites();
		this->window.display();
	}
}
void Engine::set_title(string title) {
	if (title != "") this->window.setTitle("FOOTBALL MANAGER | " + title);
	else this->window.setTitle("FOOTBALL MANAGER");
}
void Engine::draw_sprites() {
	for (vector<Sprite*>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		this->window.draw(*(*it)->get_sprite());
	}
}
void Engine::remove_sprite(const unsigned char* c_data) {
	int number = 0;
	for (vector<Sprite*>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		if ((*it)->get_data() == c_data) break;
		number++;
	}
	this->sprites.erase(this->sprites.begin() + number);
}
/*
void Engine::add_ts(const unsigned char* c_data, size_t size) {
	this->textures.push_back(sf::Texture());
	this->sprites.push_back(sf::Sprite());
	this->data.push_back(c_data);
	this->textures.back().loadFromMemory(c_data, size);
	this->sprites.back().setTexture(this->textures.back());
}
void Engine::remove_ts(const unsigned char* c_data) {
	int number = 0;
	for (vector<const unsigned char*>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
		if (*it == c_data) break;
		number++;
	}
	this->sprites.erase(this->sprites.begin() + number);
	this->textures.erase(this->textures.begin() + number);
	this->data.erase(this->data.begin() + number);
}

void Engine::draw_sprites() {
	this->window.draw(s_ba);
	for (vector<sf::Sprite>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		this->window.draw(*it);
	}
}*/