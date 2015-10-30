#include "Player.h"

#include <string>
#include <iostream>
using namespace std;

/*
 * Default Constructor, takes no arguments
 */
Player::Player() {
    this->name="";
}

/*
 * Constructor which initializes the player name which is given as an argument
 */
Player::Player(std::string name) {
    this->name=name;
}
/*
 * Equals method that determines two players are the same if they have the same name and not equal if they do not.
 */

bool operator==(Player &p1, Player &p2) {
    return (p1.getPlayerName()==p2.getPlayerName());
}
bool operator!=(Player &p1, Player &p2) {
    return (p1.getPlayerName()!=p2.getPlayerName());
}