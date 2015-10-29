#include "stdafx.h"
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
vector< string > Continent::getCountries()
{
	return countries;
}

//Returns the number of countries in the continent
int Continent::getNumCountries()
{
	return countries.size();
}

//Sets the name of the continent
void Continent::setContinentName(string name)
{
	continentName = name;
}

//Sets the list of countries and the number of entries in the list
void Continent::setCountries(vector< string > list)
{
	countries = list;
}

//Adds a country to this continent
void Continent::addCountry(string c)
{
	countries.push_back(c);
}
