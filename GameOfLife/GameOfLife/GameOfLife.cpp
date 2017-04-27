#include "GameOfLife.h"

//ctor
GameOfLife::GameOfLife()
{
	initBoard();
}

//configure the board for the next generation
//where all the logic is implemented
void GameOfLife::sljedecaGeneracija()
{
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {

			int aliveCellsAroundCurrentCell = numberOfSurroundingAliveCells(i, j);

			//Alive cell logic
			if (_currentGeneration[i][j] == ALIVE_CELL) {

				if (aliveCellsAroundCurrentCell < 2 || aliveCellsAroundCurrentCell > 3)
					_nextGeneration[i][j] = DEAD_CELL;

				else
					_nextGeneration[i][j] = ALIVE_CELL;

			}

			//Dead cell logic
			else {

				if(aliveCellsAroundCurrentCell == 3)
					_nextGeneration[i][j] = ALIVE_CELL;

				else
					_nextGeneration[i][j] = DEAD_CELL;

			}
		}
	}

	//Next generation comes to life!
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLUMNS; j++)
			_currentGeneration[i][j] = _nextGeneration[i][j];
}

//Draw the board
void GameOfLife::iscrtaj()
{
	//Clear screen
	system("cls");

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			cout << _currentGeneration[i][j];
		}
		cout << endl;
	}
}

//Initialize the board (by default 20% chance to spawn live cell on each spot) - called only when the game is run
void GameOfLife::initBoard()
{
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {

			if (randomHitChance(ALIVE_CELL_SPAWN_CHANCE_PERCENTAGE))
				_currentGeneration[i][j] = ALIVE_CELL;

			else
				_currentGeneration[i][j] = DEAD_CELL;

		}
	}
}

//RNG - can be turned into RNG for double numbers (currently it's being rounded to int)
//includes both [from] and [to] in the generating interval
int GameOfLife::getRandomNumber(int from, int to)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(from, to);

	return round(dist(mt));
}

//Returns whether or not something was successful based on the given percentage (using random number)
bool GameOfLife::randomHitChance(int percentChanceToHit)
{
	if (percentChanceToHit < 1 || percentChanceToHit > 100) return false;

	return (getRandomNumber(1, 100) <= percentChanceToHit);
}

//Checks all the cells around the current spot and counts how many cells are alive
int GameOfLife::numberOfSurroundingAliveCells(int currentRow, int currentColumn)
{
	int aliveCells = 0;

	//i = currentRow, j = currentColumn;

	//(i - 1, j - 1)(i, j - 1)(i + 1, j - 1)
	//(i - 1, j    )(i, j    )(i + 1, j    )
	//(i - 1, j + 1)(i, j + 1)(i + 1, j + 1)

	for (int i = currentRow - 1; i <= currentRow + 1; i++) {
		for (int j = currentColumn - 1; j <= currentColumn + 1; j++) {

			//Don't check the current spot
			if (!(i == currentRow && j == currentColumn)) {

				//Don't check if out of bounds (exception) - simply don't count them
				if (i >= 0 && i < NUM_ROWS && j >= 0 && j < NUM_COLUMNS) {

					//Raise the count if there are alive cells
					if (_currentGeneration[i][j] == ALIVE_CELL) aliveCells++;

				}

			}
		}
	}

	return aliveCells;
}
