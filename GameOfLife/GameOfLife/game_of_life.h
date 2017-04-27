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
	bool _polje[REDAKA][STUPACA];
	bool _sljedece_polje[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool evolve_zivu(int i, int j);
	bool evolve_mrtvu(int i, int j);
	//bool celija_zauzeta(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
