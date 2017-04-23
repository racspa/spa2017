#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int STUPACA_SA_OKVIROM = STUPACA + 2;
	static const unsigned int REDAKA = 20;
	static const unsigned int REDAKA_SA_OKVIROM = REDAKA + 2;
	bool _generacija[REDAKA_SA_OKVIROM][STUPACA_SA_OKVIROM];
	bool _sljedeca_generacija[REDAKA_SA_OKVIROM][STUPACA_SA_OKVIROM];

	int slucajna_vrijednost();
	bool stvaranje_zivota_u_celiji(int postotak_sanse_za_zivot);
	//bool celija_zauzeta(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
