#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "Observer.h"
#include "Map.h"
#include "Country.h"
#include "Continent.h"

using namespace std;

class MapView : public Observer {
public:
	MapView();
	MapView(Map* m);
	MapView(vector<Country>& countries, vector<Continent>& continents);
	~MapView();

	virtual void Update();
	virtual void update(std::string str, std::string playername, std::string phasename);
	void printself();
private:
	Map *_subject;
};

#endif