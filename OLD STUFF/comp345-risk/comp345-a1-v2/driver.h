/* 
 * Driver class. Implements the entire game loop within itself, to be called once in the program's
 * main function with run().
 */

#include "player.h"
#include <vector>

#ifndef DRIVER_H
#define DRIVER_H
class driver {
private:
	int numberofplayers;
	std::vector<player> playerlist;
public:
	driver();
	void reinforce(player& p);
	void attack(player& p);
	void fortify(player& p);
	void run();
};
#endif