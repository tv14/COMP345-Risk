#ifndef PLAYER_H
#define	PLAYER_H

#include <string>

using namespace std;

class Player {
public:
	Player::Player();
	Player::Player(std::string name);
	Player::Player(const Player&p);
	Player::~Player();
	string Player::getPlayerName();
	int Player::getCurrentReinforcements();
	int Player::getBattlesWon();
	bool Player::getAI();
	string Player::getAiStrat();

	void Player::setCurrentReinforcements(int r);
	void Player::addBattlesWon();
	void Player::setBattlesWon(int b);
	void Player::setAI(bool t);
	void Player::setAiStrat(string strat);
	string Player::toString();

	friend bool operator==(Player &p1, Player &p2);
	friend bool operator !=(Player &p1, Player &p2);


private:
	string name;
	int currentReinforcements;
	int battleswon;//NOTE: should add another private variable here for cards+card type for the reinforcement phase
	bool ai;
	string aiStrat;

};

#endif	/* PLAYER_H */