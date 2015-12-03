/*
 *
 * Mouad Bouras , 27671083
 * COMP 345 assignment 3
 *
 * MapAdapter.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: mouadbouras
 */

#include "MapAdapter.h"

using namespace std;

string MapAdapter::removeIndices(string str){
	str.erase(remove(str.begin(), str.end(), '{'), str.end());
	str.erase(remove(str.begin(), str.end(), '}'), str.end());
	str.erase(remove(str.begin(), str.end(), '['), str.end());
	str.erase(remove(str.begin(), str.end(), ']'), str.end());
	return str;
}

void MapAdapter::parseSettings(string settings){
	settings.erase(remove(settings.begin(), settings.end(), '\n'), settings.end());
	settings.erase(remove(settings.begin(), settings.end(), '\r'), settings.end());
	settings.erase(remove(settings.begin(), settings.end(), '\t'), settings.end());

	vector<string*> map_settings ;
	  string* setting ;
	  	  	 setting = new string[2];

	settings = removeIndices(settings);
	settings.erase(remove(settings.begin(), settings.end(), '"'), settings.end());

	settings = settings.substr(settings.find(":")+1);
	//cout << settings << endl;
	setting[0] =  settings.substr(0,settings.find(":"));
	settings = settings.substr(settings.find(":")+1);
	setting[1] = settings.substr(0,settings.find(","));
	settings = settings.substr(settings.find(",")+1);
	map_settings.push_back(setting);

	setting = new string[2];

	setting[0] =  settings.substr(0,settings.find(":"));
	settings = settings.substr(settings.find(":")+1);
	setting[1] = settings.substr(0,settings.find(","));
	settings = settings.substr(settings.find(",")+1);
	map_settings.push_back(setting);

	setting = new string[2];

	setting[0] =  settings.substr(0,settings.find(":"));
	settings = settings.substr(settings.find(":")+1);
	setting[1] = settings.substr(0,settings.find(","));
	settings = settings.substr(settings.find(",")+1);
	map_settings.push_back(setting);

	setting = new string[2];

	setting[0] =  settings.substr(0,settings.find(":"));
	settings = settings.substr(settings.find(":")+1);
	setting[1] = settings.substr(0,settings.find(","));
	settings = settings.substr(settings.find(",")+1);
	map_settings.push_back(setting);

	setting = new string[2];

	setting[0] =  settings.substr(0,settings.find(":"));
	settings = settings.substr(settings.find(":")+1);
	setting[1] = settings.substr(0,settings.find(","));
	settings = settings.substr(settings.find(",")+1);
	map_settings.push_back(setting);

	manager->setMapSettings(map_settings);
}

void MapAdapter::parseContinents(string continents){

	continents.erase(remove(continents.begin(), continents.end(), '\n'), continents.end());
	continents.erase(remove(continents.begin(), continents.end(), '\r'), continents.end());
	continents.erase(remove(continents.begin(), continents.end(), '\t'), continents.end());

	vector<string*> map_continents ;
	string* continent ;

	continents = removeIndices(continents);
	continents.erase(remove(continents.begin(), continents.end(), '"'), continents.end());

	continents = continents.substr(continents.find(":")+1);

	while( continents != "" )
	{
		continent = new string[2];

		continent[0] =  continents.substr(0, continents.find(":"));
		continents = continents.substr(continents.find(":")+1);

		continent[1] =  continents.substr(0, continents.find(","));
		continents = continents.substr(continents.find(",")+1) ;

		map_continents.push_back(continent);

		if (continents == continents.substr(continents.find(",")+1)) // no comma last value.
		{
		  continent = new string[2];
		  continent[0] =  continents.substr(0, continents.find(":"));
		  continents = continents.substr(continents.find(":")+1);

		  continent[1] =  continents.substr(0, continents.find(","));
		  continents = continents.substr(continents.find(",")+1) ;

		  map_continents.push_back(continent);
		  break;
		}

	}

	manager->setMapContinents(map_continents);


}

