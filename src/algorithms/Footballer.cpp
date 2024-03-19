#include "algorithms/Footballer.h"
#include "algorithms/Club.h"
#include "algorithms/Player.h"
#include <iostream>

using namespace std;

Footballer::Footballer() {}

Footballer::Footballer(string name, short power, int price) {
	this->name = name;
	this->power = power;
	this->price = price;
}

// Setters
void Footballer::set_flu(short flu) { this->flu = flu; }
void Footballer::set_is_resurrected(bool is_resurrected) { this->is_resurrected = is_resurrected; }
void Footballer::set_is_dead(int is_dead) { this->is_dead = is_dead; }
void Footballer::set_club(Club* club) { this->club = club; }

// Getters
string Footballer::get_name() const { return this->name; }
int Footballer::get_price() const { return this->price; }
short Footballer::get_power() const { return this->power; }
short Footballer::get_flu() const { return this->flu; }
bool Footballer::get_is_resurrected() const { return this->is_resurrected; }
bool Footballer::get_is_dead() const { return this->is_dead; }
Club* Footballer::get_club() const { return this->club; }

// Methods
void Footballer::new_turn() {
	if (this->flu != 0) this->flu--;
}
bool Footballer::is_available() const {
	if (this->flu == 0 && !this->is_dead)
		return true;
	else
		return false;
}

int Footballer::buy(Club* club) {
	Player* player = club->get_owner();
	int price_bought = player->withdrawal(this->price);
	this->club = club;
	this->club->set_footballer(this);
	cout << "Footballer " << this->name << " was bought in " << club->get_name() << " for " << price_bought << endl;
	return price_bought;
}

int Footballer::sell(bool is_transfer_market) {
	Player* player = club->get_owner();
	bool use_economist = false;
	int sold_price = this->price;
	if (!is_transfer_market)
		use_economist = true;
		sold_price /= 2;
	sold_price = player->deposit(sold_price, use_economist);
	this->club->set_footballer(nullptr);
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
	else {
		Footballer* second_footballer = new_club->get_footballer();
		second_footballer->set_club(this->club);
		this->club->set_footballer(second_footballer);
		this->club = new_club;
		this->club->set_footballer(this);
	}
}

bool Footballer::can_be_bought(Club* club) const {
	vector<Club*> my_clubs = club->get_owner()->suitable_clubs_for("Footballer");
	if (this->club != nullptr || this->is_dead || club->get_footballer() != nullptr || !club->get_owner()->can_withdrawal(this->price)) return false;
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) 
		if (*it == club) return true;
	return false;
}