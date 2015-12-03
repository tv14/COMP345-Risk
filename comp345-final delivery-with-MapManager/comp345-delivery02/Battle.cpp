/* 
 * File:   Battle.cpp
 * Author: Tam
 * 
 * Created on October 1, 2015, 10:52 PM
 */

#include "Battle.h"
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <iostream>

/*
 * constructor with armies initialized. There is  no default constructor since all battle must have at least 2 attackers and 1 defender
 */
Battle::Battle(int aarmy, int darmy) {
    if (aarmy<2 || darmy<1)
    {
        std::cout << "Error. Insufficient amount of armies to do battle";
        exit(1);
    }
    else {
        this->attackerarmy=aarmy;
        this->defenderarmy=darmy;
        attackerwon=0;
        defenderwon=0;
    }
}
/*
 * Rolls a dice 
 */
 int Battle::roll() {
    return rand() %6+1;
}

/*
 * This method allows the attacking player to attack with a smaller army if he decides to 
 * i.e attacking with 1 army when he has 3 armies vs 2 defending armies to avoid the possibility of losing 2 armies in a single fight
 */
 int Battle::numberOfAttackers() {
     int limit;
     (this->Battle::getAttackerArmy()-1>=3) ? limit=3 : limit=this->Battle::getAttackerArmy();
     std::cout<< "Please enter the number of Attackers (1-" <<limit << "):\t";
     bool check=true;
     int numberofattackers;
     while (check)
     {
         std::cin >> numberofattackers;
         if (numberofattackers>=1 && numberofattackers<=limit)
         {
             check=false;
         }
     }
     return numberofattackers;
 }
 /*
 * This method allows the defending player to defend with a smaller army if he decides to
 */
 int Battle::numberOfDefenders() {
     int limit;
     (this->Battle::getDefenderArmy()>=2) ? limit=2 : limit=this->Battle::getDefenderArmy();
      std::cout<< "Please enter the number of Defenders (1-" <<limit << "):\t";
     bool check=true;
     int numberofdefenders;
     while (check)
     {
         std::cin >> numberofdefenders;
         if (numberofdefenders>=1 && numberofdefenders<=limit)
         {
             check=false;
         }
     }
     return numberofdefenders;
 }
 
 /*
  * rolls the appropriate amount of attacking dice and sorts them in descending order. Asks for the # of attacking dice if it is a single battle
  */
 void Battle::sortAttackerRolls() {
     int numberofattackers;
     if (allin)//If the player allins, the program will automatically attack with as many units as possible otherwise it will ask for user input.
     {
         numberofattackers=Battle::getAttackerArmy()-1;
     }
     else {
         numberofattackers=this->Battle::numberOfAttackers();
     }
     this->Battle::resetAdie();
     if (numberofattackers>=3) {
         this->Adie1=Battle::roll();
         this->Adie2=Battle::roll();
         this->Adie3=Battle::roll();
         
         if(this->Adie3>=this->Adie2) {
              std::swap (this->Adie3,this->Adie2);
         }
         if (this->Adie2>=this->Adie1) {
             std::swap (this->Adie2,this->Adie1);
         }
          if(this->Adie3>=this->Adie2) {
              std::swap (this->Adie3,this->Adie2);
         }
         this->Battle::setNumberOfAttackDice(3);
            
     }
     else if (numberofattackers==2) 
     {
         this->Adie1=Battle::roll();
         this->Adie2=Battle::roll();
         
         if(this->Adie2>=this->Adie1) 
         {
              std::swap (this->Adie1,this->Adie2);
         }
          this->Battle::setNumberOfAttackDice(2);
     }
     else
     {
         Adie1=Battle::roll();
         this->Battle::setNumberOfAttackDice(1);
     }
 }
 
 /*
  * rolls the appropriate amount of defending dice and sorts them in descending order. Asks for # of defending dice if it is a single battle
  */
 void Battle::sortDefenderRolls() {
     int numberofdefenders;
     if (allin)//If the player allins, the program will automatically defends with as many units as possible otherwise it will ask for user input.
     {
         numberofdefenders=Battle::getDefenderArmy();
     }
     else {
         numberofdefenders=this->Battle::numberOfDefenders();
     }
     this->Battle::resetDdie();
     if (numberofdefenders>=2) {
         this->Ddie1=Battle::roll();
         this->Ddie2=Battle::roll();
         
         if(this->Ddie2>=this->Ddie1) {
              std::swap (this->Ddie1,this->Ddie2);
         }  
         
     }
     else {
         Ddie1=Battle::roll();
     }
 }
 
 
/*
 * Checks to see if the attacking dice is strictly greater than the defending dice
 */
bool Battle:: attackerWins(int attackdie, int defenddie) {
    if (attackdie>defenddie)
        return true;
    else
        return false;
}

/*
 * Compares the attacking and defending dice to determine casualties, and then states said casualties
 */
void Battle::getResults() {
    int acasualties=0,dcasualties=0;
    if (this->Battle::getDdie2()!=0 && this->Battle::getAdie2()!=0) {
        if (this->Battle::attackerWins(this->Battle::getAdie2(), this->Battle::getDdie2())) {
            dcasualties++;
            attackerwon++;
        }
        else {
            acasualties++;
            defenderwon++;
        }       
    }
     
       if (this->Battle::attackerWins(this->Battle::getAdie1(), this->Battle::getDdie1())) {
            dcasualties++;
            attackerwon++;
        }
        else {
            acasualties++;
            defenderwon++;
        } 
    
    this->Battle::setAttackerArmy(this->Battle::getAttackerArmy()-acasualties);
    this->Battle::setDefenderArmy(this->Battle::getDefenderArmy()-dcasualties);
   std::cout << "Attackers have lost " << acasualties << " and Defenders have lost " << dcasualties <<std::endl;     
}

/*
 * Method to easily obtain the results of a single battle
 */
void Battle::singleBattle() {
    if (this->Battle::getAttackerArmy()>=2 && this->Battle::getDefenderArmy()>=1)
    {
        this->Battle::sortAttackerRolls();
        this->Battle::sortDefenderRolls();
        this->Battle::getResults();
    }
    else {
        std::cout<< "Insufficient units" <<std::endl;
    }
}

/*
 * Method to quickly go through multiple battles until the attackers can no longer continue attacking or the defenders have been annihilated. 
 */
void Battle::allIn() {
    while (this->Battle::getAttackerArmy()>=2 && this->Battle::getDefenderArmy()>=1)
    {
        this->Battle::sortAttackerRolls();
        this->Battle::sortDefenderRolls();
        this->Battle::getResults();
    }
 
}
