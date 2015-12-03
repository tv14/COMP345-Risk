// subject implementation

#include "subject.h"
#include "observer.h"
#include <list>

subject::subject() {
	observers = new std::list<observer*>();
}

subject::~subject() {
	delete observers;
}

void subject::attach(observer* o) {
	observers->push_back(o);
}

void subject::detach(observer* o) {
	observers->remove(o);
}

void subject::notify(std::string str, std::string playername, std::string phase) {
	std::list<observer*>::iterator it = observers->begin();
	for (; it != observers->end(); ++it) {
		(*it)->update(str, playername, phase); // "it" is a pointer that points to a pointer that points to an observer... so yeah
	}
}