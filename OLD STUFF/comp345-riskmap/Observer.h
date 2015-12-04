#ifndef OBSERVER_H
#define OBSERVER_H

#include "stdafx.h"
#include "Subject.h"

using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Subject;

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};

#endif