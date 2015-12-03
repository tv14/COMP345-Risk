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
	Map* Game::getMap();
	vector<Player>* Game::getPlayers();
	Player* Game::getCurrentPlayer();
	string* Game::getPhase();

	//Initialize game components for use
	void Game::setMap(const Map& map);
	void Game::setCurrentPlayer(const Player& player);
	void Game::setPlayers(const vector<Player>& players);
	void Game::setPhase(const string& phase);
	void Game::load(string fname);
	void Game::save(string fname);

private:
	//Game components
	Map map;
	vector<Player> players;
	Player currentPlayer;
	string phase;
};

#endif