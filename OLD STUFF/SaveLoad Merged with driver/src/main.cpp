// Zachary Eugenio, 26518257
// COMP 345 assignment 1, part 2: Game Driver

#include "Player.h"
#include "driver.h"
#include "Continent.h"
#include "Country.h"
#include "Battle.h"
#include"Fortification.h"
#include "SelectandBattle.h"
#include <iostream>
#include <ctime>

#include <string>

using namespace std;

int main() {
	srand(time(0)); 
	cout << "[running program.]\n" << endl;
	
	// create the driver.
	
	driver gamedriver = driver();

	// run the game loop and let it run its course.
	gamedriver.run();

	cout << "\n[end of program. Press enter to exit.]";
	cin.get();
	return 0;
}
