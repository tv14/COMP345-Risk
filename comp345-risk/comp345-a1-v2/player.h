// dummy player object, will most likely be implemented properly in the future by another team member

#include <string>

#ifndef PLAYER_H
#define PLAYER_H
class player {
private:
	std::string name;
public:
	player(std::string n); // constructor must be supplied a name for the player
	std::string getname();
};
#endif