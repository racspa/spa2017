#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	char _generacija[REDAKA][STUPACA];
	char _sljedeca_generacija[REDAKA][STUPACA];
	int slucajna_vrijednost();
	bool je_ziva(int i, int j);
	int broj_zivih(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
