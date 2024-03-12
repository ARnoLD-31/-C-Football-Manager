#pragma once
#include <iostream>

using namespace std;

class Club;

class Manager
{
private:
	int price;
	string type;
	short flu = 0;
	short level = 1;
	bool is_resurrected = false;
	bool is_dead = false;
	string name;
	Club* club = nullptr;
public:
	Manager();
	Manager(string name, int price, string type);

	// Setters

	void set_flu(short flu);
	void set_level(short level);
	void set_is_resurrected(bool is_resurrected);
	void set_is_dead(int is_dead);
	void set_club(Club* club);

	// Getters
	string get_name();
	string get_type();
	int get_price();
	short get_level();
	short get_flu();
	bool get_is_resurrected();
	bool get_is_dead();
	Club* get_club();

	// Methods
	bool is_available();
	int buy(Club* club);
	int sell(bool is_transfer_market);
	void die();
	void resurrect();
	void transfer(Club* new_club);
};


