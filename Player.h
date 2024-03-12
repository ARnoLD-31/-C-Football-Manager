#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Footballer;
class Manager;
class Club;

class Player {
private:
	string name;
	int balance = 10000000;
	int income = 2000000;
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
	Player(string name, int balance, int income);
	// Setters
	void set_name(string name);
	void set_balance(int balance);
	void set_income(int income);
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
	vector <Club*> get_clubs() const;
	vector <Footballer*> get_footballers() const;
	//Manager* get_economist();

	// Methods
	bool check_withdrawal(int money);
	int withdrawal(int money, char type);
	int deposit(int money, char type);
	void complete_the_circle();
};