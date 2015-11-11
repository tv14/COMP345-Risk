// driver class implementation.

#include "driver.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

//========================================================
// a bunch of helper functions for map creation
//========================================================
void cin_clear(){
	cin.ignore(10000000000, '\n');
}

string tolower(string str){
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

void logYN(string* value){
	bool valid = false;
	*value = tolower(*value);
	do{
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
		else{

			cout << "Please answer with Y/N : ";
		}
	} while (!valid);

}

void logInt(string* value){
	bool valid = false;
	do{
		try {
			cin >> *value;
			cin_clear();

			stoi(*value);
			if (stoi(*value) >= 1){
				valid = true;
			}
			else{
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
	do{
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

void addMapSettings(MapManager* manager){
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

void addContinents(MapManager* manager){
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

void addTerritories(MapManager* manager){
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

void interactiveMapCreation(MapManager* manager){

	cout << "Welcome to RISK's interactive map creation wizard!!" << endl;
	cout << "Lets get started!! " << endl << endl;

	addMapSettings(manager);
	addContinents(manager);
	addTerritories(manager);

}

void mapCreationRun() {
	bool startGame = false;

	cout << "Welcome to Team 6 Project Intermediate Build Demo. " << endl << endl;

	do{

		cout << "Would you like to load a map or create one? (type create/load) : ";
		string choice;
		string* allowed;
		allowed = new string[5];
		allowed[0] = "create";
		allowed[1] = "load";
		logValues(&choice, 2, allowed);
		MapManager* demo = new MapManager();

		if (choice == "create"){
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

		if (choice == "save"){
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
				else if (choice == "territories"){
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
	cout << "Starting Gamee" << endl;
}
//=========================================================
// end
//=========================================================

// Default constructor
driver::driver() {
}

/* Function for Reinforcement phase. Player is given armies at the beginning of each of their turns,
and is asked if they wish to send any extras to their countries. param p is a reference to the player
whose turn it is. */
void driver::reinforce(Player& p) {
	// p.givearmies(); // grant armies at start of turn, implemented separately

	cout << "--Reinforcement Phase--" << endl;
	cout << "Select country to reinforce (leave blank to skip): ";
	string input = "";
	getline(cin, input);

	// skip reinforcement if left blank
	if (input.empty()) {
		cout << "Skipping reinforcement phase.\n" << endl;
		return;
	}

	// otherwise, select number of armies to move and execute
	else {
		while (true) {
			int armies;
			cout << "Reinforcing " << input << "." << endl; 

			while (true) {
				cout << "Enter valid number of armies to send: ";
				getline(cin, input);

				stringstream stream(input); // place the input in a separate stream
				if (stream >> armies) {
					if (stream.eof() && armies > 0) // if stream was a proper number greater than 0 (e.g. not 4fff*&d34)
						break; // input is all right
				}

				cout << "Invalid input." << endl;
			}

			cout << "Sending " << armies << " armies. [implemented separately]" << endl;
			// p.reinforce(target, armies);

			// continue reinforcing, or move on to next phase (if number of armies permits)
			// if (armiesleft <= 0) return;
			cout << "Select another country to reinforce (leave blank to end): ";
			getline(cin, input); // re-using same string variable as above

			if (input.empty()) {
				cout << "Ending reinforcement phase.\n" << endl;
				return;
			}
		}
	}
}

/* Function for Attack phase. Asks the player if they wish to attack any countries, and if yes,
lets them choose which country to attack with. param p is a reference to the player whose turn it is. */
void driver::attack(Player& p) {
	cout << "--Attack Phase--" << endl;
	cout << "Select a country to attack (leave blank to skip): ";
	string target = "";
	getline(cin, target);

	// skip attack if left blank
	if (target.empty()) {
		cout << "Skipping attack phase.\n" << endl;
		return;
	}

	// otherwise, attack the other country
	else {
		while (true) {
			cout << "Select attacking country: ";
			string attacker = "";
			getline(cin, attacker);

			cout << "Attacking " << target << " with " << attacker << ". [implemented separately]" << endl;
			// p.attack(attacker, target);

			cout << "Select another country to attack (leave blank to end): ";
			getline(cin, target);

			if (target.empty()) {
				cout << "Ending attack phase.\n" << endl;
				return;
			}
		}
	}
}

/* Function for Fortification phase. Lets the player choose to move armies from one of their owned
countries to another. param p is a reference to the player whose turn it is. */
void driver::fortify(Player& p) {
	string source;
	string target;

	cout << "--Fortification Phase--" << endl;
	cout << "Do you want to fortify a country (leave blank to skip, input anything to continue): ";

	string input = "";
	getline(cin, input);
	target = input;

	// skip fortify if left blank
	if (input.empty()) {
		cout << "Skipping fortification phase.\n" << endl;
		return;
	}

	else {
		//Fortification(p,countries,countries length)
		//3 methods .setmovingfrom(), .setmovingto(), .movearmy()
		Fortification fort(p, countries, 5);
		fort.setMovingFrom();
		fort.setMovingTo();
		fort.moveArmy();
		
		cout << "Ending fortification phase.\n" << endl;

		return;
	}
}

/* The function run() contains the game loop: it is to be called once in the program's
main method, after which it will run until the game is over. */
void driver::run() {
	cout << "Welcome to the Game Driver test program.\n" <<
	"========================================" << endl;

	// =====================================
	// stage 1: startup phase
	// =====================================

	/*	
	// select number of players
	string input = "";
	
	while (true) {
		cout << "Please choose the number of players for this game (minimum 2): ";
		getline(cin, input);
		
		stringstream stream(input);
		
		if (stream >> numberofplayers) {
			if (stream.eof() && numberofplayers >= 2)
				break; // good number of players
		}
		cout << "\nInvalid input." << endl;
	}

	cout << "\nUnderstood. This match will have " << numberofplayers << " players.\n" << endl;
	
	// fill the playerlist with user-chosen names
	for (int i = 1; i <= numberofplayers; ++i) {
		string name = "";
		cout << "Choose player " << i << "\'s name: ";
		getline(cin, name);
		Player temp = Player(name);
		playerlist.push_back(temp);
	}

	// name players to make sure they are all correctly listed in playerlist
	cout << "\nPlayers in this match:" << endl;
	for (vector<Player>::iterator it = playerlist.begin(); it != playerlist.end(); ++it) {
		cout << it->getPlayerName() << endl;
	}
	*/
	
	// create/save/load Map and set up the MapManager for this match
	mapmanager =  MapManager();

	// start here

	/*
	Player p1("A"), p2("B");
	playerlist.push_back(p1);
	playerlist.push_back(p2);
	
	continents[0].setContinentName("cont1");
	continents[1].setContinentName("cont2");

	countries[0].setAll(playerlist[0], 5, "c0", "cont1");//name and continent determined during map creation, owner and army size determined during pregame setup.
	countries[1].setAll(playerlist[0], 10, "c1", "cont1");
	countries[2].setAll(playerlist[0], 15, "c2", "cont1");
	countries[3].setAll(playerlist[1], 10, "c3", "cont1");
	countries[4].setAll(playerlist[1], 20, "c4", "cont2");

	continents[0].addCountry("c0");
	continents[0].addCountry("c1");
	continents[0].addCountry("c2");
	continents[0].addCountry("c3");
	continents[1].addCountry("c4");

	countries[0].addConnection(countries[1]);//determined during map creation
	countries[0].addConnection(countries[2]);
	countries[1].addConnection(countries[2]);
	countries[1].addConnection(countries[3]);
	countries[2].addConnection(countries[3]);
	countries[2].addConnection(countries[4]);
	countries[3].addConnection(countries[4]);
	*/

	//for map loading, loads the string, splits string, and then sets Country=string[0]...string[4].., for Country.addconection(string[5]+)
	// map loading
	string filename = "";
	cout << "\nPlease specify which map to load for this match: ";
	getline(cin, filename);
	cout << "[implemented separately]";
	// loadmap();
	cout << "\nMap loaded." << endl;

	cout << "\nAssigning starting countries to players..." << endl;

	/*
	for (int i = 0; i < countriescount; i++)
	{
		int temp = rand() % (playerlist.size() - 1);
		countries[countriescount].setOwner(playerlist[temp]);
	}
	*/

	cout << "\nGame is ready.\n========================================" << endl;

	// =====================================
	// stage 2: main phase
	// =====================================
	// An iterator loops through playerlist until there is only one player remaining, who is then declared the winner.
	// For each player, go through reinforce, attack and fortify stages. Advance the iterator at the end of each turn.
	// note: in the actual game, there would likely be a certain number of turns that must pass before players are permitted to attack others.

	vector<Player>::iterator it = playerlist.begin(); // iterator is placed at beginning of playerlist
	while (playerlist.size() > 1) {
		cout << "===" << it->getPlayerName() << "\'s turn===\n" << endl;

		// run through all phases
		
		reinforce(*it);
		attack(*it);
		fortify(*it);

		// after all phases, move to next player, or if end of playerlist has been reached, move back to beginning
		++it;
		if (it == playerlist.end()) it = playerlist.begin();
	}

	// reaching this point means there is only one player left, so they win the match
	// last player is declared winner
	cout << "\nCongratulations, " << playerlist[0].getPlayerName() << " wins the game!" <<endl;
}