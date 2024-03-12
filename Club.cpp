#include "Club.h"
#include "Footballer.h"
#include "Coach.h"
#include <iostream>
#include <algorithm>

using namespace std;
Club::Club() {}
Club::Club(string name, int price, string league) {
	this->name = name;
	this->price = price;
	this->league = league;
	this->codename = this->name;
	replace(this->codename.begin(), this->codename.end(), ' ', '_');
	replace(this->codename.begin(), this->codename.end(), '-', '_');
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
string Club::get_name() const { return this->name; }
string Club::get_league() const { return this->league; }
string Club::get_codename() const { return this->codename; }
int Club::get_price() const { return this->price; }
int Club::get_income() const { return this->income; }
int Club::get_win_price(string type){ return this->win_price[type]; }
short Club::get_cooldown() const { return this->cooldown; }
Player* Club::get_owner() const { return this->owner; }
Footballer* Club::get_footballer() const { return this->footballer; }
Coach* Club::get_coach() const { return this->coach; }
Manager* Club::get_manager() const { return this->manager; }