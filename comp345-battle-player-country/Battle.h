/* 
 * File:   Battle.h
 * Author: Tam
 *
 * Created on October 1, 2015, 10:52 PM
 */

#ifndef BATTLE_H
#define	BATTLE_H
#include <iostream>

class Battle {
public:
    Battle(int attackerarmy, int defenderarmy);
    static int roll();
    int numberOfAttackers();
    int numberOfDefenders();
    void sortAttackerRolls();
    void sortDefenderRolls();
    bool attackerWins(int attackerdie, int defenderdie);
    void getResults();
    int getAttackerArmy();
    int getDefenderArmy();
    int getAdie1();
    int getAdie2();
    int getAdie3();
    int getDdie1();
    int getDdie2();
    int getNumberOfAttackDice();
    void resetAdie();
    void resetDdie();
    void setAttackerArmy(int newarmy);
    void setDefenderArmy(int newarmy);
    void setNumberOfAttackDice(int numberofattackers);
    void setAllin(bool allin);
    void singleBattle();
    void allIn();
    
    friend std::ostream& operator<< (std::ostream &out, Battle &battle);
private:
    int attackerarmy;
    int defenderarmy;
    int Adie1, Adie2, Adie3=0, Ddie1, Ddie2=0;
    bool allin=false;
    int numberofattackdice;
    

};
inline std::ostream& operator<< (std::ostream &out, Battle &battle) {
    out << "There are " << battle.getAttackerArmy() << " Attackers and " << battle.getDefenderArmy() << " Defenders"<<std::endl;

}
inline int Battle::getAttackerArmy() {
    return attackerarmy;
}
inline int Battle::getDefenderArmy() {
    return defenderarmy;
}
inline int Battle::getAdie1() {
    return Adie1;
}
inline int Battle::getAdie2() {
    return Adie2;
}
inline int Battle::getAdie3() {
    return Adie3;
}
inline int Battle::getDdie1() {
    return Ddie1;
}
inline int Battle::getDdie2() {
    return Ddie2;
}
inline int Battle::getNumberOfAttackDice() {
    return this->numberofattackdice;
}
inline void Battle::resetAdie() {
    this->Adie1=0;
    this->Adie2=0;
    this->Adie3=0;
}
inline void Battle::resetDdie() {
    this->Ddie1=0;
    this->Ddie2=0;
}
inline void Battle::setAttackerArmy(int newarmy) {
    this->attackerarmy=newarmy;
}
inline void Battle::setDefenderArmy(int newarmy) {
    this->defenderarmy=newarmy;
}
inline void Battle::setAllin(bool allin) {
    this->allin=allin;
}
inline void Battle::setNumberOfAttackDice(int attackdice) {
   this->numberofattackdice=attackdice;
}
#endif	/* BATTLE_H */

