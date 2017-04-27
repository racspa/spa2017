#include"GameOfLife.h"
#include<conio.h> //_getch()

int main() {
	GameOfLife theGame;

	//_getch() waits for a keypress - allowing fast iteration through the game
	do {
		theGame.iscrtaj();
		theGame.sljedecaGeneracija();

		cout << "Stisnite bilo koju tipku za nastavak (q = izlaz)" << endl << "Preporucam drzanje tipke!" << endl;
	} while (_getch() != 'q');

	/*bool dalje;
	do {
		theGame.iscrtaj();
		theGame.sljedecaGeneracija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);*/

	return 0;
}