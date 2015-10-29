#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>
#include "Country.h"

using namespace std;

class Continent {
public:

	Continent::Continent();
	Continent::Continent(string name);
	Continent::Continent(const Continent &c);
	Continent::~Continent();
	string Continent::getContinentName();
	vector< string > Continent::getCountries();
	int Continent::getNumCountries();

	void Continent::setContinentName(string name);
	void Continent::setCountries(vector< string > list);
	void Continent::addCountry(string c);

private:

	string continentName;
	vector< string > countries;

};

#endif