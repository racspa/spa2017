#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	static const unsigned int ODSTUPANJE = 1;
	bool _generacija[REDAKA + 2 * ODSTUPANJE][STUPACA + 2 * ODSTUPANJE];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost(unsigned int povoljno, unsigned int ukupno);
	bool celija_zauzeta(int red, int stupac);
	void izracunaj(int red, int stupac);
	void preslikaj();

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
