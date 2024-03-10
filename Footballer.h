#pragma once
#include <iostream>

using namespace std;

class Club;

class Footballer
{
private:
	int price;
	short power;
	short flu = 0;
	bool is_resurrected = false;
	bool is_dead = false;
	string name;
	Club* club = nullptr;
public:
	Footballer(string name, short power, int price);

	// Setters
	void set_flu(int flu);
	void set_is_resurrected(bool is_resurrected);
	void set_is_dead(int is_dead);
	void set_club(Club* club);

	// Getters
	string get_name();
	int get_price();
	short get_power();
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