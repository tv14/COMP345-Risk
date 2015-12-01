// logger decorator that tracks only a specific player, by name. Track multiple players 
// by chaining multiple instances of this decorator.

#pragma once

#include "loggerdecorator.h"

class playerlogger : public loggerdecorator {
private:
	std::string playername; // the name of the player this decorator should log
protected:
	logger *innerlogger;
public:
	playerlogger(logger *l, std::string playername, subject *s); // upon creation, this decorator requires an inner logger + the name of the player it should track for logging.
	~playerlogger();
	void update(std::string str, std::string playername, std::string phase);
	void innerupdate(std::string str, std::string playername, std::string phase, bool playerOK, bool phaseOK);

	void printself();
};