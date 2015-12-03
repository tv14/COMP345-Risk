// driver class implementation.

#include "driver.h"
#include "logger.h"
#include "gamelogger.h"
#include "playerlogger.h"
#include "phaselogger.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Default constructor
driver::driver() {
}

/* Function for Reinforcement phase. Player is given armies at the beginning of each of their turns,
and is asked if they wish to send any extras to their countries. param p is a reference to the player
whose turn it is. */
void driver::reinforce(player& p) {
	// p.givearmies(); // grant armies at start of turn, implemented separately

	stringstream phaselog; // add text to this log throughout the phase, then send to game logger at the end

	cout << "--Reinforcement Phase--" << endl;
	phaselog << "--Reinforcement Phase--" << endl;
	cout << "Select country to reinforce (leave blank to skip): ";
	string input = "";
	getline(cin, input);

	// skip reinforcement if left blank
	if (input.empty()) {
		cout << "Skipping reinforcement phase.\n" << endl;
		phaselog << "skipping reinforcement phase." << endl;
		notify(phaselog.str(), p.getname(), "reinforcement");
		return;
	}

	// otherwise, select number of armies to move and execute
	else {
		while (true) {
			int armies;
			cout << "Reinforcing " << input << "." << endl;
			phaselog << "Reinforcing " << input << "." << endl;

			while (true) {
				cout << "Enter valid number of armies to send: ";
				getline(cin, input);

				stringstream stream(input); // place the input in a separate stream
				if (stream >> armies) {
					if (stream.eof() && armies > 0) // if stream was a proper number greater than 0 (e.g. not 4fff*&d34)
						break; // input is all right
				}

				cout << "Invalid input." << endl;
			}

			cout << "Sending " << armies << " armies. [implemented separately]" << endl;
			phaselog << "Sending " << armies << " armies." << endl;
			// p.reinforce(target, armies);

			// continue reinforcing, or move on to next phase (if number of armies permits)
			// if (armiesleft <= 0) return;
			cout << "Select another country to reinforce (leave blank to end): ";
			getline(cin, input); // re-using same string variable as above

			if (input.empty()) {
				cout << "Ending reinforcement phase.\n" << endl;
				phaselog << "Ending reinforcement phase." << endl;
				notify(phaselog.str(), p.getname(), "reinforcement");
				return;
			}
		}
	}
}

/* Function for Attack phase. Asks the player if they wish to attack any countries, and if yes,
lets them choose which country to attack with. param p is a reference to the player whose turn it is. */
void driver::attack(player& p) {
	stringstream phaselog;

	cout << "--Attack Phase--" << endl;
	phaselog << "--Attack Phase--" << endl;
	cout << "Select a country to attack (leave blank to skip): ";
	string target = "";
	getline(cin, target);

	// skip attack if left blank
	if (target.empty()) {
		cout << "Skipping attack phase.\n" << endl;
		phaselog << "Skipping attack phase." << endl;
		notify(phaselog.str(), p.getname(), "attack");
		return;
	}

	// otherwise, attack the other country
	else {
		while (true) {
			cout << "Select attacking country: ";
			string attacker = "";
			getline(cin, attacker);

			cout << "Attacking " << target << " with " << attacker << ". [implemented separately]" << endl;
			phaselog << "Attacking " << target << " with " << attacker << "." << endl;
			// p.attack(attacker, target);

			cout << "Select another country to attack (leave blank to end): ";
			getline(cin, target);

			if (target.empty()) {
				cout << "Ending attack phase.\n" << endl;
				phaselog << "Ending attack phase." << endl;
				notify(phaselog.str(), p.getname(), "attack");
				return;
			}
		}
	}
}

/* Function for Fortification phase. Lets the player choose to move armies from one of their owned
countries to another. param p is a reference to the player whose turn it is. */
void driver::fortify(player& p) {
	stringstream phaselog;

	string source;
	string target;

	cout << "--Fortification Phase--" << endl;
	phaselog << "--Fortification Phase--" << endl;
	cout << "Select which country to fortify (leave blank to skip): ";

	string input = "";
	getline(cin, input);
	target = input;

	// skip fortify if left blank
	if (input.empty()) {
		cout << "Skipping fortification phase.\n" << endl;
		phaselog << "Skipping fortification phase." << endl;
		notify(phaselog.str(), p.getname(), "fortification");
		return;
	}

	else {
		cout << "Which country to move armies from?: ";
		getline(cin, input);
		source = input;

		int armies;
		while (true) {
			cout << "Enter valid number of armies to send: ";
			getline(cin, input);

			stringstream stream(input); // place the input in a separate stream
			if (stream >> armies) {
				if (stream.eof() && armies > 0) // if stream was a proper number greater than 0 (e.g. not 4fff*&d34)
					break; // input is all right
			}

			cout << "Invalid input." << endl;
		}

		cout << "Sending " << armies << " armies from " << source << " to " << target << ". [implemented separately]" << endl;
		phaselog << "Sending " << armies << " armies from " << source << " to " << target << "." << endl;
		// p.fortify(source, target, armies);
		
		cout << "Ending fortification phase.\n" << endl;
		phaselog << "Ending fortification phase." << endl;
		notify(phaselog.str(), p.getname(), "fortification");
	}
}

