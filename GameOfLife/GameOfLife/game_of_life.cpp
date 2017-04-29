#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 100 + 1;
}

bool game_of_life::je_ziva(int i, int j)
{
	if (_generacija[i][j] == '*')
	{
		return true;
	}
	return false;
}

int game_of_life::broj_zivih(int i, int j)
{
	int counter = 0;

	if (i < REDAKA && i > 0 && j < STUPACA && j > 0)
	{
		if (_generacija[i - 1][j - 1] == '*')
		{
			counter++;
		}

		if (_generacija[i - 1][j] == '*')
		{
			counter++;
		}

		if (_generacija[i - 1][j + 1] == '*')
		{
			counter++;
		}

		if (_generacija[i][j - 1] == '*')
		{
			counter++;
		}

		if (_generacija[i][j + 1] == '*')
		{
			counter++;
		}

		if (_generacija[i + 1][j - 1] == '*')
		{
			counter++;
		}

		if (_generacija[i + 1][j] == '*')
		{
			counter++;
		}

		if (_generacija[i + 1][j + 1] == '*')
		{
			counter++;
		}
	}

	return counter;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (slucajna_vrijednost() <= 20)
			{
				this->_generacija[i][j] = '*';
			}
			else
			{
				this->_generacija[i][j] = '-';
			}
		}
	}

}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (je_ziva(i, j))
			{
				if (broj_zivih(i, j) < 2 || broj_zivih(i, j) > 3)
				{
					_sljedeca_generacija[i][j] = '-';
				}
				if (broj_zivih(i, j) == 2 || broj_zivih(i, j) == 3)
				{
					_sljedeca_generacija[i][j] = '*';
				}
			}
			else
			{
				if (broj_zivih(i, j) == 3)
				{
					_sljedeca_generacija[i][j] = '*';
				}
				else
				{
					_sljedeca_generacija[i][j] = '-';
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

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			cout << _generacija[i][j];
		}
		cout << endl;
	}
}
