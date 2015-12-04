#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Continent.h"
#include "Country.h"

using namespace std;

class Map {
public:
	Map::Map();
	Map::Map(vector<Country>& countries, vector<Continent>& continents);
	Map::Map(const Map &obj);
	Map::~Map();
	vector<Country> Map::getCountries();
	vector<Continent> Map::getContinents();

	void Map::setCountries(vector<Country>& countries);
	void Map::setContinents(vector<Continent>& continents);

	void Map::addCountry(Country& c);
	void Map::addContinent(Continent& c);

	void Map::editCountry(Country& coun);
	void Map::editContinent(Continent& cont);

	int Map::getNumCountriesOwned(Player* player);
	int Map::getNumReinforcements(Player* player);

private:
	vector<Country> countries;
	vector<Continent> continents;
};

#endif