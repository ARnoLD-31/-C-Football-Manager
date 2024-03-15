#include <iostream>
#include <conio.h>
#include "Footballer.h"
#include "Coach.h"
#include "Manager.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"

using namespace std;

int main() {
	initialize_all();
	pl1->set_name("DSDS");
	clubs["Real Madrid"].set_owner(pl1);
	cout << clubs["Real Madrid"].get_owner()->get_name();
	clubs["Real Madrid"].set_owner(nullptr);
	cout << clubs["Real Madrid"].get_owner() << endl;
	_getch();
	return 0;
}