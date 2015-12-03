#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H

#include "GameBuilder.h"
#include <string>
#include <vector>

using namespace std;

class GameDirector {
public:
	void setGameBuilder(GameBuilder* gb) { //use a concrete builder to create a specific game
		gameBuilder = gb;
	}

	Game* getGame() { //return the contructed game
		return gameBuilder->getGame();
	}

	// Creational process to create a game using the builder
	void constructGame(Map& m, Player& cp, vector<Player>& p, string& phase) {
		gameBuilder->createNewGame();
		gameBuilder->buildMap(m);
		gameBuilder->buildPlayers(p);
		gameBuilder->buildCurrentPlayer(cp);
		gameBuilder->buildPhase(phase);
	}

private:
	GameBuilder* gameBuilder;
};

#endif
