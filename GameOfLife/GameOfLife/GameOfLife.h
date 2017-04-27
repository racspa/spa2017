#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <random>
using namespace std;

class GameOfLife {
public:
	GameOfLife();
	void sljedecaGeneracija();
	void iscrtaj();

private:
	//Functions
	void initBoard();
	int getRandomNumber(int from, int to);
	bool randomHitChance(int percentChanceToHit);
	int numberOfSurroundingAliveCells(int currentRow, int currentColumn);

	//Constants
	static const unsigned int NUM_COLUMNS = 40;
	static const unsigned int NUM_ROWS = 20;
	//Chance to spawn a live cell per tile
	static const unsigned int ALIVE_CELL_SPAWN_CHANCE_PERCENTAGE = 20;
	static const char DEAD_CELL = '-';
	static const char ALIVE_CELL = '*';

	//Variables
	char _currentGeneration[NUM_ROWS][NUM_COLUMNS];
	char _nextGeneration[NUM_ROWS][NUM_COLUMNS];

	/*
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedecaGeneracija[REDAKA][STUPACA];
	bool slucajnaVrijednost();
	bool celijaZauzeta(int i, int j);
	*/
};

#endif
