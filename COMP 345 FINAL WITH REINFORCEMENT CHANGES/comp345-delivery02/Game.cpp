/*
Implementation of product class. Stores properties of a Game object, allows access and mutation of
the properties, and enables persistence of properties in a text file using a *.save format
*/

#include "Game.h"
#include "Player.h"
#include <vector>

using namespace std;

Map * Game::getMap()
{
	return &map;
}

vector<Player>* Game::getPlayers()
{
	return &players;
}

Player * Game::getCurrentPlayer()
{
	return &currentPlayer;
}

string * Game::getPhase()
{
	return &phase;
}

void Game::setMap(const Map & map)
{
	this->map = map;
}

void Game::setCurrentPlayer(const Player & player)
{
	this->currentPlayer = player;
}

void Game::setPlayers(const vector<Player>& players)
{
	this->players = players;
}

void Game::setPhase(const string & phase)
{
	this->phase = phase;
}

// NOT FULLY IMPLEMENTED. SEE README.TXT FOR REASONING
void Game::load(string fname) 
{
	ifstream inputStream(fname + ".save");
	string line;
	vector<string> continents;

	while (getline(inputStream, line)) {
		if (line != "Countries")
			continents.push_back(line);
	}

	inputStream.close();
	cout << "Game detail goes here" << endl;
}

// Saves properties of a built Game object into a .save file
void Game::save(string fname) {
	ofstream output;
	output.open(fname + ".save");
	cout << "Saving game to " << fname << ".save" << endl;

	//Save continent data
	output << "Continents" << endl;
	for (Continent& c : map.getContinents()) {
		output << c.toString();
		output << endl;
	}
	cout << "Continents saved" << endl;
	// Save country data
	output << "Countries" << endl;
	for (Country& c : map.getCountries()) {
		output << c.toString();
		output << endl;
	}

	// Save player data
	output << "Players" << endl;
	for (Player& p : players) {
		output << p.toString();
		output << endl;
	}

	// Save player currently taking their turn and the phase they were in
	output << "Current Player" << endl;
	output << currentPlayer.getPlayerName() << endl;
	output << "Current Phase" << endl;
	output << phase << endl;

	output.close();
}
