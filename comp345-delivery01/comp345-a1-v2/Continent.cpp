
#include "Continent.h"
#include "Country.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//Default constructor
Continent::Continent()
{
}

//Constructor initializes a continent with a name, list of countries, and the number of entries in the list
Continent::Continent(string name) : continentName(name)
{
}

//Copy constructor
Continent::Continent(const Continent &c)
{
	setContinentName(c.continentName);
	setCountries(c.countries);
}

//Destructor
Continent::~Continent()
{
}

//Returns the name of the continent
string Continent::getContinentName()
{
	return continentName;
}

//Returns the list of countries in the continent
vector< Country > Continent::getCountries()
{
	return countries;
}

//Returns the number of countries in the continent
int Continent::getNumCountries()
{
	return countries.size();
}

//Returns the name of the player controlling this continent
Player* Continent::getOwner()
{
	return owner;
}

//Returns the number of armies a player receives per turn for controlling this continent
int Continent::getArmyBonus()
{
	return armyBonus;
}

int Continent::getCaptureCount() {
	return captureCount;
}

//Sets the name of the continent
void Continent::setContinentName(string name)
{
	continentName = name;
}

//Sets the list of countries and the number of entries in the list
void Continent::setCountries(vector< Country > list)
{
	countries = list;
}

//Set the name of the player controlling this continent
void Continent::setOwner(Player* o)
{
	this->owner = o;
}

//Set the bonus number of armies the controlling player receives per turn
void Continent::setArmyBonus(int b)
{
	armyBonus = b;
}

void Continent::setCaptureCount(int cc) {
	captureCount = cc;
}

//Adds a country to this continent
void Continent::addCountry(Country c)
{
	countries.push_back(c);
}

bool Continent::isPlayerOwned() {
	string player = countries.at(0).getOwner()->getPlayerName();
	bool owned = true;

	for (Country c : countries) {
		if (c.getOwner()->getPlayerName() != player)
			owned = false;
	}

	return owned;
}
