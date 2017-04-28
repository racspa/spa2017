#include "game_of_life.h"


game_of_life::game_of_life() //konstruktor - postaviti slucajne vrijednosti, trpati u polja, pozvati stupce i retke iz .h
{

	srand(time(nullptr)); //seed

	//ubacivnje u polja boolova
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{

			//treba generiraj slucajni broj
			unsigned int vrijednost = rand() % 100 + 1;
			//cout << vrijednost << endl;  //samo debagiranje
			bool generirana_vrijednost;

			//uvjet da je manje od vrijednosti postavljene u .h
			if (vrijednost <= slucajna_vrijednost)
			{
				generirana_vrijednost = true;
			}

			else
			{
				generirana_vrijednost = false;
			}
			//sad treba strpati u polje			
			trpaj_u_polje[i][j] = generirana_vrijednost;

		}
	}

}

void game_of_life::sljedeca_generacija() //uvjeti - susjedi (8 celija oko zive/mrtve
{
	
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				//		i	 jjjjjjjj  
				//		i	 p1 p2 p3  
				//		i	 p4    p5  
				//		i	 p6 p7 p8  

				//condition   ?   if true  :  if false
				//if (condition)	{is true}  else	{is false}

				int p1 = trpaj_u_polje[i - 1][j - 1]	?	(i != 0				&& j != 0)			: false;	//1	 **
				int p2 = trpaj_u_polje[i][j - 1]		?	(					   j != 0)			: false;	//2  *
				int p3 = trpaj_u_polje[i + 1][j - 1]	?	(i != REDAKA - 1	&& j != 0)			: false;	//3
				int p4 = trpaj_u_polje[i - 1][j]		?	(i != 0)								: false;	//4  **
				int p5 = trpaj_u_polje[i + 1][j]		?	(i != REDAKA - 1)						: false;	//5
				int p6 = trpaj_u_polje[i - 1][j + 1]	?	(i != 0				&& j != STUPACA - 1): false;	//6  **
				int p7 = trpaj_u_polje[i][j + 1]		?	(					   j != STUPACA - 1): false;	//7	
				int p8 = trpaj_u_polje[i + 1][j + 1]	?	(i != REDAKA - 1	&& j != STUPACA - 1): false;	//8

				int broj_susjeda = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;


				//cout << broj_susjeda << endl << endl;  //za debagiranje
			
			
				//�ivi organizam u �eliji pre�ivljava - broj susjeda 2 ili 3
				if (trpaj_u_polje[i][j])
				{
					if (broj_susjeda == 2 || broj_susjeda == 3)
					{
						_sljedeca_generacija[i][j] = true;
					}
				}

				//�ivi organizam u �eliji umire  - broj susjeda manji od 2 ili ve�i od 3
				if (trpaj_u_polje[i][j])
				{
					if (broj_susjeda < 2 || broj_susjeda > 3)
					{
						_sljedeca_generacija[i][j] = false;
					}
				}


				//U praznoj �eliji se ra�a novi organizam ukoliko se u to�no tri njene susjedne �elije nalaze �ivi organizmi.Igra �ivota po�inje od zadane po�etne konfiguracije i u diskretnim trenucima se formiraju sljede�e konfiguracije organizama istovremenom primjenom gornjih pravila na sve �elije prethodne konfiguracije.Igra nema kraja.
				if (!trpaj_u_polje[i][j])
				{
					if (broj_susjeda == 3)
					{
						_sljedeca_generacija[i][j] = true;
					}
					else
					{
						_sljedeca_generacija[i][j] = false;
					}
				}

			}
		}

		//proci kroz polje refreshati generacije
		for (int a = 0; a < REDAKA; a++) {
			for (int b = 0; b < STUPACA; b++) {
				trpaj_u_polje[a][b] = _sljedeca_generacija[a][b];
			}
		}

}

void game_of_life::iscrtaj()
{
	system("cls");
	for (int a = 0; a < REDAKA; a++)
	{
		for (int b = 0; b < STUPACA; b++)
		{
			if (trpaj_u_polje[a][b])
			{
				cout << '*';
			}

			else
			{
				cout << '-';
			}

		}
		cout << endl;
	}

	cout << endl;


}
