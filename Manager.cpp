#include "Manager.h"
#include "Club.h"
#include "Player.h"
#include <iostream>

using namespace std;

Manager::Manager() {}

Manager::Manager(string name, int price, string type) {
	this->name = name;
	this->type = type;
	this->price = price;
}

// Setters
void Manager::set_flu(short flu) { this->flu = flu; }
void Manager::set_level(short level) { this->level = level; }
void Manager::set_is_resurrected(bool is_resurrected) { this->is_resurrected = is_resurrected; }
void Manager::set_is_dead(int is_dead) { this->is_dead = is_dead; }
void Manager::set_club(Club* club) { this->club = club; }

// Getters
string Manager::get_name() const { return this->name; }
string Manager::get_type() const { return this->type; }
int Manager::get_price() const { return this->price; }
short Manager::get_flu() const { return this->flu; }
short Manager::get_level() const { return this->level; }
bool Manager::get_is_resurrected() const { return this->is_resurrected; }
bool Manager::get_is_dead() const { return this->is_dead; }
Club* Manager::get_club() const { return this->club; }

// Methods
bool Manager::is_available() const {
	if (this->flu == 0 && !this->is_dead)
		return true;
	else
		return false;
}

int Manager::buy(Club* club) {
	Player* player = club->get_owner();
	int price_bought = player->withdrawal(this->price, 'B');
	this->club = club;
	cout << "Manager " << this->name << " was bought in " << club->get_name() << " for " << price_bought << endl;
	return price_bought;
}

int Manager::sell(bool is_transfer_market) {
	Player* player = club->get_owner();
	int sold_price = this->price;
	if (!is_transfer_market)
		sold_price /= 2;
	sold_price = player->deposit(sold_price, 'B');
	this->club = nullptr;
	cout << "Manager " << this->name << " was sold for " << sold_price << endl;
	return sold_price;
}

void Manager::die() {
	this->is_dead = true;
	this->club->set_manager(nullptr);
	this->club = nullptr;
	this->flu = 0;
}

void Manager::resurrect() {
	this->is_dead = false;
	this->is_resurrected = true;
}

void Manager::transfer(Club* new_club) {
	if (new_club->get_manager() == nullptr) {
		this->club->set_manager(nullptr);
		this->club = new_club;
		this->club->set_manager(this);
	}
	else {
		Manager* second_manager = new_club->get_manager();
		second_manager->set_club(this->club);
		this->club->set_manager(second_manager);
		this->club = new_club;
		this->club->set_manager(this);
	}
}