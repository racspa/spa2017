#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	int max = 100;
	int min = 1;
	int vrijednost;
	vrijednost = rand() % (max - min + 1) + min;
	if (vrijednost <= 20)		//sansa 20% 
	{
		return true;
	}
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

int game_of_life::br_zivih_susjednih(int red, int stupac)
{
	int n = 0;
	for (int i = red - 1; i <= red + 1; i++)
	{
		for (int j = stupac - 1; j <= stupac + 1; j++)
		{
			if (!(i == red && j == stupac))
			{
				if (i >= 0 && i<REDAKA &&j >= 0 && j<STUPACA)
				{
					if (_generacija[i][j])
					{
						n++;
					}
				}
			}
		}
	}
	return n;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int zivi_susjedni = br_zivih_susjednih(i, j);
			if (_generacija[i][j])
			{
				if (zivi_susjedni<2 || zivi_susjedni>3)
				{
					_sljedeca_generacija[i][j] = false;
				}
				else
				{
					_sljedeca_generacija[i][j] = true;
				}
			}
			else
			{
				if (zivi_susjedni == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}
	for (int i = 0; i < REDAKA; i++)		//refresh nove generacije
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}


void game_of_life::iscrtaj()
{
	system("CLS");
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << '*';
			}
			else
			{
				cout << '-';
			}
		}
		cout << endl;
	}
}