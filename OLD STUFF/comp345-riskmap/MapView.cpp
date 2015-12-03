#include "stdafx.h"
#include "MapView.h"
#include <iostream>
#include <vector>

using namespace std;

MapView::MapView() {

}

MapView::MapView(Map* m) {
	_subject = m;
	_subject->Attach(this);
}

MapView::~MapView() {
	_subject->Detach(this);
}

void MapView::Update() {
	display();
}

//Prints out useful information about the countries and continents
void MapView::display() {
	vector<Country> countries = _subject->getCountries();
	vector<Continent> continents = _subject->getContinents();
	if (countries.size() > 0) {
		cout << "Countries:" << endl;
		for (Country& c : countries) {
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
		cout << "No countries to show." << endl;
	}

	cout << "Continents:" << endl;
	for (Continent& c : continents) {
		cout << c.getContinentName() << endl;
	}
}