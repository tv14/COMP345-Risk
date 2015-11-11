#include "Reinforcement.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * constructor, takes a player, array of countries/continents and their lengths
 */
Reinforcement::Reinforcement(Player& p1,Country countries[], int NUMBER_OF_COUNTRIES,Continent listofcontinents[], const int NUMBER_OF_CONTINENTS) {
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        this->listofcountries[i]=&countries[i];
    }
    this->currentplayer=&p1;
    this->NUMBER_OF_COUNTRIES=NUMBER_OF_COUNTRIES;
    this->reinforcements=0;
    
    for (int i=0;i<NUMBER_OF_CONTINENTS;i++)
    {
        this->listofcontinents[i]=&listofcontinents[i];
    }
    this->NUMBER_OF_CONTINENTS=NUMBER_OF_CONTINENTS;
}


/*
 * calculates the total reinforcements the player receives and stores that number 
 */
void Reinforcement::calculateReinforcement(){
    std::cout<< "Calculating Reinforcements for Player " << currentplayer->getPlayerName() <<std::endl;
    int countryreinforcements=0, continentreinforcements=0;
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        if (listofcountries[i]->getOwner()->getPlayerName()==currentplayer->getPlayerName())
        {
            countryreinforcements++;
        }
    }
    
     for (int i=0;i<NUMBER_OF_CONTINENTS;i++)//for all continent
     {
         int check=0;
         for (int j=0;j<listofcontinents[i]->getNumCountries();j++)//looks at each continent's countries
         {
             std::string countryincontinent=listofcontinents[i]->getCountries()[j];
             for (int k=0;k<NUMBER_OF_COUNTRIES;k++)
             {
                 if (this->listofcountries[k]->getName()==countryincontinent && this->listofcountries[k]->getOwner()==currentplayer)//checks to see if the player owns the country
                 {
                     check++;
                 }
             }
         }
         if (check==listofcontinents[i]->getNumCountries())//if the player owns all the countries of the continent, he receives the army bonus
         {
             continentreinforcements+=listofcontinents[i]->getArmyBonus();
         }
     }
    int actualcountryrein=max(3,countryreinforcements/3);//player receives reinforcements equal to his countries count/3 rounded down OR 3, whichever is higher
    
    
    std::cout<< "Player " << currentplayer->getPlayerName() << " has received " << actualcountryrein << " reinforcements from his countries" <<std::endl;
    
    std::cout<< "Player " << currentplayer->getPlayerName() << " has received " << continentreinforcements << " reinforcements from his continents" <<std::endl;
    
    int totalreinforcements= (actualcountryrein +continentreinforcements);
    this->reinforcements=totalreinforcements;
    currentplayer->setCurrentReinforcements(totalreinforcements);//player observable, not needed for delivery
}

/*
 * asks the user for a country to reinforce, checks to see if input is a proper owned country
 */
void Reinforcement::chooseCountry(){
    std::string chosencountry;
    bool check=true;
    
    while (check)
    {
        std::cout <<"Please choose a country to reinforce:\t";
        std::cin >> chosencountry;
        
        for (int i=0;i<this->NUMBER_OF_COUNTRIES;i++)//checks for all countries
        {
            if (listofcountries[i]->getName()==chosencountry)//program checks if user inputted a proper country
            {
                if (listofcountries[i]->getOwner()->getPlayerName()==this->currentplayer->getPlayerName())//checks to see if user inputted a country he owns
                {
                    this->chosencountry=listofcountries[i];
                    std::cout << "You have chosen :\t" << listofcountries[i]->getName() <<std::endl;
                    check=false;
                }
                else {
                 std::cout <<"You do not own that country" <<std::endl;   
                }
            }
        }
    }
}

/*
 * asks the user for input on the number of reinforcements to send to the chosen country, checks to see if the number is greater than 1 and less than the total number of reinforcement armies
 */
void Reinforcement::placeReinforcement(){
    int r=0;
    bool check=true;
    while (check)
    {
        std::cout << "How many armies do you wish to move to " << chosencountry->getName() << " (1- " << reinforcements <<") ?:\t";
        std::cin >>r;
        if (r>=1 && r<=reinforcements)
        {
            check=false;
        }
    }
    chosencountry->setArmyCount(chosencountry->getArmyCount()+r);
    reinforcements=reinforcements-r;
    std::cout << "You have reinforced " << chosencountry->getName() << " with " <<r << " armies" << std::endl;
    
}

/*
 * Reinforcement phase, repeatedly asks to reinforce countries until there are no more reinforcements left
 */
void Reinforcement::ReinforcementPhase(){
    do
    {
        this->Reinforcement::chooseCountry();
        this->Reinforcement::placeReinforcement();
        
        if (reinforcements==0)
        {
            std::cout <<"You have placed all the reinforcement armies. \nTerminating Reinforcement Phase\n" <<std::endl;
        }
        else {
            std::cout<< "There are still " <<this->Reinforcement::getReinforcements() << " armies to placed" <<std::endl;
        }
    }
    while (reinforcements>0);
}