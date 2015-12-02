#include <list>

#include "Fortification.h"
#include <list>
#include <iostream>
using namespace std;

Fortification::Fortification(Player& p1, vector<Country> &listofcountries): listofcountries(listofcountries) {
    this->currentplayer=&p1;
}

void Fortification::setMovingFrom(){
    std::string chosenmovingcountry;
    bool check=true;
    
    while (check)
    {
        std::cout <<"Please choose country to move units from:\t"; //user inputs a country to move from
		getline(cin, chosenmovingcountry);
        
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks for all countries
        {
            if (listofcountries[indexofcountries].getName()==chosenmovingcountry)//program checks if user inputted a proper country
            {
                if (listofcountries[indexofcountries].getOwner()->getPlayerName()==this->currentplayer->getPlayerName())//checks to see if user inputted a country he owns
                {
                    this->movingfrom=&this->listofcountries[indexofcountries];
                    
                    if (this->Fortification::noPath())//returns a statement if there is no adjacent enemy country to attack.
                    {
                        std::cout <<"There is no adjacent allied country to move to. Please choose another country." <<std::endl;
                    }
                    else
                    {
                         std::cout<< "You are moving from: \t" << listofcountries[indexofcountries].getName() <<std::endl;
                         check=false;
                    }
                }
                else {
                 std::cout <<"You do not own that country" <<std::endl;   
                }
            }
        }
    }
}

/*
 * checks if there any allied adjacent armies beside the selected moving country
 */
bool Fortification::noPath(){
   bool nopath=true;
   for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
   {
       if (movingfrom->isAdjacent(listofcountries[indexofcountries].getName()))
       {
           if (movingfrom->getOwner()->getPlayerName()==listofcountries[indexofcountries].getOwner()->getPlayerName())
           {
               nopath=false;
               break;
           }
       }
   }
   return nopath;
}

void Fortification::setMovingTo(){
   std::string chosenmovingto;
    bool check=true;
    while (check) {
        std::cout << "Please choose an country that you own to move to:\t";
        std::cin >> chosenmovingto;
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
        {
            if (listofcountries[indexofcountries].getName()==chosenmovingto)//program checks if the user inputted a proper country else displays error message
            {
                if (listofcountries[indexofcountries].getOwner()->getPlayerName()==currentplayer->getPlayerName())//checks if the player owns that country else displays error message
                {
                    if (this->movingfrom->isAdjacent(listofcountries[indexofcountries].getName()))//checks to see if the inputted country has a path
                    {
                        this->movingto=&this->listofcountries[indexofcountries];//if there is a path, the program displays a success message and sets the country to be moved to
                        std::cout<< "You are moving to:\t" << listofcountries[indexofcountries].getName() << std::endl;
                        check=false;
                    }
                    else {
                        std::cout<<"There is no path to country:\t" <<chosenmovingto <<std::endl;
                    }
                }
                else {
                    std::cout <<"You do not own that country" <<std::endl;  
                }
            }
        }
    }
}

/*
 * Checks if there exists a path of adjacent allied countries between the moving country and another country
 */
bool Fortification::hasAPath(Country &c){
	return (movingfrom->isAdjacent(c.getName()));
}

/*
 * Moves the desired amount of armies to the desired country
 */
string Fortification::moveArmy() {
	stringstream returnoutput;
	std::cout<< "How many armies do you wish to move from " <<movingfrom->getName() << " to " << movingto->getName() << " (1-" 
            <<movingfrom->getArmyCount()-1 << "):\t";
    int armycount;
	string armycountinput;
    bool check=true;
    while (check)
    {
		getline(cin, armycountinput);
		stringstream stream(armycountinput);
 
        if (stream >> armycount && armycount>0 && armycount<movingfrom->getArmyCount())
            {
            check=false;
            }
    }
    
    movingfrom->setArmyCount(movingfrom->getArmyCount()-armycount);
    movingto->setArmyCount(movingto->getArmyCount()+armycount);
    std::cout<<armycount <<" armies have been moved from " <<movingfrom->getName() << " to " <<movingto->getName()<<std::endl;
	returnoutput << armycount << " armies have been moved from " << movingfrom->getName() << " to " << movingto->getName() << "." << std::endl;
    
	return returnoutput.str();
    
    
            
}