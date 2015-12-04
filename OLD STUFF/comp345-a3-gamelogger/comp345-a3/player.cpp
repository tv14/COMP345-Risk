// player implementation

#include <string>
#include "player.h"

player::player(std::string n) : name(n) {
}

std::string player::getname() {
	return name;
}