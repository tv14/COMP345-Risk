#include "WorldControlledDecorator.h"
#include "Observer.h"
#include "GameStatDecorator.h"

using namespace std;

/*
 * the world owned % decorator constructor which also takes a vector of players/countries to obtain the percentage
 */
WorldControlledDecorator::WorldControlledDecorator(Observer* decoratedgamestatsubject, vector<Player>& listofplayers, vector<Country>& listofcountries, GameStatSubject* s)
: GameStatDecorator(decoratedgamestatsubject,s), listofplayers(listofplayers), listofcountries(listofcountries)
{
  
}

/*
 * world owned % updater which displays the original game statisitics data in addition to the percentage of the world owned by each player
 */
void WorldControlledDecorator::Update(){
    GameStatDecorator::Update();//displays original game statistics data
    std::string worldcontrolledoutput="World%Owned\t\t";//display what is about to be shown
    
    for (int indexofplayers=0;indexofplayers<listofplayers.size();indexofplayers++)//for each player
    {
        //counts how many countries a player owns
        int numofcountriesowned=0;
        for (int indexofcountries=0;indexofcountries<listofcountries.size();indexofcountries++)
        {
            //if the player owns the country, increments the count by 1
            if (listofcountries[indexofcountries].getOwner()->getPlayerName()==listofplayers[indexofplayers].getPlayerName())
            {
                numofcountriesowned++;
            }
        }
        //obtains the % world owned by dividing the number of country a player owns by the total number of countries in the world
        double worldpercentageowned=numofcountriesowned/double(listofcountries.size())*100;
        int worldpercentageownedrounded=worldpercentageowned;
        //converts the number into a string to be added onto the output
        string numbertostring = static_cast<ostringstream*>( &(ostringstream() << worldpercentageownedrounded) )->str();
        worldcontrolledoutput+=numbertostring + "\t\t";
    }
    std::cout<< worldcontrolledoutput<<std::endl;//outputs the string
    
}
