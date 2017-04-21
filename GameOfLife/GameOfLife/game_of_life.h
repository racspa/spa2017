#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 8;
	static const unsigned int init_chance_in_percent = 20;

	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	unsigned short int broj_susjeda(int r, int s);
	void update_generation();

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
