#include "Field.h"
#include "Player.h"

void cage(Player* player) {
	string this_clubs[18] = {"Barcelona", "Real Madrid", "Atletico Madrid", "Arsenal", "Liverpool", "Manchester City", "Bayern", "Borussia", "Bayer", "Juventus", "Inter", "Milan", "Al-Nassr", "Al-Ittihad", "Al-Hilal", "Spartak Moscow", "CSKA", "Krasnodar"};
	switch (player->get_position()) {
		case 0:
			cout << "Player " << player->get_name() << " stepped on start position" << endl;
			break;
		case 1:

		default:
			break;
		}
}