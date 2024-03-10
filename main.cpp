#include <iostream>
#include "Footballer.h"
#include "Globals.h"
#include "Player.h"
#include "Club.h"

using namespace std;

int main() {
	Footballer ronaldo("Ronaldo", 10, 10000000);
	pl1->set_name("");
	Club club("DDSAD", 100, "sasa", "dsd");
	cout << club.get_name() << endl;
	club.set_owner(pl1);
	ronaldo.buy(&club);
	ronaldo.sell(false);
	cout << club.get_name() << endl;
	cout << ronaldo.get_name() << endl;
	return 0;
}