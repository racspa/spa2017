#include<ctime>
#include"game_of_life.h"



bool game_of_life::slucajna_vrijednost()
{
	int random;
	random = rand() % 100 + 1;

	if (random <= this->postotak_vjerojatnosti)
	{
		return true;
	}
	return false;
}

game_of_life::game_of_life() {
	
	srand(time(NULL));

	
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			this->_generacija[i][j] = slucajna_vrijednost();
		}
	}
}


int game_of_life::broj_zivih_susjeda(int n, int m)
{
	int broj_susjeda = 0;
		for (int i = n - 1; i <= n + 1; i++)
		{
			for (int j = m - 1; j <= m + 1; j++)
			{
				if (i >= 0 && i < REDAKA && j >= 0 && j < STUPACA)	//eliminacija rubnih
				{
					if (_generacija[i][j])
					{
						if (i == n&&j == m){}						//eliminacija samog sebe
						else
						{
							broj_susjeda++;
						}
					}
				}
			}
		}
	return broj_susjeda;
}

void game_of_life::iscrtaj()
{
	system("cls");
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			if (_generacija[i][j]) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
	/*for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)     PROVJERA BROJA ZIVIH SUSJEDA
		{
			cout << broj_zivih_susjeda(i, j);
		}
		cout << endl;
	}*/
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < this->REDAKA; i++)
	{
		for (int j = 0; j < this->STUPACA; j++)
		{
			int n = broj_zivih_susjeda(i, j);
			if (_generacija[i][j])
			{
				if (n < 2 || n > 3)
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
				if (n == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	}
}
