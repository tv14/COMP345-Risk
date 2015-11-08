#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "stdafx.h"
#include "Observer.h"
#include "Map.h"
#include "Country.h"
#include "Continent.h"

using namespace std;

class MapView : public Observer {
public:
	MapView();
	MapView(Map* m);
	~MapView();

	void Update();
	void display();
private:
	Map *_subject;
};

#endif