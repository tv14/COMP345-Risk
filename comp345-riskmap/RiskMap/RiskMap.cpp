// RiskMap.cpp : Uses the Continent and Country classes to create a map upon which the game of Risk can be played
//

#include "stdafx.h"
#include "Continent.h"
#include "Country.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<Country> countries{};
vector<Continent> continents{};

//Creates a new continent and adds it to the continent vector
void makeNewCont(string contName) {
	Continent newCont;

	newCont.setContinentName(contName);
	continents.push_back(newCont);
	cout << "Created continent " << contName << endl;
}

//Creates a new country and adds it to the country vector
void makeNewCoun(string counName, string contName) {
	Country newCoun;

	newCoun.setName(counName);
	newCoun.setContinent(contName);

	//Create adjacency between existing countries
	string addConn = "N";

	if (countries.size() > 0) {
		do {
			string adjCoun = "";
			cout << "Which country is " << counName << " adjacent to?" << endl;
			getline(cin, adjCoun);
			for (Country& c : countries) {
				if (c.getName() == adjCoun) {
					newCoun.addConnection(c);
					cout << adjCoun << " now adjacent to " << counName << endl;
				}
			}
			if (countries.size() > 1) {
				cout << "Is " << counName << " adjacent to any other countries? (Y/N)" << endl;
				getline(cin, addConn);
			}
		} while (addConn == "Y");
	}

	//Add country to continent object it belongs to
	for (Continent& cont : continents) {
		if (cont.getContinentName() == contName) {
			cont.addCountry(newCoun.getName());
			cout << "Added " << newCoun.getName() << " to " << cont.getContinentName() << endl;
		}
	}
	countries.push_back(newCoun);
}

int main()
{
	int menuOp = 1;

	do {
		string counName = "";
		string contName = "";
		string menuInput = "";

		//If no continents exist, prompt user to create one
		if (continents.size() == 0) {
			cout << "Name the first continent:" << endl;
			getline(cin, contName);
			makeNewCont(contName);
		}

		//Display action menu
		cout << "Select an action using the action #:" << endl;
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
			cout << "Created country " << counName << " in continent " << contName << endl;
			break;
		case 3: //Prints out all existing countries and some info about them
			for (Country& c : countries) {
				cout << "Name: " << c.getName() << " | Continent: " << c.getContinent() << endl;
				cout << "Adjacent to: ";
				for (string s : c.getConnections()) {
					cout << s << endl;
				}
			}
			break;
		case 4: //Prints out all existing continents and some info about them
			for (Continent& c : continents) {
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

	return 0;
}
