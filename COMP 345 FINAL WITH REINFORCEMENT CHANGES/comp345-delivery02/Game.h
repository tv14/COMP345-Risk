#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*
Superclass of all generic Game objects to be created
*/
class Game {
public:
	Map*  getMap();
	vector<Player>*  getPlayers();
	Player*  getCurrentPlayer();
	string*  getPhase();

	//Initialize game components for use
	void  setMap(const Map& map);
	void  setCurrentPlayer(const Player& player);
	void  setPlayers(const vector<Player>& players);
	void  setPhase(const string& phase);
	void  load(string fname);
	void  save(string fname);

private:
	//Game components
	Map map;
	vector<Player> players;
	Player currentPlayer;
	string phase;
};

#endif
