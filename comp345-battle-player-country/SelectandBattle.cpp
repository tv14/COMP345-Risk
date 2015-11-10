#include "SelectandBattle.h"

using namespace std;


SelectandBattle::SelectandBattle(Player &p1, Country countries[], const int NUMBER_OF_COUNTRIES) {
    for (int i=0;i<NUMBER_OF_COUNTRIES;i++)
    {
        this->listofcountries[i]=&countries[i];
    }
    this->currentplayer=&p1;
    this->NUMBER_OF_COUNTRIES=NUMBER_OF_COUNTRIES;
}

/*
 *Asks and verifies that the user inputs a proper attacking country
 */
void SelectandBattle::selectAttackingCountry() {
    std::string chosenatkcountry;
    bool check=true;
    
    while (check)
    {
        std::cout <<"Please choose country to attack with:\t";//user inputs a country to attack with
        std::cin >> chosenatkcountry;
        
        for (int i=0;i<this->NUMBER_OF_COUNTRIES;i++)//checks for all countries
        {
            if (listofcountries[i]->getName()==chosenatkcountry)//program checks if user inputted a proper country
            {
                if (listofcountries[i]->getOwner()->getPlayerName()==this->currentplayer->getPlayerName())//checks to see if user inputted a country he owns
                {
                    this->attackingcountry=this->listofcountries[i];
                    
                    if (this->SelectandBattle::noEnemy())//returns a statement if there is no adjacent enemy country to attack.
                    {
                        std::cout <<"There is no adjacent enemy country to attack. Please choose another country." <<std::endl;
                    }
                    else
                    {
                         std::cout<< "You are attacking with: \t" << listofcountries[i]->getName() <<std::endl;
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
 * Checks if the chosen attacking country has a valid target to attack.
 */
bool SelectandBattle::noEnemy() {
   bool noenemy=true;
   for (int i=0;i<this->NUMBER_OF_COUNTRIES;i++)
   {
       if (attackingcountry->isAdjacent(listofcountries[i]->getName()))
       {
           if (attackingcountry->getOwner()->getPlayerName()!=listofcountries[i]->getOwner()->getPlayerName())
           {
               noenemy=false;
               break;
           }
       }
   }
   return noenemy;
}

/*
 * Asks and verifies defending country with the user
 */
void SelectandBattle::selectDefendingCountry() {
    std::string chosendefcountry;
    bool check=true;
    while (check) {
        std::cout << "Please choose an adjacent enemy country to attack:\t";
        std::cin >> chosendefcountry;
        for (int i=0;i<this->NUMBER_OF_COUNTRIES;i++)
        {
            if (listofcountries[i]->getName()==chosendefcountry)//program checks if the user inputted a proper country
            {
                
                if (this->attackingcountry->isAdjacent(listofcountries[i]->getName()) && attackingcountry->getOwner()->getPlayerName()!=listofcountries[i]->getOwner()->getPlayerName())//checks to see if the inputted country is an adjacent enemy country
                {
                    this->defendingcountry=this->listofcountries[i];
                    std::cout<< "You are attacking:\t" << listofcountries[i]->getName() << std::endl;
                    check=false;
                }
            }
        }
    }
}


/*
 * Initiates battles between the 2 selected countries. The method has options for a single battle, All in, status check and quitting. After the battle(s) have ended, the countries are updated and
 * the attacker is asked to place a certain number of armies into the newly conquered country
 */
void SelectandBattle::doBattle() {
    bool check=true;
    Battle thebattle(this->attackingcountry->getArmyCount(),this->defendingcountry->getArmyCount());
    std::cout << thebattle <<std::endl;
    while(check) {
        std::cout << "Press \"b\" to do a single battle, \"a\" to Allin, \"s\" to check army status and \"q\" to quit" << std::endl; //user inputs choice
        std::string userinput;
        std::cin >> userinput;
        
        if (userinput=="b")
        {
            thebattle.setAllin(false);
            thebattle.singleBattle();
            if (thebattle.getAttackerArmy()<2 || thebattle.getDefenderArmy()<1)
            {
                check=false;
                
            }
        }
        if (userinput=="a")
        {
            thebattle.setAllin(true);
            thebattle.allIn();
            check=false;
           
        }
        if (userinput=="s")
        {
            std::cout << thebattle <<std::endl;
        }
        if (userinput=="q")
        {
            check=false;
           
        }
        
    }
    this->attackingcountry->setArmyCount(thebattle.getAttackerArmy()); //the countries are updated after the battle has ended
    this->defendingcountry->setArmyCount(thebattle.getDefenderArmy());
    
    std::cout << thebattle <<std::endl;
    
    if (this->defendingcountry->getArmyCount()==0) //if the defenders have been annihilated, the program will ask the user to move a certain number of units into the conquered country
    {
        check=true;
        while (check) 
        {
            std::cout << "The Defending army has been defeated! Please enter the number of armies you wish to move into the country ( " << thebattle.getNumberOfAttackDice() << " - " 
            << thebattle.getAttackerArmy()-1<< "): \t";
            int movingarmy;
            std::cin >> movingarmy;
            std::cout <<std::endl;
            
            if (movingarmy>=thebattle.getNumberOfAttackDice() && movingarmy<thebattle.getAttackerArmy()) //checks to see that the user moves equal to or more than his last attacking number of dice
            {                                                                                              // but leaves at least 1 army behind in his attacking country.
                this->attackingcountry->setArmyCount(this->attackingcountry->getArmyCount()-movingarmy);
                this->defendingcountry->setOwner(this->attackingcountry->getOwner());
                this->defendingcountry->setArmyCount(movingarmy);
                this->currentplayer->addBattlesWon();
                check=false;
            }
        }
  
    }
    else {
        std:;cout<< "The Attackers no longer have enough units."<<std::endl;
    }
    
}
