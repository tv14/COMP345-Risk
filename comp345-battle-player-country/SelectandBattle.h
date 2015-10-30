/* 
 * File:   SelectandBattle.h
 * Author: Tam
 *
 * Created on October 18, 2015, 3:06 PM
 */

#ifndef SELECTANDBATTLE_H
#define	SELECTANDBATTLE_H
#include "Player.h"
#include "Battle.h"
#include "Country.h"

class SelectandBattle {
public:
    SelectandBattle(Player p1,Country countries[],const int NUMBER_OF_COUNTRIES);
    void selectAttackingCountry();
    void selectDefendingCountry();
    bool noEnemy();
    Country* getAttackingCountry();
    Country* getDefendingCountry();
    void doBattle();
    
private:
    Player currentplayer;
    Country* listofcountries[100];
    int NUMBER_OF_COUNTRIES;
    Country* attackingcountry;
    Country* defendingcountry;
    
};
inline Country* SelectandBattle::getAttackingCountry() {
    return this->attackingcountry;
}
inline Country* SelectandBattle::getDefendingCountry() {
    return this->defendingcountry;
}

#endif	/* SELECTANDBATTLE_H */

