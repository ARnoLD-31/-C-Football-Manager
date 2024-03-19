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
class Engine;

void initialize_all();

const float screen_x = 1500;
const float screen_y = 1000;
extern Engine* engine;
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
