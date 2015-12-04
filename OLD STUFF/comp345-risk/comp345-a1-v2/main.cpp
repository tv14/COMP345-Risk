// Zachary Eugenio, 26518257
// COMP 345 assignment 1, part 2: Game Driver

#include "player.h"
#include "driver.h"

#include <iostream>

using namespace std;

int main() {
	cout << "[running program.]\n" << endl;
	
	// create the driver.
	driver gamedriver = driver();

	// run the game loop and let it run its course.
	gamedriver.run();

	cout << "\n[end of program. Press enter to exit.]";
	cin.get();
	return 0;
}
