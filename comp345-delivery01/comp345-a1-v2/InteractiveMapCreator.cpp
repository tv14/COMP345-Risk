/*
*
*  Author: Mouad Bouras
*  Number: #27671083
*  InteractiveMapCreator.cpp class definition.
*  Assignment 2 "Save/Load"
*
*/



#include <iostream>
#include "MapManager.h"

using namespace std;

void cin_clear() {
	cin.ignore(10000000000, '\n');
}

string tolower(string str) {
	int i = 0;
	char c;
	while (str[i])
	{
		c = str[i];
		putchar(tolower(c));
		i++;
	}
	return str;
}

void logYN(string* value) {
	bool valid = false;
	*value = tolower(*value);
	do {
		cin >> *value;
		cin_clear();
		if (*value == "y" || *value == "yes")
		{
			*value = "yes";
			valid = true;

		}
		else if (*value == "n" || *value == "no")
		{
			*value = "no";
			valid = true;
		}
		else {

			cout << "Please answer with Y/N : ";
		}
	} while (!valid);

}

void logInt(string* value) {
	bool valid = false;
	do {
		try {
			cin >> *value;
			cin_clear();

			stoi(*value);
			if (stoi(*value) >= 1) {
				valid = true;
			}
			else {
				cout << "Please enter a positive integer value : ";
			}
		}
		catch (invalid_argument)
		{
			cout << "Please enter a positive integer value : ";
		}
	} while (!valid);

}

void logValues(string* value, int allowedCount, string* firstAllowed)
{
	bool valid = false;
	//*value = tolower(*value);
	do {
		cin >> *value;
		cin_clear();


		for (int i = 0; i<allowedCount; i++)
		{
			if (*value == firstAllowed[i])
			{
				*value = firstAllowed[i];
				valid = true;
			}
		}
		if (!valid)
		{
			cout << "Please enter one of the options suggested : ";
		}

	} while (!valid);

}

void addMapSettings(MapManager* manager) {
	//---------------------map settings section ---------------------------
	string map_settings[5];
	string input_limitation[5];

	cout << "First, lets start with your name : ";
	getline(cin, map_settings[3]);


	cout << endl << "Now, what should this map be called ? : ";
	getline(cin, map_settings[0]);


	cout << endl << "Does this map wrap around? (like our planet) Y/N : ";
	logYN(&map_settings[1]);

	cout << endl << "Does this map allow scrolling? (horizontal, vertical or none) : ";
	input_limitation[0] = "horizontal";
	input_limitation[1] = "vertical";
	input_limitation[2] = "none";
	logValues(&map_settings[2], 3, input_limitation);

	cout << endl << "Do you want to allow the map to display warnings? Y/N : ";
	logYN(&map_settings[4]);

	cout << endl << "We're done with map settings! " << endl << endl;


	manager->setMapSettings(map_settings[0], map_settings[1], map_settings[2], map_settings[3], map_settings[4]);

}

void addContinents(MapManager* manager) {
	//--------------------- continents section ---------------------------

	string count, continentName, continentCaptureCount;
	int intCount;


	cout << "Now onto continents, How many continents is your map going to have? :  ";
	logInt(&count);

	intCount = stoi(count);

	for (int i = 0; i < intCount; i++)
	{
		cout << "Enter a name for continent " << i + 1 << " :  ";
		cin >> continentName;
		cin_clear();

		cout << "Enter continent capture count: ";
		logInt(&continentCaptureCount);

		manager->addContinent(continentName, continentCaptureCount);
	}


	cout << endl << "We're done with Continents!! " << endl << endl;
}

