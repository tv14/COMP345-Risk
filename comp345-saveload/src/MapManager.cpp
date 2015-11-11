/*
 *
 *  Author: Mouad Bouras
 *  Number: #27671083
 *  MapManager.cpp class implementation.
 *  Assignment 2 "Save/Load"
 *
 */
#include "MapManager.h"
#include <iostream>
#include <fstream>

using namespace std;

	MapManager::MapManager(){
		map_file_name = "unsaved_map.map";
		map_continents_count= 0;
		map_territories_count = 0;
	}

	MapManager::MapManager(string map_file_name){
		this->map_file_name = map_file_name + ".map";
		map_continents_count = 0;
		map_territories_count = 0 ;
	}

	string** MapManager::getMapSettings(){
		return map_settings;
	}
	string** MapManager::getMapContinents(){
		return map_continents;
	}
	string** MapManager::getMapTerritories(){
		return map_territories;
	}

	void  MapManager::setMapSettings(string** map_settings){
		this->map_settings = map_settings;
	}

	void  MapManager::setMapContinents(string** map_continents){
		this->map_continents = map_continents;
	}

	void  MapManager::setMapTerritories(string** map_territories){
		this->map_territories = map_territories;
	}

	void MapManager::setMapContinentCount(int map_continents_count)
	{
		this->map_continents_count = map_continents_count;
	}

	void MapManager::setMapTerritoryCount(int map_territories_count){
		this->map_territories_count = map_territories_count;
	}

	int MapManager::getMapContinentCount(){
		return map_continents_count;
	}
	int MapManager::getMapTerritoryCount(){
		return map_territories_count;
	}

	void MapManager::setMapSettings(string image, string wrap , string scroll , string author , string warn)
	{
		string** settings;
		settings = new string*[5];

		settings[0] = new string[2];
		settings[1] = new string[2];
		settings[2] = new string[2];
		settings[3] = new string[2];
		settings[4] = new string[2];


		settings[0][0] = "image";
		settings[0][1] = image;


		settings[1][0] = "wrap";
		settings[1][1] = wrap;

		settings[2][0] = "scroll";
		settings[2][1] = scroll;

		settings[3][0] = "author";
		settings[3][1] = author;

		settings[4][0] = "warn";
		settings[4][1] = warn;



		this->setMapSettings(settings);

		//delete settings;

	}
	void MapManager::addContinent(string continent_name , string capture_count)
	{
			string** continent;
			continent = new string*[map_continents_count + 1];
			if (map_continents_count > 0)
			{
				for(int i = 0 ; i < map_continents_count ; i++)
				{
					continent[i] = new string[2];

					continent[i][0] = map_continents[i][0];
					continent[i][1] = map_continents[i][1];
				}
			}

			continent[map_continents_count] = new string[2];
			continent[map_continents_count][0] = continent_name;
			continent[map_continents_count][1] = capture_count;

			//delete map_continents;
			setMapContinents(continent);
			this->map_continents_count++;
	}
    void MapManager::addTerritory(string name , string x , string y , string continent , string adjacent )
    {
		string** territory;
		territory = new string*[map_territories_count + 1];
		if (map_territories_count > 0)
		{
			for(int i = 0 ; i < map_territories_count ; i++)
			{
				territory[i] = new string[5];

				territory[i][0] = map_territories[i][0];
				territory[i][1] = map_territories[i][1];
				territory[i][2] = map_territories[i][2];
				territory[i][3] = map_territories[i][3];
				territory[i][4] = map_territories[i][4];

			}
		}

		territory[map_territories_count] = new string[5];

		territory[map_territories_count][0] = name;
		territory[map_territories_count][1] = x;
		territory[map_territories_count][2] = y;
		territory[map_territories_count][3] = continent;
		territory[map_territories_count][4] = adjacent;

		//cout << "" << endl;

	//	delete map_territories;
		setMapTerritories(territory);
		this->map_territories_count++;

	   // delete territory;

    }
	void MapManager::saveMap(){
		saveMap(this->map_file_name);
	}

	void MapManager::saveMap(string filename){

    	fstream inout;
		inout.open(filename, ios::out);

		inout << "[Map]" << endl;
		for (int i = 0 ; i < 5 ; i++)
		{
			inout << map_settings[i][0] << "=" << map_settings[i][1]  << endl;
		}


		inout << endl << "[Continents]" << endl;
		for (int i = 0 ; i < map_continents_count ; i++)
		{
			inout << map_continents[i][0] << "=" << map_continents[i][1]  << endl;
		}


		inout << endl << "[Territories]" << endl;
		for (int i = 0 ; i < map_territories_count ; i++)
		{
			inout << map_territories[i][0] << "," << map_territories[i][1] << "," << map_territories[i][2] << "," << map_territories[i][3] << "," << map_territories[i][4] << endl;
		}

		inout.close();

    }

	string* MapManager::loadMap(){

		  fstream inout;

		  string currentLine;

		  int mapSize = 0;
		  int lineCounter = 0;

		  bool settingsSection = false;
		  bool continentSection = false;
		  bool territorySection = false;

		  //inout.open(map_file_name, ios::in);

		  ifstream ifile(map_file_name);
		  if (ifile) {
			  inout.open(map_file_name, ios::in);
		  }
		  else
		  {
			  cout << "File doesn't Exist." << endl;
			  return 0;

		  }

		  for(mapSize ; !inout.eof(); mapSize++){
			  getline(inout,currentLine);
			  currentLine.erase(currentLine.find_last_not_of(" \n\r\t")+1);

			 if(currentLine.compare( 0, 12 ,"[Map]") == 0 )
			{
				bool settingsSection = true;
			    bool continentSection = false;
				bool territorySection = false;
			}
			 if(currentLine.compare( 0, 12 ,"[Continents]") == 0 )
			 {
				 settingsSection = false;
				 continentSection = true;
				 territorySection = false;
				 continue;
			 }
			 if(currentLine.compare( 0, 13 ,"[Territories]") == 0 )
			 {
				 settingsSection = false;
				 continentSection = false;
				 territorySection = true;
				 continue;
			 }


			 if(continentSection && (currentLine.length() > 0) )
			 {
				 map_continents_count++ ;
			 }
			 if(territorySection && (currentLine.length() > 0) )
			 {
				 map_territories_count++ ;
			 }
		  }
		  inout.close();


		  inout.open(map_file_name, ios::in);

		  string *myMap;
		  myMap = new string[mapSize];

		 map_settings = new string*[5];
		  for (int i = 0; i < 5; i++)
			  map_settings[i] = new string[2];

		 map_continents = new string* [map_continents_count];
		  for (int i = 0; i < map_continents_count; i++)
			  map_continents[i] = new string[2];

		 map_territories = new string* [map_territories_count];
		 for (int i = 0; i < map_territories_count; i++)
			 map_territories[i] = new string[5];


		  for(int i=0; i<mapSize; i++){
			  getline(inout,currentLine);
			  currentLine.erase(currentLine.find_last_not_of(" \n\r\t")+1);
			  if (currentLine.length() > 0){
				  myMap[lineCounter] = currentLine;

			      if(lineCounter > 0 && lineCounter < 6 )
			      {
			         map_settings[lineCounter-1][0] = currentLine.substr(0,currentLine.find("="));
			         map_settings[lineCounter-1][1] = currentLine.substr(currentLine.find("=")+1);

			      }
			      if(lineCounter > 6 && lineCounter < (7+map_continents_count) )
			      {
			    	  map_continents[lineCounter-7][0] = currentLine.substr(0,currentLine.find("="));
			    	  map_continents[lineCounter-7][1] = currentLine.substr(currentLine.find("=")+1);

			      }
			      if((lineCounter > (7+map_continents_count)) && (lineCounter <= (7+map_continents_count+map_territories_count)) )
			      {
			    	  map_territories[lineCounter-(8+map_continents_count)][0] =  currentLine.substr(0,currentLine.find(","));
			    	  currentLine = currentLine.substr(currentLine.find(",")+1);

			    	  map_territories[lineCounter-(8+map_continents_count)][1] =  currentLine.substr(0,currentLine.find(","));
			    	  currentLine = currentLine.substr(currentLine.find(",")+1);

			    	  map_territories[lineCounter-(8+map_continents_count)][2] =  currentLine.substr(0,currentLine.find(","));
			    	  currentLine = currentLine.substr(currentLine.find(",")+1);

			    	  map_territories[lineCounter-(8+map_continents_count)][3] =  currentLine.substr(0,currentLine.find(","));
			    	  currentLine = currentLine.substr(currentLine.find(",")+1);

			    	  map_territories[lineCounter-(8+map_continents_count)][4] =  currentLine;

			      }

			    	  lineCounter++;
			  }

			}

			//cout << mapSize << endl;

			return myMap;

	}

	int MapManager::getTerritoryIdByName( string territory)
	{
		int count = 0 ;
		int index = 0 ;
		for (int i=0 ; i < map_territories_count ; i++ )
		{
			if(map_territories[i][0] == territory)
			{
				index = i ;
				count++;
			}
		}
		if (count > 1)
		{
			return -2;
		}
		else if (count == 1)
		{
			return index;
		}
		else{
			return -1;
		}
	}

	string* MapManager::getAdjacents(int index){

		string adjacentsStr = map_territories[index][4];
		int adjacentCount = 0;

		while(adjacentsStr.find(",") < adjacentsStr.length() )
		{
			adjacentCount++;
			adjacentsStr = adjacentsStr.substr(adjacentsStr.find(",")+1);
		}
		if (adjacentsStr.length() > 0){
			adjacentCount++;
		}

		adjacentsStr = map_territories[index][4];
		string* adjacents = new string[adjacentCount+1];
		adjacents[0] = to_string(adjacentCount);
		string tmpStr;
		for(int i = 1 ; i <= adjacentCount ; i++)
		{
			tmpStr = adjacentsStr.substr(0,adjacentsStr.find(","));
			tmpStr = tmpStr.erase(tmpStr.find_last_not_of(" \n\r\t")+1);
			tmpStr = tmpStr.erase(0,tmpStr.find_first_not_of(" \n\r\t"));
			adjacents[i] = tmpStr;
		    adjacentsStr = adjacentsStr.substr(adjacentsStr.find(",")+1);
		}
		return adjacents;

	}

	string MapManager::validateTerritories(){
		string errorlog = "";

		if (map_continents_count > 32){errorlog = errorlog + "Error : too many continents.\n";}
		if (map_territories_count > 255) {errorlog = errorlog + "Error : too many territories.\n";}

		string* currentTerritory ;
		string* currentadjacents ;
		for(int i=0 ; i < map_territories_count ; i ++) // Looping through all territories
		{
			currentTerritory = map_territories[i];

			if (getTerritoryIdByName(currentTerritory[0]) == -2){
				errorlog = errorlog + "Error : Duplicate territory " + currentTerritory[0] + ".\n";
			}

			try {
					stoi(currentTerritory[1]);
					stoi(currentTerritory[2]);
			}
			catch (invalid_argument)
			{
				errorlog = errorlog + "Error : Invalid X,Y coordinate values for territory " + currentTerritory[0] ;
			}

			bool validContinent = false;
			for(int k = 0 ; k < map_continents_count ; k++)// Looping through countries and comparing them to current territory
			{
				if(currentTerritory[3] == map_continents[k][0]){
					validContinent = true;
				}
			}
			if (!validContinent){
				errorlog = errorlog + "Error : Invalid continent " + currentTerritory[3] + " for territory " + currentTerritory[0] + ".\n";
			}

			currentadjacents = getAdjacents(i);
			int size = stoi(currentadjacents[0]);
			if (size > 10){
				errorlog = errorlog + "Error : Maximum adjacency surpassed by territory " + currentTerritory[0] + ".\n";
			}
			string* targetTerritory;
			string* targetadjacents;

			for (int j = 1 ; j <= size  ; j++) // Looping through adjacent territories of current territory
			{
				int targetIndex = getTerritoryIdByName(currentadjacents[j]);
				if(targetIndex >= 0 && targetIndex <= map_territories_count)
				{
					targetTerritory = map_territories[targetIndex];
					targetadjacents = getAdjacents(targetIndex);
					int targetadjacentsCount = stoi(targetadjacents[0]);
					bool adjacencyMatched = false;
					for(int m = 1 ; m <= targetadjacentsCount ; m++)//looping through target territory adjacents
					{
						if(targetadjacents[m] == currentTerritory[0]){
							adjacencyMatched = true;
						}
					}
					if(!adjacencyMatched){
						errorlog = errorlog + "Error : Adjacency territory '" + currentadjacents[j] + "' of '" + currentTerritory[0] + "' not matched\n";
					}
				}
				else
				{
					errorlog = errorlog + "Error : Adjacency territory '" + currentadjacents[j] + "' of '" + currentTerritory[0] + "' not found\n" ;
				}
			}

		}


		return errorlog;
	}

	string MapManager::validateContinents(){
		string errorlog = "";

		for(int i=0 ; i < map_continents_count ; i ++) // Looping through all territories
		{
			try {
					stoi(map_continents[i][1]);
			}
			catch (invalid_argument)
			{
				errorlog = "Invalid Continent Capture Value";
			}
		}

		return errorlog;

		}

	string MapManager::validateSettings(){
		string errorlog = "";
		return errorlog;
	}

	string MapManager::validateMap(){
		return  "Setting errors : \n" +
				validateSettings() +
				"Continent errors : \n" +
				validateContinents() +
				"Territory errors : \n" +
				validateTerritories();
	}
	bool MapManager::isValid(){
		string str = validateSettings() + validateContinents() + validateTerritories();
		if ( str  == "")
		{
			return true;
		}
		{
			return false;
		}
	}
