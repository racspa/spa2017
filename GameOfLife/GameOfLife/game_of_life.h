#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class game_of_life {
private:
	static const unsigned int REDAKA = 20;
	static const unsigned int STUPACA = 40;
	static const unsigned int slucajna_vrijednost=20;
	bool trpaj_u_polje[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();

};

#endif
