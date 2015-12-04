/* 
 * File:   SelectandBattle.h
 * Author: Tam
 *
 * Created on October 18, 2015, 3:06 PM
 */

#ifndef SELECTANDBATTLE_H
#define	SELECTANDBATTLE_H

#include "Battle.h"
#include "Country.h"
#include <vector>
#include <sstream>
#include <string>

class SelectandBattle {
public:
    SelectandBattle(Player &p1,vector<Country> &listofcountries);
    void selectAttackingCountry();
    void selectDefendingCountry();
    bool noEnemy();
    Country* getAttackingCountry();
    Country* getDefendingCountry();
    void doBattle();
	bool ownsAllCountries();
    string AttackPhase();
    
private:
    Player* currentplayer;
    vector<Country> *listofcountries;
    Country* attackingcountry;
    Country* defendingcountry;
    bool draw;
    
	stringstream returnoutput;
};
inline Country* SelectandBattle::getAttackingCountry() {
    return this->attackingcountry;
}
inline Country* SelectandBattle::getDefendingCountry() {
    return this->defendingcountry;
}

#endif	/* SELECTANDBATTLE_H */

