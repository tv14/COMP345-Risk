/* 
 * File:   Observer.h
 * Author: Tam
 *
 * Created on November 2, 2015, 8:01 PM
 */

/*
 * Observable class, observers the Subject Class, and is superclass for the Concrete Observer (PlayerView) class
 */
#ifndef OBSERVER_H
#define	OBSERVER_H

#include <string>

class Observer {
public:
    ~Observer();
    virtual void Update()=0;
	virtual void update(std::string str, std::string playername, std::string phasename) = 0;
	virtual void printself() = 0;
protected:
    Observer();
};


#endif	/* OBSERVER_H */

