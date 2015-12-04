/* 
 * File:   BattlesWonDecorator.h
 * Author: Tam
 *
 * Created on November 22, 2015, 8:53 PM
 */

#ifndef BATTLESWONDECORATOR_H
#define	BATTLESWONDECORATOR_H
#include "GameStatDecorator.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class BattlesWonDecorator : public GameStatDecorator {
    public:
       BattlesWonDecorator(Observer* decoratedgamestatsubject,vector<Player> &listofplayers,GameStatSubject* s);
       void Update();
	   void update(std::string str, std::string playername, std::string phasename);
	   void printself();
    private:
        vector<Player> *listofplayers;
};


#endif	/* BATTLESWONDECORATOR_H */

