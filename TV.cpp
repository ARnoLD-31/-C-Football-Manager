#include "TV.h"
#include "Player.h"

TV::TV(string name) {
	this->name = name;
}
//Setters
void TV::set_owner(Player* owner) { this->owner = owner; }

//Getters
string TV::get_name() const { return this->name; }
Player* TV::get_owner() const { return this->owner; }

//Methods
int TV::buy(Player* player) {
	this->owner = player;
	int price_bought = this->owner->withdrawal(price);
	cout << "TV " << this->name << " was bought by " << this->owner->get_name() << " for " << price_bought << endl;
	return price_bought;
}

int TV::sell() {
	int price_sold = this->owner->deposit(price);
	cout << "TV " << this->name << " was sold by " << this->owner->get_name() << " for " << price_sold << endl;
	this->owner = nullptr;
	return price_sold;
}

void TV::stepped(Player* player) {
	cout << "Player " << player->get_name() << " stepped on " << this->name << ". ";
	if (player == this->owner) {
		cout << "He's the owner" << endl;
	}
	else {
		int payment = this->owner->get_TV_payment();
		cout << "The owner's " << this->owner->get_name() << endl;
		if (player->can_withdrawal(payment, false)) {
			this->owner->deposit(payment, false);
			cout << player->get_name() << " successfully paid " << player->withdrawal(payment, false) << " to " << this->owner->get_name() << endl;
		}
		else {
			player->need_money(payment, false);
		}
	}
}
