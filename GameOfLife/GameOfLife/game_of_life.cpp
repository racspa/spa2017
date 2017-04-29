#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int random = rand() % 100 + 1;
	if(random >= 0 && random <= 20)
	{
		return true;

	}
	return false;
}

bool game_of_life::je_ziva(int i, int j)
{
	if(_generacija[i][j] == '*')
	{
		return true;
	}
	return false;
}

int game_of_life::zivi(int i, int j)
{
	int counter = 0;

	if(i < REDAKA && i > 0 && j < STUPACA && j > 0)
	{

		/* [i-1,j-1] [i-1,j] [i-1,j+1]
		   [i,j-1]    ZIVA   [i,j+1]
		   [i+1,j-1] [i+1,j] [i+1,j+1]
		*/



		if(_generacija[i - 1][j - 1] == '*')
		{
			counter++;
		}

		if(_generacija[i - 1][j] == '*')
		{
			counter++;
		}

		if(_generacija[i - 1][j + 1] == '*')
		{
			counter++;
		}

		if(_generacija[i][j - 1] == '*')
		{
			counter++;
		}

		if(_generacija[i][j + 1] == '*')
		{
			counter++;
		}

		if(_generacija[i + 1][j - 1] == '*')
		{
			counter++;
		}

		if(_generacija[i + 1][j] == '*')
		{
			counter++;
		}

		if(_generacija[i + 1][j + 1] == '*')
		{
			counter++;
		}
	}

	return counter;
}

//Pocetna inicijalizacija polja
game_of_life::game_of_life()
{

	srand((unsigned int)time(nullptr));


	for(int i = 0; i < REDAKA; i++)
	{
		for(int j = 0; j < STUPACA; j++)
		{
			if(slucajna_vrijednost())
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
	for(int i = 0; i < REDAKA; i++)
	{
		for(int j = 0; j < STUPACA; j++)
		{
			if(je_ziva(i, j))
			{
				/*Živi organizam u ćeliji umire u sljedećoj generaciji ukoliko je broj njegovih
				susjeda manji od dva (zbog usamljenosti) ili veći od tri (zbog prenaseljenosti).*/
				if(zivi(i, j) < 2 || zivi(i, j) > 3)
				{
					_sljedeca_generacija[i][j] = '-';
				}
				/*Živi organizam u ćeliji preživljava u sljedećoj generaciji ukoliko je broj njegovih susjeda dva ili tri.*/
				if(zivi(i, j) == 2 || zivi(i, j) == 3)
				{
					_sljedeca_generacija[i][j] = '*';
				}
			}
			else
			{
				/*U praznoj ćeliji se rađa novi organizam ukoliko se u
				točno tri njene susjedne ćelije nalaze živi organizmi.*/
				if(zivi(i, j) == 3)
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

	for(int i = 0; i < REDAKA; i++)
	{
		for(int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	system("cls");

	for(int i = 0; i < REDAKA; i++)
	{
		for(int j = 0; j < STUPACA; j++)
		{
			cout << _generacija[i][j];
		}
		cout << endl;
	}
}