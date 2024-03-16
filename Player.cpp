#include <iostream>
#include <vector>
#include <cmath>
#include "Player.h"
#include "TV.h"
#include "Club.h"
#include "Footballer.h"
#include "Coach.h"
#include "Manager.h"
#include "Globals.h"

using namespace std;

Player::Player() {}
Player::Player(string name) {
	this->name = name;
}
Player::Player(string name, int balance, int income) {
	this->name = name;
	this->balance = balance;
	this->income = income;
}
// Setters
void Player::set_name(string name) { this->name = name; }
void Player::set_balance(int balance) { this->balance = balance; }
void Player::set_income(int income) { this->income = income; }
void Player::set_position(short position) { this->position = position; }
void Player::set_is_disqualified(bool is_disqualified) { this->is_disqualified = is_disqualified; }
void Player::set_bonus(string type, short count) { this->bonuses[type] = count; }
void Player::set_statistic(string type, int number) { this->statistics[type] = number; }

// Getters
string Player::get_name() const { return this->name; }
int Player::get_balance() const { return this->balance; }
int Player::get_income() const { return this->income; }
short Player::get_position() const { return this->position; }
bool Player::get_is_disqualified() const { return this->is_disqualified; }
int Player::get_bonus(string type) { return this->bonuses[type]; }
int Player::get_statistic(string type) { return this->statistics[type]; }
int Player::get_TV_payment() const {
	short count = Player::get_TVs().size() - 1;
	return TV_payment[count];
}
Manager* Player::get_economist() const {
	Manager* manager = nullptr;
	vector <Manager*> managers = Player::get_managers();
	for (auto it = managers.begin(); it != managers.end(); ++it) {
		if ((*it)->get_type() == "Economist") {
			if (manager == nullptr || manager->get_level() < (*it)->get_level()) {
				manager = *it;
			}
		}
	}
	return manager;
}
vector<TV*> Player::get_TVs() const {
	vector<TV*> temp;
	for (auto& pair : TVs) {
		if (pair.second.get_owner() == this) {
			temp.push_back(&pair.second);
		}
	}
	return temp;
}
vector<Club*> Player::get_clubs() const {
	vector<Club*> temp;
	for (auto& pair : clubs) {
		if (pair.second.get_owner() == this) {
			temp.push_back(&pair.second);
		}
	}
	return temp;
}
vector<Footballer*> Player::get_footballers() const {
	vector<Footballer*> temp;
	for (auto& pair : footballers) {
		if (pair.second.get_club() != nullptr && pair.second.get_club()->get_owner() == this) {
			temp.push_back(&pair.second);
		}
	}
	return temp;
}
vector<Coach*> Player::get_coaches() const {
	vector<Coach*> temp;
	for (auto& pair : coaches) {
		if (pair.second.get_club() != nullptr && pair.second.get_club()->get_owner() == this) {
			temp.push_back(&pair.second);
		}
	}
	return temp;
}
vector<Manager*> Player::get_managers() const {
	vector<Manager*> temp;
	for (auto& pair : managers) {
		if (pair.second.get_club() != nullptr && pair.second.get_club()->get_owner() == this) {
			temp.push_back(&pair.second);
		}
	}
	return temp;
}

// Methods
int Player::money_conversion(int money, char type, bool use_economist) const {
	Manager* economist = Player::get_economist();
	if (type == '+') {
		if (economist != nullptr && use_economist)
			money += round(money * economist_bonus_deposit[economist->get_level() - 1] / 1000) * 1000;
	}
	else {
		if (economist != nullptr && use_economist)
			money -= round(money * economist_bonus_withdrawal[economist->get_level() - 1] / 1000) * 1000;
	}
	return money;
}

bool Player::can_withdrawal(int money, bool use_economist) const {
	money = Player::money_conversion(money, '-', use_economist);
	if (this->balance >= money)
		return true;
	else
		return false;
}

int Player::withdrawal(int money, char type, bool use_economist) {
	if (type == 'B') {
		money = Player::money_conversion(money, '-', use_economist);
		this->balance -= money;
	}
	else 
		this->income -= money;
	return money;
}

int Player::deposit(int money, char type, bool use_economist) {
	if (type == 'B') {
		money = Player::money_conversion(money, '+', use_economist);
		this->balance += money;
	}
	else
		this->income += money;
	return money;
}

void Player::need_money(int money, bool use_economist) {
	money = Player::money_conversion(money, '-', use_economist);
	cout << "Player " << this->name << " needs " << money - this->balance;
	// TODO: Something to sell 
}

void Player::complete_the_circle() {
	cout << this->name << " completed the circle. Credited " << this->deposit(this->income, 'B', false) << endl;
}