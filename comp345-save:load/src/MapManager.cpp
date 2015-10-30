/*
 *
 *  Author: Mouad Bouras
 *  Number: #27671083
 *  MapManager.cpp class implementation.
 *  Assignment 1 "Save/Load"
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
		this->map_file_name = map_file_name;
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
		settings = new string*[2];

		settings[0] = new string[2];
		settings[1] = new string[2];

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

		delete settings;

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

			this->map_continents = continent;
			this->map_continents_count++;
		    delete continent;

	}
    void MapManager::addTerritory(string name , string x , string y , string continent , string adjecent )
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
		territory[map_territories_count][4] = adjecent;

		cout << "" << endl;

		setMapTerritories( territory);
		this->map_territories_count++;

	    delete territory;
    }

	void MapManager::saveMap(string filename){

    	fstream inout;
		inout.open(filename, ios::out);

		inout << "[Map]" << endl;
		for (int i = 0 ; i < 5 ; i++)
		{
			inout << map_settings[i][0] << "=" << map_settings[i][1]  << endl;
		}

		inout <<  endl;

		inout << "[Continents]" << endl;
		for (int i = 0 ; i < map_continents_count ; i++)
		{
			inout << map_continents[i][0] << "=" << map_continents[i][1]  << endl;
		}

		inout <<  endl;

		inout << "[Territories]" << endl;
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

		  inout.open(map_file_name, ios::in);

		  for(mapSize ; !inout.eof(); mapSize++){
			  getline(inout,currentLine);
			  currentLine.erase(currentLine.find_last_not_of(" \n\r\t")+1);

			 if(currentLine.compare( 0, 12 ,"[Map") == 0 )
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



