/** 
 * COMP 345: RISK
 * 
 * authors:
 * 
 * Zachary Eugenio	26518257
 */

#include "player.h"
#include "driver.h"

#include <iostream>

int main() {
	std::cout << "[running program.]\n" << std::endl;
	
	// create the driver, assign its game logger.
	driver *gamedriver = new driver();

	// run the game loop and let it run its course.
	gamedriver->run();

	std::cout << "\n[end of program. Press enter to exit.]";
	std::cin.get();
	return 0;
}
