// logger decorator that tracks only a specific phase, by name (reinforcement, attack, fortification).
// Track multiple phases by chaining multiple instances of this decorator.

#pragma once

#include "loggerdecorator.h"

class phaselogger : public loggerdecorator {
private:
	std::string phasename; // the name of the phase this decorator should log
protected:
	logger *innerlogger;
public:
	phaselogger(logger *l, std::string phasename, Subject *s); // upon creation, this decorator requires an inner logger + the name of the phase it should track for logging.
	~phaselogger();
	void Update();
	void update(std::string str, std::string playername, std::string phasename);
	void innerupdate(std::string str, std::string playername, std::string phasename, bool playerOK, bool phaseOK);

	void printself();
};