void addTerritories(MapManager* manager) {
	//--------------------- Territory section ---------------------------

	string territory[5];
	string count = "";
	int intCount = 0;


	cout << "Now onto territories, How many territories is your map going to have? :  ";
	logInt(&count);

	intCount = stoi(count);

	for (int i = 0; i < intCount; i++)
	{
		cout << "Enter a name for territory " << i + 1 << " :  ";
		cin >> territory[0];
		cin_clear();

		cout << "Enter X coordinate value for territory " << i + 1 << " :  ";
		logInt(&territory[1]);

		cout << "Enter Y coordinate value for territory " << i + 1 << " :  ";
		logInt(&territory[2]);

		cout << "Enter continent of territory " << i + 1 << " :  ";
		cin >> territory[3];
		cin_clear();

		cout << "Enter adjacent territories of territory " << i + 1 << " (Separated by a comma ex: territory1, territory2, ...) :  ";
		getline(cin, territory[4]);

		manager->addTerritory(territory[0], territory[1], territory[2], territory[3], territory[4]);
	}

}

void interactiveMapCreation(MapManager* manager)
{

	cout << "Welcome to RISK's interactive map creation wizard!!" << endl;
	cout << "Lets get started!! " << endl << endl;

	addMapSettings(manager);
	addContinents(manager);
	addTerritories(manager);

}

int main() {

	bool startGame = false;

	cout << "Welcome to Team 6 Project Intermediate Build Demo. " << endl << endl;

	do {

		cout << "Would you like to load a map or create one? (type create/load) : ";
		string choice;
		string* allowed;
		allowed = new string[5];
		allowed[0] = "create";
		allowed[1] = "load";
		logValues(&choice, 2, allowed);
		MapManager* demo = new MapManager();

		if (choice == "create") {
			interactiveMapCreation(demo);
		}
		else if (choice == "load")
		{
			string mapname;
			bool exit = false;
			do
			{
				cout << "Enter your map file name (no need to write .map, type exit to go back) : ";
				getline(cin, mapname);
				if (mapname == "exit")
				{
					exit = true;
					break;
				}
				demo = new MapManager(mapname);
			} while (demo->loadMap() == 0);
			if (exit == true)
			{
				continue;
			}
		}

		cout << "The map file was loaded properly, would you like to Edit this map or Save it and start the game? (type edit/save) : ";
		allowed[0] = "edit";
		allowed[1] = "save";

		logValues(&choice, 2, allowed);

		if (choice == "save") {
			cout << "Verifying map" << endl;
			cout << demo->validateMap();
			cout << endl << "Saving map" << endl;
			demo->saveMap();
			if (choice == "save" && demo->isValid())
			{
				startGame = true;
			}
			else if (choice == "save" && !demo->isValid())
			{
				cout << "The loaded map file is not playable, Try loading a valid map. " << endl;
			}

		}
		else if (choice == "edit")
		{
			do
			{
				cout << "What would you like to modify? (Enter : settings,continents,territories or exit to save and quit) : ";
				allowed[0] = "settings";
				allowed[1] = "continents";
				allowed[2] = "territories";
				allowed[3] = "exit";
				logValues(&choice, 4, allowed);
				if (choice == "exit")
				{
					cout << "Verifying map" << endl;
					cout << demo->validateMap();
					cout << endl << "Saving map" << endl;
					demo->saveMap();
					break;
				}
				else if (choice == "settings")
				{
					addMapSettings(demo);
				}
				else if (choice == "continents")
				{
					addContinents(demo);
				}
				else if (choice == "territories") {
					addTerritories(demo);
				}

			} while (true);

			cout << "The map file was edited properly, would you like to start the game or load a new map?  (type start/load) : ";
			allowed[0] = "start";
			allowed[1] = "load";
			logValues(&choice, 2, allowed);
			if (choice == "start" && demo->isValid())
			{
				startGame = true;
			}
			else if (choice == "start" && !demo->isValid())
			{
				cout << "The loaded map file is not playable, Try loading a valid map. " << endl;
			}


		}
	} while (startGame == false);


	// GAME STARTS HERE
	cout << "Starting Game" << endl;


	return 0;
};
