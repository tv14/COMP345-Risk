/* 
 * File:   PlayerView.h
 * Author: Tam
 *
 * Created on November 2, 2015, 9:06 PM
 */

#ifndef PLAYERVIEW_H
#define	PLAYERVIEW_H
#include "Observer.h"
#include "PlayerSubject.h"

/*
 * Concrete Observer which observers the PlayerSubject class
 */
class PlayerView : public Observer {
public:
    PlayerView();
    PlayerView(PlayerSubject* s);
    ~PlayerView();
    void Update();
    void display();
private:
    PlayerSubject* _subject;
        
};


#endif	/* PLAYERVIEW_H */

