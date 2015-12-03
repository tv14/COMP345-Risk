#include "SelectandBattle.h"

using namespace std;


SelectandBattle::SelectandBattle(Player &p1, vector<Country>&listofcountries) : listofcountries(listofcountries) {
    this->currentplayer=&p1;
    draw=false;
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
		getline(cin, chosenatkcountry);
        
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks for all countries
        {
     	   Country countryC = listofcountries[indexofcountries];
            if (countryC.getName()==chosenatkcountry)//program checks if user inputted a proper country
            {
                if (countryC.getOwner()->getPlayerName()==this->currentplayer->getPlayerName())//checks to see if user inputted a country he owns
                {
                    this->attackingcountry=&this->listofcountries[indexofcountries];
                    
                    if (this->SelectandBattle::noEnemy())//returns a statement if there is no adjacent enemy country to attack.
                    {
                        std::cout <<"There is no adjacent enemy country to attack. Please choose another country." <<std::endl;
                    }
                    else
                    {   //displays success statement for an appropriate country
                         std::cout<< "You are attacking with: \t" << countryC.getName() <<std::endl;
						 returnoutput << "You are attacking with: \t" << countryC.getName() << std::endl;
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
   for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks for all adjacent countries
   {
	   Country countryC = listofcountries[indexofcountries];
	   string countryCSTR = countryC.getName();
       if (attackingcountry->isAdjacent(countryCSTR))
       {    //looks for an appropriate defending country, if it is found, the program returns false
           if (attackingcountry->getOwner()->getPlayerName()!=countryC.getOwner()->getPlayerName())
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
        getline(cin, chosendefcountry);//prompts user for a country
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks all existing countries
        {
     	   Country countryC = listofcountries[indexofcountries];
    	   string countryCSTR = countryC.getName();


            if (countryC.getName()==chosendefcountry)//program checks if the user inputted a proper country
            {
                //checks if the inputted country is a valid defending country
                if (this->attackingcountry->isAdjacent(countryCSTR) && attackingcountry->getOwner()->getPlayerName()!=countryC.getOwner()->getPlayerName())//checks to see if the inputted country is an adjacent enemy country
                {
                    this->defendingcountry=&this->listofcountries[indexofcountries];//displays success
                    std::cout<< "You are attacking:\t" << countryC.getName() << std::endl;
					returnoutput << "You are attacking:\t" << countryC.getName() << std::endl;
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
		getline(cin, userinput);
        
        if (userinput=="b")//does a single battle
        {
            thebattle.setAllin(false);
            thebattle.singleBattle();
            if (thebattle.getAttackerArmy()<2 || thebattle.getDefenderArmy()<1)//if there are not enough units to do battle, program quits
            {
                check=false;
                
            }
        }
        if (userinput=="a")//allins
        {
            thebattle.setAllin(true);
            thebattle.allIn();
            check=false;
           
        }
        if (userinput=="s")//displays status of the attackers/defenders if asked for
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
    
    std::cout << thebattle <<std::endl;//displays status after the battle phase is finished
    
    this->currentplayer->setBattlesWon(this->currentplayer->getBattlesWon()+thebattle.getAttackerWon());//updates the two players with their respective amount of battles won/fought
    this->currentplayer->setBattlesFought(this->currentplayer->getBattlesWon()+thebattle.getAttackerWon()+thebattle.getDefenderWon());
    this->defendingcountry->getOwner()->setBattlesWon(this->defendingcountry->getOwner()->getBattlesWon()+thebattle.getDefenderWon());
    this->defendingcountry->getOwner()->setBattlesFought(this->defendingcountry->getOwner()->getBattlesWon()+thebattle.getAttackerWon()+thebattle.getDefenderWon());
    
    
    if (this->defendingcountry->getArmyCount()==0) //if the defenders have been annihilated, the program will ask the user to move a certain number of units into the conquered country
    {
		int movingarmy;

        while (true) 
        {   //prompts input for the amount of armies to move into the newly conquered country, must move at least 1 and must have at least 1 army stay behind
            std::cout << "The Defending army has been defeated! Please enter the number of armies you wish to move into the country ( " << thebattle.getNumberOfAttackDice() << " - " 
            << thebattle.getAttackerArmy()-1<< "): \t";
            string movingarmyinput;
			getline(cin, movingarmyinput); // capture the input, but it may not be an actual int
			cout << endl;
			stringstream stream(movingarmyinput);

			if (stream >> movingarmy && movingarmy >= thebattle.getNumberOfAttackDice() && movingarmy<thebattle.getAttackerArmy()) //checks to see that the user moves equal to or more than his last attacking number of dice
            {                                                                                              // but leaves at least 1 army behind in his attacking country.
                
                //moves the desired amount of armies from the attacking country to the conquered country
                this->attackingcountry->setArmyCount(this->attackingcountry->getArmyCount()-movingarmy);
                this->defendingcountry->setOwner(this->attackingcountry->getOwner());
                this->defendingcountry->setArmyCount(movingarmy);

				returnoutput << "The Defending army has been defeated! Moved " << movingarmy << " armies into the country." << endl;
                
                if (draw==false)//draws a card if this is the first time the player successfully conquered a country
                {
                 this->currentplayer->drawACard();   
                 draw==true;
                }
                
				return;
            }
			else {
				cout << "Invalid input." << endl; // either invalid number of armies, or non-numerical input.
			}
        }  
    }
    else {
        std::cout<< "The Attackers no longer have enough units."<<std::endl;
		returnoutput << "The Attackers no longer have enough units." << std::endl;
    }
    
}

string SelectandBattle::AttackPhase(){
	string userinput;

    bool continueattacking=false;
    do 
    {    
     this->selectAttackingCountry();
     this->selectDefendingCountry();
     this->doBattle();
     
    bool check=true; //ensures user input a proper response
     while (check)
     {
        std::cout<<"Do you wish to continue attacking? y/n :\t ";
		getline(cin, userinput);
        if (userinput=="y")
        {
            continueattacking=true;
            check=false;
        }
        if (userinput=="n")
        {
            continueattacking=false;
            check=false;
			cout << endl;

			returnoutput << "Ending attack phase." << endl;
        }
     }
     
    }
    while (continueattacking);

	return returnoutput.str();
}
