/* 
 * File:   GameStatSubject.h
 * Author: Tam
 *
 * Created on November 18, 2015, 10:00 PM
 */

#ifndef GAMESTATSUBJECT_H
#define	GAMESTATSUBJECT_H
#include "Subject.h"
#include "Player.h"
#include "Continent.h"
#include "Country.h"
#include <vector>
#include <string>
#include <iostream>

class GameStatSubject: public Subject {
    public:
        GameStatSubject(vector<Player> &players, vector<Country> &countries);
        ~GameStatSubject();
        void deriveNumberOfCountriesOwned();
        void deriveTotalNumberofArmiesOwned();
        void deriveTotalNumberOfCardsOwned();
        vector<Player> getListOfPlayers();
        vector<Country> getListOfCountries();
        vector<int> getListOfNumberOfCountriesOwned();
        vector<int> getListOfTotalArmiesOwned();
        vector<int> getListOfNumberOfCards();
        void setListOfPlayers(vector<Player> players);
        
    private:    
        vector<Player> &listofplayers;
        vector<Country> &listofcountries;
        vector<int> listofnumberofcountriesowned;
        vector<int> listoftotalarmiesowned;
        vector<int> listofnumberofcardsowned;
        std::string decorator;
        
        
};
inline vector<Player> GameStatSubject::getListOfPlayers(){
    return listofplayers;
}
inline vector<Country> GameStatSubject::getListOfCountries(){
    return listofcountries;
}
inline vector<int> GameStatSubject::getListOfNumberOfCountriesOwned(){
    return listofnumberofcountriesowned;
}
inline vector<int> GameStatSubject::getListOfTotalArmiesOwned(){
    return listoftotalarmiesowned;
}
inline vector<int> GameStatSubject::getListOfNumberOfCards(){
    return listofnumberofcardsowned;
}
#endif	/* GAMESTATSUBJECT_H */

