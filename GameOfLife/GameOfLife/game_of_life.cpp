#include "game_of_life.h"

#include <time.h>

bool game_of_life::slucajna_vrijednost() {
	int temp;
	temp = rand() % 100 + 1;

	bool postoji=false;
	if (temp <= init_chance_in_percent) {
		postoji = true;
	}
	return postoji;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true) {
		return true;
	}
	return false;
}

unsigned short int game_of_life::broj_susjeda(int r, int s)
{
	unsigned short int susjedi=0;
	//	1	2	3
	//	4	X	5
	//	6	7	8
	// Provjera da pozicija postoji, pa provjera zivota

	if (r == 0 || s == 0) {} //1
	else {
		if (_generacija[r-1][s-1] == true) {
			susjedi += 1;
		}
	}

	if (r == 0) {} //2
	else {
		if (_generacija[r-1][s] == true) {
			susjedi += 1;
		}
	}

	if (r == 0 || s == STUPACA -1) {} //3
	else {
		if (_generacija[r - 1][s + 1] == true) {
			susjedi += 1;
		}
	}

	if (s == 0) {} //4
	else {
		if (_generacija[r][s - 1] == true) {
			susjedi += 1;
		}
	}

	if (s == STUPACA-1) {} //5
	else {
		if (_generacija[r][s + 1] == true) {
			susjedi += 1;
		}
	}

	if (r == REDAKA - 1 || s == 0) {} //6
	else {
		if (_generacija[r -1][s + 1] == true) {
			susjedi += 1;
		}
	}

	if (r == REDAKA-1) {} //7
	else {
		if (_generacija[r + 1][s] == true) {
			susjedi += 1;
		}
	}

	if (r == REDAKA - 1 || s == STUPACA - 1) {} //8
	else {
		if (_generacija[r + 1][s + 1] == true) {
			susjedi += 1;
		}
	}

	return susjedi;
}

void game_of_life::update_generation()
{
	for (int r = 0;r < REDAKA;r++) {
		for (int s = 0;s < STUPACA;s++) {
			_generacija[r][s] = _sljedeca_generacija[r][s];
		}
	}
}

game_of_life::game_of_life()
{
	srand(time(NULL)); // used in slucajna_vrijednost

	for (int r = 0;r < REDAKA;r++) {
		for (int s = 0;s < STUPACA;s++) {
			_generacija[r][s] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int r = 0;r < REDAKA;r++) {
		for (int s = 0;s < STUPACA;s++) {

			bool alive = _generacija[r][s];
			unsigned short int _broj_susjeda = broj_susjeda(r, s);

			if (alive && _broj_susjeda < 2) {	//Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
				_sljedeca_generacija[r][s] = false;
			}

			if (alive) {	//Any live cell with two or three live neighbours lives on to the next generation.
				if (_broj_susjeda == 2 || _broj_susjeda == 3) {
					_sljedeca_generacija[r][s] = true;
				}
			}

			if (alive && _broj_susjeda > 3) {	//Any live cell with more than three live neighbours dies, as if by overpopulation.
				_sljedeca_generacija[r][s] = false;
			}

			if (!alive && _broj_susjeda == 3) {	//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
				_sljedeca_generacija[r][s] = true;
			}
		}
	}
	update_generation();
}

void game_of_life::iscrtaj()
{
	system("cls");
	for (int r = 0;r < REDAKA;r++) {
		for (int s = 0;s < STUPACA;s++) {

			if (_generacija[r][s] == true) {
				cout << '*';
			}
			else {
				cout << '_';
			}
			if (s < STUPACA - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;
}
