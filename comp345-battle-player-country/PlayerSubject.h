/* 
 * File:   PlayerSubject.h
 * Author: Tam
 *
 * Created on November 2, 2015, 8:40 PM
 */

#ifndef PLAYERSUBJECT_H
#define	PLAYERSUBJECT_H
#include "Subject.h"
#include <string>
#include "Country.h"
#include "Continent.h"
#include <vector>

/*
 * also known as the Concrete Observable, this class changes the value of the player/countries and then updates the Observer class
 */
class PlayerSubject : public Subject {
public:
    PlayerSubject(Player &p, vector<Country> &listofcountries, vector<Continent> &listofcontinents);
    std::string getCountriesOwned();
    std::string getContinentsOwned();
    int getCurrentReinforcements();
    int getTotalArmies();
    int getBattlesWon();
    void changeOwner(Country country);
    void setCurrentReinforcements(int r);
    void setTotalArmies(int a);
    void setBattlesWon(int b);
    void battleWon();
    ~PlayerSubject();
    
    
private:
    Player *chosenplayer;
    vector<Country> &listofcountries;
    std::string countriesowned;
    std::string continentsowned;
    int currentreinforcements;
    int totalarmies;
    int battleswon;
    vector<Continent> &listofcontinents;
        
};



#endif	/* PLAYERSUBJECT_H */

