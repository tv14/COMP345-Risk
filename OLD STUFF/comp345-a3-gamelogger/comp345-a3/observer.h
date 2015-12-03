// observer class: defines behavior of objects that observe "subject" objects. in this assignment, the logger
// is the observer, and observes the driver, which updates its observer whenever a player takes an action.

#pragma once

#include <string>

class observer {
public:
	~observer();
	virtual void update(std::string str, std::string playername, std::string phasename) = 0;
	virtual void printself() = 0;
protected:
	observer();
};