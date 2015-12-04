/* 
 * Driver class. Implements the entire game loop within itself, to be called once in the program's
 * main function with run().
 */

#include "Player.h"
#include "subject.h"
#include "Continent.h"
#include "Country.h"
#include <vector>

#ifndef DRIVER_H
#define DRIVER_H
class driver : public Subject {
private:
	int numberofplayers;
	std::vector<Player> playerlist;
	vector<Country> countries;
	vector<Continent> continents;
	int cardcounter = 0;
public:
	driver();
	void reinforce(Player& p);
	void attack(Player& p);
	void fortify(Player& p);
	void run();

	void printobservers();
};
#endif