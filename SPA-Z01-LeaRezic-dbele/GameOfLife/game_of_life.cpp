/* Postovanje, nadam se da ste dobro i da je u redu ubaciti malo komentara. :) Pokusala sam implementaciju napraviti tako da radi i ako se promijeni broj stupaca i redaka ili ako se promijeni ELTYPE.
Nisam nazalost imala puno vremena za zadacu, pa mi se cini da bi izvedba mogla biti ljepsa, odnosno ako nadjete vremena za koju povratnu kritiku/komentar, bila bih zahvalna.*/

#include "game_of_life.h"
#include <ctime>


int game_of_life::slucajna_vrijednost(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


// ******** Funkcija vraca broj susjeda
int game_of_life::broj_susjeda(int i, int j)
{
	int brojac = 0;
	// ako postoje celije lijevo, broji zive (provjerava i postoje li gore i dolje)
	if (j - 1 >= 0) {
		if (celija_zauzeta(i, j - 1)) brojac++;
		if ((i - 1 >= 0) && celija_zauzeta(i - 1, j - 1)) brojac++;
		if ((i + 1 < REDAKA) && celija_zauzeta(i + 1, j - 1)) brojac++;
	}
	// ako postoje celije desno, broji zive (provjerava i postoje li gore i dolje)
	if (j + 1 < STUPACA) {
		if (celija_zauzeta(i, j + 1)) brojac++;
		if ((i - 1 >= 0) && celija_zauzeta(i - 1, j + 1)) brojac++;
		if ((i + 1 < REDAKA) && celija_zauzeta(i + 1, j + 1)) brojac++;
	}
	// ako su zivi gornji i donji neka ih izbroji
	if ((i - 1 >= 0) && celija_zauzeta(i - 1, j)) brojac++;
	if ((i + 1 < REDAKA) && celija_zauzeta(i + 1, j)) brojac++;

	return brojac;
}


// ******** Buduci da su mi vrijednosti celija bool mozda funkcija nema smisla ovdje, ali ostavila sam ju za slucaj da se zeli promijeniti ELTYPE u headeru.
bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == ZIVA) return true;
	return false;
}


// ******** Konstruktor je prva generacija, a sansa od 20% se dobije od slucajnog broja od 1 do 100 pa ako je % 5 == 0 celija je ZIVA
game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (slucajna_vrijednost(1, 100) % 5 == 0) _generacija[i][j] = ZIVA;
			else _generacija[i][j] = MRTVA;
		}
	}
}


// ******** Ova funkcija kroz petlju poziva brojanje susjeda pa ovisno o tome i stanju ziva/mrtva odredjuje sudbinu nove generacije
void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i,j) && (broj_susjeda(i,j) < 2 || broj_susjeda(i, j) > 3)) _sljedeca_generacija[i][j] = MRTVA;
			else if (!celija_zauzeta(i, j) && (broj_susjeda(i, j) != 3)) _sljedeca_generacija[i][j] = MRTVA;
			else _sljedeca_generacija[i][j] = ZIVA;
		}
	}
	// prepisuje se nova generacija u staru
	for (int i = 0; i < REDAKA; i++) for (int j = 0; j < STUPACA; j++) _generacija[i][j] = _sljedeca_generacija[i][j];
}


// ******** Iscrtavanje samo gleda je li zauzeta celija ili ne
void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i,j)) cout << "*";
			else cout << "-";
		}
		cout << endl;
	}
}
