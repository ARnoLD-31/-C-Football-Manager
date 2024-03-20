#include "graphics/Graphics.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "graphics/resources/background.h"
#include "graphics/resources/background_blurred.h"
#include "graphics/resources/table.h"
#include "graphics/resources/MiSans.h"
#include "algorithms/Player.h"
#include "Globals.h"
//SPRITE
Sprite::Sprite() {}
Sprite::Sprite(string name, const unsigned char* c_data, size_t size) {
	this->name = name;
	this->c_data = c_data;
	this->size = size;
	this->texture.loadFromMemory(c_data, size);
	this->sprite.setTexture(this->texture);
}
//	Setters
void Sprite::set_name(string name) { this->name = name; }
void Sprite::set_texture(sf::Texture* texture) { this->texture = *texture; }
void Sprite::set_sprite(sf::Sprite* sprite) { this->sprite = *sprite; }
void Sprite::set_data(const unsigned char* c_data, size_t size) { 
	this->c_data = c_data; 
	this->size = size;
}
void Sprite::set_pos(float x, float y) { this->sprite.setPosition(x, y); }
void Sprite::set_central_pos() {
	pos = this->texture.getSize();
	float x = (screen_x - pos.x) / 2;
	float y = (screen_y - pos.y) / 2;
	this->sprite.setPosition(x, y);
}
//	Getters
sf::Sprite* Sprite::get_sprite() { return &this->sprite; }
sf::Texture* Sprite::get_texture() { return &this->texture; }
sf::Vector2f Sprite::get_pos() { return this->sprite.getPosition(); }
string Sprite::get_name() { return this->name; }
const unsigned char* Sprite::get_data() { return this->c_data; }
//	Methods
void Sprite::event_handler(sf::Event event) {

}

//SHOWCLOCK
ShowClock::ShowClock(sf::Clock* clock) { 
	this->clock = clock;
	this->font.loadFromMemory(c_MiSans, c_MiSans_len);
	this->text.setFont(this->font);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(1300, 0);
}
//	Getters
sf::Time ShowClock::get_elapsed_time() { return this->clock->getElapsedTime(); }
sf::Text* ShowClock::get_text() {
	unsigned int time = 0;
	int minutes = 0;
	time = ShowClock::get_elapsed_time().asSeconds();
	while (time >= 60) {
		minutes++;
		time -= 60;
	}
	if (minutes == 0) {
		this->text.setString("Elapsed time: " + to_string(time) + " secs");
	}
	else {
		this->text.setString("Elapsed time: " + to_string(minutes) + " mins " + to_string(time) + " secs");
	}
	this->text.setPosition(screen_x - this->text.getGlobalBounds().width - 12, 15);
	return &this->text;
}

//ENGINE
Engine::Engine() : window(sf::VideoMode(1500, 1000), "FOOTBALL MANAGER") {
	window.setFramerateLimit(60);
	sf::Clock CLOCK;
	ShowClock clock(&CLOCK);
	Sprite s_background("background", background, background_len);
	Sprite s_background_blurred("background_blurred", background_blurred, background_blurred_len);
	Sprite s_table("table", table, table_len);
	s_table.set_central_pos();
	this->sprites.push_back(&s_background);
	this->sprites.push_back(&s_background_blurred);
	this->sprites.push_back(&s_table);
	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {
			Engine::event_handler(event);
		}
		this->window.clear();
		Engine::draw_sprites();
		this->window.draw(*clock.get_text());
		this->window.display();
	}
}
//	Setters
void Engine::set_title(string title) {
	if (title != "") this->window.setTitle("FOOTBALL MANAGER | " + title);
	else this->window.setTitle("FOOTBALL MANAGER");
}
//	Getters
Sprite* Engine::get_pointer(string name) {
	Sprite* ptr = nullptr;
	for (vector<Sprite*>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		if ((*it)->get_name() == name) {
			ptr = *it;
			break;
		}
	}
	return ptr;
}
//	Methods
void Engine::event_handler(sf::Event event) {
	if(event.type == sf::Event::Closed) this->window.close();
	else if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode < 128)
			if (Engine::get_pointer("table") != nullptr) {
				this->name += static_cast<char>(event.text.unicode);
			}
	}
	else if (event.type == sf::Event::KeyPressed) {
		if (event.key.scancode == sf::Keyboard::Scan::Enter) {
			if (Engine::get_pointer("table") != nullptr && this->name != "") {
				if (pl1->get_name() == "") {
					pl1->set_name(this->name);
					this->name = "";
				}
				else if (pl2->get_name() == "") {
					pl2->set_name(this->name);
					this->name = "";
					Engine::remove_sprite("table");
					Engine::remove_sprite("background_blurred");
				}
			}
		}
	}
}
void Engine::draw_sprites() {
	for (vector<Sprite*>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		this->window.draw(*(*it)->get_sprite());
	}
}
void Engine::remove_sprite(string name) {
	for (vector<Sprite*>::iterator it = this->sprites.begin(); it != this->sprites.end(); ++it) {
		if ((*it)->get_name() == name) {
			this->sprites.erase(it);
			break;
		}
	}
}
