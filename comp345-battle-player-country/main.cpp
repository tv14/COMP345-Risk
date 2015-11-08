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

    Player p1("A"),p2("B");//driver created
    
    Country countries [5];//from map creation
    Continent continents[2];
    continents[0].setContinentName("cont1");
    continents[1].setContinentName("cont2");
    
    continents[0].addCountry("c0");
    continents[0].addCountry("c1");
    continents[0].addCountry("c2");
    continents[0].addCountry("c3");
    continents[1].addCountry("c4");
    
    countries[0].setAll(p1,5,"c0", "cont1");//name and continent determined during map creation, owner and army size determined during pregame setup.
    countries[1].setAll(p1,10,"c1", "cont1");
    countries[2].setAll(p1,15,"c2", "cont1");
    countries[3].setAll(p2,10,"c3", "cont1");
    countries[4].setAll(p2,20,"c4", "cont2");
    
    countries[0].addConnection(countries[1]);//determined during map creation
    countries[0].addConnection(countries[2]);
    countries[1].addConnection(countries[2]);
    countries[1].addConnection(countries[3]);
    countries[2].addConnection(countries[3]);
    countries[2].addConnection(countries[4]);
    countries[3].addConnection(countries[4]);
   
   
   
    PlayerSubject *ps1=new PlayerSubject(p1, countries, 5, continents,2 );//create observable and observer classes
    PlayerView *pv1=new PlayerView(ps1);
    
    SelectandBattle newbattle(p1,countries,5);//initiates a single battle
    newbattle.selectAttackingCountry();
    newbattle.selectDefendingCountry();
    
    newbattle.doBattle();
    
    ps1->setCurrentReinforcements(5);//sets reinforcements and then the observer is updated and displays all info on the player subject (p1)
   
    delete pv1;
    delete ps1;
    
    
    
    
    return 0;
}

