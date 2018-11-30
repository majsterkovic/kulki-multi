#include "definicje.hpp"

extern bool wygrana;
void pokazwygrana(unsigned char plansza[12][12], int z, int w)
{
   if(plansza[z][w]=='X')
        {
            PlaySound("coin.wav", NULL, SND_ASYNC);
            cout << "Wygral gracz X!" << endl;
        }
    else if(plansza[z][w]=='O')
        {
            PlaySound(".wav", NULL, SND_ASYNC);
            cout << "Wygral gracz O!" << endl;
        }
}



int sprawdzenie(unsigned char plansza[12][12])
{
for(int j=0; j<11; j++)
{
    for(int i=0;i<11;i++)
    {
        if
        (
            ((plansza[i][j]==plansza[i+1][j]) && (plansza[i+2][j] == plansza[i+3][j]) && (plansza[i][j]==plansza[i+3][j]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O'))) ||
            ((plansza[i][j]==plansza[i+1][j+1]) && (plansza[i+2][j+2] == plansza[i+3][j+3]) && (plansza[i][j]==plansza[i+3][j+3]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O'))) ||
            ((plansza[i][j]==plansza[i-1][j+1]) && (plansza[i-2][j+2] == plansza[i-3][j+3]) && (plansza[i][j]==plansza[i-3][j+3]) && ((plansza[i][j]=='X') || (plansza[i][j]=='O')))
        )
           {
              wygrana = true;
              pokazwygrana(plansza, i, j);


           }
        if((plansza[j][i]==plansza[j][i+1]) && (plansza[j][i+2] == plansza[j][i+3]) && (plansza[j][i]==plansza[j][i+3]) && ((plansza[j][i]=='X') || (plansza[j][i]=='O')))
        {
            wygrana = true;
            pokazwygrana(plansza, j, i);
        }

           /*jak działa to nie ruszać*/
    }
}

return wygrana;
}
