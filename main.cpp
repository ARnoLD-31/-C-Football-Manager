#include <iostream>
#include <conio.h>
#include "Footballer.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"

using namespace std;

int main() {
	initialize_clubs();
	initialize_footballers();
	cout << (*clubs)["Real Madrid"].get_name() << endl;
	_getch();
	return 0;
}