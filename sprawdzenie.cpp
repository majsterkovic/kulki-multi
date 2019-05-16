#include "definicje.hpp"

extern bool wygrana;
extern int x;
extern int y;

extern unsigned char Xx;
extern unsigned char Oo;

bool sprawdzPlansze(unsigned char plansza[12][12])
{
    for(int i=0; i<11; i++)
        {
        if(plansza[1][i]==176)
            return true; // pusta
        }
    return false; // pełna
}


void pokazwygrana(unsigned char plansza[12][12], int wspolrzedne[16][8], int liczba_win)
{
    system("cls");
    unsigned char graczwygrany;
    if(plansza[  wspolrzedne[0][0]]  [wspolrzedne[0][1] ]==Xx)
        {
           graczwygrany = Xx;
        }
    else if( plansza[wspolrzedne[0][0]] [wspolrzedne[0][1]]==Oo)
        {
            graczwygrany = Oo;
        }

    for(int j=0; j<liczba_win; j++)
    {
        plansza[wspolrzedne[j][0]][wspolrzedne[j][1]] = '$';
        plansza[wspolrzedne[j][2]][wspolrzedne[j][3]] = '$';
        plansza[wspolrzedne[j][4]][wspolrzedne[j][5]] = '$';
        plansza[wspolrzedne[j][6]][wspolrzedne[j][7]] = '$';
    }

    planszuj(plansza);

    if(graczwygrany==Xx)
        {
            cout << "Wygral gracz " << Xx <<" !" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            for(int i=0; i<liczba_win; i++)
            {
                PlaySound("coin.wav", NULL, SND_ASYNC);
                std::this_thread::sleep_for(std::chrono::milliseconds(1900));
            }
        }
    else if(graczwygrany==Oo)
        {
            cout << "Wygral gracz " << Oo <<" !" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            for(int i=0; i<liczba_win; i++)
            {
                PlaySound("coin.wav", NULL, SND_ASYNC);
                std::this_thread::sleep_for(std::chrono::milliseconds(1900));
            }
        }


}


int sprawdzenie(unsigned char plansza[12][12])
{
    int wsp[16][8];
    int liczba_wygranych = 0;
    for(int i=0;i<4;i++)
    {
        if((plansza[x][y-3+i]==plansza[x][y-2+i]) && (plansza[x][y-1+i] == plansza[x][y+i]) && (plansza[x][y-2+i]==plansza[x][y+i]))
        {
            wygrana = true;
            wsp[liczba_wygranych][0] = x;
            wsp[liczba_wygranych][1] = y-3+i;
            wsp[liczba_wygranych][2] = x;
            wsp[liczba_wygranych][3] = y-2+i;
            wsp[liczba_wygranych][4] = x;
            wsp[liczba_wygranych][5] = y-1+i;
            wsp[liczba_wygranych][6] = x;
            wsp[liczba_wygranych][7] = y+i;
            liczba_wygranych++;
        }

        if((plansza[x-3+i][y]==plansza[x-2+i][y]) && (plansza[x-1+i][y] == plansza[x+i][y]) && (plansza[x-2+i][y]==plansza[x+i][y]))
        {
            wygrana = true;
            wsp[liczba_wygranych][0] = x-3+i;
            wsp[liczba_wygranych][1] = y;
            wsp[liczba_wygranych][2] = x-2+i;
            wsp[liczba_wygranych][3] = y;
            wsp[liczba_wygranych][4] = x-1+i;
            wsp[liczba_wygranych][5] = y;
            wsp[liczba_wygranych][6] = x+i;
            wsp[liczba_wygranych][7] = y;
            liczba_wygranych++;
        }

        if((plansza[x-3+i][y-3+i]==plansza[x-2+i][y-2+i]) && (plansza[x-1+i][y-1+i] == plansza[x+i][y+i]) && (plansza[x-2+i][y-2+i]==plansza[x+i][y+i]))
        {
            wygrana = true;
            wsp[liczba_wygranych][0] = x-3+i;
            wsp[liczba_wygranych][1] = y-3+i;
            wsp[liczba_wygranych][2] = x-2+i;
            wsp[liczba_wygranych][3] = y-2+i;
            wsp[liczba_wygranych][4] = x-1+i;
            wsp[liczba_wygranych][5] = y-1+i;
            wsp[liczba_wygranych][6] = x+i;
            wsp[liczba_wygranych][7] = y+i;
            liczba_wygranych++;
        }

        if((plansza[x+3-i][y-3+i]==plansza[x+2-i][y-2+i]) && (plansza[x+1-i][y-1+i] == plansza[x-i][y+i]) && (plansza[x+2-i][y-2+i]==plansza[x-i][y+i]))
        {
            wygrana = true;
            wsp[liczba_wygranych][0] = x+3-i;
            wsp[liczba_wygranych][1] = y-3+i;
            wsp[liczba_wygranych][2] = x+2-i;
            wsp[liczba_wygranych][3] = y-2+i;
            wsp[liczba_wygranych][4] = x+1-i;
            wsp[liczba_wygranych][5] = y-1+i;
            wsp[liczba_wygranych][6] = x-i;
            wsp[liczba_wygranych][7] = y+i;
            liczba_wygranych++;
        }
    }
    if(liczba_wygranych>0)
        pokazwygrana(plansza, wsp, liczba_wygranych);
}