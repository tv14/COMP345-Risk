#include "stdafx.h"
#include "Country.h"
#include "Continent.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Default constructor
Country::Country()
{
}

//Creates a country with a name
Country::Country(string name, string cont) : name(name), continent(cont)
{
}

//Copy constructor
Country::Country(const Country & obj)
{
	name = obj.name;
	connections = obj.connections;
	owner = obj.owner;
	armyCount = obj.armyCount;
	continent = obj.continent;
}

//Destructor
Country::~Country()
{
}

//Returns the name of the country
string Country::getName()
{
	return name;
}

//Sets the name of the country
void Country::setName(string name)
{
	this->name = name;
}

//Returns the list of countries that are adjacent to this
vector<string> Country::getConnections()
{
	return connections;
}

//Receive a list of countries adjacent to this, and the count
void Country::setConnections(vector<string> conns)
{
	connections = conns;
}

//Return the number of armies in this country
int Country::getArmyCount()
{
	return armyCount;
}

//Receive the number of armies in this country
void Country::setArmyCount(int a)
{
	armyCount = a;
}

//Return the number of countries adjacent to this
int Country::getNumConns()
{
	return connections.size();
}

//Return the name of the player who owns this country
string Country::getOwner()
{
	return owner;
}

//Set the owner of this country
void Country::setOwner(string o)
{
	owner = o;
}

//Return the continent this country belongs to
string Country::getContinent()
{
	return this->continent;
}

//Set the continent this country belongs to
void Country::setContinent(string cont)
{
	this->continent = cont;
}

//Check whether this country is adjacent to the passed country and return T/F
bool Country::isAdjacent(string& c)
{
	bool found = false;
	if (find(connections.begin(), connections.end(), c) != connections.end()) {
		found = true;
	}
	return found;
}

//Add a new country to the list of adjacent countries
void Country::addConnection(Country &conn)
{
	connections.push_back(conn.getName());
	if (!conn.isAdjacent(name)) {
		conn.addConnection(*this);
	}
}
