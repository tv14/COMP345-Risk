#ifndef RISKGAMEBUILDER_H
#define RISKGAMEBUILDER_H

#include "GameBuilder.h"

using namespace std;

/*
Game-specific implementation of the Builder class; probably an unnecessary use of inheritance 
since only one kind of game is being saved, but that might be related to the product class (Game.h)
being too specific to Risk
*/
class RiskGameBuilder : public GameBuilder {
public:
	virtual void buildMap(Map& map) {
		m_game->setMap(map);
		cout << "Map built" << endl;
	}

	virtual void buildCurrentPlayer(Player& player) {
		m_game->setCurrentPlayer(player);
		cout << "Current player built" << endl;
	}

	virtual void buildPlayers(vector<Player>& players) {
		m_game->setPlayers(players);
		cout << "Players built" << endl;
	}

	virtual void buildPhase(string& phase) {
		m_game->setPhase(phase);
		cout << "Phase built" << endl;
	}
};

#endif