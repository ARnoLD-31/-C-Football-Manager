#pragma once
#include <iostream>

using namespace std;

class Player;

class TV
{
private:
	string name;
	unsigned int price = 2000000;
	Player* owner = nullptr;
public:
	TV() {};
	TV(string name);

	//Setters
	void set_owner(Player* owner);

	//Getters
	string get_name() const;
	Player* get_owner() const;

	//Methods
	int buy(Player* player);
	int sell();
	void stepped(Player* player);
};

