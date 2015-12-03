/* 
 * File:   Subject.h
 * Author: Tam
 *
 * Created on November 2, 2015, 8:02 PM
 */

#ifndef SUBJECT_H
#define	SUBJECT_H
#include "Observer.h"
#include <list>
#include "Player.h"
#include "Country.h"
#include <vector>

using namespace std;


/*
 * Also known as the Observable, and is superclass of the Concrete Observable (PlayerSubject) class
 */
class Subject {
public:
    virtual void Attach(Observer* obs);
    virtual void Detach(Observer* obs);
    virtual void Notify();
    Subject();
    ~Subject();
        
private:
    list<Observer*> *_observers;
};

#endif	/* SUBJECT_H */

