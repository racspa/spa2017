#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	char _generacija[REDAKA][STUPACA];
	char _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool granice(int &i, int &j);
    bool celija_je_ziva(int &i, int &j);
    int broj_zivih_susjeda(int &i, int &j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
