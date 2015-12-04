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
#include <vector>
#include <sstream>
#include <string>

class Fortification {
public:
    Fortification();
    Fortification(Player &p1,vector<Country> &listofcountries);
    bool hasAPath(Country &c);
    Country* getMovingFrom();
    Country* getMovingTo();
    void setMovingFrom();
    void setMovingTo();
    bool noPath();
    string moveArmy();
private:
    Player* currentplayer;
    vector<Country> &listofcountries;
    int NUMBER_OF_COUNTRIES;
    Country* movingfrom;
    Country* movingto;
};

inline Country* Fortification::getMovingFrom(){
    return this->movingfrom;
}
inline Country* Fortification::getMovingTo(){
    return this->movingto;
}

#endif	/* FORTIFICATION_H */

