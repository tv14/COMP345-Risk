#include "GameStatDecorator.h"
#include "Subject.h"

using namespace std;

/*
 * Abstract decorator constructor which decorates the game statistics observer and attaches to the game statistics subject 
 */
GameStatDecorator::GameStatDecorator(Observer* decoratedgamestatsubject,GameStatSubject* s){
    this->decoratedgamestatsubject=decoratedgamestatsubject;
    s->Detach(decoratedgamestatsubject);//detaches the gamestatobserver so that its contents are not repeated twice
    s->Attach(this);//attaches the decorator so that the decorated part can also be shown when the subject is updated
}
GameStatDecorator::~GameStatDecorator(){
    delete this->decoratedgamestatsubject;
}
void GameStatDecorator::Update(){
    decoratedgamestatsubject->Update();
}

void GameStatDecorator::update(std::string str, std::string playername, std::string phasename){};

void GameStatDecorator::printself(){};