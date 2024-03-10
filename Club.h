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
	Club(string name, int price, string league, string codename);
	//Setters
	void set_cooldown(short cooldown);
	void set_owner(Player* owner);
	void set_footballer(Footballer* footballer);
	void set_coach(Coach* coach);
	void set_manager(Manager* manager);

	//Getters
	string get_name();
	string get_league();
	string get_codename();
	int get_price();
	int get_income();
	int get_win_price(string type);
	short get_cooldown();
	Player* get_owner();
	Footballer* get_footballer();
	Coach* get_coach();
	Manager* get_manager();
};