#include "GameStatObserver.h"



GameStatObserver::GameStatObserver(){
}
GameStatObserver::GameStatObserver(GameStatSubject* s){
    _gamestatsubject=s;
    _gamestatsubject->Attach(this);
}
GameStatObserver::~GameStatObserver(){
    _gamestatsubject->Detach(this);
}

/*
 * Upon being notified by the Observable/Subject (which is GameStatSubject). It outputs the number of countries, the total army count and the number of cards of each player
 */
void GameStatObserver::Update() {
    std::string playeroutput="",countriesoutput="", armyoutput="", cardsoutput="", decorator="";
    
    //formats the player name in an orderly format along with a header
    playeroutput="Player Name\t\t";
    for (int indexofplayers=0;indexofplayers<_gamestatsubject->getListOfPlayers().size();indexofplayers++)
    {
        playeroutput+=_gamestatsubject->getListOfPlayers()[indexofplayers].getPlayerName() + "\t\t";
    }
    
    //formats the number of countries in an orderly format along with a header 
    countriesoutput+="NumofCountries\t\t";
   for (int indexofplayers=0;indexofplayers<_gamestatsubject->getListOfPlayers().size();indexofplayers++)
    {
       int Number=_gamestatsubject->getListOfNumberOfCountriesOwned()[indexofplayers];
       string numbertostring = static_cast<ostringstream*>( &(ostringstream() << Number) )->str(); 
       countriesoutput+=numbertostring + "\t\t";
    }
    
    //formats the total army count in an orderly format along with a header
    armyoutput+="TotalArmyCount\t\t";
    for (int indexofplayers=0;indexofplayers<_gamestatsubject->getListOfPlayers().size();indexofplayers++)
    {
        int Number=_gamestatsubject->getListOfTotalArmiesOwned()[indexofplayers];
        string numbertostring = static_cast<ostringstream*>( &(ostringstream() << Number) )->str(); 
        armyoutput+=numbertostring+ "\t\t";
    }
    
    //formats the number of cards in an orderly format along with a header
    cardsoutput+="TotalNumofCards\t\t";
    for (int indexofplayers=0;indexofplayers<_gamestatsubject->getListOfPlayers().size();indexofplayers++)
    {
        int Number=_gamestatsubject->getListOfPlayers()[indexofplayers].getNumberOfCards();
        string numbertostring = static_cast<ostringstream*>( &(ostringstream() << Number) )->str(); 
        cardsoutput+=numbertostring+ "\t\t";
    }
    //outputs the results
    std::cout<<playeroutput<<std::endl;
    std::cout<<countriesoutput<<std::endl;
    std::cout<<armyoutput<<std::endl;
    std::cout<<cardsoutput<<std::endl;
    std::cout<<decorator;
}
