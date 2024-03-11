#include <iostream>
#include "Player.h"
#include "Manager.h"

using namespace std;

Player::Player() {
	this->balance = 10000000;
	this->income = 2000000;
}
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

// Getters
string Player::get_name() { return this->name; }
int Player::get_balance() { return this->balance; }
int Player::get_income() { return this->income; }
short Player::get_position() { return this->position; }
bool Player::get_is_disqualified() { return this->is_disqualified; }
int Player::get_bonus(string type) { return this->bonuses[type]; }
int Player::get_statistic(string type) { return this->statistics[type]; }
//Manager* Player::get_economist() { return this->economist; }

// Methods
bool Player::check_withdrawal(int money) {
	/*if (Player::get_economist() != nullptr)
		;*/
	if (this->balance >= money)
		return true;
	else
		return false;
}

int Player::withdrawal(int money, char type) {
	/*if (Player::get_economist() != nullptr)
		;*/
	this->balance -= money;
	return money;
}

int Player::deposit(int money, char type) {
	if (type == 'B') //if (Player::get_economist() != nullptr and type == 'B')
		;
	if (type == 'B')
		this->balance += money;
	else
		this->income += money;
	return money;
}


void Player::complete_the_circle() {
	cout << this->name << " completed the circle. Credited " << this->deposit(this->income, 'B') << endl;
}