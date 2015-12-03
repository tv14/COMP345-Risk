/* 
 * File:   Fortification.h
 * Author: Tam
 *
 * Created on November 8, 2015, 10:44 PM
 */

#ifndef FORTIFICATION_H
#define	FORTIFICATION_H
#include "Country.h"
#include "Player.h"

class Fortification {
public:
    Fortification();
    Fortification(Player &p1,Country c[], int NUMBER_OF_COUNTRIES);
    bool hasAPath(Country &c);
    Country* getMovingFrom();
    Country* getMovingTo();
    void setMovingFrom();
    void setMovingTo();
    bool noPath();
    void moveArmy();
	int getNumberOfCountries();
private:
    Player* currentplayer;
    Country* listofcountries[100];
    int NUMBER_OF_COUNTRIES=0;
    Country* movingfrom;
    Country* movingto;
};
inline int Fortification::getNumberOfCountries(){
	return NUMBER_OF_COUNTRIES;
}

inline Country* Fortification::getMovingFrom(){
    return this->movingfrom;
}
inline Country* Fortification::getMovingTo(){
    return this->movingto;
}

#endif	/* FORTIFICATION_H */

