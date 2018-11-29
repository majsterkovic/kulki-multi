#include "definicje.hpp"

extern bool wygrana;
int sprawdzenie(unsigned char plansza[12][12])
{
    for(int j=0; j<11; j++)
    {
    for(int i=0;i<11;i++)
    {
        if
        (
            ((plansza[j][i]==plansza[j][i+1]) && (plansza[j][i+2] == plansza[j][i+3]) && (plansza[j][i]==plansza[j][i+3]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O'))) ||
            ((plansza[i][j]==plansza[i+1][j]) && (plansza[i+2][j] == plansza[i+3][j]) && (plansza[i][j]==plansza[i+3][j]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O'))) ||
            ((plansza[i][j]==plansza[i+1][j+1]) && (plansza[i+2][j+2] == plansza[i+3][j+3]) && (plansza[i][j]==plansza[i+3][j+3]) && ((plansza[i][j]=='X') || (plansza[i][i]=='O'))) ||
            ((plansza[i][j]==plansza[i-1][j+1]) && (plansza[i-2][j+2] == plansza[i-3][j+3]) && (plansza[i][j]==plansza[i-3][j+3]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O')))
        )
           {
              wygrana = true;
              if(plansza[i][j]=='X')
              cout << "Wygrales! Gitara siema!" << endl;
              else if(plansza[i][j]=='O')
              cout << "Wygral komputer ty slabiaku!" << endl;
           }

           /*jak działa to nie ruszać*/
        /*ruszyłem i działa*/
    }
    }
return wygrana;
}
