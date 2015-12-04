/* 
 * File:   GameStatDecorator.h
 * Author: Tam
 *
 * Created on November 18, 2015, 4:03 PM
 */

#ifndef GAMESTATDECORATOR_H
#define	GAMESTATDECORATOR_H
#include "GameStatSubject.h"

class GameStatDecorator : public Observer {
    protected:
        Observer* decoratedgamestatsubject;
    public:
        GameStatDecorator (Observer* decoratedgamestatsubject, GameStatSubject* s);
        ~GameStatDecorator();
        void Update();
		void update(std::string str, std::string playername, std::string phasename);
		void printself();
            
};

#endif	/* GAMESTATDECORATOR_H */

