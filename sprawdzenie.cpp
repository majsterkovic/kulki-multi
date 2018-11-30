#include "definicje.hpp"

extern bool wygrana;
extern int x;
extern int y;

void pokazwygrana(unsigned char plansza[12][12], int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
   if(plansza[x1][y1]=='X')
        {
            PlaySound("coin.wav", NULL, SND_ASYNC);
            cout << "Wygral gracz X!" << endl;
        }
    else if(plansza[x1][y1]=='O')
        {
            PlaySound("coin.wav", NULL, SND_ASYNC);
            cout << "Wygral gracz O!" << endl;
        }
}


int sprawdzenie(unsigned char plansza[12][12])
{
    int wsp[4][2];
    for(int i=0;i<4;i++)
    {
        if((plansza[x][y-3+i]==plansza[x][y-2+i]) && (plansza[x][y-1+i] == plansza[x][y+i]) && (plansza[x][y-2+i]==plansza[x][y+i]))
        {
            wygrana = true;
            pokazwygrana(plansza, x, y-3+i, x, y-2+i, x, y-1+i, x,y+i);
        }

        if((plansza[x-3+i][y]==plansza[x-2+i][y]) && (plansza[x-1+i][y] == plansza[x+i][y]) && (plansza[x-2+i][y]==plansza[x+i][y]))
        {
            wygrana = true;
            pokazwygrana(plansza, x-3+i, y, x-2+i, y, x-1+i, y, x+i, y);
        }

        if((plansza[x-3+i][y-3+i]==plansza[x-2+i][y-2+i]) && (plansza[x-1+i][y-1+i] == plansza[x+i][y+i]) && (plansza[x-2+i][y-2+i]==plansza[x+i][y+i]))
        {
            wygrana = true;
            pokazwygrana(plansza, x-3+i, y-3+i, x-2+i, y-2+i, x-1+i, y-1+i, x+i, y+i);
        }

        if((plansza[x+3-i][y-3+i]==plansza[x+2-i][y-2+i]) && (plansza[x+1-i][y-1+i] == plansza[x-i][y+i]) && (plansza[x+2-i][y-2+i]==plansza[x-i][y+i]))
        {
            wygrana = true;
            pokazwygrana(plansza, x+3-i, y-3+i, x+2-i, y-2+i, x+1-i, y-1+i, x-i, y+i);
        }
    }
    return wygrana;
}
