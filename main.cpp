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
	initialize_clubs();
	initialize_footballers();
	initialize_coaches();
	initialize_managers();
	cout << (*managers)["Ronaldo"].get_name() << endl;
	(*clubs)["Real Madrid"].set_owner(pl1);
	for (Club* value : pl1->get_clubs()) {
		cout << value->get_name() << endl;
	}
	_getch();
	return 0;
}