#pragma once
#include <iostream>
#include <map>

using namespace std;

class Player;
class Footballer;
class Coach;
class Manager;

class Club {
private:
	string name;
	string league;
	string codename;
	int price;
	int income;
	short cooldown = 0;
	Player* owner = nullptr;
	Footballer* footballer = nullptr;
	Coach* coach = nullptr;
	Manager* manager = nullptr;
	map <string, int> win_price = { {"Footballer", 0},
								{"Coach", 0},
								{"Manager", 0} };
public:
	Club();
	Club(string name, int price, string league);
	//Setters
	void set_cooldown(short cooldown);
	void set_owner(Player* owner);
	void set_footballer(Footballer* footballer);
	void set_coach(Coach* coach);
	void set_manager(Manager* manager);

	//Getters
	string get_name() const;
	string get_league() const;
	string get_codename() const;
	int get_price() const;
	int get_income() const;
	int get_win_price(string type);
	int get_current_win_price();
	short get_power() const;
	short get_cooldown() const;
	Player* get_owner() const;
	Footballer* get_footballer() const;
	Coach* get_coach() const;
	Manager* get_manager() const;

	//Methods
	void new_turn();
	bool is_available() const;
	bool can_be_bought(Player* player) const;
	int buy(Player* player);
	int sell();
};