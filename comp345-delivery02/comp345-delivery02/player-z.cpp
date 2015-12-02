// player implementation

#include <string>
#include "Player.h"

Player::Player(std::string n) : name(n) {
}

std::string Player::getPlayerName() {
	return name;
}