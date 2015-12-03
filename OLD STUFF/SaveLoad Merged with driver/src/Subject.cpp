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