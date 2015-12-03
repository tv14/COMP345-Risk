/*
 * MapManager.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: mouadbouras
 */

#include "MapManager.h"

#include <cctype>

using namespace std;

string tolowercase(string str){
	int i = 0;
	char c;
	while (str[i])
	{
		c = str[i];
		str[i] = tolower(c);
		i++;
	}
	return str;
}

MapManager::MapManager(string map_file_name)
{
	this->map_file_name = map_file_name;

}

MapManager::MapManager() {
	// TODO Auto-generated constructor stub
	map_file_name = "unsaved_map.map";


}


void MapManager::setMapSettings(string image, string wrap , string scroll , string author , string warn)
{
	this->map_settings.clear();

	string* settings;

	settings = new string[2];

	settings[0] = "image";
	settings[1] = image;
	map_settings.push_back(settings);

	settings = new string[2];

	settings[0] = "wrap";
	settings[1] = wrap;
	map_settings.push_back(settings);

	settings = new string[2];

	settings[0] = "scroll";
	settings[1] = scroll;
	map_settings.push_back(settings);

	settings = new string[2];

	settings[0] = "author";
	settings[1] = author;
	map_settings.push_back(settings);

	settings = new string[2];

	settings[0] = "warn";
	settings[1] = warn;
	map_settings.push_back(settings);
}

void MapManager::addContinent(string continent_name , string capture_count)
{
		string* continent;
		continent = new string[2];

		continent[0] = continent_name;
		continent[1] = capture_count;

		this->map_continents.push_back(continent);
}

void MapManager::addTerritory(string name , string x , string y , string continent , string adjacent )
   {
		string* territory;
		territory = new string[5];

		territory[0] = name;
		territory[1] = x;
		territory[2] = y;
		territory[3] = continent;
		territory[4] = adjacent;

		this->map_territories.push_back(territory);

   }

vector<string> MapManager::loadMap(){
	  fstream inout;
	  string currentLine;
	  int lineCounter = 0;
	  vector<string> myMap;

	  ifstream ifile(map_file_name+".map");
	  if (ifile) {
		  inout.open(map_file_name+".map", ios::in);
	  }
	  else
	  {
		  cout << "File doesn't Exist." << endl;
		  return myMap;

	  }

	  int section = 0;
	  for(int i=0; !inout.eof(); i++){

		  getline(inout,currentLine);
		  currentLine.erase(currentLine.find_last_not_of(" \n\r\t")+1);

		  myMap.push_back(currentLine);
		  string* setting ;
		  	  	 setting = new string[2];
		  string* continent ;
		  	  	 continent = new string[2];
		  string* territory;
		  	  	 territory = new string[5];

		  if (currentLine.length() > 0)
		  {

			if(currentLine.compare( 0, 12 ,"[Map]") == 0 )
			{
				 section = 1;
				 continue;
			}
			 if(currentLine.compare( 0, 12 ,"[Continents]") == 0 )
			 {
				 section = 2;
				 continue;
			 }
			 if(currentLine.compare( 0, 13 ,"[Territories]") == 0 )
			 {
				 section = 3;
				 continue;

			 }

		      if(section==1 )
		      {
		    	  setting[0] = currentLine.substr(0,currentLine.find("="));
		    	  setting[1] = currentLine.substr(currentLine.find("=")+1);
		          map_settings.push_back(setting);

		      }

		      if(section==2 )
		      {
		    	  continent[0] = currentLine.substr(0,currentLine.find("="));
				  continent[1] = currentLine.substr(currentLine.find("=")+1);
		    	  map_continents.push_back(continent);
		      }

		      if(section==3)
		      {
		    	  territory[0] = currentLine.substr(0,currentLine.find(","));
		    	  currentLine = currentLine.substr(currentLine.find(",")+1);

		    	  territory[1] = currentLine.substr(0,currentLine.find(","));
		    	  currentLine = currentLine.substr(currentLine.find(",")+1);

		    	  territory[2] = currentLine.substr(0,currentLine.find(","));
		    	  currentLine = currentLine.substr(currentLine.find(",")+1);

		    	  territory[3] = currentLine.substr(0,currentLine.find(","));
		    	  currentLine = currentLine.substr(currentLine.find(",")+1);

		    	  territory[4] = currentLine;
		    	  map_territories.push_back( territory);
		      }
		    	  lineCounter++;
		  }
		}
		return myMap;
}

