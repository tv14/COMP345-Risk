/* 
 * File:   InterfaceGameSubject.h
 * Author: Tam
 *
 * Created on November 22, 2015, 5:28 PM
 */

#ifndef INTERFACEGAMESUBJECT_H
#define	INTERFACEGAMESUBJECT_H
#include "Subject.h"
#include "Player.h"
#include "Country.h"
#include <vector>

class InterfaceGameSubject : public Subject {
    public:
        virtual vector<Player> getListOfPlayers();
        virtual vector<Country> getListOfCountries();
        virtual vector<int> getListOfNumberOfCountriesOwned();
        virtual vector<int> getListOfTotalArmiesOwned();
        virtual vector<int> getListOfNumberOfCards();
};



#endif	/* INTERFACEGAMESUBJECT_H */

