#include "Coach.h"
#include "Club.h"
#include "Player.h"
#include <iostream>

using namespace std;

Coach::Coach() {}

Coach::Coach(string name, short power, int price) {
	this->name = name;
	this->power = power;
	this->price = price;
}

// Setters
void Coach::set_flu(short flu) { this->flu = flu; }
void Coach::set_strike(short strike) { this->strike = strike; }
void Coach::set_is_resurrected(bool is_resurrected) { this->is_resurrected = is_resurrected; }
void Coach::set_is_dead(int is_dead) { this->is_dead = is_dead; }
void Coach::set_club(Club* club) { this->club = club; }

// Getters
string Coach::get_name() const { return this->name; }
int Coach::get_price() const { return this->price; }
short Coach::get_power() const { return this->power; }
short Coach::get_flu() const { return this->flu; }
short Coach::get_strike() const { return this->strike; }
bool Coach::get_is_resurrected() const { return this->is_resurrected; }
bool Coach::get_is_dead() const { return this->is_dead; }
Club* Coach::get_club() const { return this->club; }

// Methods
bool Coach::is_available() const {
	if (this->flu == 0 && !this->is_dead)
		return true;
	else
		return false;
}

int Coach::buy(Club* club) {
	Player* player = club->get_owner();
	int price_bought = player->withdrawal(this->price);
	this->club = club;
	this->club->set_coach(this);
	cout << "Coach " << this->name << " was bought in " << club->get_name() << " for " << price_bought << endl;
	return price_bought;
}

int Coach::sell(bool is_transfer_market) {
	Player* player = club->get_owner();
	bool use_economist = false;
	int sold_price = this->price;
	if (!is_transfer_market)
		use_economist = true;
		sold_price /= 2;
	sold_price = player->deposit(sold_price, use_economist);
	this->club->set_coach(nullptr);
	this->club = nullptr;
	cout << "Coach " << this->name << " was sold for " << sold_price << endl;
	return sold_price;
}

void Coach::die() {
	this->is_dead = true;
	this->club->set_coach(nullptr);
	this->club = nullptr;
	this->flu = 0;
}

void Coach::resurrect() {
	this->is_dead = false;
	this->is_resurrected = true;
}

void Coach::transfer(Club* new_club) {
	if (new_club->get_coach() == nullptr) {
		this->club->set_coach(nullptr);
		this->club = new_club;
		this->club->set_coach(this);
	}
	else {
		Coach* second_coach = new_club->get_coach();
		second_coach->set_club(this->club);
		this->club->set_coach(second_coach);
		this->club = new_club;
		this->club->set_coach(this);
	}
}

bool Coach::can_be_bought(Club* club) const {
	vector<Club*> my_clubs = club->get_owner()->suitable_clubs("Coach");
	if (this->club != nullptr || this->is_dead || club->get_footballer() == nullptr || club->get_coach() != nullptr || !club->get_owner()->can_withdrawal(this->price)) return false;
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) 
		if (*it == club) return true;
	return false;
}