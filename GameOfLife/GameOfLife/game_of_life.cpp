#include <time.h>
#include <random>
#include "game_of_life.h"

int game_of_life::random_number(int min, int max)
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(min, max);

	return uni(rng);
}

void game_of_life::slucajna_vrijednost()
{
	for (int i = 0; i < REDAKA; i++)
	{
		srand(time(NULL));
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = random_number(0, 100) <= 20;
		}
	}
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || j < 0)
		return false;

	if (_generacija[i][j])
		return true;

	return false;
}

// racuna broj susjednih zivih celija
// gledamo svih 8 susjednih celija
int game_of_life::broj_susjeda(int i, int j)
{
	int count = 0;
	for (int k = i - 1; k <= i + 1; k++)
	{
		for (int l = j - 1; l <= j + 1; l++)
		{
			if (k == i && l == j)
				continue;

			if (celija_zauzeta(k, l))
				count++;
		}
	}
	return count;
}

// racuna broj susjednih zivih celija
// gledamo samo 4 susjedne celije
//int game_of_life::broj_susjeda(int i, int j)
//{
//	int count = 0;
//	for (int k = i - 1; k <= i + 1; k++)
//	{
//		for (int l = j - 1; l <= j + 1; l++)
//		{
//			if ((k == i && l == j) ||
//				k != i && l != j)
//				continue;
//
//			if (celija_zauzeta(k, l))
//				count++;
//		}
//	}
//	return count;
//}

game_of_life::game_of_life()
{
	slucajna_vrijednost();
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int count = broj_susjeda(i, j);

			if (celija_zauzeta(i, j))
			{
				// umire
				if (count < 2 || count > 3)
					_sljedeca_generacija[i][j] = false;
				// ostaje
				else if (count == 2 || count == 3)
					_sljedeca_generacija[i][j] = _generacija[i][j];
			}
			else
			{
				// radja se
				if (count == 3)
					_sljedeca_generacija[i][j] = true;
				else
					_sljedeca_generacija[i][j] = false;
			}
		}
	}

	// kopiramo rezultate natrag u glavno polje
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
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i, j))
				cout << '*';
			else
				cout << '-';
		}
		cout << endl;
	}
}
