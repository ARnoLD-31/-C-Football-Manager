#pragma once
#include <map>
#include <iostream>

using namespace std;

class Club;
class Player;
class Footballer;

void initialize_clubs();
void initialize_footballers();

extern Player* pl1;
extern Player* pl2;
extern map <string, Club>* clubs;
extern map <string, Footballer>* footballers;
