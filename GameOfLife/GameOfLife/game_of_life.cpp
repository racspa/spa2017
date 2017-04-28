#include "game_of_life.h"
#include <ctime>
bool game_of_life::slucajna_vrijednost()
{
	int rand_vrijednost = random();
	if (rand_vrijednost >= 0 && rand_vrijednost <= 20) {
		return true;
	}
		return false;
	
}

int game_of_life::susjedi(int i, int j)
{
	int count_susjedi = 0;

	if (i!=0 && j!=0)
	{
		count_susjedi += _generacija[i - 1][j - 1];
	}
	if (i!=REDAKA-1 && j!=0)
	{
		count_susjedi += _generacija[i + 1][j-1];
	}

	if (i != 0 && j !=STUPACA-1)
	{
		count_susjedi += _generacija[i-1][j+1];
	}
	if (i != REDAKA - 1 && j != STUPACA -1)
	{
		count_susjedi += _generacija[i +1][j+1];
	}

	if (i != 0)
	{
		count_susjedi += _generacija[i-1][j];
	}
	if (j != 0)
	{
		count_susjedi += _generacija[i][j-1];
	}
	if (j!=STUPACA-1)
	{
		count_susjedi += _generacija[i][j+1];
	}
	if (i != REDAKA-1)
	{
		count_susjedi += _generacija[i+1][j];
	}

	return count_susjedi ;
}

int game_of_life::random()
{
	return rand() % 100+1;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}
//------------------------------JAVNE METODE----------------------------------
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

			int next_gen = susjedi(i, j);
			
				if (next_gen < 2 || next_gen>3) {
					_sljedeca_generacija[i][j] = false;
				}


				if (next_gen == 2 || next_gen == 3)
				{
					_sljedeca_generacija[i][j] =  celija_zauzeta(i,j);
				}
				
			if (!celija_zauzeta(i,j)) {
				if (next_gen == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
			
			}

		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
			
		}
	}
}
void game_of_life::iscrtaj()
{
	system("cls");
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
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
