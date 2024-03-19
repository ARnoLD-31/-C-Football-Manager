#pragma once
#include <map>
#include <iostream>

using namespace std;

class Club;
class TV;
class Player;
class Footballer;
class Coach;
class Manager;

void initialize_all();
void initialize_clubs();
void initialize_TVs();
void initialize_footballers();
void initialize_coaches();
void initialize_managers();

extern Player* pl1;
extern Player* pl2;
extern map <string, Club> clubs;
extern map <string, TV> TVs;
extern map <string, Footballer> footballers;
extern map <string, Coach> coaches;
extern map <string, Manager> managers;
extern int sheikh_bonus[3];
extern short ff_bonus[3];
extern float economist_bonus_deposit[3];
extern float economist_bonus_withdrawal[3];
extern int TV_payment[4];
