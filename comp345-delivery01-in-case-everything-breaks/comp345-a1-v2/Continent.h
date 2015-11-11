#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>
#include "Country.h"
#include "Player.h"

using namespace std;

class Continent {
public:

	Continent();
	Continent(string name);
	Continent(const Continent &c);
	~Continent();
	string getContinentName();
	vector< string > getCountries();
	int getNumCountries();
	Player getOwner();
	int getArmyBonus();

	void setContinentName(string name);
	void setCountries(vector< string > list);
	void setOwner(Player o);
	void setArmyBonus(int b);

	void addCountry(string c);

private:

	string continentName;
	vector< string > countries;
	Player* owner;
	int armyBonus;

};

#endif