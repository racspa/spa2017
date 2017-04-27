#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	int sansa = rand() % 5 + 1;
	if (sansa == 3) { return 1; }
	else { return 0; }
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA + 2; i++) {
		for (int j = 0; j < STUPACA + 2; j++) {
			if (i == 0 || i == REDAKA + 1 || j == 0 || j == STUPACA + 1) {
				_generacija[i][j] = 0;
			}
			else {
				_generacija[i][j] = slucajna_vrijednost();
			}
		}
	}
	iscrtaj();
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA + 2; i++) {
		for (int j = 0; j < STUPACA + 2; j++) {
			if (i == 0 || i == REDAKA + 1 || j == 0 || j == STUPACA + 1) {
				_sljedeca_generacija[i][j] = 0; }
			else {
				int susjedi = 0;
				susjedi = susjedi + _generacija[i - 1][j - 1] + _generacija[i - 1][j] + _generacija[i - 1][j + 1] + _generacija[i][j - 1] + _generacija[i][j + 1] + _generacija[i + 1][j - 1] + _generacija[i + 1][j] + _generacija[i + 1][j + 1];
				if (celija_zauzeta(i, j)) {
					if (susjedi == 2 || susjedi == 3) {
						_sljedeca_generacija[i][j] = _generacija[i][j];
					}
					else { _sljedeca_generacija[i][j] = 0; }
				}
				else if (!celija_zauzeta(i, j) && susjedi == 3) {
					_sljedeca_generacija[i][j] = 1;
				}
				else { _sljedeca_generacija[i][j] = _generacija[i][j]; }
			}
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	iscrtaj();
}

void game_of_life::iscrtaj()
{
	for (int i = 1; i < REDAKA + 1; i++) {
		for (int j = 1; j < STUPACA + 1; j++) {
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
