#pragma once
#include <map>
#include <iostream>

using namespace std;

class Club;
class Player;
class Footballer;
class Coach;
class Manager;

void initialize_clubs();
void initialize_footballers();
void initialize_coaches();
void initialize_managers();

extern Player* pl1;
extern Player* pl2;
extern map <string, Club>* clubs;
extern map <string, Footballer>* footballers;
extern map <string, Coach>* coaches;
extern map <string, Manager>* managers;
extern map <short, int> sheikh_bonus;
extern map <short, short> ff_bonus;
extern map <short, float> economist_bonus_deposit;
extern map <short, float> economist_bonus_withdrawal;
