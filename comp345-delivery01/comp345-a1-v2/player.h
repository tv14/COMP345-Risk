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
    Player (const Player&p);
    string getPlayerName();
    int getCurrentReinforcements();
    int getBattlesWon();
    bool getAI();
    void setCurrentReinforcements(int r);
    void addBattlesWon();
    void setBattlesWon(int b);
    void setAI(bool t);
    friend  bool operator==(Player &p1, Player &p2);
    friend bool operator !=(Player &p1, Player &p2);
    
    
private:
    std::string name;
    int currentreinforcements;
    int battleswon;//NOTE: should add another private variable here for cards+card type for the reinforcement phase
    bool ai;
    
};
inline string Player::getPlayerName() {
    return this->name;
}
inline int Player::getCurrentReinforcements(){
    return this->currentreinforcements;
}
inline int Player::getBattlesWon(){
    return this->battleswon;
}
inline bool Player::getAI(){
    return this->ai;
}
inline void Player::setCurrentReinforcements(int r){
    this->currentreinforcements=r;
}
inline void Player::addBattlesWon(){
    this->battleswon++;
}
inline void Player::setBattlesWon(int b){
    this->battleswon=b;
}
inline void Player::setAI(bool t){
    this->ai=t;
}
#endif	/* PLAYER_H */