void MapManager::saveMap(){
	saveMap(this->map_file_name);
}

void MapManager::saveMap(string filename){

	fstream inout;
	inout.open(filename+".map", ios::out);

	inout << "[Map]" << endl;
	for (int i = 0 ; i < getMapSettings().size() ; i++)
	{
		inout << getMapSettings().at(i)[0] << "=" << getMapSettings().at(i)[1]  << endl;
	}

	inout << endl << "[Continents]" << endl;
	for (int i = 0 ; i < getMapContinents().size() ; i++)
	{
		inout << getMapContinents().at(i)[0] << "=" << getMapContinents().at(i)[1]  << endl;
	}

	inout << endl << "[Territories]" << endl;
	for (int i = 0 ; i < getMapTerritories().size() ; i++)
	{
		inout << getMapTerritories().at(i)[0] << "," << getMapTerritories().at(i)[1] << "," << getMapTerritories().at(i)[2] << "," << getMapTerritories().at(i)[3] << "," << getMapTerritories().at(i)[4] << endl;
	}

	inout.close();
}

int MapManager::getTerritoryIdByName( string territory)
	{
		int count = 0 ;
		int index = 0 ;
		for (int i=0 ; i < getMapTerritories().size() ; i++ )
		{
			if(getMapTerritories().at(i)[0] == territory)
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

vector<string> MapManager::getAdjacents(int index){

		string adjacentsStr = getMapTerritories().at(index)[4];
		int adjacentCount = 0;

		while(adjacentsStr.find(",") < adjacentsStr.length() )
		{
			adjacentCount++;
			adjacentsStr = adjacentsStr.substr(adjacentsStr.find(",")+1);
		}
		if (adjacentsStr.length() > 0){
			adjacentCount++;
		}

		//numAdjacents = adjacentCount; //sets global variable so other methods can iterate through adjacent countries
		adjacentsStr = getMapTerritories().at(index)[4];
		vector<string> adjacents ;// = new string[adjacentCount+1];
		//adjacents[0] = to_string(adjacentCount);
		string tmpStr;
		for(int i = 1 ; i <= adjacentCount ; i++)
		{
			tmpStr = adjacentsStr.substr(0,adjacentsStr.find(","));
			tmpStr = tmpStr.erase(tmpStr.find_last_not_of(" \n\r\t")+1);
			tmpStr = tmpStr.erase(0,tmpStr.find_first_not_of(" \n\r\t"));
			adjacents.push_back(tmpStr);
		    adjacentsStr = adjacentsStr.substr(adjacentsStr.find(",")+1);
		}
		return adjacents;

	}

string MapManager::validateTerritories()
{
	string errorlog = "";

	if (getMapTerritories().size() > 255) {errorlog = errorlog + "Error : too many territories.\n";}

	string* currentTerritory ;
	vector<string> currentadjacents ;

	for(int i=0 ; i < getMapTerritories().size() ; i ++) // Looping through all territories
	{
		currentTerritory = getMapTerritories().at(i);

		if (getTerritoryIdByName(currentTerritory[0]) == -2){
			errorlog = errorlog + "Error : Duplicate territory " + currentTerritory[0] + ".\n";
		}

		try {
				stoi(currentTerritory[1]);
				stoi(currentTerritory[2]);
		}
		catch (invalid_argument)
		{
			errorlog = errorlog + "Error : Invalid X,Y coordinate values for territory " + currentTerritory[0] + ".\n" ;
		}

		bool validContinent = false;
		for(int k = 0 ; k < getMapContinents().size() ; k++)// Looping through countries and comparing them to current territory
		{
			if(currentTerritory[3] == map_continents[k][0]){
				validContinent = true;
			}
		}
		if (!validContinent){
			errorlog = errorlog + "Error : Invalid continent " + currentTerritory[3] + " for territory " + currentTerritory[0] + ".\n";
		}

		currentadjacents = getAdjacents(i);
		if (currentadjacents.size() > 10){
			errorlog = errorlog + "Error : Maximum adjacency surpassed by territory " + currentTerritory[0] + ".\n";
		}

		string* targetTerritory;
		vector<string> targetadjacents;

		for (int j = 0 ; j < currentadjacents.size()   ; j++) // Looping through adjacent territories of current territory
		{
			int targetIndex = getTerritoryIdByName(currentadjacents.at(j));
			if(targetIndex >= 0 && targetIndex <= getMapTerritories().size())
			{
				targetTerritory = getMapTerritories().at(targetIndex);
				targetadjacents = getAdjacents(targetIndex);
				//int targetadjacentsCount = stoi(targetadjacents[0]);
				bool adjacencyMatched = false;
				for(int m = 0 ; m < targetadjacents.size() ; m++)//looping through target territory adjacents
				{
					if(targetadjacents.at(m) == currentTerritory[0]){
						adjacencyMatched = true;
					}
				}
				if(!adjacencyMatched){
					errorlog = errorlog + "Error : Adjacency territory '" + currentadjacents.at(j) + "' of '" + currentTerritory[0] + "' not matched\n";
				}
			}
			else
			{
				errorlog = errorlog + "Error : Adjacency territory '" + currentadjacents.at(j) + "' of '" + currentTerritory[0] + "' not found\n" ;
			}
		}

	}
	return errorlog;
}

string MapManager::validateContinents(){
	string errorlog = "";

	if (getMapContinents().size() > 32){errorlog = errorlog + "Error : too many continents.\n";}


	for(int i=0 ; i < getMapContinents().size() ; i ++) // Looping through all territories
	{
		try {
				stoi(getMapContinents().at(i)[1]);

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

	if(getMapSettings().size() > 5)
	{
		errorlog += "Error : too many setting values.\n";
	}

	for (int i = 0 ; i < getMapSettings().size() ; i++)
	{
		if((tolowercase(getMapSettings().at(i)[0]) != "image") &&
		   (tolowercase(getMapSettings().at(i)[0]) != "wrap") &&
		   (tolowercase(getMapSettings().at(i)[0]) != "scroll") &&
		   (tolowercase(getMapSettings().at(i)[0]) != "author") &&
		   (tolowercase(getMapSettings().at(i)[0]) != "warn"))
		{
			errorlog += "Error : invalid setting "+ tolowercase(getMapSettings().at(i)[0]) +".\n";
		}

		if(    (tolowercase(getMapSettings().at(i)[0]) == "wrap" || tolowercase(getMapSettings().at(i)[0]) == "warn")
		    && (tolowercase(getMapSettings().at(i)[1]) != "yes" && tolowercase(getMapSettings().at(i)[1]) != "no" ))
		{
			errorlog += "Error : invalid value for setting "+ tolowercase(getMapSettings().at(i)[0]) +".\n";
		}

		if( tolowercase(getMapSettings().at(i)[0]) == "scroll" &&
				( tolowercase(getMapSettings().at(i)[1]) != "none" &&
				  tolowercase(getMapSettings().at(i)[1]) != "horizontal" &&
				  tolowercase(getMapSettings().at(i)[1]) != "vertical" ))
		{
			errorlog += "Error : invalid value for setting scroll.\n";
		}

	}
	return errorlog;
}

string MapManager::validateMap(){
	string str =  "";
	if(	validateSettings() != "")
	{
		str += "Setting errors : \n" + validateSettings() ;
	}
	if(	validateContinents() != "")
	{
		str += "Continent errors : \n" + validateContinents() ;
	}
	if(	validateTerritories() != "")
	{
		str += "Territory errors : \n" + validateTerritories() ;
	}
	  return str;
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

//===========================martin's additions ======================================





void MapManager::populateCountryVector() {

	vector<string> adjacents;
	Country newCountry;

	for (int i = 0; i < getMapTerritories().size(); i++) {
		newCountry = Country(getMapTerritories().at(i)[0], getMapTerritories().at(i)[3]);
		adjacents = getAdjacents(i);
		newCountry.setConnections(adjacents);
		countries.push_back(newCountry);
	}

	populateAdjacencies();
	map.setCountries(countries);
}

void MapManager::populateContinentVector() {
	Continent newContinent;

	for (int i = 0; i < getMapContinents().size(); i++) {
		newContinent = Continent(getMapContinents().at(i)[0]);
		newContinent.setCaptureCount(atoi(getMapContinents().at(i)[1].c_str()));
		continents.push_back(newContinent);
	}
	map.setContinents(continents);
}


void MapManager::populateAdjacencies(){

	for(Country &current : countries)
	{
		//cout << "Count : " << current.getConnections().size() << endl;
		for(string &adjacent : current.getConnections())
		{
			for(Country &c : countries)
			{
				if (c.getName() == adjacent)
				{
					current.addConnection(c);
				}
			}

		}
	}

}



MapManager::~MapManager() {
	// TODO Auto-generated destructor stub
}

