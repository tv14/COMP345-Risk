#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>
#include "Country.h"
#include "Player.h"

using namespace std;

class Continent {
public:
	Continent::Continent();
	Continent::Continent(string name);
	Continent::Continent(const Continent &c);
	Continent::~Continent();
	string Continent::getContinentName();
	vector< Country > Continent::getCountries();
	int Continent::getNumCountries();
	Player* Continent::getOwner();
	int Continent::getArmyBonus();
	int Continent::getCaptureCount();

	void Continent::setContinentName(string& name);
	void Continent::setCountries(vector<Country>& list);
	void Continent::setOwner(Player* o);
	void Continent::setArmyBonus(int b);
	void Continent::setCaptureCount(int cc);

	void Continent::addCountry(Country& c);
	//bool Continent::isPlayerOwned();
	string Continent::toString();

private:
	string continentName;
	vector< Country > countries;
	Player* owner;
	int armyBonus = 0;
	int captureCount = 0;
};

#endif