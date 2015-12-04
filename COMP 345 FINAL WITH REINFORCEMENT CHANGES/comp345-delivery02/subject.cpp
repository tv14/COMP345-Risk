#include "Subject.h"
#include "Observer.h"

Subject::Subject() {
    _observers=new list<Observer*>;
}

Subject::~Subject(){
    delete _observers;
}

void Subject::Attach(Observer* obs) {
    _observers->push_back(obs);
}

void Subject::Detach(Observer* obs) {
    _observers->remove(obs);
}

/*
 * Updates alls attached observers
 */
void Subject::Notify(){
    list<Observer*>::iterator i= _observers->begin();
    for (;i !=_observers->end();i++)
    {
        (*i)->Update();
    }
}

void Subject::notify(std::string str, std::string playername, std::string phase) {
	std::list<Observer*>::iterator it = _observers->begin();
	for (; it != _observers->end(); ++it) {
		(*it)->update(str, playername, phase); // "it" is a pointer that points to a pointer that points to an observer... so yeah
	}
}