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
std::cout  <<"c0 is adjacent to c1 and c2.\nc1 and c2 are also adjacent to c3.\nc2 is also adjacent to c4\n"<<std::endl;

    Player p1("A"),p2("B");//driver created
    Country countries [5];//from map creation
    
    
    countries[0].setAll(p1,5,"c0");//name determined during map creation, owner and army size determined during pregame setup.
    countries[1].setAll(p1,10,"c1");
    countries[2].setAll(p1,15,"c2");
    countries[3].setAll(p2,10,"c3");
    countries[4].setAll(p2,20,"c4");
    countries[0].addAdjacent(countries[1]);//determined during map creation
    countries[0].addAdjacent(countries[2]);
    countries[1].addAdjacent(countries[0]);
    countries[1].addAdjacent(countries[2]);
    countries[1].addAdjacent(countries[3]);
    countries[2].addAdjacent(countries[0]);
    countries[2].addAdjacent(countries[1]);
    countries[2].addAdjacent(countries[3]);
    countries[2].addAdjacent(countries[4]);
    countries[3].addAdjacent(countries[1]);
    countries[3].addAdjacent(countries[2]);
    countries[3].addAdjacent(countries[4]);
    countries[4].addAdjacent(countries[2]);
    countries[4].addAdjacent(countries[3]);
   
    
    
   
    SelectandBattle newbattle(p1,countries,5);
    
    
    newbattle.selectAttackingCountry();
    newbattle.selectDefendingCountry();
    
    newbattle.doBattle();
    
   
    
    
    
    
    
    return 0;
}

