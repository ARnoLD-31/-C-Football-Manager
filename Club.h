#pragma once
#include <iostream>

using namespace std;

class Footballer;
class Player;

class Club {
private:
	string name;
	Player* owner = nullptr;
	Footballer* footballer = nullptr;
public:
	Club(string name);
	Player* get_owner();
	Footballer* get_footballer();
	string get_name();
	void set_owner(Player* owner);
	void set_footballer(Footballer* footballer);
};