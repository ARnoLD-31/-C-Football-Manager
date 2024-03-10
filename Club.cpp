#include "Club.h"
#include "Footballer.h"
#include <iostream>

using namespace std;

Club::Club(string name, int price, string league, string codename) {
	this->name = name;
	this->price = price;
	this->league = league;
	this->codename = codename;
	this->income = this->price / 10;
	this->win_price = { {"Footballer", this->price / 100000 / 3 * 100000},
						{"Coach", this->price / 100000 / 1.5 * 100000},
						{"Manager", this->price * 2} };
}
//Setters
void Club::set_owner(Player* owner) { this->owner = owner; }
void Club::set_footballer(Footballer* footballer) { this->footballer = footballer; }
void Club::set_cooldown(short cooldown) { this->cooldown = cooldown; }
void Club::set_coach(Coach* coach) { this->coach = coach; }
void Club::set_manager(Manager* manager) { this->manager = manager; }

// Getters
string Club::get_name() { return this->name; }
string Club::get_league() { return this->league; }
string Club::get_codename() { return this->codename; }
int Club::get_price() { return this->price; }
int Club::get_income() { return this->income; }
int Club::get_win_price(string type) { return this->win_price[type]; }
short Club::get_cooldown() { return this->cooldown; }
Player* Club::get_owner() { return this->owner; }
Footballer* Club::get_footballer() { return this->footballer; }
Coach* Club::get_coach() { return this->coach; }
Manager* Club::get_manager() { return this->manager; }