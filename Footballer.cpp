#include "Footballer.h"
#include "Club.h"
#include "Player.h"
#include <iostream>

using namespace std;

Footballer::Footballer(string name, short power, int price) {
	this->name = name;
	this->power = power;
	this->price = price;
}

// Setters
void Footballer::set_flu(int flu) { this->flu = flu; }
void Footballer::set_is_resurrected(bool is_resurrected) { this->is_resurrected = is_resurrected; }
void Footballer::set_is_dead(int is_dead) { this->is_dead = is_dead; }
void Footballer::set_club(Club* club) { this->club = club; }

// Getters
string Footballer::get_name() { return this->name; }
int Footballer::get_price() { return this->price; }
short Footballer::get_power() { return this->power; }
short Footballer::get_flu() { return this->flu; }
bool Footballer::get_is_resurrected() { return this->is_resurrected; }
bool Footballer::get_is_dead() { return this->is_dead; }
Club* Footballer::get_club() { return this->club; }

// Methods
bool Footballer::is_available() {
	if (this->flu == 0 && !this->is_dead)
		return true;
	else
		return false;
}

int Footballer::buy(Club* club) {
	Player* player = club->get_owner();
	int bought_price = player->withdrawal(this->price, 'B');
	this->club = club;
	cout << "Footballer " << this->name << " was bought in " << club->get_name() << " for " << bought_price << endl;
	return bought_price;
}

int Footballer::sell(bool is_transfer_market) {
	Player* player = club->get_owner();
	int sold_price = this->price;
	if (!is_transfer_market)
		sold_price /= 2;
	sold_price = player->withdrawal(sold_price, 'B');
	this->club = nullptr;
	cout << "Footballer " << this->name << " was sold for " << sold_price << endl;
	return sold_price;
}

void Footballer::die() {
	this->is_dead = true;
	this->club->set_footballer(nullptr);
	this->club = nullptr;
	this->flu = 0;
}

void Footballer::resurrect() {
	this->is_dead = false;
	this->is_resurrected = true;
}

void Footballer::transfer(Club* new_club) {
	if (new_club->get_footballer() == nullptr) {
		this->club->set_footballer(nullptr);
		this->club = new_club;
		this->club->set_footballer(this);
	}
}