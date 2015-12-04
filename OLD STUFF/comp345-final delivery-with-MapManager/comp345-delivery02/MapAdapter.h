/*
 * Mouad Bouras , 27671083
 * COMP 345 assignment 3
 *
 * MapAdapter.h
 *
 *  Created on: Nov 26, 2015
 *      Author: mouadbouras
 */

#ifndef SRC_MAPADAPTER_H_
#define SRC_MAPADAPTER_H_
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "MapManager.h"

using namespace std;

class MapAdapter : public MapManager {

public:

	string removeIndices(string str);
	void parseSettings(string settings);
	void parseContinents(string continents);
	void parseTerritories(string territories );



	MapAdapter(MapManager* mm);

	vector<string> loadJSONMap();

	void saveJSONMap();
	void saveJSONMap(string filename);


	void setMapManager(MapManager* manager);


private:
	MapManager* manager ;


};

void inline MapAdapter::setMapManager(MapManager* mm){
	this->manager = mm;
}


#endif /* SRC_MAPADAPTER_H_ */
