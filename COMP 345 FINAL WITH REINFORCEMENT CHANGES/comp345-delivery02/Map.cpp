#include <string>
#include <vector>
#include <iostream>
#include "Continent.h"
#include "Continent.h"
#include "Map.h"

using namespace std;

Map::Map() {

}

Map::Map(vector<Country>& countries, vector<Continent>& continents) : countries(countries), continents(continents) {
	Notify();
}

Map::Map(const Map &obj) {
	countries = obj.countries;
	continents = obj.continents;
}

Map::~Map() {

}

vector<Country> Map::getCountries()
{
	return countries;
}

vector<Continent> Map::getContinents()
{
	return continents;
}

void Map::setCountries(vector<Country>& countries)
{
	this->countries = countries;
	Notify();
}

void Map::setContinents(vector<Continent>& continents)
{
	this->continents = continents;
	Notify();
}

void Map::addCountry(Country& c)
{
	countries.push_back(c);
	Notify();
}

void Map::addContinent(Continent& c)
{
	continents.push_back(c);
	Notify();
}

//Methods used to overwrite an existing object in the country or continent vectors.
void Map::editCountry(Country& coun) {
	for (Country& c : countries) {
		if (c.getName() == coun.getName())
			c = coun;
	}
	Notify();
}
void Map::editContinent(Continent& cont) {
	for (Continent& c : continents) {
		if (c.getContinentName() == cont.getContinentName())
			c = cont;
	}
	Notify();
}

//Returns the number of countries controlled by a player
int Map::getNumCountriesOwned(Player* player) {
	int numOwned = 0;

	for (Country& c : countries) {
		if (c.getOwner()->getPlayerName() == player->getPlayerName())
			numOwned++;
	}

	return numOwned;
}

//Returns the number of reinforcements a player will receive based on the number of countries
//they control divided by 3 (minimum 3), plus the bonus from any continents they control
int Map::getNumReinforcements(Player* player) {
	int reinforcements = 3;

	if (getNumCountriesOwned(player) / 3 <= 3)
		return reinforcements;
	else {
		reinforcements = getNumCountriesOwned(player) / 3;
		for (Continent& c : continents) {
			if (c.getOwner()->getPlayerName() == player->getPlayerName())
				reinforcements += c.getArmyBonus();
		}
	}

	return reinforcements;
}

void Map::getMapState() {
	Notify();
}
