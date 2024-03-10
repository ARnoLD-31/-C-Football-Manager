#include "Club.h"
#include "Footballer.h"
#include <iostream>

using namespace std;

Club::Club(string name) {
	this->name = name;
}
Player* Club::get_owner() { return this->owner; }
Footballer* Club::get_footballer() { return this->footballer; }
string Club::get_name() { return this->name; }
void Club::set_owner(Player* owner) { this->owner = owner; }
void Club::set_footballer(Footballer* footballer) { this->footballer = footballer; }