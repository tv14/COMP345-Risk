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

class Reinforcement {
public:
    Reinforcement(Player& p1,Country countries[], int NUMBER_OF_COUNTRIES, Continent listofcontinents[], const int NUMBER_OF_CONTINENTS);
    void calculateReinforcement();
    void chooseCountry();
    void placeReinforcement();
    void ReinforcementPhase();
    int getReinforcements();
private:
    Player *currentplayer;
    Country* listofcountries[100];
    int NUMBER_OF_COUNTRIES;
    int reinforcements;
    Continent* listofcontinents[30];
    int NUMBER_OF_CONTINENTS;
    Country * chosencountry;
     
};

inline int Reinforcement::getReinforcements(){
    return this->reinforcements;
}

#endif	/* REINFORCEMENT_H */

