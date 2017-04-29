#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int broj = rand() % 5;
	// Broj moze biti 0 - 4. Jedna od tih vrednosti => 20% sanse
	if (broj == 1) {
		return 1;
	}
	return 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	// Ako je izvan tablice racunamo da nema organizma
	if (i < 0 || i >= REDAKA || j < 0 || j >= STUPACA) {
		return 0;
	}

	return _generacija[i][j];
}

int game_of_life::prebroji_susjedne_celije(int i, int j)
{
	int brojac = 0;

	//red iznad.........
	if (celija_zauzeta(i - 1, j - 1) != 0) {
		brojac++;
	}

	if (celija_zauzeta(i - 1, j) != 0) {
		brojac++;
	}

	if (celija_zauzeta(i - 1, j + 1) != 0) {
		brojac++;
	}

	//paralelno..........
	if (celija_zauzeta(i, j - 1) != 0) {
		brojac++;
	}

	if (celija_zauzeta(i, j + 1) != 0) {
		brojac++;
	}

	//red ispod..........
	if (celija_zauzeta(i + 1, j - 1) != 0) {
			brojac++;
	}

	if (celija_zauzeta(i + 1, j) != 0) {
			brojac++;
	}

	if (celija_zauzeta(i + 1, j + 1) != 0) {
			brojac++;
	}
	
	return brojac;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjedne_celije = prebroji_susjedne_celije(i, j);
			if (susjedne_celije == 2) {
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
			if (susjedne_celije == 3) {
				_sljedeca_generacija[i][j] = 1;
			}
			if (susjedne_celije < 2 || susjedne_celije > 3) {
				_sljedeca_generacija[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	system("CLS");

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}
