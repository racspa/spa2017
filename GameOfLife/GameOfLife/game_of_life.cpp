#include "game_of_life.h"

game_of_life::game_of_life()
{
	srand(time(NULL));

	for (int red = ODSTUPANJE; red < REDAKA+ODSTUPANJE; red++)
	{
		for (int stupac = ODSTUPANJE; stupac < STUPACA+ODSTUPANJE; stupac++)
		{
			_generacija[red][stupac] = slucajna_vrijednost(1, 5);
		}
	}
}

bool game_of_life::slucajna_vrijednost(unsigned int povoljno, unsigned int ukupno)
{
	return rand() % ukupno + 1 <= povoljno;
}

void game_of_life::preslikaj()
{
	for (int red = ODSTUPANJE; red < REDAKA + ODSTUPANJE; red++)
	{
		for (int stupac = ODSTUPANJE; stupac < STUPACA + ODSTUPANJE; stupac++)
		{
			_generacija[red][stupac] = _sljedeca_generacija[red - ODSTUPANJE][stupac - ODSTUPANJE];
		}
	}
}

bool game_of_life::celija_zauzeta(int red, int stupac)
{
	return _generacija[red + ODSTUPANJE][stupac + ODSTUPANJE] == true;
}

void game_of_life::izracunaj(int red, int stupac)
{
	int brojSusjeda = 0;

	brojSusjeda += celija_zauzeta(red - 1, stupac);
	brojSusjeda += celija_zauzeta(red + 1, stupac);
	brojSusjeda += celija_zauzeta(red, stupac - 1);
	brojSusjeda += celija_zauzeta(red, stupac + 1);
	brojSusjeda += celija_zauzeta(red - 1, stupac - 1);
	brojSusjeda += celija_zauzeta(red + 1, stupac + 1);
	brojSusjeda += celija_zauzeta(red - 1, stupac + 1);
	brojSusjeda += celija_zauzeta(red + 1, stupac - 1);

	if (celija_zauzeta(red, stupac) == true)
	{
		if (brojSusjeda < 2 || brojSusjeda > 3)
		{
			_sljedeca_generacija[red][stupac] = false;
		}
		else
		{
			_sljedeca_generacija[red][stupac] = true;
		}
	}
	else if (celija_zauzeta(red, stupac) == false)
	{
		if (brojSusjeda == 3)
		{
			_sljedeca_generacija[red][stupac] = true;
		}
		else
		{
			_sljedeca_generacija[red][stupac] = false;
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int red = 0; red < REDAKA; red++)
	{
		for (int stupac = 0; stupac < STUPACA; stupac++)
		{
			izracunaj(red, stupac);
		}
	}

	preslikaj();
}

void game_of_life::iscrtaj()
{
	string polje = "";
	int pozicija = 0;

	for each (bool celija in _generacija)
	{
		if (pozicija == STUPACA + 2 * ODSTUPANJE)
		{
			polje += "\n";
			pozicija = 0;
		}

		if (celija == true)
		{
			polje += "X ";
		}
		else
		{
			polje += "- ";
		}

		pozicija++;
	}

	cout << polje << endl;
}