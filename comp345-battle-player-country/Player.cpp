#include "Player.h"
#include <algorithm>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Default Constructor, takes no arguments
 */
Player::Player() {
    this->name="";
    currentreinforcements=0;
    battleswon=0;
    ai=false;
    numberofcards=0, soldiercards=0, cannoncards=0, horsecards=0;
    battlesfought=0;
}

/*
 * Constructor which initializes the player name which is given as an argument
 */
Player::Player(std::string name) {
    this->name=name;
    currentreinforcements=0;
    battleswon=0;
    ai=false;
    numberofcards=0, soldiercards=0, cannoncards=0, horsecards=0;
    battlesfought=0;
}

/*
 * Copy Constructor
 */
Player::Player(const Player&p) {
    name=p.name;
    currentreinforcements=p.currentreinforcements;
    battleswon=p.battleswon;
    ai=p.ai;
    numberofcards=p.numberofcards;
    battlesfought=p.battlesfought;
    soldiercards=p.soldiercards;
    cannoncards=p.cannoncards;
    horsecards=p.horsecards;
}

/*
 * Draws a random card (which consists of 3 types: soldier, horse, cannon) and then adds it to the player's hand/number of cards
 */
void Player::drawACard(){
    int cardtype=0;
    cardtype=rand() %3+1;//randomly draws a card
    
    switch(cardtype)//adds the drawn card to the appropriate card type
        {
            case 1:
                soldiercards++;
                break;
            case 2:
                horsecards++;
                break;
            case 3:
                cannoncards++;
                break;
            default:
                std::cout<<"Error, card not properly drawn"<<std::endl;
                break;
        }
    this->numberofcards++;//adds to the number of cards
}

void Player::displayCards(){
     std::cout<< "Player " <<this->getPlayerName() << " owns the following cards :\t" << soldiercards << " Soldiers\t" << horsecards << " Horses\t" << cannoncards << " Cannons"<<std::endl;
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