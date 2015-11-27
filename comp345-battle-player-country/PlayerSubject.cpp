#include "PlayerSubject.h"
#include <iostream>


/*
 * Constructor with parameters, requires a single player, an array of countries+continents, and their lengths
 */
PlayerSubject::PlayerSubject(Player &p, vector<Country> &listofcountries, vector<Continent> &listofcontinents) : listofcountries(listofcountries), listofcontinents(listofcontinents) {
    chosenplayer=&p;
    currentreinforcements=p.getCurrentReinforcements();
    battleswon=p.getBattlesWon();
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
     for (int indexofcontinents=0;indexofcontinents<listofcontinents.size();indexofcontinents++)
     {
         int check=0;
         for (int indexofcountriesinacontinent=0;indexofcountriesinacontinent<listofcontinents[indexofcontinents].getNumCountries();indexofcountriesinacontinent++)
         {
             std::string countryincontinent=listofcontinents[indexofcontinents].getCountries()[indexofcountriesinacontinent];
             for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
             {
                 if (this->listofcountries[indexofcountries].getName()==countryincontinent && this->listofcountries[indexofcountries].getOwner()==chosenplayer)
                 {
                     check++;
                 }
             }
         }
         if (check==listofcontinents[indexofcontinents].getNumCountries())
         {
             output+=listofcontinents[indexofcontinents].getContinentName() + "\n";
         }
     }
    return output;
}

/*
 * returns in a string format, the countries the player owns
 */
std::string PlayerSubject::getCountriesOwned() {
    std::string output=chosenplayer->getPlayerName() + " owns the following countries : \n";
    for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
    {
        if (listofcountries[indexofcountries].getOwner()->getPlayerName()==chosenplayer->getPlayerName())
        {
            output +=listofcountries[indexofcountries].getName() + "\n";
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
    for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
    {
        if (listofcountries[indexofcountries].getOwner()->getPlayerName()==chosenplayer->getPlayerName())
        {
            totalarmies+=listofcountries[indexofcountries].getArmyCount();
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