#include "BattlesWonDecorator.h"

using namespace std;


/*
 * the battle won % decorator constructor which also takes a vector of players to obtain their win percentage
 */
BattlesWonDecorator::BattlesWonDecorator(Observer* decoratedgamestatsubject, vector<Player>& listofplayers,GameStatSubject* s)
: GameStatDecorator(decoratedgamestatsubject,s), listofplayers(listofplayers)
{
    
}

/*
 * Battle % updater which outputs the original statistics data in addition to the battle & of each player
 */
void BattlesWonDecorator::Update(){
    GameStatDecorator::Update();//displays original game statistics data first
    std::string battlepercentageoutput="Battles%Won\t\t";//displays what's going to be shown
    for (int indexofplayers=0;indexofplayers<listofplayers.size();indexofplayers++)//checks for each player
    {
        //obtain the players' win percentage by diving their battleswon/battlesfought and then multiply by 100
        double battlepercentage= listofplayers[indexofplayers].getBattlesWon()/double(listofplayers[indexofplayers].getBattlesFought())*100;
        int battlepercentagerounded=battlepercentage;
        //converts the number into a string to be added onto the output
        string numbertostring = static_cast<ostringstream*>( &(ostringstream() << battlepercentagerounded) )->str();
        battlepercentageoutput+=numbertostring + "\t\t";
    }
    std::cout<< battlepercentageoutput<<std::endl;//outputs the string
}
