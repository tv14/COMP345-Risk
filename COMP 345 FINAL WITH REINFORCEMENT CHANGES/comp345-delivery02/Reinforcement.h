/* 
 * File:   Reinforcement.h
 * Author: Tam
 *
 * Created on November 11, 2015, 1:53 AM
 */

#ifndef REINFORCEMENT_H
#define	REINFORCEMENT_H
#include "Country.h"
#include "Continent.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

class Reinforcement {
public:
    Reinforcement(Player &p1,vector<Country>&listofcountries, vector<Continent>&listofcontinents, int &cardcounter) ;
    void calculateReinforcement();
    bool calculateCardsReinforcement();
    bool useCards();
    void chooseCountry();
    void placeReinforcement();
    string ReinforcementPhase();
    int getReinforcements();
    vector<Country> getListOfCountry();
    vector<Continent> getListOfContinent();
    int getCardCounter();
    void setCardCounter(int cardcounter);
private:
    Player *currentplayer;
    vector<Country> &listofcountries;
    int reinforcements;
    vector<Continent> &listofcontinents;
    Country * chosencountry;
	int cardcounter;
	
	stringstream returnoutput;
};

inline int Reinforcement::getReinforcements(){
    return this->reinforcements;
}
inline vector<Country> Reinforcement::getListOfCountry(){
    return this->listofcountries;
}
inline vector<Continent> Reinforcement::getListOfContinent(){
    return this->listofcontinents;
}
inline int Reinforcement::getCardCounter(){
    return this->cardcounter;
}
inline void Reinforcement::setCardCounter(int cardcounter){
    this->cardcounter=cardcounter;
}
#endif	/* REINFORCEMENT_H */

