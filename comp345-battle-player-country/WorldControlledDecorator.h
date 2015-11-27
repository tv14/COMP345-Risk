/* 
 * File:   WorldControlledDecorator.h
 * Author: Tam
 *
 * Created on November 22, 2015, 4:16 PM
 */

#ifndef WORLDCONTROLLEDDECORATOR_H
#define	WORLDCONTROLLEDDECORATOR_H
#include "GameStatDecorator.h"
#include "Country.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class WorldControlledDecorator : public GameStatDecorator {
    public:
        WorldControlledDecorator(Observer* decoratedgamestatsubject,vector<Player> &listofplayers, vector<Country> &listofcountries,GameStatSubject* s);
        void Update();
    private:
        vector<Player> &listofplayers;
        vector<Country> &listofcountries;
};

#endif	/* WORLDCONTROLLEDDECORATOR_H */

