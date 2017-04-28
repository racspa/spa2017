#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int _STUPACA = 40;
	static const unsigned int _REDAKA = 20;
	static const unsigned int _vjerojatnost = 20;
	bool _generacija[_REDAKA][_STUPACA];
	bool _sljedeca_generacija[_REDAKA][_STUPACA];
	bool _slucajna_vrijednost();
	int _broj_susjeda(int i, int j);
public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif