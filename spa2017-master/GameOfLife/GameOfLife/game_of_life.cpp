#include "game_of_life.h"
#include <ctime>
bool game_of_life::slucajna_vrijednost()
{
    int _stanje;
   
    _stanje = (rand() % 100) + 1;

    if (_stanje <= 20)
    {
        return true;
    }
    return false;
    
}

bool game_of_life::granice(int &i, int &j)
{
    if (i > 0 && i < REDAKA && j > 0 && j < STUPACA)
    {
          return true;
    }

    return false;
}

bool game_of_life::celija_je_ziva(int &i, int &j)
{
    if (_generacija[i][j] == '*') {

        return true;
    }
    return false;
}

int game_of_life::broj_zivih_susjeda(int &i, int &j)
{
    int susjedi = 0;

    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            int broj1 = i + x;
            int broj2 = j + y;
            if (granice(broj1, broj2) && _generacija[broj1][broj2] == '*')
            {
                susjedi++;
            }

        }
    }

   if (celija_je_ziva(i,j))
      {
        susjedi = susjedi - 1;
      }

    return susjedi;
}

game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            if (slucajna_vrijednost())
            {
                this->_generacija[i][j] = '*';
            }
            else
            {
                this->_generacija[i][j] = '-';
            }
        }
    }

}

void game_of_life::sljedeca_generacija()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
          if (celija_je_ziva(i,j))
          {
          int a = broj_zivih_susjeda(i, j);
              if (a < 2 || a > 3)
              {
                  _sljedeca_generacija[i][j] = '-';
              }
              else if (a == 3 || a == 2)
              {
                  _sljedeca_generacija[i][j] = '*';
              }
          }
          else
          {
              int a = broj_zivih_susjeda(i, j);
              if (a == 3)
              {
                  _sljedeca_generacija[i][j] = '*';
              }
              else
                  _sljedeca_generacija[i][j] = '-';
          }
          
        }
    }

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
   
}

void game_of_life::iscrtaj()
{
    system("cls");
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            cout << _generacija[i][j];       
        }

        cout << endl;
    }
}
