#include "Country.h"
#include "Player.h"
#include <string>

/*
 * Default Constructors, takes no arguments
 */
Country::Country() {
    this->Country::setCountryArmy(0);
    this->name="";
}
/*
 * Constructor which initializes the player currently holding the country, army amount in the country and the country name as arguments.
 */
 Country::Country(Player owner, int countryarmy, std::string name) {
     this->Country::setCountryArmy(countryarmy);
     this->Country::setOwner(owner);
     this->name=name;
             
}
 /*
  * Takes a Country as an argument and sets that country to be adjacent to the this one.
  */
void Country::addAdjacent(Country othercountry) {
    int i=0;
    while (i !=-1)
    {
        if (this->adjacent[i]=="")
        {
            this->adjacent[i]=othercountry.getCountryName();
            i=-1;
        }
        else 
        {
            i++;
        }
    }
}

/*
 * Takes a Country as an argument and determines if it is adjacent to this one.
 */
bool Country::isAdjacent(Country othercountry) {
    for (int i=0;i<100;i++)
    {
        if(this->adjacent[i]==othercountry.getCountryName())
        {
            return true;
        }
        if (this->adjacent[i]=="")
        {
            return false;
        }
    }
    return false;
    
}

/*
 * A country is same as another country is they have the same name. Thus they are also not equal if the names are not the same.
 */
bool operator==(Country &c1, Country &c2) {
    return (c1.getCountryName()==c2.getCountryName());
}
bool operator!=(Country &c1, Country &c2) {
     return (c1.getCountryName()!=c2.getCountryName());
}