#include <iostream>
#include <conio.h>
#include <vector>
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
	pl1->set_balance(200000000);
	clubs["Real Madrid"].set_owner(pl1);
	clubs["Barcelona"].set_owner(pl1);
	clubs["Atletico Madrid"].set_owner(pl1);
	footballers["Cristiano Ronaldo"].buy(&clubs["Real Madrid"]);
	footballers["Lionel Messi"].buy(&clubs["Barcelona"]);
	footballers["Kilian Mbappe"].buy(&clubs["Atletico Madrid"]);
	clubs["Spartak Moscow"].set_owner(pl1);
	clubs["CSKA"].set_owner(pl1);
	clubs["Krasnodar"].set_owner(pl1);
	clubs["Al-Nassr"].set_owner(pl1);
	vector<Club*> m_clubs = pl1->suitable_clubs("Manager");
	cout << coaches["Josep Guardiola"].can_be_bought(&clubs["Barcelona"]);
	_getch();
	return 0;
}