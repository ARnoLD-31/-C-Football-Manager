#include <iostream>
#include "Footballer.h"
#include "Player.h"
#include "Club.h"

using namespace std;

int main() {
	Footballer ronaldo("Ronaldo", 10, 10000000);
	Player first("Pa");
	Club club("DDSAD");
	cout << club.get_name() << endl;
	club.set_owner(&first);
	ronaldo.buy(&club);
	ronaldo.sell(false);
	cout << club.get_name() << endl;
	cout << ronaldo.get_name() << endl;
	return 0;
}