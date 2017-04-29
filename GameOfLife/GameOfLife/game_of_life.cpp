//
//  game_of_life.cpp
//  HW SPA
//
//  Created by Mark Tselikov on 27.04.17.
//  Copyright © 2017 Mark Tselikov. All rights reserved.
//


#include "game_of_life.h"

using namespace std;


game_of_life::game_of_life() {
    
    for(int i = 0; i < sizeof(_generacija) / sizeof(_generacija [0]); i++) {
        for(int j = 0; j < sizeof(_generacija [0]); j++) {
            _generacija [i] [j] = slucajna_vrijednost(20);
        }
    }
}


bool game_of_life::slucajna_vrijednost(int probability) {
    
    int value = rand() % 100;
    if(value > probability) return false;
    else return true;
}


bool game_of_life::celija_zauzeta(int i, int j) {
    
    if(_generacija [i][j] == true) return true;
    else return false;
}


void game_of_life::sljedeca_generacija() {
    
    int aliveNeighbours = 0;
    for(int i = 0; i < sizeof(_generacija) / sizeof(_generacija [0]); i++) {
        for(int j = 0; j < sizeof(_generacija [0]); j++) {
            
            aliveNeighbours = checkNeighbours(i, j);
            
            if(aliveNeighbours < 2 || aliveNeighbours > 3) _generacija [i][j] = false;
            if(aliveNeighbours == 3) _generacija [i][j] = true;
        }
    }
    
}


/**
 * A method that checks the adjacent cells and counts how many of them are alive
 * The border cells are concidered to not go out of bounds
 */
int game_of_life::checkNeighbours(int i, int j) {
    
    int aliveNeighbours = 0;
    if(i != 0) {
        if(_generacija[i - 1][j]) aliveNeighbours++;
    }
    if(j != 0) {
        if(_generacija[i][j - 1]) aliveNeighbours++;
    }
    if(i != sizeof(_generacija) / sizeof(_generacija [0])) {
        //cout << "i: " << i << endl; // TEST
        if(_generacija[i + 1][j]) aliveNeighbours++;
    }
    if(j != sizeof(_generacija [0])) {
        //cout << "j: "  << j << endl; // TEST
        if(_generacija[i][j + 1]) aliveNeighbours++;
    }
    
    return aliveNeighbours;
}


void game_of_life::iscrtaj() {
    
    for(int i = 0; i < sizeof(_generacija) / sizeof(_generacija [0]); i++) {
        for(int j = 0; j < sizeof(_generacija [0]); j++) {
            if(_generacija [i][j] == true) {
                cout << '*';
            }
            else {
                cout << '-'; //check
            }
        }
        cout << endl;
    }
    cout << endl;
}

