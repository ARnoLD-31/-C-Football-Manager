#include <iostream>
#include <conio.h>
#include "TV.h" 
#include "Footballer.h"
#include "Coach.h"
#include "Manager.h"
#include "Player.h"
#include "Club.h"
#include "Globals.h"

using namespace std;

int main() {
	initialize_all();
	pl1->set_name("OLEG");
	pl1->set_balance(20000000);
	clubs["Real Madrid"].set_owner(pl1);
	managers["Karl Marx"].buy(&clubs["Real Madrid"]);
	TVs["Setanta Sports"].buy(pl1);
	_getch();
	return 0;
}