#include "game_of_life.h"

int game_of_life::rand_broj(int min, int max) {
	return rand() % (max - min + 1) + min;
}

bool game_of_life::slucajna_vrijednost() {
	int slucajna_vrijednost = rand_broj(0, 100);
	return (slucajna_vrijednost >= 0 && slucajna_vrijednost <= 20); //vrati ako je vrijednost od 0-20
}

bool game_of_life::celija_zauzeta(int x, int y) {
	return _generacija[x][y]; 
}


int game_of_life::neighbour_count_alg(int x, int y) {
	int neighbour_count_alg = 0; //brojac da se zna sto se radi sa celijom


	if (x != 0 && y != 0)
		neighbour_count_alg += _generacija[x - 1][y - 1];

	if (x != 0)
		neighbour_count_alg += _generacija[x - 1][y];

	if (x != 0 && y != STUPACA - 1)
		neighbour_count_alg += _generacija[x - 1][y + 1];

	if (x != 0)
		neighbour_count_alg += _generacija[x][y - 1];

	if (x != STUPACA - 1)
		neighbour_count_alg += _generacija[x][y + 1];

	if (x != REDAKA - 1 && y != 0)
		neighbour_count_alg += _generacija[x + 1][y - 1];

	if (x != REDAKA - 1)
		neighbour_count_alg += _generacija[x + 1][y];

	if (x != REDAKA - 1 && y != STUPACA - 1)
		neighbour_count_alg += _generacija[x + 1][y + 1];
		
	return neighbour_count_alg;
}

game_of_life::game_of_life() {
	srand(time(nullptr));

	for (int x = 0; x < REDAKA; x++) {
		for (int y = 0; y < STUPACA; y++) {
			_generacija[x][y] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {
	
	for (int x = 0; x < REDAKA; x++) {
		for (int y = 0; y < STUPACA; y++) {
			int neighbour_count = neighbour_count_alg(x, y);


			_sljedeca_generacija[x][y] = (celija_zauzeta(x, y) ? (neighbour_count == 2 || neighbour_count == 3) : (neighbour_count == 3));
		}
	}

	
	for (int x = 0; x < REDAKA; x++) { //postavlja sljedecu generaciju kao trenutnu
		for (int y = 0; y < STUPACA; y++) {
			_generacija[x][y] = _sljedeca_generacija[x][y];
		}
	}
}

void game_of_life::iscrtaj() { //prolazi kroz cijelo xy polje i ako je true roka * ako je false roka -
	
	for (int x = 0; x < REDAKA; x++) {
		for (int y = 0; y < STUPACA; y++) {
			char current_gen = _generacija[x][y] ? '*' : '-';
			cout << current_gen;
		}

		cout << endl;
	}
}