#include <iostream>
#include "Footballer.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"

using namespace std;

int main() {
	initialize_clubs();
	cout << Real_Madrid->get_name();
	return 0;
}