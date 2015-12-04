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

MapView::MapView(vector<Country>& countries, vector<Continent>& continents) {
	Map m = Map(countries, continents);
	_subject = &m;
	_subject->Attach(this);
}

MapView::~MapView() {
	_subject->Detach(this);
}

void MapView::Update() {
	printself();
}

//do nothing method to avoid compile errors about inheritance
void MapView::update(string str, string playername, string phasename) {

}

//Prints out useful information about the countries and continents
void MapView::printself() {
	vector<Country> countries = _subject->getCountries();
	vector<Continent> continents = _subject->getContinents();
	if (countries.size() > 0) {
		cout << "Countries:" << endl;
		for (Country& c : countries) {
			cout << c.getName() << " belongs to " << c.getContinent() << ", is owned by ";
			if (c.getOwner() != nullptr)
				cout << c.getOwner();
			else
				cout << "nobody";
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
		cout << c.getContinentName() << " contains ";
		for (Country& cou : c.getCountries()) {
			cout << cou.getName() << ", ";
		}
		cout << "is owned by ";
		if (c.getOwner() != nullptr)
			cout << c.getOwner();
		else
			cout << "nobody";
		cout << ", gives a bonus of " << c.getArmyBonus() << " armies, and can be captured with " << c.getCaptureCount() << " countries. " << endl;
	}
}