// subject class, from which all Observer pattern subjects will inherit (namely, driver).

#pragma once

#include "observer.h"
#include <list>
#include <string>

class subject {
protected:
	std::list<observer*>* observers;
public:
	void attach(observer* o);
	void detach(observer* o);
	void notify(std::string str, std::string playername, std::string phase);
	subject();
	~subject();
};
