// the basic game logger class. As gamelogger directly inherits from this class, it defines
// gamelogger's basic functions, that is, to log everything that it is passed by driver when it
// updates. Other gamelogger decorators, also inheriting from this class, will modify the basic gamelogger
// by only allowing through certain events, e.g. only certain players, or only certain phases. Important: the
// decorators only ADD functionality, they cannot REMOVE anything. Therefore, once you add something to the
// game logger, it is expected that you will want to keep it there until the end of the game.

#pragma once

#include "observer.h"
#include "subject.h"
#include <string>

class logger : public Observer {
public:
	virtual void innerupdate(std::string str, std::string playername, std::string phase, bool playerOK, bool phaseOK) = 0;
	virtual void printself() = 0;
};