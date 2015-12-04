#include "BattlesWonDecorator.h"

using namespace std;


/*
 * the battle won % decorator constructor which also takes a vector of players to obtain their win percentage
 */
BattlesWonDecorator::BattlesWonDecorator(Observer* decoratedgamestatsubject, vector<Player>& listofplayers,GameStatSubject* s)
: GameStatDecorator(decoratedgamestatsubject,s), listofplayers(&listofplayers)
{
    
}

/*
 * Battle % updater which outputs the original statistics data in addition to the battle & of each player
 */
void BattlesWonDecorator::Update(){
    GameStatDecorator::Update();//displays original game statistics data first
    std::string battlepercentageoutput="Battles%Won\t\t";//displays what's going to be shown
    for (int indexofplayers=0;indexofplayers<listofplayers->size();indexofplayers++)//checks for each player
    {
        //obtain the players' win percentage by diving their battleswon/battlesfought and then multiply by 100
		double battlepercentage;
		// if the player has not fought a battle the % is set to 0 to ensure that divide by zero does not occur
		if ((*listofplayers)[indexofplayers].getBattlesFought() == 0)
		{
			battlepercentage = 0;
		}
		else {
			battlepercentage = (*listofplayers)[indexofplayers].getBattlesWon() / double((*listofplayers)[indexofplayers].getBattlesFought()) * 100;
		}

		string numbertostring = to_string(battlepercentage);
        battlepercentageoutput+=numbertostring + "\t";
    }
    std::cout<< battlepercentageoutput<<std::endl;//outputs the string
}

void BattlesWonDecorator::update(std::string str, std::string playername, std::string phasename){};

void BattlesWonDecorator::printself(){};