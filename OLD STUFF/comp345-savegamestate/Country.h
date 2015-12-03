#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>
#include "Player.h"

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
	Player* Country::getOwner();
	void Country::setOwner(Player* o);
	string Country::getContinent();
	void Country::setContinent(string cont);
	bool Country::isAdjacent(string& c);
	void Country::addConnection(Country &conn);
	void Country::setAll(Player &o, int armycount, string& name, string& continent);
	vector<Country> Country::getConnectionsByCountry();
	void Country::setConnectionsByCountry(vector<Country> conns);
	string Country::toString();

private:
	string name;
	vector<string> connectionStrings;
	vector<Country> connectionsByCountry;
	string continent;
	Player* owner;
	int armyCount;
};

#endif