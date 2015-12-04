// driver class implementation.

#include "driver.h"

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
    // NOTE: user input prompt is currently redundant, since there are already
    // text prompts in the SelectAndBattle class, to be included later.

	cout << "--Reinforcement Phase--" << endl;
	cout << "Select country to reinforce (leave blank to skip): ";
	string input = "";
	getline(cin, input);

	// skip reinforcement if left blank
	if (input.empty()) {
		cout << "Skipping reinforcement phase.\n" << endl;
		return;
	}

	// otherwise, select number of armies to move and execute
	else {
		while (true) {
			int armies;
			cout << "Reinforcing " << input << "." << endl; 

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
			// p.reinforce(target, armies);

			// continue reinforcing, or move on to next phase (if number of armies permits)
			// if (armiesleft <= 0) return;
			cout << "Select another country to reinforce (leave blank to end): ";
			getline(cin, input); // re-using same string variable as above

			if (input.empty()) {
				cout << "Ending reinforcement phase.\n" << endl;
				return;
			}
		}
	}
}

/* Function for Attack phase. Asks the player if they wish to attack any countries, and if yes,
lets them choose which country to attack with. param p is a reference to the player whose turn it is. */
void driver::attack(player& p) {
	cout << "--Attack Phase--" << endl;
	cout << "Select a country to attack (leave blank to skip): ";
	string target = "";
	getline(cin, target);

	// skip attack if left blank
	if (target.empty()) {
		cout << "Skipping attack phase.\n" << endl;
		return;
	}

	// otherwise, attack the other country
	else {
		while (true) {
			cout << "Select attacking country: ";
			string attacker = "";
			getline(cin, attacker);

			cout << "Attacking " << target << " with " << attacker << ". [implemented separately]" << endl;
			// p.attack(attacker, target);

			cout << "Select another country to attack (leave blank to end): ";
			getline(cin, target);

			if (target.empty()) {
				cout << "Ending attack phase.\n" << endl;
				return;
			}
		}
	}
}

/* Function for Fortification phase. Lets the player choose to move armies from one of their owned
countries to another. param p is a reference to the player whose turn it is. */
void driver::fortify(player& p) {
	string source;
	string target;

	cout << "--Fortification Phase--" << endl;
	cout << "Select which country to fortify (leave blank to skip): ";

	string input = "";
	getline(cin, input);
	target = input;

	// skip fortify if left blank
	if (input.empty()) {
		cout << "Skipping fortification phase.\n" << endl;
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
		// p.fortify(source, target, armies);

		cout << "Ending fortification phase.\n" << endl;
		return;
	}
}

/* The function run() contains the game loop: it is to be called once in the program's
main method, after which it will run until the game is over. */
void driver::run() {
	cout << "Welcome to the Game Driver test program.\n" <<
	"========================================" << endl;

	// =====================================
	// stage 1: startup phase
	// =====================================

	// select number of players
	string input = "";
	
	while (true) {
		cout << "Please choose the number of players for this game (minimum 2): ";
		getline(cin, input);
		
		stringstream stream(input);
		
		if (stream >> numberofplayers) {
			if (stream.eof() && numberofplayers >= 2)
				break; // good number of players
		}
		cout << "\nInvalid input." << endl;
	}

	cout << "\nUnderstood. This match will have " << numberofplayers << " players.\n" << endl;
	
	// fill the playerlist with user-chosen names
	for (int i = 1; i <= numberofplayers; ++i) {
		string name = "";
		cout << "Choose player " << i << "\'s name: ";
		getline(cin, name);
		player temp = player(name);
		playerlist.push_back(temp);
	}

	// name players to make sure they are all correctly listed in playerlist
	cout << "\nPlayers in this match:" << endl;
	for (vector<player>::iterator it = playerlist.begin(); it != playerlist.end(); ++it) {
		cout << it->getname() << endl;
	}

	// map loading
	string filename = "";
	cout << "\nPlease specify which map to load for this match: ";
	getline(cin, filename);
	cout << "[implemented separately]";
	// loadmap();
	cout << "\nMap loaded." << endl;

	cout << "\nAssigning starting countries to players..." << endl;
	cout << "[implemented separately]";
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
}