/* 
 * File:   main.cpp
 * Author: Tam
 *
 * Created on October 1, 2015, 10:37 PM
 */

#include <cstdlib>
#include <iostream>
#include "Battle.h"
#include <ctime>
#include "Country.h"
#include "PlayerSubject.h"
#include "PlayerView.h"
#include "Player.h"
#include "SelectandBattle.h"
#include "Fortification.h"
#include "Reinforcement.h"
#include "GameStatSubject.h"
#include "GameStatObserver.h"
#include "GameStatDecorator.h"
#include "WorldControlledDecorator.h"
#include "BattlesWonDecorator.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
srand(time(0)) ;//needs to be in main to determine dice rolls
    
std::cout << "This program assumes that there are 5 countries (named c0,c1,c2,c3,c4) and 2 players (p1,p2)\np1 (the current player) owns c0,c1,c2 and p2 owns c3 and c4\n";
std::cout <<"the countries have (5,10,15,10,20) armies respectively" <<std::endl;
std::cout  <<"c0 is adjacent to c1 and c2.\nc1 and c2 are also adjacent to c3.\nc2 is also adjacent to c4"<<std::endl;
std::cout << "There are two continents(cont1, cont2). c0-c3 reside in cont1 and c4 resides in cont2\n"<<std::endl;


Player p1("A"),p2("B");
    vector<Player> Players;//driver created
    Players.push_back(p1);
    Players.push_back(p2);
    
    
    vector<Country> countries(5);
    
    
    // Country countries [5];//from map creation
    Continent cont1("cont1"),cont2("cont2");
    
    vector<Continent> continents;
    continents.push_back(cont1);
    continents.push_back(cont2);
    
    continents[0].setContinentName("cont1");
    continents[1].setContinentName("cont2");
    continents[0].setArmyBonus(3);
    continents[1].setArmyBonus(1);
    
    continents[0].addCountry("c0");
    continents[0].addCountry("c1");
    continents[0].addCountry("c2");
    continents[0].addCountry("c3");
    continents[1].addCountry("c4");
    
    countries[0].setAll(Players[0],5,"c0", "cont1");//name and continent determined during map creation, owner and army size determined during pregame setup.
    countries[1].setAll(Players[0],10,"c1", "cont1");
    countries[2].setAll(Players[0],15,"c2", "cont1");
    countries[3].setAll(Players[1],10,"c3", "cont1");
    countries[4].setAll(Players[1],20,"c4", "cont2");
    
    countries[0].addConnection(countries[1]);//determined during map creation
    countries[0].addConnection(countries[2]);
    countries[1].addConnection(countries[2]);
    countries[1].addConnection(countries[3]);
    countries[2].addConnection(countries[3]);
    countries[2].addConnection(countries[4]);
    countries[3].addConnection(countries[4]);
    
    Players[0].drawNumberOfCards(5);//player 1 has 5 cards in hand
    
    Players[0].setBattlesFought(10);//both players have fought 10 battles, player 1 winning 3, player 2 winning 7
    Players[1].setBattlesFought(10);
    Players[0].setBattlesWon(3);
    Players[1].setBattlesWon(7);
    
    
    GameStatSubject *sub=new GameStatSubject(Players,countries);
    Observer *obs=new GameStatObserver(sub);
    obs= new WorldControlledDecorator(obs,Players, countries,sub);
    obs=new BattlesWonDecorator(obs,Players,sub);
   
    sub->Notify();
    
   

    
    std::cout<<Players[0].getCurrentReinforcements();
   
   
    
    Reinforcement rein(Players[0],countries,continents, 3);
    
    rein.calculateReinforcement();
    rein.calculateCardsReinforcement();
    rein.ReinforcementPhase();
     std::cout<<countries[0].getArmyCount();
    
    
    
    Fortification fort(Players[0],countries);//fortification phase. Only requires these 4 lines
    fort.setMovingFrom();
    fort.setMovingTo();
    fort.moveArmy();
 
   
    PlayerSubject *ps1=new PlayerSubject(Players[0], countries, continents);//create observable and observer classes
    PlayerView *pv1=new PlayerView(ps1);
    
    SelectandBattle newbattle(Players[0],countries);//initiates a single battle
    newbattle.AttackPhase();
    
    ps1->setCurrentReinforcements(5);//sets reinforcements and then the observer is updated and displays all info on the player subject (p1)
   
    delete pv1;
    delete ps1;

    
   
    
    return 0;
}

