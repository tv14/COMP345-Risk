#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Continent.h"
#include "Country.h"

using namespace std;

class Map {
public:
	 Map();
	 Map(vector<Country>& countries, vector<Continent>& continents);
	 Map(const Map &obj);
	 ~Map();
	vector<Country>  getCountries();
	vector<Continent>  getContinents();

	void  setCountries(vector<Country>& countries);
	void  setContinents(vector<Continent>& continents);

	void  addCountry(Country& c);
	void  addContinent(Continent& c);

	void  editCountry(Country& coun);
	void  editContinent(Continent& cont);

	int  getNumCountriesOwned(Player* player);
	int  getNumReinforcements(Player* player);

private:
	vector<Country> countries;
	vector<Continent> continents;
};

#endif
