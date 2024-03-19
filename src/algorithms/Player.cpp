#include <iostream>
#include <vector>
#include <cmath>
#include "algorithms/Player.h"
#include "algorithms/TV.h"
#include "algorithms/Club.h"
#include "algorithms/Footballer.h"
#include "algorithms/Coach.h"
#include "algorithms/Manager.h"
#include "Globals.h"

using namespace std;

Player::Player() {}
Player::Player(string name) {
	this->name = name;
}
Player::Player(string name, int balance) {
	this->name = name;
	this->balance = balance;
}
// Setters
void Player::set_name(string name) { this->name = name; }
void Player::set_balance(int balance) { this->balance = balance; }
void Player::set_position(short position) { this->position = position; }
void Player::set_is_disqualified(bool is_disqualified) { this->is_disqualified = is_disqualified; }
void Player::set_bonus(string type, short count) { this->bonuses[type] = count; }
void Player::set_statistic(string type, int number) { this->statistics[type] = number; }

// Getters
string Player::get_name() const { return this->name; }
int Player::get_balance() const { return this->balance; }
short Player::get_position() const { return this->position; }
bool Player::get_is_disqualified() const { return this->is_disqualified; }
int Player::get_bonus(string type) { return this->bonuses[type]; }
int Player::get_statistic(string type) { return this->statistics[type]; }
int Player::get_income() const {
	int income = 2000000;
	vector<Club*> my_clubs = Player::get_clubs();
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) {
		income += (*it)->get_income();
	}
	return Player::money_conversion(income, '+');
}
int Player::get_TV_payment() const {
	short count = Player::get_TVs().size() - 1;
	return TV_payment[count];
}
Manager* Player::get_economist() const {
	Manager* manager = nullptr;
	vector <Manager*> managers = Player::get_managers();
	for (vector <Manager*>::iterator it = managers.begin(); it != managers.end(); ++it) {
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
vector<string> Player::get_leagues() const {
	bool is_in_vector = false;
	vector<string> leagues;
	vector<Club*> my_clubs = Player::get_clubs();
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) {
		for (vector<string>::iterator it1 = leagues.begin(); it1 != leagues.end(); ++it1) {
			if (*it1 == (*it)->get_league()) {
				is_in_vector = true;
				break;
			}
		}
		if (!is_in_vector)
			leagues.push_back((*it)->get_league());
		is_in_vector = false;
	}
	return leagues;
}
vector<string> Player::get_full_leagues() const {
	vector<string> full_leagues;
	vector<string> leagues = Player::get_leagues();
	vector<Club*> my_clubs = Player::get_clubs();
	short count = 0;
	for (vector<string>::iterator it = leagues.begin(); it != leagues.end(); ++it) {
		count = 0;
		for (vector<Club*>::iterator it1 = my_clubs.begin(); it1 != my_clubs.end(); ++it1) {
			if (*it == (*it1)->get_league())
				count++;
		}
		if (count == 3) {
			full_leagues.push_back(*it);
		}
	}
	return full_leagues;
}

// Methods
Club* Player::the_most_club(string type) const {
	vector<Club*> my_clubs = Player::get_clubs();
	if (my_clubs.size() == 0) return nullptr;
	Club* club = nullptr;
	short number = my_clubs[0]->get_power();
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) {
		if ((type == "powerless" && (*it)->get_power() < number) || (type == "powerful" && (*it)->get_power() > number)) {
			number = (*it)->get_power();
		}
	}
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) {
		if ((*it)->get_power() == number && (club == nullptr || ((type == "powerless" && (*it)->get_price() < club->get_price()) || (type == "powerful" && (*it)->get_price() > club->get_price())))) {
			club = *it;
		}
	}
	return club;
}
vector <Club*> Player::suitable_clubs_for(string for_what) const {
	vector<Club*> my_clubs = Player::get_clubs();
	vector<string> full_leagues = Player::get_full_leagues();
	vector<Club*> fit_clubs;
	for (vector<Club*>::iterator it = my_clubs.begin(); it != my_clubs.end(); ++it) {
		if ((for_what == "Death" && (*it)->get_footballer() != nullptr) || (for_what == "Match" && (*it)->is_available()) || (for_what == "Footballer" && (*it)->get_footballer() == nullptr))
			fit_clubs.push_back(*it);
		else if (for_what == "Coach" || for_what == "Manager") {
			if (full_leagues.size() == 0 || my_clubs.size() / full_leagues.size() < 3) return fit_clubs;
			if (for_what == "Coach" && ((*it)->get_footballer() == nullptr || (*it)->get_coach() != nullptr)) continue;
			else if (for_what == "Manager" && ((*it)->get_footballer() == nullptr || (*it)->get_coach() == nullptr || (*it)->get_coach() != nullptr)) continue;
			for (vector<string>::iterator it1 = full_leagues.begin(); it1 != full_leagues.end(); ++it1) {
				if (*it1 == (*it)->get_league())
					fit_clubs.push_back(*it);
			}
		}
	}
	return fit_clubs;
}
int Player::money_conversion(int money, char type, bool use_economist) const {
	Manager* economist = Player::get_economist();
	if (type == '+' && economist != nullptr && use_economist) 
		money += round(money * economist_bonus_deposit[economist->get_level() - 1] / 1000) * 1000;
	else if (economist != nullptr && use_economist) 
		money -= round(money * economist_bonus_withdrawal[economist->get_level() - 1] / 1000) * 1000;
	return money;
}
bool Player::can_withdrawal(int money, bool use_economist) const {
	money = Player::money_conversion(money, '-', use_economist);
	if (this->balance >= money)
		return true;
	else
		return false;
}
int Player::withdrawal(int money, bool use_economist) {
	money = Player::money_conversion(money, '-', use_economist);
	this->balance -= money;
	return money;
}
int Player::deposit(int money, bool use_economist) {
	money = Player::money_conversion(money, '+', use_economist);
	this->balance += money;
	return money;
}
void Player::need_money(int money, bool use_economist) {
	money = Player::money_conversion(money, '-', use_economist);
	cout << "Player " << this->name << " needs " << money - this->balance;
	// TODO: Something to sell 
}
void Player::complete_the_circle() {
	cout << this->name << " completed the circle. Credited " << this->deposit(Player::get_income(), false) << endl;
}