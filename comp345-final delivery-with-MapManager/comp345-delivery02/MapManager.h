/*
 * MapManager.h
 *
 *  Created on: Nov 23, 2015
 *      Author: mouadbouras
 */

#ifndef SRC_MAPMANAGER_H_
#define SRC_MAPMANAGER_H_
#include <String>
#include <vector>
#include <iostream>
#include <fstream>
#include "Country.h"
#include "Continent.h"
#include "Map.h"

using namespace std;

class MapManager {
public:
	MapManager();
	MapManager(string map_file_name); // Class constructor that takes a filename
	virtual ~MapManager();

	vector<string> loadMap();
	void saveMap();
	void saveMap(string filename);

	int getTerritoryIdByName( string territory);
	vector<string> getAdjacents(int index);
	string validateTerritories();
	string validateContinents();
	string validateSettings();
	string validateMap();
	bool isValid();

	void setMapSettings(string image, string wrap , string scroll , string author , string warn);

	void addContinent(string continent_name , string capture_count);
    void addTerritory(string name , string x , string y , string continent , string adjacent );


	void setMapFileName(string file_name);

	void setMapSettings(vector<string*> map_settings);      // Mutators
	void setMapContinents(vector<string*> map_continents);
	void setMapTerritories(vector<string*> map_territories);

	string getMapFileName();
	vector<string*> getMapSettings();   // Accessors
	vector<string*> getMapContinents();
	vector<string*> getMapTerritories();

	//============martin's part=================

	vector<Continent> getContinents();
	vector<Country> getCountries();
	Map getMap();

	void setContinents(vector<Continent> c);
	void setCountries(vector<Country> c);
	void setMap(Map m);

private: // class elements.
	string map_file_name;

	vector<string*> map_settings;
	vector<string*> map_continents;
	vector<string*> map_territories;

	vector<Country> countries; // countries are territories
	vector<Continent> continents;

	void populateCountryVector();
	void populateContinentVector();
	void populateAdjacencies();
	//Country* getCountryByName(string name);


	Map map;



};

inline void MapManager::setMapFileName(string file_name){
	this->map_file_name = file_name;
}

inline void MapManager::setMapSettings(vector<string*> map_settings){
	this->map_settings = map_settings;
}     // Mutators
inline void MapManager::setMapContinents(vector<string*> map_continents)
{
	this->map_continents = map_continents;
}
inline void MapManager::setMapTerritories(vector<string*> map_territories){
	this->map_territories = map_territories;
}

inline string MapManager::getMapFileName(){
	return map_file_name;
}
inline vector<string*> MapManager::getMapSettings()   // Accessors
{
	return map_settings;
}
inline vector<string*> MapManager::getMapContinents(){
	return map_continents;
}
inline vector<string*> MapManager::getMapTerritories(){
	return map_territories;
}

//========== martin's additions =================

inline vector<Continent> MapManager::getContinents()
{
	if (continents.size() == 0)
		populateContinentVector();
	return continents;
}

inline vector<Country> MapManager::getCountries()
{
	if (countries.size() == 0)
		populateCountryVector();
	return countries;
}
inline Map MapManager::getMap() {
	return map;
}

inline void MapManager::setContinents(vector<Continent> c)
{
	continents = c;
}

inline void MapManager::setCountries(vector<Country> c)
{
	countries = c;
}

inline void MapManager::setMap(Map m) {
	map = m;
}



#endif /* SRC_MAPMANAGER_H_ */