/* The function run() contains the game loop: it is to be called once in the program's
main method, after which it will run until the game is over. */
void driver::run() {
	cout << "Welcome to the Game Logger test program.\n" <<
	"========================================" << endl;

	// =====================================
	// stage 1: startup phase
	// =====================================

	// for the purpose of demonstration, two players are pre-initialized in playerlist.
	player firstplayer = player("player1");
	player secondplayer = player("player2");
	playerlist.push_back(firstplayer);
	playerlist.push_back(secondplayer);

	cout << "Game will have two players, player1 and player2." << endl;

	/**
	 * HOW TO SET UP GAME LOGGER:
	 * Once the players are established, you can select which players/phases you want to track.
	 * For tracking players:
	 *		Create a playerlogger decorator and pass the player's name, as a string. This is why the playerlist must be
	 *		esblished before you can choose which players to track. The names must be passed exactly as they are:
	 *		there is no case-correction applied.
	 * For tracking phases:
	 *		Create a phaselogger decorator and pass one of three phases, as strings: "reinforcement", "attack" or "fortification",
	 *		exactly as they are written, without quotes. The phases each call notify() with these exact arguments, and so the decorator
	 *		must match them to the letter in order for them to be recorded.
	 * Chaining decorators:
	 *		Decorators can be chained. For example, you can track player1 and also track their reinforcement + attack phases. Simply add
	 *		a playerlogger for "player1", a phaselogger for "reinforcement" and a phaselogger for "attack".
	 * On modifying the basic logger:
	 *		The basic logger simply logs everything. However, as soon as you add one decorator, it nullifies the entire logger, meaning
	 *		it will be set to track no phase and no player until you explicitly add them yourself. In other words, you will have either no
	 *		decorators, or *at least* two: one for the player, and one for the phase. Example: adding only a playerlogger for player1 and nothing
	 *		else will result in nothing being logged: you must also provide at least one phase to be logged, as well.
	 * Have fun logging!!!
	 */
	logger *log = new gamelogger(this);

	//stringstream logsetupstream;
	string logsetupinput = "";
	cout << "\nGAME LOGGER SETUP:" << endl;
	cout << "\n==Player logging==" << endl;
	cout << "Enter the name of a player to log (leave empty to skip): ";
	getline(cin, logsetupinput);

	if (logsetupinput.empty()) {
		cout << "Skipping log setup: using default settings (log all)." << endl;
	}

	else {
		while (true) {
			cout << "Adding player \"" << logsetupinput << "\" to the logger." << endl;
			log = new playerlogger(log, logsetupinput, this);

			cout << "Add next player (leave empty to continue): ";
			getline(cin, logsetupinput);

			if (logsetupinput.empty()) break;
		}

		cout << "\n==Phase logging==" << endl;
		cout << "Enter the name of the phase to log (choose from \"reinforcement\", \"attack\" and \"fortification\"): ";
		getline(cin, logsetupinput);

		while (true) {
			cout << "Adding phase \"" << logsetupinput << "\" to the logger." << endl;
			log = new phaselogger(log, logsetupinput, this);

			cout << "Add next phase (leave empty to end setup): ";
			getline(cin, logsetupinput);

			if (logsetupinput.empty()) break;
		}
	}

	cout << "\nLog setup complete. Stack of custom decorators:\n" << endl;

	printobservers();

	cout << "\nGame is ready.\n========================================" << endl;

	// =====================================
	// stage 2: main phase
	// =====================================
	// An iterator loops through playerlist until there is only one player remaining, who is then declared the winner.
	// For each player, go through reinforce, attack and fortify stages. Advance the iterator at the end of each turn.
	// note: in the actual game, there would likely be a certain number of turns that must pass before players are permitted to attack others.

	vector<player>::iterator it = playerlist.begin(); // iterator is placed at beginning of playerlist
	while (playerlist.size() > 1) {
		cout << "===" << it->getname() << "\'s turn===\n" << endl;
		stringstream currentturn;
		currentturn << "===" << it->getname() << "\'s turn===" << endl;
		notify(currentturn.str(), it->getname(), "turnindicator");

		// run through all phases
		reinforce(*it);
		attack(*it);
		fortify(*it);

		// after all phases, move to next player, or if end of playerlist has been reached, move back to beginning
		++it;
		if (it == playerlist.end()) it = playerlist.begin();
	}

	// reaching this point means there is only one player left, so they win the match
	// last player is declared winner
	cout << "\nCongratulations, " << playerlist[0].getname() << " wins the game!" <<endl;
	stringstream winner;
	winner << "\nCongratulations, " << playerlist[0].getname() << " wins the game!" << endl;
	notify(winner.str(), playerlist[0].getname(), "endgame");
}

// for debug
void driver::printobservers() {
	for (list<observer*>::iterator it = observers->begin(); it != observers->end(); ++it) {
		(*it)->printself();
	}
}