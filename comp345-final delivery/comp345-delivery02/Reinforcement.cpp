#include "Reinforcement.h"


using namespace std;

/*
 * constructor, takes a player, array of countries/continents and their lengths
 */
Reinforcement::Reinforcement(Player& p1,vector<Country> &listofcountries,vector<Continent> &listofcontinents, int &cardcounter) : listofcountries(listofcountries), listofcontinents(listofcontinents){
    this->currentplayer=&p1;
    this->reinforcements=0;
    this->cardcounter=cardcounter;
}


/*
 * calculates the total reinforcements the player receives and stores that number 
 */
void Reinforcement::calculateReinforcement(){
    cout<< "Calculating Reinforcements for player \"" << currentplayer->getPlayerName() << "\"" << endl;
    int countryreinforcements=0, continentreinforcements=0;
    for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks ever
    {
        if (listofcountries[indexofcountries].getOwner()->getPlayerName()==currentplayer->getPlayerName())
        {
            countryreinforcements++;
        }
    }
    
     for (int indexofcontinents=0;indexofcontinents<listofcontinents.size();indexofcontinents++)//for all continent
     {
         int check=0;
         for (int indexofcountriesincontinent=0;indexofcountriesincontinent<listofcontinents[indexofcontinents].getNumCountries();indexofcountriesincontinent++)//looks at each continent's countries
         {
             string countryincontinent=listofcontinents[indexofcontinents].getCountries()[indexofcountriesincontinent];
             for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
             {
                 if (this->listofcountries[indexofcountries].getName()==countryincontinent && this->listofcountries[indexofcountries].getOwner()->getPlayerName()==currentplayer->getPlayerName())//checks to see if the player owns the country
                 {
                     check++;
                 }
             }
         }
         if (check==listofcontinents[indexofcontinents].getNumCountries())//if the player owns all the countries of the continent, he receives the army bonus
         {
             continentreinforcements+=listofcontinents[indexofcontinents].getArmyBonus();
         }
     }
    int actualcountryrein=max(3,countryreinforcements/3);//player receives reinforcements equal to his countries count/3 rounded down OR 3, whichever is higher
    
    
    cout<< "Player \"" << currentplayer->getPlayerName() << "\" has received " << actualcountryrein << " reinforcements from his countries." << endl;
    
    cout<< "Player \"" << currentplayer->getPlayerName() << "\" has received " << continentreinforcements << " reinforcements from his continents." << endl;
    
    int totalreinforcements= (actualcountryrein +continentreinforcements);
    this->reinforcements=totalreinforcements;
    currentplayer->setCurrentReinforcements(totalreinforcements);
}

/*
 * checks to see if there are enough valid cards to spend
 */
bool Reinforcement::useCards(){
    int enoughcards=currentplayer->getSoldierCards()+currentplayer->getHorseCards()+currentplayer->getCannonCards();
    if (enoughcards<3)//immediately returns false if there are not enough cards
    {
        return false;
    }
    if (currentplayer->getSoldierCards()>=3 || currentplayer->getHorseCards()>=3 || currentplayer->getCannonCards()>=3)//returns true if there are 3 cards of any 1 type
    {
        return true;
    }
    if (currentplayer->getSoldierCards()>=1 && currentplayer->getHorseCards()>=1 && currentplayer->getCannonCards()>=1)//returns true if there are 1 card of each type
    {
        return true;
    }
    else //returns false otherwise
    { 
        return false;
    }
    
}

