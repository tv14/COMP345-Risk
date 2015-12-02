// driver class implementation.

#include "driver.h"
#include "logger.h"
#include "gamelogger.h"
#include "playerlogger.h"
#include "phaselogger.h"
#include "Fortification.h"
#include "Continent.h"
#include "Reinforcement.h"
#include "SelectandBattle.h"

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
void driver::reinforce(Player& p) {
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
		notify(phaselog.str(), p.getPlayerName(), "reinforcement");
		return;
	}

	// otherwise, select number of armies to move and execute
	else {
		Reinforcement rein(p, countries, continents, cardcounter);
		rein.calculateReinforcement();
		rein.calculateCardsReinforcement();
		phaselog << rein.ReinforcementPhase();
		notify(phaselog.str(), p.getPlayerName(), "reinforcement");		
	}
}

/* Function for Attack phase. Asks the player if they wish to attack any countries, and if yes,
lets them choose which country to attack with. param p is a reference to the player whose turn it is. */
void driver::attack(Player& p) {
	stringstream phaselog;

	cout << "--Attack Phase--" << endl;
	phaselog << "--Attack Phase--" << endl;
	cout << "Enter anything to initiate an attack (leave blank to skip): ";
	string target = "";
	getline(cin, target);

	// skip attack if left blank
	if (target.empty()) {
		cout << "Skipping attack phase.\n" << endl;
		phaselog << "Skipping attack phase." << endl;
		notify(phaselog.str(), p.getPlayerName(), "attack");
		return;
	}

	// otherwise, attack the other country
	else {
		SelectandBattle newbattle(p, countries);
		phaselog << newbattle.AttackPhase();

		notify(phaselog.str(), p.getPlayerName(), "attack");
	}
}

/* Function for Fortification phase. Lets the player choose to move armies from one of their owned
countries to another. param p is a reference to the player whose turn it is. */
void driver::fortify(Player& p) {
	string source;
	string target;
	stringstream phaselog;

	cout << "--Fortification Phase--" << endl;
	phaselog << "--Fortification Phase--" << endl;
	cout << "Do you want to fortify a country (leave blank to skip, input anything to continue): ";

	string input = "";
	getline(cin, input);
	target = input;

	// skip fortify if left blank
	if (input.empty()) {
		cout << "Skipping fortification phase.\n" << endl;
		phaselog << "Skipping fortification phase.\n" << endl;
		notify(phaselog.str(), p.getPlayerName(), "fortification");
		return;
	}

	//Fortification(p,countries,countries length)
	//3 methods .setmovingfrom, .setmovingto , .movearmy
	Fortification fort(p, countries);
	fort.setMovingFrom();
	fort.setMovingTo();
	phaselog << fort.moveArmy();
		

	cout << "Ending fortification phase.\n" << endl;

	phaselog << "Ending fortification phase." << endl;
	notify(phaselog.str(), p.getPlayerName(), "fortification");

	return;
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
	Player firstplayer("player1"), secondplayer("player2");
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

	// map loaded here

	Continent cont1("cont1"), cont2("cont2");
	cont1.setArmyBonus(3);
	cont2.setArmyBonus(2);
	continents.push_back(cont1);
	continents.push_back(cont2);


	Country c0,c1,c2,c3,c4;
	countries.push_back(c0);
	countries.push_back(c2);
	countries.push_back(c3);
	countries.push_back(c4);
	countries.push_back(c1);

	continents[0].addCountry("c0");
	continents[0].addCountry("c1");
	continents[0].addCountry("c2");
	continents[0].addCountry("c3");
	continents[0].addCountry("c4");

	countries[0].setAll(playerlist[0], 5, "c0", "cont1");//name and continent determined during map creation, owner and army size determined during pregame setup.
	countries[1].setAll(playerlist[0], 10, "c1", "cont1");
	countries[2].setAll(playerlist[0], 15, "c2", "cont1");
	countries[3].setAll(playerlist[1], 10, "c3", "cont1");
	countries[4].setAll(playerlist[1], 20, "c4", "cont2");

	countries[0].addConnection(countries[1]);//determined during map creation
	countries[0].addConnection(countries[2]);
	countries[1].addConnection(countries[2]);
	countries[1].addConnection(countries[3]);
	countries[2].addConnection(countries[3]);
	countries[2].addConnection(countries[4]);
	countries[3].addConnection(countries[4]);
	

	//stringstream logsetupstream;
	string logsetupinput = "";
	cout << "\nGAME LOGGER SETUP:" << endl;
	cout << "\n==Player logging==" << endl;
	cout << "Enter the name of a player to log (leave empty to skip): ";
	getline(cin, logsetupinput);

	if (logsetupinput.empty()) {
		cout << "\nSkipping log setup: using default settings (log all)." << endl;
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

	vector<Player>::iterator it = playerlist.begin(); // iterator is placed at beginning of playerlist
	while (playerlist.size() > 1) {
		cout << "===" << it->getPlayerName() << "\'s turn===\n" << endl;
		stringstream currentturn;
		currentturn << "===" << it->getPlayerName() << "\'s turn===" << endl;
		notify(currentturn.str(), it->getPlayerName(), "turnindicator");

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
	cout << "\nCongratulations, " << playerlist[0].getPlayerName() << " wins the game!" <<endl;
	stringstream winner;
	winner << "\nCongratulations, " << playerlist[0].getPlayerName() << " wins the game!" << endl;
	notify(winner.str(), playerlist[0].getPlayerName(), "endgame");
}

// for debug
void driver::printobservers() {
	for (list<Observer*>::iterator it = _observers->begin(); it != _observers->end(); ++it) {
		(*it)->printself();
	}
}