#include "PlayerSubject.h"
#include <iostream>

/*
 * displays error if the default constructor is initialized
 */
PlayerSubject::PlayerSubject(){
std::cout <<"ERROR: PlayerSubject should not be called as default" <<std::endl;
}

/*
 * Constructor with parameters, requires a single player, an array of countries+continents, and their lengths
 */
PlayerSubject::PlayerSubject(Player &p, Country listofcountries[], const int NUMBER_OF_COUNTRIES, Continent listofcontinents[], const int NUMBER_OF_CONTINENTS) {
    chosenplayer=&p;
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        this->listofcountries[i]=&listofcountries[i];
    }
    this->NUMBER_OF_COUNTRIES=NUMBER_OF_COUNTRIES;
    currentreinforcements=p.getCurrentReinforcements();
    battleswon=p.getBattlesWon();
    
    for (int i=0;i<NUMBER_OF_CONTINENTS;i++)
    {
        this->listofcontinents[i]=&listofcontinents[i];
    }
    this->NUMBER_OF_CONTINENTS=NUMBER_OF_CONTINENTS;
    
}

/*
 * destructor
 */
PlayerSubject::~PlayerSubject()
{
}

/*
 * returns in a string format, the continents the player owns
 */
std::string PlayerSubject::getContinentsOwned() {
    std::string output=chosenplayer->getPlayerName() + " owns the following continents : \n";
     for (int i=0;i<NUMBER_OF_CONTINENTS;i++)
     {
         int check=0;
         for (int j=0;j<listofcontinents[i]->getNumCountries();j++)
         {
        	 Country c = listofcontinents[i]->getCountries()[j];
             std::string countryincontinent = c.getName();
             for (int k=0;k<NUMBER_OF_COUNTRIES;k++)
             {
                 if (this->listofcountries[k]->getName()==countryincontinent && this->listofcountries[k]->getOwner()==chosenplayer)
                 {
                     check++;
                 }
             }
         }
         if (check==listofcontinents[i]->getNumCountries())
         {
             output+=listofcontinents[i]->getContinentName() + "\n";
         }
     }
    return output;
}

/*
 * returns in a string format, the countries the player owns
 */
std::string PlayerSubject::getCountriesOwned() {
    std::string output=chosenplayer->getPlayerName() + " owns the following countries : \n";
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        if (listofcountries[i]->getOwner()->getPlayerName()==chosenplayer->getPlayerName())
        {
            output +=listofcountries[i]->getName() + "\n";
        }
    }
    return output;
}


int PlayerSubject::getCurrentReinforcements() {
    return this->chosenplayer->getCurrentReinforcements();
}

void PlayerSubject::setCurrentReinforcements(int r){
    this->chosenplayer->setCurrentReinforcements(r);
    PlayerSubject::Notify();
}

int PlayerSubject::getTotalArmies() {
    int totalarmies=0;
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        if (listofcountries[i]->getOwner()->getPlayerName()==chosenplayer->getPlayerName())
        {
            totalarmies+=listofcountries[i]->getArmyCount();
        }
    }
    return totalarmies;
}

int PlayerSubject::getBattlesWon() {
    return this->chosenplayer->getBattlesWon();
}

void PlayerSubject::setBattlesWon(int b){
    this->chosenplayer->setBattlesWon(b);
    PlayerSubject::Notify();
}

/*
 * changes the owner of a country to the player subject
 */
void PlayerSubject::changeOwner(Country country) {
    country.setOwner(chosenplayer);
    PlayerSubject::Notify();
}
