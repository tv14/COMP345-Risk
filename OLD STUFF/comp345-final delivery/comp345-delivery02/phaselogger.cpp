// phase logger implementation. Handles only phase tracking.

#include "phaselogger.h"
#include <iostream>

phaselogger::phaselogger(logger *l, std::string phasename, Subject *s) {
	this->innerlogger = l;
	this->phasename = phasename;

	// after wrapping the previous logger, detach it from its subject, and take over as the observer.
	s->Detach(l);
	s->Attach(this);
}

phaselogger::~phaselogger() {
	/*
	delete innerlogger;
	*/
}

void phaselogger::Update() {
	// nothing
}

void phaselogger::update(std::string str, std::string playername, std::string phasename) {
	//std::cout << "(update called. calling innerupdate...)" << std::endl;
	bool ok = false;
	if (this->phasename == phasename ||
		phasename == "turnindicator" ||
		phasename == "winner") { // if the update is relevant to the phase being tracked (always track turn indicator/winner announcement), then...
		ok = true;
	}
	//std::cout << "(phaseOK is: " << ok << ")" << std::endl;
	innerlogger->innerupdate(str, playername, phasename, false, ok);
}

void phaselogger::innerupdate(std::string str, std::string playername, std::string phasename, bool playerOK, bool phaseOK) {
	//std::cout << "(innerupdate called. passing along...)" << std::endl;
	bool ok = false;
	if (phaseOK) innerlogger->innerupdate(str, playername, phasename, playerOK, true);
	else if (this->phasename == phasename ||
		phasename == "turnindicator" ||
		phasename == "winner") {
		ok = true;
	}
	//std::cout << "(phaseOK is: " << ok << ")" << std::endl;
	innerlogger->innerupdate(str, playername, phasename, playerOK, ok); // pass to next decorator
}

// for debug
void phaselogger::printself() {
	std::cout << "-> a phaselogger set to log " << phasename << "..." << std::endl;
	innerlogger->printself();
}