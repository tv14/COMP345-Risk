#include "PlayerView.h"
#include "PlayerSubject.h"
#include <iostream>

using namespace std;

PlayerView::PlayerView() {  
}

/*
 * constructor, also attaches to observable class
 */
PlayerView::PlayerView(PlayerSubject* s){
 _subject=s;
 _subject->Attach(this);
}

/*
 * destructor, also detaches from observable class
 */
PlayerView::~PlayerView(){
    _subject->Detach(this);
}

/*
 * Upon receiving an update from the Subject/Observable class, it displays the results
 */
void PlayerView::Update(){
    PlayerView::display();
}

/*
 * displays the continents owned, countries owned, current reinforcements, total armies and battles won of the player that is being observed
 */
void PlayerView::display(){
    std::string continentsowned=_subject->PlayerSubject::getContinentsOwned();
    std::string countriesowned=_subject->PlayerSubject::getCountriesOwned();
    int currentreinforcements=_subject->PlayerSubject::getCurrentReinforcements();
    int totalarmies= _subject->PlayerSubject::getTotalArmies();
    int battleswon= _subject->PlayerSubject::getBattlesWon();
    
    std::cout<<continentsowned << countriesowned << "\nCurrent Reinforcements:\t" << currentreinforcements << "\nTotal Armies:\t" << totalarmies << "\nBattles Wons:\t"
            << battleswon <<std::endl;
}