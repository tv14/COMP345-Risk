// player logger implementation. Handles only player tracking.

#include "playerlogger.h"
#include <iostream>

playerlogger::playerlogger(logger *l, std::string playername, subject *s) {
	this->innerlogger = l;
	this->playername = playername;

	// after wrapping the previous logger, detach it from its subject, and take over as the observer.
	s->detach(l);
	s->attach(this);
}

playerlogger::~playerlogger() {
	/*
	delete innerlogger;
	*/
}

void playerlogger::update(std::string str, std::string playername, std::string phasename) {
	//std::cout << "(update called. calling innerupdate...)" << std::endl;
	bool ok = false;
	if (this->playername == playername) { // if the update is relevant to the player being tracked, then...
		ok = true;
	}
	//std::cout << "(playerOK is: " << ok << ")" << std::endl;
	innerlogger->innerupdate(str, playername, phasename, ok, false);
}

void playerlogger::innerupdate(std::string str, std::string playername, std::string phasename, bool playerOK, bool phaseOK) {
	//std::cout << "(innerupdate called. passing along...)" << std::endl;
	bool ok = false;
	if (playerOK) innerlogger->innerupdate(str, playername, phasename, true, phaseOK);
	else if (this->playername == playername) {
		ok = true;
	}
	//std::cout << "(playerOK is: " << ok << ")" << std::endl;
	innerlogger->innerupdate(str, playername, phasename, ok, phaseOK); // pass to next decorator
}

// for debug
void playerlogger::printself() {
	std::cout << "-> a playerlogger set to log " << playername << "..." << std::endl;
	innerlogger->printself();
}