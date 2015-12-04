/*
 *
 *  Author: Mouad Bouras
 *  Number: #27671083
 *  MapManager.h class definition.
 *  Assignment 2 "Save/Load"
 *
 */

#ifndef MAPMANAGER_H_
#define MAPMANAGER_H_
#include <String>
#include <vector>
#include "Country.h"
#include "Continent.h"
#include "Map.h"

using namespace std;

class MapManager{

public:
	MapManager(); // Default constructor
	MapManager(string map_file_name); // Class constructor that takes a filename

	string* loadMap(); //Method to load the Map from the .map file
	void saveMap();// Method to save map to current filename
	void saveMap(string fileName);// Method to save the map to "filename.map"


	void setMapSettings(string image, string wrap , string scroll , string author , string warn); // Method to override the setting of the loaded map
	void addContinent(string continent_name , string capture_count);// Method to add a continent to the loaded map.
    void addTerritory(string name , string x , string y , string continent , string adjecent ); // Method to add a Territory to the loaded map.

	void setMapFileName(string file_name);
    void setMapSettings(string** map_settings);      // Mutators
	void setMapContinents(string** map_continents);
	void setMapTerritories(string** map_territories);

	void setMapContinentCount(int map_continents_count);
	void setMapTerritoryCount(int map_territories_count);

	string** getMapSettings();   // Accessors
	string** getMapContinents();
	string** getMapTerritories();

	vector<Continent> getContinents();
	vector<Country> getCountries();
	Map getMap();

	void setContinents(vector<Continent> c);
	void setCountries(vector<Country> c);
	void setMap(Map m);

	int getMapContinentCount();
	int getMapTerritoryCount();

	int getTerritoryIdByName(string territory);
	string* getAdjacents(int index);

	string validateSettings();
	string validateContinents();
	string validateTerritories();
	string validateMap();
	bool isValid();

private: // class elements.
	string map_file_name;
	string** map_settings;
	string** map_continents;
	string** map_territories;
	int map_continents_count;
	int map_territories_count;

	vector<Country> countries;
	vector<Continent> continents;
	Map map;
	int numAdjacents;

	void populateCountryVector();
	void populateContinentVector();
};
#endif /* MYCLASS_H_ */
