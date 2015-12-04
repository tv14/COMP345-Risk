// game logger class. as an observer of "driver", it is notified whenever a player takes an action
// and prints the output to a file "gamelog.txt".
// NOTE that it is actually indirectly inherits observer.h through logger.

#pragma once

#include "logger.h"
#include "driver.h"
#include <fstream>
#include <string>

class gamelogger : public logger {
public:
	gamelogger();
	gamelogger(driver* s);
	~gamelogger();
	void Update();
	void update(std::string str, std::string playername, std::string phase);
	void innerupdate(std::string str, std::string playername, std::string phase, bool playerOK, bool phaseOK);
	void printtolog(std::string str);
	void printself();
private:
	driver* subject;
	std::ofstream log;
};