void MapAdapter::parseTerritories(string territories ){

	territories.erase(remove(territories.begin(), territories.end(), '\n'), territories.end());
	territories.erase(remove(territories.begin(), territories.end(), '\r'), territories.end());
	territories.erase(remove(territories.begin(), territories.end(), '\t'), territories.end());

	vector<string*> map_territories ;
	string* territory ;

	territories = removeIndices(territories);
	territories = territories.substr(territories.find(":")+1);


	while( territories != "" )
	{
		territory = new string[5];

		territory[0] =  territories.substr(1, territories.find(",")-1);
		territories = territories.substr(territories.find(",")+1);

		territory[1] =  territories.substr(0, territories.find(","));
		territories = territories.substr(territories.find(",")+1) ;

		territory[2] =  territories.substr(0, territories.find(","));
		territories = territories.substr(territories.find(",")+1) ;

		territory[3] =  territories.substr(0, territories.find(","));
		territories = territories.substr(territories.find(",")+1) ;

		territory[4] =  territories.substr(0, territories.find('"'));
		map_territories.push_back(territory);

		if(territories.substr(territories.find('"')+1) == "") //last itteration
		{
			break;
		}

		territories = territories.substr(territories.find('"')+1) ;
		territories = territories.substr(territories.find('"')) ;

	}

	manager->setMapTerritories(map_territories);

}

MapAdapter::MapAdapter(MapManager* mm){
		this->manager = mm;
	}

vector<string> MapAdapter::loadJSONMap(){
	  fstream inout;
	  string currentLine;
	  string strSettings ="";
	  string strContinents="";
	  string strTerritories="";
	  int lineCounter = 0;
	  vector<string> myMap;

	  ifstream ifile(manager->getMapFileName()+".json");
	  if (ifile) {
		  inout.open(manager->getMapFileName()+".json", ios::in);
	  }
	  else
	  {
		  cout << "File doesn't Exist." << endl;
		  return myMap;

	  }

	  int section = 1;
	  int curlyCount=0;
	  for(int i=0; !inout.eof(); i++){

		  getline(inout,currentLine);
		  currentLine.erase(currentLine.find_last_not_of(" \n\r\t")+1);

		  myMap.push_back(currentLine);

		  if (currentLine.length() > 0)
		  {
			if(currentLine.compare(0,1,"{") == 0 ){
				curlyCount++;
			}
			if(currentLine.compare(currentLine.size()-1,1,"}") == 0){
				curlyCount--;
			}
			if(section==1 )
			{
			  strSettings += currentLine;
			}

			if(section==2 )
			{
			  strContinents += currentLine;
			}

			if(section==3)
			{
			  strTerritories += currentLine;
			}
			if(curlyCount == 0){
				section ++;
			}
		    	  lineCounter++;
		  }

		}
	  parseSettings( strSettings);
	  parseContinents( strContinents);
	  parseTerritories( strTerritories);

		return myMap;

}

void MapAdapter::saveJSONMap(){
	saveJSONMap(manager->getMapFileName());
}

void MapAdapter::saveJSONMap(string filename){

	fstream inout;
	inout.open(filename+".json", ios::out);

	inout << "{\"Map\" : " << endl;
	inout << "{[" << endl;

	for (int i = 0 ; i < manager->getMapSettings().size() ; i++)
	{
		inout << '"' << manager->getMapSettings().at(i)[0] << '"' << ":" << '"' << manager->getMapSettings().at(i)[1] << '"';
		if(i != manager->getMapSettings().size()-1 )
		{
			inout << "," << endl;
		}
	}
	inout << endl << "]}" << endl;
	inout << '}' << endl;

	inout << "{\"Continents\" :" << endl;
	inout << "{[" << endl;

	for (int i = 0 ; i < manager->getMapContinents().size() ; i++)
	{
		inout << '"'<< manager->getMapContinents().at(i)[0] << '"' << ":" << manager->getMapContinents().at(i)[1] ;

		if(i != manager->getMapContinents().size()-1 )
		{
			inout << "," << endl;
		}
	}

	inout << endl << "]}" << endl;
	inout << '}' << endl;



	inout << "{\"Territories\" : " << endl;
	inout << "{[" << endl;
	for (int i = 0 ; i < manager->getMapTerritories().size() ; i++)
	{
		inout << '"' << manager->getMapTerritories().at(i)[0] << "," << manager->getMapTerritories().at(i)[1] << "," << manager->getMapTerritories().at(i)[2] << "," << manager->getMapTerritories().at(i)[3] << "," << manager->getMapTerritories().at(i)[4] << '"' ;
		if(i != manager->getMapTerritories().size()-1 )
		{
			inout << "," << endl;
		}
	}

	inout << endl << "]}" << endl;
	inout << '}' << endl;


	inout.close();
}

