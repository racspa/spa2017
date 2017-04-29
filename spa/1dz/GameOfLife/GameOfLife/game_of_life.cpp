#include "game_of_life.h"
#include <time.h>
using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	if (rand() % 5 == 0) return 1;
	return 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

int game_of_life::prebroji_susjede(int i, int j)
{
	int broj_susjeda = 0;
	int x[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int y[8] = { 0, -1, 1,  -1, 0, 1, -1, 1 };

	for (int k = 0; k < 8; k++) {
		// provjera da li je unutar 2d polja susjed
		if (i + x[k] < 0 || j + y[k] < 0 || i + x[k] >= REDAKA || j + y[k] >= STUPACA) continue;
		// ako je susjed ziv onda je 1 ako nije je nula
		broj_susjeda += _generacija[i + x[k]][j + y[k]];
	}

	return broj_susjeda;
}

game_of_life::game_of_life()
{
	srand(time(NULL));
	for (int i = 0; i < REDAKA; i++)
		for (int j = 0; j < STUPACA; j++)
			_generacija[i][j] = slucajna_vrijednost();
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = prebroji_susjede(i, j);
			if (_generacija[i][j]==true) {
				if (susjedi == 2 || susjedi == 3)
					_sljedeca_generacija[i][j] = 1;
				else
					_sljedeca_generacija[i][j] = 0;
			}
			else {
				if (susjedi == 3)
					_sljedeca_generacija[i][j] = 1;
				else
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
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j]==true)
				cout << "*";
			else
				cout << "-";
		}
		cout << endl;
	}
}
