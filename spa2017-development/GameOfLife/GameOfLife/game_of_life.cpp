#include <ctime>
#include <iostream>
#include "game_of_life.h"

//Generiranje slučajne vrijednosti između 1 i 100
int game_of_life::slucajna_vrijednost()
{
	return rand() % 100 + 1;
}

//Stvaramo život u čeliji u ovisnosti o postoku šanse za život
bool game_of_life::stvaranje_zivota_u_celiji(int postotak_sanse_za_zivot)
{
	int slucajni_broj = slucajna_vrijednost();

	return ((slucajni_broj > 0) && (slucajni_broj <= postotak_sanse_za_zivot));
}

game_of_life::game_of_life()
{
	srand(time(nullptr));

	//Kreiramo prvo stanje i dodajemo okvir oko naše matrice zbog lakšeg izračuna susjeda.
	for (int i = 0; i < REDAKA_SA_OKVIROM; i++)
	{
		for (int j = 0; j < STUPACA_SA_OKVIROM; j++)
		{
			if (i == 0 || j == 0)
				_generacija[i][j] = 0;
			else if (i == REDAKA_SA_OKVIROM - 1 || j == STUPACA_SA_OKVIROM - 1)
				_generacija[i][j] = 0;
			else
				_generacija[i][j] = stvaranje_zivota_u_celiji(20);
		}
	}
}

//Iscrtavamo stanje trenutne generacije
void game_of_life::iscrtaj()
{
	system("cls");

	//Iscrtavamo stanje ignorirajući okvir
	for (int i = 1; i < REDAKA_SA_OKVIROM - 1; i++)
	{
		for (int j = 1; j < STUPACA_SA_OKVIROM - 1; j++)
		{
			cout << (_generacija[i][j] ? "+" : "-");
		}

		cout << endl;
	}
}

//Kreiranje sljedeće generacije
void game_of_life::sljedeca_generacija()
{
	//Ignoriramo okvir i vrtimo
	for (int i = 1; i < REDAKA_SA_OKVIROM - 1; i++)
	{
		for (int j = 1; j < STUPACA_SA_OKVIROM - 1; j++)
		{
			int broj_susjeda = 0;

			broj_susjeda = _generacija[i - 1][j - 1] +
						   _generacija[i - 1][j] +
						   _generacija[i - 1][j + 1] +
						   _generacija[i][j - 1] +
						   _generacija[i][j + 1] +
						   _generacija[i + 1][j - 1] +
						   _generacija[i + 1][j] +
						   _generacija[i + 1][j + 1];

			//Provjeravamo stanje čelije
			if (_generacija[i][j])
			{
				//Živi organizam u ćeliji preživljava u sljedećoj generaciji ukoliko je broj njegovih susjeda dva ili tri.
				if (broj_susjeda == 2 || broj_susjeda == 3)
					_sljedeca_generacija[i][j] = 1;
				//Živi organizam u ćeliji umire u sljedećoj generaciji ukoliko je broj njegovih susjeda manji od dva (zbog usamljenosti) ili veći od tri (zbog prenaseljenosti).
				else
					_sljedeca_generacija[i][j] = 0;
			}
			else
			{
				//U praznoj ćeliji se rađa novi organizam ukoliko se u točno tri njene susjedne ćelije nalaze živi organizmi.
				if (broj_susjeda == 3)
					_sljedeca_generacija[i][j] = 1;
				//Inače ga ostavljamo kao nerođenog
				else
					_sljedeca_generacija[i][j] = 0;
			}
		}
	}

	//Postavimo sljedecu generaciju kao trenutnu
	for (int i = 0; i < REDAKA_SA_OKVIROM; i++)
	{
		for (int j = 0; j < STUPACA_SA_OKVIROM; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

