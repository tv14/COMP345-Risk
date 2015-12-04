#include "GameStatSubject.h"


using namespace std;


/*
 * constructor initialized with the given player/country list and immediately derives the number of countriesowned, totalarmycount, and total cards of each player
 */
GameStatSubject::GameStatSubject(vector<Player> &players, vector<Country> &countries) : listofplayers(&players), listofcountries(&countries){
    this->GameStatSubject::deriveNumberOfCountriesOwned();
    this->GameStatSubject::deriveTotalNumberofArmiesOwned();
    this->GameStatSubject::deriveTotalNumberOfCardsOwned();
}
/*
 * calculates the number of countries owned by each player
 */
void GameStatSubject::deriveNumberOfCountriesOwned(){
    this->listofnumberofcountriesowned.clear();//clear the current list of countries owned in the event of a second derivation
	for (int indexofplayers = 0; indexofplayers<listofplayers->size(); indexofplayers++)//calculates for all players
    {
        int numberofcountriesowned=0;
		for (int indexofcountries = 0; indexofcountries<listofcountries->size(); indexofcountries++)//checks each country for every player
        {
            if ((*listofcountries)[indexofcountries].getOwner()->getPlayerName()==(*listofplayers)[indexofplayers].getPlayerName())//if the player owns the country, the country count increments
            {
                numberofcountriesowned++;
            }
        }
       this->listofnumberofcountriesowned.push_back(numberofcountriesowned);//pushes the number of country that player owns into the list
        
    }
}
void GameStatSubject::deriveTotalNumberofArmiesOwned(){
    this->listoftotalarmiesowned.clear();//clears the current list of total armies in the event of a second derivation
	for (int indexofplayers = 0; indexofplayers<listofplayers->size(); indexofplayers++)//calculates for all players
    {
        int numberofarmiesowned=0;
		for (int indexofcountries = 0; indexofcountries<listofcountries->size(); indexofcountries++)//checks each country for every player
        {
			if ((*listofcountries)[indexofcountries].getOwner()->getPlayerName() == (*listofplayers)[indexofplayers].getPlayerName())//if the player owns the country, the army count is added to the total army count
            {
				numberofarmiesowned += (*listofcountries)[indexofcountries].getArmyCount();
            }
        }
       this->listoftotalarmiesowned.push_back(numberofarmiesowned);//pushes the total army count of the player into the list
       
    }
}

void GameStatSubject::deriveTotalNumberOfCardsOwned(){
    this->listofnumberofcardsowned.clear();//clears the current list of cards owned in the even of a second derivation
    for (int indexofplayers=0;indexofplayers<listofplayers->size();indexofplayers++)//calculates for each player
    {
        this->listofnumberofcardsowned.push_back((*listofplayers)[indexofplayers].getNumberOfCards());//pushes the number of cards the player has into the list
    }
}
