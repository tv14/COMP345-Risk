#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Country {
public:
	 Country();
	 Country(string name, string continent);
	 Country(const Country &obj);
	 ~Country();
	string  getName();
	void  setName(string name);
	vector<string>  getConnections();
	void  setConnections(vector<string> conns);
	int  getArmyCount();
	void  setArmyCount(int a);
	void  addArmies(int add);
	void  removeArmies(int remove);
	int  getNumConns();
	Player* getOwner();
	void  setOwner(Player* o);
	string  getContinent();
	void  setContinent(string cont);
	bool  isAdjacent(string& c);
	void  addConnection(Country &conn);
	void  setAll(Player &o, int armycount, string& name, string& continent);
	vector<Country>  getConnectionsByCountry();
	void  setConnectionsByCountry(vector<Country> conns);
	string  toString();

private:
	string name;
	vector<string> connectionStrings;
	vector<Country> connectionsByCountry;
	string continent;
	Player* owner;
	int armyCount;
};

#endif
