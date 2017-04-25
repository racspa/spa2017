#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost() {
	int slucajna_vrijednost = random(0, 100);
	return (slucajna_vrijednost >= 0 && slucajna_vrijednost <= 20);
}

bool game_of_life::celija_zauzeta(int i, int j) {
	return _generacija[i][j];
}

int game_of_life::random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int game_of_life::susjedi(int i, int j) {
	int broj_susjeda = 0;

	if (i != 0 && j != 0)
		broj_susjeda += _generacija[i - 1][j - 1];

	if (i != 0)
		broj_susjeda += _generacija[i - 1][j];

	if (i != 0 && j != STUPACA - 1)
		broj_susjeda += _generacija[i - 1][j + 1];

	if (j != 0)
		broj_susjeda += _generacija[i][j - 1];

	if (j != STUPACA - 1)
		broj_susjeda += _generacija[i][j + 1];

	if (i != REDAKA - 1 && j != 0)
		broj_susjeda += _generacija[i + 1][j - 1];

	if (i != REDAKA - 1)
		broj_susjeda += _generacija[i + 1][j];

	if (i != REDAKA - 1 && j != STUPACA - 1)
		broj_susjeda += _generacija[i + 1][j + 1];

	return broj_susjeda;
}

game_of_life::game_of_life() {
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int br_susjeda = susjedi(i, j);
			_sljedeca_generacija[i][j] = (celija_zauzeta(i, j) ? (br_susjeda == 2 || br_susjeda == 3) : (br_susjeda == 3));
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj() {
	system("cls");
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			cout << (_generacija[i][j] ? '*' : '-');
		}
		cout << endl;
	}
}