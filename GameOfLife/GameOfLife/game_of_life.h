#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 60;
	static const unsigned int REDAKA = 40;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int x, int y);
	int rand_broj(int min, int max); //m-min, M-Max
	int neighbour_count_alg(int min, int max);//Funkcija za brojanje broja susjeda

public:
	game_of_life();
	void sljedeca_generacija(); //def konstruktor
	void iscrtaj();
};

#endif