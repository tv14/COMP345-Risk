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
        std::cout <<"Please choose country to move units from:\t";//user inputs a country to move from
        std::cin >> chosenmovingcountry;
        
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
    if (movingfrom->isAdjacent(c.getName()))
    {
        return true;
    }
    
    bool checked[this->NUMBER_OF_COUNTRIES];//creates a boolean which checks if the path has already visited this country
    for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//initializes all checks to false
    {
        checked[indexofcountries]=false;
    }
    
   list<Country*> queue;//creates a queue which will push and then check all unvisited adjacent allied countries
    
    for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//the path starts at the moving country and thus it is the first country visited
    {
        if (movingfrom->getName()==listofcountries[indexofcountries].getName())
        {
            checked[indexofcountries]=true;
            queue.push_back(movingfrom);
        }
    }
    
    
    Country* current;//creates a pointer which indicates the country that the path is currently at
    
    while (!queue.empty())//repeatedly checks unvisited allied adjacent countries until there are none left
    {
      
        current=queue.front();//the pointer points to the current country along the path and removes it from queue
        queue.pop_front();
       
        for (int it=0;it<current->getConnectionsByCountry().size();it++)//checks for all adjacent countries
        {
            if (current->getConnectionsByCountry()[it].isAdjacent(c.getName()))//if the desired country is found, returns true
            {
                return true;
            }
            
            for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)//checks to see if an adjacent country has already been checked, if not it pushes to into the queue country to be checked
            {
                if (current->getConnectionsByCountry()[it].getName()==listofcountries[indexofcountries].getName())
                {
                    if (!checked[indexofcountries])
                    {
                        for(int k=0;k<NUMBER_OF_COUNTRIES;k++)
                        {   //ensures the adjacent unchecked country is also an allied country
                            if ((current->getConnectionsByCountry()[it]).getName()==listofcountries[k].getName() && listofcountries[k].getOwner()->getPlayerName()==currentplayer->getPlayerName())
                            {//
                                checked[it]=true;
                               // queue.push_back(listofcountries[k]);
                            }
                        }       
                    }   
                }
                
            }
            
        }
        
    }
    return false;
}

/*
 * Moves the desired amount of armies to the desired country
 */
void Fortification::moveArmy() {
    std::cout<< "How many armies do you wish to move from " <<movingfrom->getName() << " to " << movingto->getName() << " (1-" 
            <<movingfrom->getArmyCount()-1 << "):\t";
    int armycount;
    bool check=true;
    while (check)
    {
        std::cin>>armycount; 
        if (armycount>0 && armycount<movingfrom->getArmyCount())
            {
            check=false;
            }
    }
    
    movingfrom->setArmyCount(movingfrom->getArmyCount()-armycount);
    movingto->setArmyCount(movingto->getArmyCount()+armycount);
    std::cout<<armycount <<" armies have been moved from " <<movingfrom->getName() << " to " <<movingto->getName()<<std::endl;
    
    
    
            
}