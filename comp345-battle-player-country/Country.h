/* 
 * File:   Country.h
 * Author: Tam
 *
 * Created on October 13, 2015, 9:39 PM
 */

#ifndef COUNTRY_H
#define	COUNTRY_H
#include <string>
#include "Player.h"
using namespace std;

class Country {
public:
    Country();
    Country( Player owner, int countryarmy, std::string name);
    Player getOwner();
    int getCountryArmy();
    void setOwner(Player newowner);
    void setCountryArmy(int newarmy);
    string getCountryName();
    void setCountryName(string newname);
    void setAll(Player newowner, int newarmy, string newname);
    void addAdjacent(Country othercountry);
    bool isAdjacent(Country othercountry);
    friend bool operator==(Country &c1, Country &c2);
    friend bool operator!=(Country &c1, Country &c2);

private:
    Player* owner;
    int countryarmy;
    std::string name;
    std::string adjacent[100]={""};
    
        
};
inline Player Country::getOwner() {
    return *owner;
}
inline int Country::getCountryArmy() {
    return this->countryarmy;
}
inline string Country::getCountryName(){
    return this->name;
}
inline void Country::setCountryArmy(int newarmy) {
    this->countryarmy=newarmy;
}
inline void Country::setOwner(Player newowner) {
    this->owner=&newowner;
}
inline void Country::setCountryName(string newname){
    this->name=newname;
}
/*
 * Method used to quickly change the Country's variables at once.
 */
inline void Country::setAll(Player newowner, int newarmy, string newname) {
    this->owner=&newowner;
    this->countryarmy=newarmy;
    this->name=newname;
    
}
#endif	/* COUNTRY_H */

