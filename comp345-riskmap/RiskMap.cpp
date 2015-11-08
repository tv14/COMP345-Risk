// RiskMap.cpp : Uses the Continent and Country classes to create a map upon which the game of Risk can be played
//

#include "stdafx.h"
#include "Continent.h"
#include "Country.h"
#include "MapView.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Map map;
MapView *mapView = new MapView(&map);

//Creates a new continent and adds it to the continent vector
void makeNewCont(string contName) {
	Continent newCont;

	newCont.setContinentName(contName);
	map.addContinent(newCont);
}

//Creates a new country and adds it to the country vector
void makeNewCoun(string counName, string contName) {
	Country newCoun;

	newCoun.setName(counName);
	newCoun.setContinent(contName);

	//Create adjacency between existing countries
	string addConn = "N";

	if (map.getCountries().size() > 0) {
		do {
			string adjCoun = "";
			cout << "Which country is " << counName << " adjacent to?" << endl;
			getline(cin, adjCoun);
			for (Country& c : map.getCountries()) {
				if (c.getName() == adjCoun) {
					newCoun.addConnection(c);
					map.editCountry(c);
				}
			}
			if (map.getCountries().size() > 1) {
				cout << "Is " << counName << " adjacent to any other countries? (Y/N)" << endl;
				getline(cin, addConn);
			}
		} while (addConn == "Y");
	}

	//Set owner and army size of country
	string owner = "";
	string armyInput = "";
	int armies = 0;
	cout << "Which player does " << counName << " belong to?" << endl;
	getline(cin, owner);
	newCoun.setOwner(owner);

	cout << "How many armies does " << counName << " have?" << endl;
	//Validates numerical input from user
	while (true) {
		getline(cin, armyInput);
		stringstream numStream(armyInput);
		if (numStream >> armies)
			break;
		cout << "Please try again using a valid number." << endl;
	}
	newCoun.setArmyCount(armies);

	//Add country to continent object it belongs to
	for (Continent& cont : map.getContinents()) {
		if (cont.getContinentName() == contName) {
			cont.addCountry(newCoun.getName());
		}
	}
	map.addCountry(newCoun);
}

int main()
{
	int menuOp = 1;

	do {
		string counName = "";
		string contName = "";
		string menuInput = "";

		//If no continents exist, prompt user to create one
		if (map.getContinents().size() == 0) {
			cout << "Name the first continent:" << endl;
			getline(cin, contName);
			makeNewCont(contName);
		}

		//Display action menu
		cout << "\nSelect an action using the action #:" << endl;
		cout << "1: Create new continent" << endl;
		cout << "2: Create new country" << endl;
		cout << "3: View countries" << endl;
		cout << "4: View continents" << endl;
		cout << "0: Exit" << endl;

		//Validates numerical input from user
		while (true) {
			getline(cin, menuInput);
			stringstream numStream(menuInput);
			if (numStream >> menuOp)
				break;
			cout << "Please try again using a valid number." << endl;
		}

		//Test user input and perform the requested action
		switch (menuOp) {
		case 1: //Creates new continent
			cout << "Name of new continent:" << endl;
			getline(cin, contName);
			makeNewCont(contName);
			break;
		case 2: //Creates new country
			cout << "Name of new country:" << endl;
			getline(cin, counName);
			cout << "Which continent does " << counName << " belong to?" << endl;
			getline(cin, contName);
			makeNewCoun(counName, contName); //Assumes valid continent input, TODO: FIX
			break;
		case 3: //Prints out all existing countries and some info about them
			if (map.getCountries().size() > 0) {
				for (Country& c : map.getCountries()) {
					cout << c.getName() << " belongs to " << c.getContinent() << ", is owned by ";
					if (!c.getOwner().empty())
						cout << c.getOwner();
					else
						cout << " nobody";
					cout << ", has " << c.getArmyCount() << " armies, and is adjacent to ";
					if (c.getNumConns() > 0) {
						for (string s : c.getConnections()) {
							cout << s << endl;
						}
					}
					else
						cout << "no other countries. " << endl;
				}
			}
			else {
				cout << "No countries to show. " << endl;
			}
			break;
		case 4: //Prints out all existing continents and some info about them
			for (Continent& c : map.getContinents()) {
				cout << "Name: " << c.getContinentName() << " # countries: " << c.getNumCountries() << endl;
				cout << c.getContinentName() << " contains: ";
				for (string s : c.getCountries()) {
					cout << s << endl;
				}
			}
			break;
		default:
			break;
		}
	} while (menuOp != 0);

	delete mapView;
	mapView = NULL;
	return 0;
}
