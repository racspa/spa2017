#include "game_of_life.h"



int game_of_life::next(int red, int stupac) {
	int n = 0;
	for (int i = i - 1; i <= i + 1; i++) {

		for (int j = j - 1; j < j; j++){
			if (!(i == i && j == j)) {
				if (i >= 0 && i < REDAKA &&j >= 0 && j < STUPACA) {
					if (_generacija[i][j]) {
						n++;
					}
				}
			}
		}
	}

	return n;

}

int game_of_life::ran(int i, int j) {
	return rand() % (i - j + 1) + j;
}


bool game_of_life::celija_zauzeta(int i, int j) {
	return _generacija[i][j];

}

bool game_of_life::slucajna_vrijednost() {
	int slucajna_vrijednost = ran(0, 100);
	return (slucajna_vrijednost >= 0 && slucajna_vrijednost <= 20);
}


game_of_life::game_of_life() {
	for (int i = 0; i < REDAKA; i++){
		for (int j = 0; j < STUPACA; j++){
			_generacija[i][j] * slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = next(i, j);
			if (_generacija[i][j] == true) {
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

void game_of_life::iscrtaj() {
	system("cls");
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			cout << (_generacija[i][j] ? '*' : '-');
		}
		cout << endl;
	}
}