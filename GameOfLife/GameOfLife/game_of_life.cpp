#include "game_of_life.h"
#include <ctime>
#include <random>
#include <array>
#include <iostream>

bool game_of_life::slucajna_vrijednost()
{
	return  (rand() % 100) < 20;
}

game_of_life::game_of_life()
{
	srand(time(NULL));
	
	for (auto &polje : _generacija) {
		for (auto &b : polje) {
			b = slucajna_vrijednost();
		}
	}
	

}

void game_of_life::sljedeca_generacija()
{
	__sljedeca_generacija = _generacija;

	for (int i = 1; i < REDAKA -1; i++) {
		for (int j = 1; j < STUPACA -1; j++) {

		
					int count = 
					_generacija[i - 1][j - 1] +
					_generacija[i - 1][j] +
					_generacija[i - 1][j + 1] +
					_generacija[i][j - 1] +
					_generacija[i][j + 1] +
					_generacija[i + 1][j - 1] +
					_generacija[i + 1][j] +
					_generacija[i + 1][j + 1];


					if (count < 2 || count > 3)
						__sljedeca_generacija[i][j] = false;
					if (count == 2)
						__sljedeca_generacija[i][j] = _generacija[i][j];
					if (count == 3)
						__sljedeca_generacija[i][j] = true;
				
			}
	}
	
	_generacija = __sljedeca_generacija;

}

void game_of_life::iscrtaj()
{

	system("cls");
	for (int i = 1; i < REDAKA - 1; i++) {
		for (int j = 1; j < STUPACA - 1; j++) {
			if (_generacija[i][j]) {
				std::cout << '*';
			}
			else
			{
				std::cout << '-';
			}
		}
		std::cout << std::endl;
	}
	

}
