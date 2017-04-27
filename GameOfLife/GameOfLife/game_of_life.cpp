#include "game_of_life.h"
#include<time.h>


bool game_of_life::slucajna_vrijednost()
{
	if ((rand() % 100 + 1) <= 20) return true;
	else return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || i > REDAKA || j < 0 || j > STUPACA) return false;
	return _generacija[i][j];
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
			int zauzetihCelija = 0;

			for (int k = i - 1; k <= i + 1; k++) {
				for (int l = j - 1; l <= j + 1; l++) {
					if (!(k == i && l == j)) {
						if (celija_zauzeta(k, l)) zauzetihCelija++;
					}
				}
			}

			if (_generacija[i][j]) {
				if (zauzetihCelija < 2 || zauzetihCelija > 3) _sljedeca_generacija[i][j] = false;
				else _sljedeca_generacija[i][j] = true;
			}
			else {
				if (zauzetihCelija == 3) _sljedeca_generacija[i][j] = true;
				else _sljedeca_generacija[i][j] = false;
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
			if (_generacija[i][j]) cout << '*';
			else cout << '-';
		}
		cout << endl;
	}
}
