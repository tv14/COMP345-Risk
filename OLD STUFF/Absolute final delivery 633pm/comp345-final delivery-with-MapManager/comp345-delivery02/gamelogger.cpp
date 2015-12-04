/* 
 * Gamelogger implementation. THE WAY IT WORKS IS THIS:
 * Driver prompts the user for input. Whenever something meaningful happens, e.g. user attacks another country,
 * the text output is forwarded to a stringstream within the driver. In this way, the stringstream is built up
 * throughout the phase.
 * At the end of the phase, the driver calls notify(), passing the stringstream as a string. the string is then passed
 * all the way to the game logger, which can use the string to print the game's output to a file, log.txt.
 * Note that the logger only retains "useful" information for following the gameplay, and ignores things like actual input
 * prompts or invalid input notifications.
 */

#include "gamelogger.h"
#include <iostream>
#include <fstream>

gamelogger::gamelogger() {
}

/** 
 * the constructor to be used. creates this gamelogger as an observer of parameter s and
 * automatically attaches this gamelogger to s.
 */
gamelogger::gamelogger(driver* s) {
	subject = s;
	subject->Attach(this);

	log.open("log.txt"); // upon creation, open a file: log.txt
}

// detach self upon deletion
gamelogger::~gamelogger() {
	subject->Detach(this);
	log.close(); // don't forget to close the log
}

void gamelogger::Update() {
	// nothing
}

// getting called directly via update() means there are no decorators surrounding the logger: print to log right away
void gamelogger::update(std::string str, std::string playername, std::string phasename) {
	printtolog(str);
}

// getting called via innerupdate means there are decorators surrounding this game logger:
// both conditions must be true to print to log.
void gamelogger::innerupdate(std::string str, std::string playername, std::string phase, bool playerOK, bool phaseOK) {
	//std::cout << "(innermost innerupdate has been called. checking to see if conditions were met...)" << std::endl;
	if (playerOK && phaseOK)
		printtolog(str);
}

void gamelogger::printtolog(std::string str) {
	//std::cout << "(conditions were met, printing to log...)" << std::endl;
	log << str << std::endl;
}

void gamelogger::printself() {
	std::cout << "-> the base logger." << std::endl;
}