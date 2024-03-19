#pragma once
#include <iostream>

using namespace std;

class Club;

class Manager
{
private:
	int price = 0;
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
	string get_name() const;
	string get_type() const;
	int get_price() const;
	short get_level() const;
	short get_flu() const;
	bool get_is_resurrected() const;
	bool get_is_dead() const;
	Club* get_club() const;

	// Methods
	void new_turn();
	bool is_available() const;
	int buy(Club* club);
	int sell(bool is_transfer_market);
	void die();
	void resurrect();
	void transfer(Club* new_club);
	bool can_be_bought(Club* club) const;
};


