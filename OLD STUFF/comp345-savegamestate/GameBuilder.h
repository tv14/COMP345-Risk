#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "Game.h"

using namespace std;

/*
Abstract class providing the structure for all concrete game builders
*/
class GameBuilder {
public:
	//Return a built Game object
	Game* GameBuilder::getGame() { return m_game; }

	//Create a generic empty Game
	void GameBuilder::createNewGame() { m_game = new Game; }

	//Virtual methods to create all game components
	virtual void buildMap(Map& map) = 0;
	virtual void buildCurrentPlayer(Player& player) = 0;
	virtual void buildPlayers(vector<Player>& players) = 0;
	virtual void buildPhase(string& phase) = 0;

protected:
	Game* m_game;
};

#endif