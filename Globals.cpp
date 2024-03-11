#include "Globals.h"
#include "Club.h"
#include "Footballer.h"
#include "Player.h"
#include <iostream>

using namespace std;


string club_names[18] = { "Manchester City", "Arsenal", "Liverpool", "Barcelona", "Real Madrid", "Atletico Madrid", "Inter", "Milan", "Juventus", "Bayern", "Borussia", "Leipzig", "Al-Nassr", "Al-Ittihad", "Al-Hilal", "Spartak Moscow", "CSKA", "Krasnodar"};
string club_leagues[6] = { "EPL", "La Liga", "Seria A", "Bundesliga", "Pro League", "RPL" };
int club_prices[18] = { 5000000, 4600000, 4400000, 
4600000, 4500000, 4200000, 
4600000, 4400000, 4000000, 
4400000, 4200000, 3800000, 
4300000, 4100000, 4200000, 
3800000, 3700000, 3500000 };

string footballer_names[34] = {"Cristiano Ronaldo", "Lionel Messi", "Robert Lewandowski", "Erling Haaland", "Kevin De Bruyne", "Jude Bellingham", "Vinicius Junior", "Neymar Junior", "Sergio Ramos", "Toni Kroos", "Jesse Lingard", "Victor Osimhen", "Ruben Dias", "Philippe Coutinho", "Antonio Rudiger", "Ferland Mendy", "Georginio Wijnaldum", "Dani Carvajal", "Aleksandr Golovin", "Denis Cheryshev", "Aleksey Miranchuk", "Quincy Promes", "Eduard Spertsyan", "Konstantin Tyukavin", "Fedor Chalov", "Aleksandr Sobolev", "Aleksandr Shishkin", "Vladimir Obukhov", "Artem Lebedenko", "Gleb Zakharov", "Dominic Solanke", "Emiliano Buendia", "Ismaila Sarr", "Yakou Meite"};
int footballer_powers[34] = {10, 10, 10, 10, 8, 8, 8, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2 };
map <short, int> footballer_pps = { {2, 1000000}, {4, 2000000}, {6, 4000000}, {8, 6500000}, {10, 10000000} };


Player PLAYER_1;
Player PLAYER_2;
Club MANCHESTER_CITY("Manchester City", 5000000, "EPL");
Club ARSENAL("Arsenal", 4600000, "EPL");
Club LIVERPOOL("Liverpool", 4400000, "EPL");
Club BARCELONA("Barcelona", 4600000, "La Liga");
Club REAL_MADRID("Real Madrid", 4500000, "La Liga");
Club ATLETICO_MADRID("Atletico Madrid", 4200000, "La Liga");
Club INTER("Inter", 4600000, "Seria A");
Club MILAN("Milan", 4400000, "Seria A");
Club JUVENTUS("JUVENTUS", 4000000, "Seria A");
Club BAYER("Bayer", 4600000, "Seria A");


Player* pl1 = &PLAYER_1;
Player* pl2 = &PLAYER_2;
Club* Real_Madrid = &REAL_MADRID;


