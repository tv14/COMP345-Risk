#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>
#include "Continent.h"

using namespace std;

class Country {
public:
	Country::Country();
	Country::Country(string name, string continent);
	Country::Country(const Country &obj);
	Country::~Country();
	string Country::getName();
	void Country::setName(string name);
	vector<string> Country::getConnections();
	void Country::setConnections(vector<string> conns);
	int Country::getArmyCount();
	void Country::setArmyCount(int a);
	void Country::addArmies(int add);
	void Country::removeArmies(int remove);
	int Country::getNumConns();
	string Country::getOwner();
	void Country::setOwner(string o);
	string Country::getContinent();
	void Country::setContinent(string cont);
	bool Country::isAdjacent(string& c);
	void Country::addConnection(Country &conn);

private:
	string name;
	vector<string> connections;
	string continent;
	string owner;
	int armyCount;
};

#endif