#include "game_of_life.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

int game_of_life::brojSusjeda(int x, int y){
	int count=0;
	if(celija_zauzeta(x-1,y-1))count++;
	if(celija_zauzeta(x+1,y-1))count++;
	if(celija_zauzeta(x-1,y+1))count++;
	if(celija_zauzeta(x+1,y+1))count++;
	return count;
}

bool game_of_life::slucajna_vrijednost(){
	return rand()%100+1<=20;
}

bool game_of_life::celija_zauzeta(int i, int j){
	if(i<0||j<0)return false;
	if(i>=REDAKA||j>STUPACA)return false;
	return _generacija[i][j];
}

game_of_life::game_of_life(){
	srand(time(0));

	for(int x=0;x<REDAKA;x++){
		for(int y=0;y<STUPACA;y++){
			_generacija[x][y]=slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija(){
	for(int x=0;x<REDAKA;x++){
		for(int y=0;y<STUPACA;y++){

			int broj=brojSusjeda(x,y);
			if(celija_zauzeta(x,y))_sljedeca_generacija[x][y]=broj==2||broj==3;
			else _sljedeca_generacija[x][y]=broj==3;

		}
	}

	for(int x=0;x<REDAKA;x++){
		for(int y=0;y<STUPACA;y++){
			_generacija[x][y]=_sljedeca_generacija[x][y];
		}
	}
}

void game_of_life::iscrtaj(){
	system ("cls");
	for(int x=0;x<REDAKA;x++){
		for(int y=0;y<STUPACA;y++){
			if(celija_zauzeta(x,y))cout<<"*";
			else cout<<"-";
		}
		cout<<"\n";
	}
}
