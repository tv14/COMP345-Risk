// RiskSave.cpp : Defines the entry point for the console application.
//
//
//#include "Continent.h"
//#include "Country.h"
//#include "Map.h"
//#include "Player.h"
//#include "GameDirector.h"
//#include "RiskGameBuilder.h"
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "creating directors n stuff" << endl;
//
//	GameDirector director;
//	GameBuilder* builder = new RiskGameBuilder;
//
//	director.setGameBuilder(builder);
//
//	Player p1 = Player("p1");
//	p1.setBattlesWon(2);
//	p1.setAI(false);
//	p1.setCurrentReinforcements(3);
//
//	Player p2 = Player("p2");
//	p2.setBattlesWon(3);
//	p2.setAI(true);
//	p2.setAiStrat("aggressive");
//	p2.setCurrentReinforcements(5);
//
//	vector<Player> players;
//	players.push_back(p1);
//	players.push_back(p2);
//
//	Continent con1 = Continent("con1");
//	con1.setArmyBonus(4);
//	con1.setCaptureCount(2);
//	con1.setOwner(&p1);
//
//	Country cou1 = Country("cou1", "con1");
//	cou1.setOwner(&p1);
//	cou1.setArmyCount(3);
//
//	Country cou2 = Country("cou2", "con1");
//	cou2.addConnection(cou1);
//	cou2.setOwner(&p2);
//	cou2.setArmyCount(4);
//
//	con1.addCountry(cou1);
//	con1.addCountry(cou2);
//
//	Map map = Map();
//	map.addContinent(con1);
//	map.setCountries(con1.getCountries());
//
//	string phase = "battle";
//	Player currPlayer = p1;
//
//	director.constructGame(map, currPlayer, players, phase);
//
//	Game* risk = director.getGame();
//
//	cout << "saving" << endl;
//	risk->save("test");
//
//	delete builder;
//	delete risk;
//	builder = NULL;
//	risk = NULL;
//
//	cout << "execution complete" << endl;
//
//	system("PAUSE");
//
//    return EXIT_SUCCESS;
//}

