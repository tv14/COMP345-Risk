// Zachary Eugenio, 26518257
// COMP 345 assignment 3, part 4: Game Logger

#include "player.h"
#include "driver.h"
#include "MapManager.h"

#include <iostream>

using namespace std;

int main() {
	cout << "[running program.]\n" << endl;
        
        // testmap.map is a simple map with two adjacent countries, c1 and c2. c1 will go to player1 and c2 to player2, so use that to test victory conditions.
	MapManager* manager = new MapManager("testmap");
	manager->loadMap();
	if (manager->isValid()) {
		cout << "Map file is valid!" << endl;
	}

	// fill the driver's country and continents list, based on the map loaded above.
	vector<Continent>continents = manager->getContinents();
	vector<Country>countries = manager->getCountries();
	
	// create the driver, assign its game logger.
	driver *gamedriver = new driver(continents, countries);

	// run the game loop and let it run its course.
	gamedriver->run();

	cout << "\n[end of program. Press enter to exit.]";
	cin.get();
	return 0;
}
