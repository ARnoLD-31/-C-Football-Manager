#pragma once
#include <map>
#include <iostream>

using namespace std;

class Club;
class Player;
class Footballer;
class Coach;

void initialize_clubs();
void initialize_footballers();
void initialize_coaches();

extern Player* pl1;
extern Player* pl2;
extern map <string, Club>* clubs;
extern map <string, Footballer>* footballers;
extern map <string, Coach>* coaches;
