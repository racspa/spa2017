#include "game_of_life.h"
#include <ctime>
//Public
void game_of_life::sljedeca_generacija() {
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_polje[i][j]) {
				_sljedece_polje[i][j] = evolve_zivu(i,j);
			}
			else {
				_sljedece_polje[i][j] = evolve_mrtvu(i,j);
			}
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_polje[i][j] = _sljedece_polje[i][j];
		}
	}
}

void game_of_life::iscrtaj() {
	system("cls");
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_polje[i][j]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
	cout << endl;
}

game_of_life::game_of_life() {
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_polje[i][j] = slucajna_vrijednost();
		}
	}
}

/*bool game_of_life::celija_zauzeta(int i, int j){
	return false;
}*/
//Privatna
bool game_of_life::slucajna_vrijednost() {
	if (rand() % 100 + 1 <= 20) {
		return true;
	}
	return false;
}

bool game_of_life::evolve_zivu(int i, int j){
	int susjedi = 0;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (!((i + k < 0 || j + l < 0) || (i + k >= REDAKA || j + l >= STUPACA))) {
				if (_polje[i+k][j+l]) {
					//cout << "Polje[" << i + 1 + k << "][" << j + 1 + l << "] Susjedi++" << endl;
					susjedi++;
				}
			}
		}
	}
	susjedi--;
	//cout << "Polje[" << i + 1 << "][" << j + 1 << "] Susjedi = " << susjedi << endl;
	return (susjedi == 2 || susjedi == 3);
}

bool game_of_life::evolve_mrtvu(int i, int j){
	int susjedi = 0;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (!((i + k < 0 || j + l < 0) || (i + k >= REDAKA || j + l >= STUPACA))) {
				if (_polje[i + k][j + l]) {
					susjedi++;
				}
			}
		}
	}
	return susjedi == 3;
}
