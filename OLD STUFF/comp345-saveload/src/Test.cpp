///*
// *
// *  Author: Mouad Bouras
// *  Number: #27671083
// *  Test.cpp test method.
// *  Assignment 1 "Save/Load"
// *
// */
//
//#include <iostream>
//#include "MapManager.h"
//
//using namespace std;
//
//int main() {
//
//	MapManager* nm = new MapManager();
//
//	nm->setMapSettings("world","no","no","Mouda","yes");
//
//	nm->addContinent("America" , "5" );
//	nm->addContinent("Africa" , "as" );
//	nm->addContinent("Australia" , "8" );
//	nm->addContinent("Asia" , "15" );
//	nm->addContinent("Europe" , "12" );
//
//
//	nm->addTerritory("Morocco","1","2","Africa","Algeria, Tunesia, Mauritania");
//	nm->addTerritory("Algeria","1","2","Africa","Morocco, Tunesia, Mauritania");
//	nm->addTerritory("Tunesia","1","2","Africa","Morocco, Algeria, Mauritania");
//	nm->addTerritory("Mauritania","1","2","Africa","Morocco, Algeria, Tunesia");
//
//
//	nm->addTerritory("France","1","2","Europe","Spain, Italy");
//	nm->addTerritory("Spain","1","2","Europe","France, Italy");
//	nm->addTerritory("Italy","1","2","Europe","Spain, France");
//
//	nm->addTerritory("Canada","1","2","America","US, Mexico, Argentina");
//	nm->addTerritory("US","1","2","America","Canada, Mexico, Argentina");
//	nm->addTerritory("Mexico","1","2","America","US, Canada, Argentina");
//	nm->addTerritory("Argentina","1","2","America","US, Mexico, Canada");
//
//
//		//                Testing Accessors
////
////		cout << "Map Image Name : " <<  nm->getMapSettings()[0][1] << endl;
////		cout << "Map Author : " << nm->getMapSettings()[3][1] << endl;
////
////		cout << "======== Continents ========" << endl ;
////		for (int i = 0 ; i < nm->getMapContinentCount() ; i ++)
////		{
////			cout << "Continent Name : " << nm->getMapContinents()[i][0] << endl
////			     << "Territories to capture : " <<  nm->getMapContinents()[i][1] << endl <<endl;
////		}
////
////		cout << "======== Territories ========" << endl ;
////
////
////		for (int i = 0 ; i < nm->getMapTerritoryCount() ; i ++)
////		{
////			cout << "Territory Name : " << nm->getMapTerritories()[i][0] << endl
////				 << " x : " <<  nm->getMapTerritories()[i][1] << " | y : " <<  nm->getMapTerritories()[i][2] << endl
////				 << " Continent : " <<  nm->getMapTerritories()[i][3] << " | Adjacent : " <<  nm->getMapTerritories()[i][4] << endl << endl;
////
////		}
//
//	cout << nm->validateTerritories() << endl;
//	cout << nm->validateContinents() << endl;
//
//	nm->saveMap("newMap.map");
//
////	MapManager* mm = new MapManager("mymap.map");
////	string *str = mm->loadMap();
////
////	string* adj ;
////
////	adj = mm->getAdjacents(0);
////	cout << "" << mm->validateTerritories() << endl;
////
////
////	mm->addContinent("Jamaica" , "5" );
////
////    mm->addTerritory( "vivian",  "10" , "20" , "link" , "DAT BOOTY,AINT,NO,GOOD" );
////   	mm->saveMap("risk.map");
//
//
////	int size = stoi(adj[0]);
////	for (int j = 0 ; j <= size  ; j++){
////		cout << adj[j] << endl;
////	}
////
////
////	//                Testing Accessors
////
////	cout << "Map Image Name : " <<  mm->getMapSettings()[0][1] << endl;
////	cout << "Map Author : " << mm->getMapSettings()[3][1] << endl;
////
////	cout << "======== Continents ========" << endl ;
////	for (int i = 0 ; i < mm->getMapContinentCount() ; i ++)
////	{
////		cout << "Continent Name : " << mm->getMapContinents()[i][0] << endl
////		     << "Territories to capture : " <<  mm->getMapContinents()[i][1] << endl <<endl;
////	}
////
////	cout << "======== Territories ========" << endl ;
////
////
////	for (int i = 0 ; i < mm->getMapTerritoryCount() ; i ++)
////	{
////		cout << "Territory Name : " << mm->getMapTerritories()[i][0] << endl
////			 << " x : " <<  mm->getMapTerritories()[i][1] << " | y : " <<  mm->getMapTerritories()[i][2] << endl
////			 << " Continent : " <<  mm->getMapTerritories()[i][3] << " | Adjacent : " <<  mm->getMapTerritories()[i][4] << endl << endl;
////
////	}
////
////	//                   Testing mutators
////
////	string** territories;
////	territories = new string*[3];
////
////	mm->setMapTerritoryCount(3);
////
////	territories[0] = new string[5];
////	territories[1] = new string[5];
////	territories[2] = new string[5];
////
////	territories[0][0] = "3P" ;
////	territories[0][1] = "184" ;
////	territories[0][2] = "111" ;
////	territories[0][3] = "Park";
////	territories[0][4] = "2L,4P,10TB";
////
////	territories[1][0] = "5RS";
////	territories[1][1] = "353";
////	territories[1][2] = "64";
////	territories[1][3] = "Right Side";
////	territories[1][4] = "10TB,6RS,4P";
////
////	territories[2][0] = "59LS";
////	territories[2][1] = "39";
////	territories[2][2] = "13";
////	territories[2][3] = "Left Side";
////	territories[2][4] = "10TB,8LS,1L";
////
////	mm->setMapTerritories(territories);
////
////
////	//    Saving the map with the modified territories to the output file.
////	mm->saveMap("risk.map");
//
//	return 0;
//
//}
