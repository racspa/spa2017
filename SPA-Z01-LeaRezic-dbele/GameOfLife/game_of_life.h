#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
using namespace std;
typedef bool ELTYPE;

// U header sam dodala ELTYPE tipa bool, pa se u implementaciji celije odredjuju sa ZIVA ili MRTVA, neovisno o tome sto je ELTYPE

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	static const ELTYPE ZIVA = true;
	static const ELTYPE MRTVA = false;
	ELTYPE _generacija[REDAKA][STUPACA];
	ELTYPE _sljedeca_generacija[REDAKA][STUPACA];
	int slucajna_vrijednost(int min, int max);
	int broj_susjeda(int i, int j);
	bool celija_zauzeta(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
