#include "Player.h"
#include <iostream>
#include "Economist.h"

using namespace std;


Player::Player(string name) {
	this->name = name;
	this->balance = 10000000;
	this->income = 2000000;
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
void Player::set_economist(Economist* economist) { this->economist = economist; }

// Getters
string Player::get_name() { return this->name; }
int Player::get_balance() { return this->balance; }
int Player::get_income() { return this->income; }
short Player::get_position() { return this->position; }
bool Player::get_is_disqualified() { return this->is_disqualified; }
int Player::get_bonus(string type) { return this->bonuses[type]; }
int Player::get_statistic(string type) { return this->statistics[type]; }
Economist* Player::get_economist() { return this->economist; }

// Metods
bool Player::check_withdrawal(int money) {
	/*if (economist != nullptr)
		;  TODO*/
	if (this->balance >= money)
		return true;
	else
		return false;
}

int Player::withdrawal(int money) {
	/*if (economist != nullptr)
		; */
	this->balance -= money;
	return money;
}

int Player::deposit(int money) {
	/*if (economist != nullptr)
		; */
	this->balance += money;
	return money;
}
