#include "game_of_life.h"
#include<ctime>


int game_of_life::counter(int i, int j)
{

	int counter = 0;

	if (i != 0 && j!=0)
	{
		if (celija_zauzeta(i-1, j-1)) //provjeri celiju lijevo iznad
		{
			counter++;
		}
	}
	if (j != 0)
	{
		if (celija_zauzeta(i, j - 1)) //provjeri celiju lijevo 
		{
			counter++;
		}
	}
	if (j != 0 && i != REDAKA - 1)
	{
		if (celija_zauzeta(i + 1, j - 1)) //provjeri celiju lijevo  dolje
		{
			counter++;
		}
	}
	if (i != 0)
	{
		if (celija_zauzeta(i - 1, j)) //provjeri celiju iznad
		{
			counter++;
		}
	}
	if (i != REDAKA -1)
	{
		if (celija_zauzeta(i + 1, j)) //provjeri celiju ispod
		{
			counter++;
		}
	}
	if (i != 0 && j != STUPACA - 1)
	{
		if (celija_zauzeta(i - 1, j + 1)) //provjeri celiju desno gore
		{
			counter++;
		}
	}
	if (j != STUPACA - 1)
	{
		if (celija_zauzeta(i, j + 1)) //provjeri celiju desno 
		{
			counter++;
		}
	}
	if (i != REDAKA - 1 && j != STUPACA - 1)
	{
		if (celija_zauzeta(i + 1, j + 1)) //provjeri celiju desno dolje
		{
			counter++;
		}
	}
	return counter;
}



bool game_of_life::slucajna_vrijednost()
{
	
	int slucajna_vrijednost = rand() % (100 - 1 + 1) + 1;
	
			if (slucajna_vrijednost <= 20 && slucajna_vrijednost >= 0)
			{
				//  inicijalna celija ziva.
				return true;
			}
			else
			{
				// inicijalna celija ziva mrtva.
				return false;
			}
}

game_of_life::game_of_life()
{
	
	//inicijaliziraj polje s 20% sanse.

	srand(time(nullptr));
	
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			
			_generacija[i][j] = slucajna_vrijednost();
			
		}
	}
}


bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int br_zivih = counter(i,j);
			

		
				if (br_zivih  < 2 || br_zivih  > 3)  //usamljenost ili prenaseljenost.
					{
						_sljedeca_generacija[i][j] = false;
					}

				if (br_zivih == 2)
					{
						_sljedeca_generacija[i][j] = celija_zauzeta(i,j);   // 2 ziva susjeda - celija ostaje u istom stanju.
					}
				
				if (br_zivih == 3)
					{
						_sljedeca_generacija[i][j] = true; // 3 ziva susjeda - celija ostaje ziva ili se radja.
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
	system("CLS");


	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			// ako je celija u generaciji celija ziva ispisi (*), inace (-). 
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}

		}
		cout << endl;

	}



}


