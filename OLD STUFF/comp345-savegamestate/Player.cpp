#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

/*
* Default Constructor, takes no arguments
*/
Player::Player() {
	this->name = "";
	currentReinforcements = 0;
	battleswon = 0;
	ai = false;
}

/*
* Constructor which initializes the player name which is given as an argument
*/
Player::Player(string name) {
	this->name = name;
	currentReinforcements = 0;
	battleswon = 0;
	ai = false;
}

/*
* Copy Constructor
*/
Player::Player(const Player&p) {
	name = p.name;
	currentReinforcements = p.currentReinforcements;
	battleswon = p.battleswon;
	ai = p.ai;
	aiStrat = p.aiStrat;
}

Player::~Player()
{
}

/*
* Equals method that determines two players are the same if they have the same name and not equal if they do not.
*/

bool operator==(Player &p1, Player &p2) {
	return (p1.getPlayerName() == p2.getPlayerName());
}
bool operator!=(Player &p1, Player &p2) {
	return (p1.getPlayerName() != p2.getPlayerName());
}

string Player::getPlayerName() {
	return this->name;
}
int Player::getCurrentReinforcements() {
	return this->currentReinforcements;
}
int Player::getBattlesWon() {
	return this->battleswon;
}
bool Player::getAI() {
	return this->ai;
}
string Player::getAiStrat() {
	return this->aiStrat;
}
void Player::setCurrentReinforcements(int r) {
	this->currentReinforcements = r;
}
void Player::addBattlesWon() {
	this->battleswon++;
}
void Player::setBattlesWon(int b) {
	this->battleswon = b;
}
void Player::setAI(bool t) {
	this->ai = t;
}
void Player::setAiStrat(string strat) {
	this->aiStrat = strat;
}
string Player::toString() {
	string playerString = "";

	playerString = name + ",";
	playerString += to_string(ai) + "," + aiStrat + ","; 
	playerString += to_string(battleswon) + "," + to_string(currentReinforcements);

	return playerString;
}