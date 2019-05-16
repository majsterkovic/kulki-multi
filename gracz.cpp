#include "definicje.hpp"

extern int x;
extern int y;

extern unsigned char Xx;
extern unsigned char Oo;

int gracz(unsigned char plansza[12][12], int gracz)
{
    cout << "Ruch gracza nr " << gracz << endl;
    bool b = 1;
    planszuj(plansza);

    do{

        do{
            cin.clear();
            cin.sync();
            cout << "Gdzie chcesz postawic swoja kulke? Podaj wspolrzedne [wiersz i kolumna]: ";
            cin >> x;
            cin >> y;
        }while (cin.fail() != 0);


    x = x+1;
    y = y+1;
    if((plansza[x][y] == 176) && (plansza[x+1][y] == '0' || plansza[x+1][y] == Oo || plansza[x+1][y] == Xx))
        {
            if(gracz == 1)
                plansza[x][y] = Xx;
            else if(gracz == 2)
                plansza[x][y] = Oo;
                b = 0;
            Beep(1122,788);
            planszuj(plansza);
        }
    else
    {
            cout << "Sprobuj jeszcze raz: " << endl;
    }

    }while(b==1);
}
