#include "Globals.h"
#include "Club.h"
#include "Footballer.h"
#include "Coach.h"
#include "Player.h"
#include <iostream>

using namespace std;


string club_names[18] = { "Manchester City", "Arsenal", "Liverpool", "Barcelona", "Real Madrid", "Atletico Madrid", "Inter", "Milan", "Juventus", "Bayern", "Borussia", "Leipzig", "Al-Nassr", "Al-Ittihad", "Al-Hilal", "Spartak Moscow", "CSKA", "Krasnodar"};
string club_leagues[6] = { "EPL", "La Liga", "Seria A", "Bundesliga", "Pro League", "RPL" };
int club_prices[18] = { 5000000, 4600000, 4400000, 4600000, 4500000, 4200000, 4600000, 4400000, 4000000, 4400000, 4200000, 3800000, 4300000, 4100000, 4200000, 3800000, 3700000, 3500000 };

string footballer_names[34] = {"Cristiano Ronaldo", "Lionel Messi", "Robert Lewandowski", "Erling Haaland", "Kevin De Bruyne", "Jude Bellingham", "Vinicius Junior", "Neymar Junior", "Sergio Ramos", "Toni Kroos", "Jesse Lingard", "Victor Osimhen", "Ruben Dias", "Philippe Coutinho", "Antonio Rudiger", "Ferland Mendy", "Georginio Wijnaldum", "Dani Carvajal", "Aleksandr Golovin", "Denis Cheryshev", "Aleksey Miranchuk", "Quincy Promes", "Eduard Spertsyan", "Konstantin Tyukavin", "Fedor Chalov", "Aleksandr Sobolev", "Aleksandr Shishkin", "Vladimir Obukhov", "Artem Lebedenko", "Gleb Zakharov", "Dominic Solanke", "Emiliano Buendia", "Ismaila Sarr", "Yakou Meite"};
short footballer_powers[34] = {10, 10, 10, 10, 8, 8, 8, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2 };
map <short, int> footballer_pps = { {2, 1000000}, {4, 2000000}, {6, 4000000}, {8, 6500000}, {10, 10000000} };

string coach_names[16] = {"Josep Guardiola", "Jurgen Klopp", "Zinedine Zidane", "Alex Ferguson", "Valeriy Lobanovskyi", "Oleg Romantsev", "Konstantin Beskov", "Dick Advocaat", "Fabio Capello", "Massimo Carrera", "Neil Warnock", "Chris Hughton", "Billy Davies", "Mick McCarthy", "Tony Mowbray", "Dave Jones"};
short coach_powers[16] = { 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };
map <short, int> coach_pps = { {1, 1000000 }, {2, 2200000}, {3, 4000000} };

map<string, Footballer> FOOTBALLERS;
map<string, Club> CLUBS;
map<string, Coach> COACHES;
Player PLAYER_1;
Player PLAYER_2;

map<string, Footballer>* footballers = &FOOTBALLERS;
map<string, Club>* clubs = &CLUBS;
map<string, Coach>* coaches = &COACHES;
Player* pl1 = &PLAYER_1;
Player* pl2 = &PLAYER_2;

void initialize_clubs() {
	for (int i = 0; i < 18; i++) {
		CLUBS[club_names[i]] = Club(club_names[i], club_prices[i], club_leagues[i / 3]);
	}
}

void initialize_footballers() {
	for (int i = 0; i < 34; i++) {
		FOOTBALLERS[footballer_names[i]] = Footballer(footballer_names[i], footballer_powers[i], footballer_pps[footballer_powers[i]]);
	}
}

void initialize_coaches() {
	for (int i = 0; i < 16; i++) {
		COACHES[coach_names[i]] = Coach(coach_names[i], coach_powers[i], coach_pps[coach_powers[i]]);
	}
}