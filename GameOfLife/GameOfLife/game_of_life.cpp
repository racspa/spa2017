#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	int random =  rand() % 100;
	if (random <= 19)
	{
		return true;
	}
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
			if (_generacija[i][j] == 1 && i < REDAKA && j < STUPACA && i >= 0 && j >= 0)			//ako je polje na mjestu [i][j] == 1, ako je celija u rangeu, vrati true
			{
				return true;
			}
				return false;						// ako nije, vrati false
}

game_of_life::game_of_life()
{
	srand(time(nullptr));			// seed
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();		//popunjavanje polja
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
				int brojac_susjeda = 0;				//brojaè susjeda
				if (celija_zauzeta(i - 1, j - 1))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i - 1, j))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i - 1, j + 1))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i , j - 1))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i , j + 1))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i + 1, j - 1))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i + 1, j ))
				{
					brojac_susjeda++;
				}
				if (celija_zauzeta(i + 1, j + 1))
				{
					brojac_susjeda++;
				}
				//živi
				if (celija_zauzeta(i,j))
				{
					if (brojac_susjeda < 2 || brojac_susjeda > 3)
					{
						_sljedeca_generacija[i][j] = false;
					}
					else if (brojac_susjeda == 2 || brojac_susjeda == 3)
					{
						_sljedeca_generacija[i][j] = true;
					}
				}
					
			//mrtvi
				else
				{
					if (brojac_susjeda == 3)
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
				if (_generacija[i][j])
				{
					cout << '*';				//zvjezdica umjesto true, minus umjesto false
				}
				else
				{
					cout << '-';
				}
			}
			cout << endl;
		}
}
