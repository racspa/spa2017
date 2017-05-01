#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;

	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << "Dalje (d-1/n-0): ";
		cin >> dalje;
	} while (dalje == true);

	return 0;
}