void Reinforcement::calculateCardsReinforcement(){
    this->currentplayer->displayCards();
    if (Reinforcement::useCards())
    {
        bool check=true;
        string userinput;
        
        while (check)
        {
            cout<<"Do you wish to spend cards to reinforce? (+" <<this->getCardCounter()*5<<" reinforcements) y/n:\t";
			getline(cin, userinput);
            
            bool secondcheck=true;
            if (userinput=="y")
            {
                while(secondcheck)
                {
                    cout<<"Press 1, 2 or 3 to spend 3 soldier/horse/cannon cards respectively. Press 4 to spend one of each card. Press \"b\" to go back :\t";
					getline(cin, userinput);
                    
                    if (userinput=="1")
                    {
                        if (currentplayer->getSoldierCards()>=3)//checks to see if the player has enough soldier cards
                        {
                            cout << "Spending 3 soldier cards and receiving " <<this->getCardCounter()*5<< " reinforcements"<<endl;
                            this->reinforcements+=this->getCardCounter()*5;//adds the appropriate number of reinforcements
                            this->setCardCounter(this->getCardCounter()+1);//increments the card counter
                            currentplayer->setSoldierCards(currentplayer->getSoldierCards()-3);//removes 3 soldier cards from the player's hand
                            currentplayer->setNumberOfCards(currentplayer->getNumberOfCards()-3);//decreases the number of cards in the player's hand by 3
                            check=false, secondcheck=false;//ends the card calculating phase
                        }
                        else
                        {
                            cout<< "You do not have enough soldier cards to spend"<<endl;//displays error message if there are not enough cards
                        }
                    }
                    
                    if (userinput=="2")
                    {
                        if (currentplayer->getHorseCards()>=3)//checks to see if the player has enough horse cards
                        {
                            cout << "Spending 3 horse cards and receiving " <<this->getCardCounter()*5<< " reinforcements"<<endl;
                            this->reinforcements+=this->getCardCounter()*5;//adds the appropriate number of reinforcements
                            this->setCardCounter(this->getCardCounter()+1);//increments the card counter
                            currentplayer->setHorseCards(currentplayer->getHorseCards()-3);//removes 3 horse cards from the player's hand
                            currentplayer->setNumberOfCards(currentplayer->getNumberOfCards()-3);//decreases the number of cards in the player's hand by 3
                            check=false, secondcheck=false;//ends the card calculating phase
                        }
                        else
                        {
                            cout<< "You do not have enough horse cards to spend"<<endl;//displays error message if there are not enough cards
                        }
                    }
                    
                    if (userinput=="3")
                    {
                        if (currentplayer->getCannonCards()>=3)//checks to see if the player has enough cannon cards
                        {
                            cout << "Spending 3 cannon cards and receiving " <<this->getCardCounter()*5<< " reinforcements"<<endl;
                            this->reinforcements+=this->getCardCounter()*5;//adds the appropriate number of reinforcements
                            this->setCardCounter(this->getCardCounter()+1);//increments the card counter
                            currentplayer->setCannonCards(currentplayer->getCannonCards()-3);//removes 3 cannon cards from the player's hand
                            currentplayer->setNumberOfCards(currentplayer->getNumberOfCards()-3);//decreases the number of cards in the player's hand by 3
                            check=false, secondcheck=false;//ends the card calculating phase
                        }
                        else
                        {
                            cout<< "You do not have enough cannon cards to spend"<<endl;//displays error message if there are not enough cards
                        }
                    }
                    
                    if (userinput=="4")
                    {       //checks to see if the player has 1 card of each type
                        if (currentplayer->getSoldierCards()>=1 && currentplayer->getHorseCards()>=1 && currentplayer->getCannonCards()>=1)
                        {
                            cout<< "Spending 1 card of each type and receiving "<<this->getCardCounter()*5<< " reinforcements)"<<endl;
                            this->reinforcements+=this->getCardCounter()*5;//adds the appropriate number of reinforcements
                            this->setCardCounter(this->getCardCounter()+1);//increments the card counter
                            currentplayer->setCannonCards(currentplayer->getCannonCards()-1);//removes 1 card of each type from the player's hand
                            currentplayer->setHorseCards(currentplayer->getHorseCards()-1);
                            currentplayer->setSoldierCards(currentplayer->getSoldierCards()-1);
                            currentplayer->setNumberOfCards(currentplayer->getNumberOfCards()-3);//decreases the number of cards in the player's hand by 3
                            check=false, secondcheck=false;//ends the card calculating phase
                        }
                        else {
                            cout<< "You do not have 1 of each card type to spend"<<endl;//displays error message if there are not enough cards
                        }
                    }
                    
                    if (userinput=="b")//goes back 1 step
                    {
                        cout<< "Going back..."<<endl;
                        secondcheck=false;
                    }
                }
            }
            
            if (userinput=="n") 
            {
                cout<< "Player " << currentplayer->getPlayerName() << " does not wish to spend cards to reinforce."<<endl;
                check=false;
            }
        }
    }
    else {
        cout<< "There are not enough valid cards to spend on reinforcement."<<endl;
    }
   
}

/*
 * asks the user for a country to reinforce, checks to see if input is a proper owned country
 */
void Reinforcement::chooseCountry(){
    string chosencountry;
    bool check=true;
    
    while (check)
    {
        cout <<"Please choose a country to reinforce:\t";
		getline(cin, chosencountry);
        
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks for all countries
        {
            if (listofcountries[indexofcountries].getName()==chosencountry)//program checks if user inputted a proper country
            {
                if (listofcountries[indexofcountries].getOwner()->getPlayerName()==this->currentplayer->getPlayerName())//checks to see if user inputted a country he owns
                {
                    this->chosencountry=&listofcountries[indexofcountries];
                    cout << "You have chosen :\t" << listofcountries[indexofcountries].getName() <<endl;
                    check=false;
                }
                else {
                 cout <<"You do not own that country" <<endl;   
                }
            }
        }
    }
}

/*
 * asks the user for input on the number of reinforcements to send to the chosen country, checks to see if the number is greater than 1 and less than the total number of reinforcement armies
 */
void Reinforcement::placeReinforcement(){
	stringstream returnoutput;
    int r=0;
    bool check=true;
	string input;
    while (check)
    {
        cout << "How many armies do you wish to move to " << chosencountry->getName() << " (1- " << reinforcements <<") ?:\t";
       
		getline(cin, input);
		stringstream stream(input);

        if (stream >> r && r >= 1 && r <= reinforcements)
        {
            check=false;
        }
    }
    chosencountry->setArmyCount(chosencountry->getArmyCount()+r);
    reinforcements=reinforcements-r;
    cout << "You have reinforced " << chosencountry->getName() << " with " <<r << " armies" << endl;
	returnoutput << "You have reinforced " << chosencountry->getName() << " with " << r << " armies" << endl;
	stringoutput+= returnoutput.str();
    
}

/*
 * Reinforcement phase, repeatedly asks to reinforce countries until there are no more reinforcements left
 */
string Reinforcement::ReinforcementPhase(){
	
	do
    {
        this->Reinforcement::chooseCountry();
        this->Reinforcement::placeReinforcement();
        
        if (reinforcements==0)
        {
            cout <<"You have placed all the reinforcement armies. \nTerminating Reinforcement Phase\n" <<endl;
			stringoutput += "You have placed all the reinforcement armies. \nTerminating Reinforcement Phase\n";
			return stringoutput;
        }
        else {
            cout<< "There are still " <<this->Reinforcement::getReinforcements() << " armies to placed" <<endl;
        }
    }
    while (reinforcements>0);
}