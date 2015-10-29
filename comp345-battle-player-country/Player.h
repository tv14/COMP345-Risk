/* 
 * File:   Player.h
 * Author: Tam
 *
 * Created on October 13, 2015, 10:08 PM
*/

#ifndef PLAYER_H
#define	PLAYER_H
#include <string>


using namespace std;

class Player{
public:
    Player();
    Player(std::string name);
    string getPlayerName();
    friend  bool operator==(Player &p1, Player &p2);
    friend bool operator !=(Player &p1, Player &p2);
    
    
private:
    std::string name;
    //NOTE: should add another private variable here for cards+card type for the reinforcement phase
    
};
inline string Player::getPlayerName() {
    return this->name;
}

#endif	/* PLAYER_H */

