// Zachary Eugenio, 26518257
// COMP 345 assignment 1, part 2: Game Driver
// note: Some parts are to be implemented separately. These parts have been denoted as such.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "player.h"

using namespace std;

// turns a string into its lowercase equivalent and returns it. not necessary in this program,
// but may be needed in the final project (for string comparison purposes).
string lowercase(string str) {
	string lowercasestr = str;
	for (unsigned int i = 0; i < lowercasestr.length(); ++i) {
		lowercasestr[i] = tolower(lowercasestr[i]);
	}

	return lowercasestr;
}

// free functions used in main phase:

// gives the user the option to reinforce one of their countries
// param p is the player whose turn it is
void reinforce(player& p) {
	// p.givearmies(); // grant armies at start of turn, implemented separately

	cout << "--Reinforcement Phase--" << endl;
	cout << "Select country to reinforce (leave blank to skip): ";
	string input = "";
	getline(cin, input);

	// skip reinforcement if left blank
	if (input.empty()) {
		cout << "Skipping reinforcement phase." << endl;
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

				cout << "\nInvalid input." << endl;
			}

			cout << "Sending " << armies << " armies.\n[implemented separately]\n" << endl;
			// p.reinforce(target, armies);

			// continue reinforcing, or move on to next phase (if number of armies permits)
			// if (armiesleft <= 0) return;
			cout << "Select next target (leave blank to end): ";
			getline(cin, input); // re-using same string variable as above

			if (input.empty()) {
				cout << "Ending reinforcement phase.\n" << endl;
				return;
			}
		}
	}
}

// asks the player if they wish to launch any attacks on adjacent countries
// (adjacency is verified separately)
// param p is the player whose turn it is
void attack(player& p) {
	cout << "--Attack Phase--" << endl;
	cout << "Select a country to attack (leave blank to skip): ";
	string target = "";
	getline(cin, target);

	// skip attack if left blank
	if (target.empty()) {
		cout << "Skipping attack phase." << endl;
		return;
	}

	// otherwise, attack the other country
	else {
		while (true) {
			cout << "Select attacking country: ";
			string attacker = "";
			getline(cin, attacker);

			cout << "Attacking " << target << " with " << attacker << "." << endl;
			// p.attack(attacker, target);
			cout << "[implemented separately]" << endl;

			cout << "\nSelect next country to attack (leave blank to end): ";
			getline(cin, target);

			if (target.empty()) {
				cout << "Ending attack phase.\n" << endl;
				return;
			}
		}
	}
}

// lets the player move their armies between the countries they own
// param p is the player whose turn it is
void fortify(player& p) {
	string source;
	string target;

	cout << "--Fortification Phase--" << endl;
	cout << "Select which country to send fortifications from (leave blank to skip): ";

	string input = "";
	getline(cin, input);
	source = input;

	// skip fortify if left blank
	if (source.empty()) {
		cout << "Skipping fortification phase." << endl;
		return;
	}

	else {
		while (true) {
			cout << "Next, select which country to move the armies to: ";
			getline(cin, input);
			target = input;

			int armies;
			while (true) {
				cout << "Enter valid number of armies to send: ";
				getline(cin, input);

				stringstream stream(input); // place the input in a separate stream
				if (stream >> armies) {
					if (stream.eof() && armies > 0) // if stream was a proper number greater than 0 (e.g. not 4fff*&d34)
						break; // input is all right
				}

				cout << "\nInvalid input." << endl;
			}

			cout << "Sending " << armies << " armies from " << source << " to " << target << "." << endl;
			// p.fortify(source, target, armies);
			cout << "[implemented separately]" << endl;

			// continue fortifying, or end the turn
			cout << "\nSelect next country to send armies from (leave blank to skip): ";
			getline(cin, source);

			// end turn if left blank
			if (source.empty()) {
				cout << "Ending fortification phase." << endl;
				return;
			}
		}
	}
}

int main() {
	// to begin, create a vector of player objects that will serve to store all players in the game

	vector<player> playerlist;

	cout << "Welcome to the Game Driver test program.\n" <<
		"========================================" << endl;
	
	// =====================================
	// stage 1: startup phase
	// =====================================

	// select number of players
	int numberofplayers;
	string input = "";

	while (true) {
		cout << "Please choose the number of players for this game (minimum 2): ";
		getline(cin, input);
		
		stringstream stream(input);
		
		if (stream >> numberofplayers) {
			if (stream.eof() && numberofplayers >= 1)
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
		player temp(name);
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
		cout << "\n===" << it->getname() << "\'s turn===\n" << endl;

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

	cout << "\n[end of program. Press enter to exit.]";
	cin.get();
	return 0;
}
