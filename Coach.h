#pragma once
#include <iostream>

using namespace std;

class Club;

class Coach
{
private:
	int price = 0;
	short power = 0;
	short flu = 0;
	short strike = 0;
	bool is_resurrected = false;
	bool is_dead = false;
	string name;
	Club* club = nullptr;
public:
	Coach ();
	Coach (string name, short power, int price);

	// Setters

	void set_flu(short flu);
	void set_strike(short strike);
	void set_is_resurrected(bool is_resurrected);
	void set_is_dead(int is_dead);
	void set_club(Club* club);

	// Getters
	string get_name() const;
	int get_price() const;
	short get_power() const;
	short get_strike() const;
	short get_flu() const;
	bool get_is_resurrected() const;
	bool get_is_dead() const;
	Club* get_club() const;

	// Methods
	bool is_available() const;
	int buy(Club* club);
	int sell(bool is_transfer_market);
	void die();
	void resurrect();
	void transfer(Club* new_club);
	bool can_be_bought(Club* club) const;
};

