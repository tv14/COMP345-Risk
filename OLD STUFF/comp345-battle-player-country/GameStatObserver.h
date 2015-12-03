/* 
 * File:   GameStatObserver.h
 * Author: Tam
 *
 * Created on November 18, 2015, 9:58 PM
 */

#ifndef GAMESTATOBSERVER_H
#define	GAMESTATOBSERVER_H
#include "Observer.h"
#include "GameStatSubject.h"
#include <vector>
#include <iostream>
#include<sstream>

class GameStatObserver: public Observer {
    public:
        GameStatObserver();
        GameStatObserver(GameStatSubject* s);
        ~GameStatObserver();
        void Update();
        
    private:
        GameStatSubject* _gamestatsubject;
};


#endif	/* GAMESTATOBSERVER_H */

