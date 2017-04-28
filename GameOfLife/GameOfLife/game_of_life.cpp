#include "game_of_life.h"

//********************* PRIVATNE METODE *********************
bool game_of_life::_slucajna_vrijednost() {
	return _vjerojatnost >= rand() % 100 + 1;
}

int game_of_life::_broj_susjeda(int i, int j) {
	int gl = _generacija[i - 1][j - 1];
	int gs = _generacija[i - 1][j];
	int gd = _generacija[i - 1][j + 1];
	int sl = _generacija[i][j - 1];
	int sd = _generacija[i][j + 1];
	int dl = _generacija[i + 1][j - 1];
	int ds = _generacija[i + 1][j];
	int dd = _generacija[i + 1][j + 1];

	int gornji = gl + gs + gd;
	int srednji = sl + sd;
	int donji = dl + ds + dd;
	int lijevi = gl + sl + dl;
	int desni = gd + sd + dd;
	int zbroj = gl + gs + gd + sl + sd + dl + ds + dd;

	if (i == 0 && j == 0) {
		return sd + ds + dd;
	}
	else if (i == 0 && j == _REDAKA - 1) {
		return sl + dl + ds;
	}
	else if (i == _STUPACA - 1 && j == 0) {
		return gs + gd + sd;
	}
	else if (i == _STUPACA - 1 && j == _REDAKA - 1) {
		return gl + gs + sl;
	}
	else if (i == 0) {
		return zbroj - gornji;
	}
	else if (j == 0) {
		return zbroj - lijevi;
	}
	else if (i == _STUPACA - 1) {
		return zbroj - donji;
	}
	else if (j == _REDAKA - 1) {
		return zbroj - desni;
	}
	else {
		return zbroj;
	}
}

//********************* JAVNE METODE *********************
void game_of_life::iscrtaj() {
	for (int i = 0; i < _REDAKA; i++) {
		for (int j = 0; j < _STUPACA; j++) {
			if (_generacija[i][j]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}

game_of_life::game_of_life() {
	for (int i = 0; i < _REDAKA; i++) {
		for (int j = 0; j < _STUPACA; j++) {
			_generacija[i][j] = _slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {
	for (int i = 0; i < _REDAKA; i++) {
		for (int j = 0; j < _STUPACA; j++) {
			if (_generacija[i][j]) {
				if (_broj_susjeda(i, j) < 2 || _broj_susjeda(i, j) > 3) {
					_sljedeca_generacija[i][j] = false;
				}
				else {
					_sljedeca_generacija[i][j] = true;
				}
			}
			if (!_generacija[i][j]) {
				if (_broj_susjeda(i, j) == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else {
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}

	for (int i = 0; i < _REDAKA; i++) {
		for (int j = 0; j < _STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}