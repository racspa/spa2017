#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include<array>

class game_of_life {
private:
	static const unsigned int STUPACA = 42;
	static const unsigned int REDAKA = 22;
	std::array<std::array<bool, STUPACA>, REDAKA> _generacija;
	std::array<std::array<bool, STUPACA>, REDAKA> __sljedeca_generacija;
	bool slucajna_vrijednost();
public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
