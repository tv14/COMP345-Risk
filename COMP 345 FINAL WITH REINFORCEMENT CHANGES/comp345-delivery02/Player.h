/* 
 * File:   Player.h
 * Author: Tam
 *
 * Created on October 13, 2015, 10:08 PM
*/

#ifndef PLAYER_H
#define	PLAYER_H
#include <string>
#include <vector>


using namespace std;

class Player{
public:
    Player();
    Player(std::string name);
    Player (const Player&p);
    string getPlayerName();
    void setPlayerName(string name);
    int getCurrentReinforcements();
    int getBattlesWon();
    int getBattlesFought();
    bool getAI();
    void setCurrentReinforcements(int r);
    void addBattlesWon();
    void setBattlesWon(int b);
    void setAI(bool t);
    void addBattlesFought();
    void setBattlesFought(int b);
    int getNumberOfCards();
    void drawNumberOfCards(int newnumber);
    void drawACard();
    void displayCards();
    int getSoldierCards();
    int getHorseCards();
    int getCannonCards();
    void setSoldierCards(int n);
    void setHorseCards(int n);
    void setCannonCards(int n);
    void setNumberOfCards(int n);
	string toString();
    friend  bool operator==(Player &p1, Player &p2);
    friend bool operator !=(Player &p1, Player &p2);

private:
    std::string name;
    int currentreinforcements;
    int battleswon;
    int battlesfought;
    bool ai;
    int numberofcards;
    int soldiercards, horsecards, cannoncards;
    
    
};
inline string Player::getPlayerName() {
    return this->name;
}
inline void Player::setPlayerName(string name){
    this->name=name;
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
inline int Player::getBattlesFought(){
    return this->battlesfought;
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
inline void Player::addBattlesFought(){
    this->battlesfought++;
}
inline void Player::setBattlesFought(int b){
    this->battlesfought=b;
}
inline int Player::getNumberOfCards(){
    return this->numberofcards;
}
inline void Player::drawNumberOfCards(int newnumber){
    for (int cardsdrawn=0;cardsdrawn<newnumber;cardsdrawn++)
    {
        this->Player::drawACard();
    }
}
inline int Player::getSoldierCards(){
    return this->soldiercards;
}
inline int Player::getHorseCards(){
    return this->horsecards;
}
inline int Player::getCannonCards(){
    return this->cannoncards;
}
inline void Player::setSoldierCards(int n){
    this->soldiercards=n;
}
inline void Player::setHorseCards(int n){
    this->horsecards=n;
}
inline void Player::setCannonCards(int n){
    this->cannoncards=n;
}
inline void Player::setNumberOfCards(int n){
    this->numberofcards=n;
}
#endif	/* PLAYER_H */

