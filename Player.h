#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Footballer;
class Manager;
class TV;
class Club;
class Coach;
class Manager;

class Player {
private:
	string name;
	int balance = 10000000;
	short position = 0;
	bool is_disqualified = false;
	map <string, short> bonuses = { {"Transfer market", 0},
									{"Vaccine", 0},
									{"Resurrection", 0},
									{"Charity Match", 0}};
	map <string, int> statistics = { {"Throws", 0},
									   {"Summary of throws", 0},
									   {"Money Earned", 0},
									   {"Money Spent", 0}};
public:
	Player();
	Player(string name);
	Player(string name, int balance);
	// Setters
	void set_name(string name);
	void set_balance(int balance);
	void set_position(short position);
	void set_is_disqualified(bool is_disqualified);
	void set_bonus(string type, short count);
	void set_statistic(string type, int number);

	// Getters
	string get_name() const;
	int get_balance() const;
	int get_income() const;
	short get_position() const;
	bool get_is_disqualified() const;
	int get_bonus(string type);
	int get_statistic(string type);
	int get_TV_payment() const;
	vector <TV*> get_TVs() const;
	vector <Club*> get_clubs() const;
	vector <Footballer*> get_footballers() const;
	vector <Coach*> get_coaches() const;
	vector <Manager*> get_managers() const;
	vector <string> get_leagues() const;
	vector <string> get_full_leagues() const;
	Manager* get_economist() const;
	
	// Methods
	vector <Club*> suitable_clubs(string for_what) const;
	Club* the_most_club(string type) const;
	int money_conversion(int money, char type, bool use_economist = true) const;
	bool can_withdrawal(int money, bool use_economist = true) const;
	int withdrawal(int money, bool use_economist = true);
	int deposit(int money, bool use_economist = true);
	void need_money(int money, bool use_economist = true);
	void complete_the_circle();
};