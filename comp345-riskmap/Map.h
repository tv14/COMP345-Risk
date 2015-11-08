#ifndef MAP_H
#define MAP_H

#include "stdafx.h"
#include <string>
#include <vector>
#include "Subject.h"
#include "Continent.h"
#include "Continent.h"

using namespace std;

class Map : public Subject {
public:
	Map::Map();
	Map::Map(vector<Country> countries, vector<Continent> continents);
	Map::Map(const Map &obj);
	Map::~Map();
	vector<Country> Map::getCountries();
	vector<Continent> Map::getContinents();

	void Map::setCountries(vector<Country> countries);
	void Map::setContinents(vector<Continent> continents);

	void Map::addCountry(Country c);
	void Map::addContinent(Continent c);

	void Map::editCountry(Country& coun);
	void Map::editContinent(Continent& cont);
private:
	vector<Country> countries;
	vector<Continent> continents;
};

#endif