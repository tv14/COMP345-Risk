#ifndef CONTINENT_H
#define CONTINENT_H

#include "stdafx.h"
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
	Player Continent::getOwner();
	int Continent::getArmyBonus();

	void Continent::setContinentName(string name);
	void Continent::setCountries(vector< Country > list);
	void Continent::setOwner(Player o);
	void Continent::setArmyBonus(int b);

	void Continent::addCountry(Country c);

	bool Continent::isPlayerOwned();

private:

	string continentName;
	vector< Country > countries;
	Player* owner;
	int armyBonus;

};

#endif