#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "game_of_life.h"
using namespace std;

int main() {

	srand(time(nullptr));

	game_of_life the_game;

	bool dalje;

	cout << "Dalje (1/0): ";
	cin >> dalje;

	while (dalje) {

		system("cls");

		the_game.sljedeca_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;

	}
	
	return 0;
}
