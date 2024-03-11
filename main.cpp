#include <iostream>
#include <conio.h>
#include "Footballer.h"
#include "Coach.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"

using namespace std;

int main() {
	initialize_clubs();
	initialize_footballers();
	initialize_coaches();
	cout << (*coaches)["Josep Guardiola"].get_name() << endl;
	_getch();
	return 0;
}