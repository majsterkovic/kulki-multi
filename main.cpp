#include "definicje.hpp"

//kod 0 = 48
//kod ░ = 176
bool wygrana = false;
int x;
int y;

int gracz(unsigned char plansza[12][12], int gracz)
{

    bool b = 1;

    planszuj(plansza);

    do{
    cout << "Gdzie chcesz postawic swoja kulke? Podaj wspolrzedne [wiersz i kolumna]: ";
    cin >> y;
    cin >> x;
    x = x+1;
    y = y+1;
    if((plansza[x][y] == 176) && (plansza[x+1][y] == '0' || plansza[x+1][y] == 'O' || plansza[x+1][y] == 'X'))
        {
            if(gracz == 1)
                plansza[x][y] = 'X';
            else if(gracz ==2)
                plansza[x][y] = 'O';
                b = 0;
            Beep(1000,1000);
            planszuj(plansza);
        }
    else
    {
            cout << "Sprobuj jeszcze raz: " << endl;
    }

    }while(b==1);
}



int main()
{
    srand(time(NULL));
    char zgoda = 'T';

    while(zgoda=='T')
    {

    system("cls");
    wygrana == false;
    cout << "Witaj w grze w kulki xD" << endl << endl << "\a" ;
    unsigned char plansza[12][12];
    wypelnijplansze(plansza);

    for(int g=1; g<11; g++)
        {
        for(int h=1; h<11; h++)
        {
            plansza[g][h] = 176;
        }
    }

    do{

    gracz(plansza, 1);
    sprawdzenie(plansza);
    if(wygrana==true) break;

    else
    {
    cout << "Uwaga, czyszczenie konsoli za 2 sekundy" << endl;
    kropki(2);
    system("cls");
    }


    gracz(plansza, 2);
    sprawdzenie(plansza);

    if(wygrana == false)
    {
    cout << "Uwaga, czyszczenie konsoli za 2 sekundy!" << endl;
    kropki(2);
    system("cls");
    }


    }while(wygrana==false);

    cout << "Czy chcesz zagrac jeszcze raz? (T/N): " << endl;

    do{
        cin >> zgoda;

        if(zgoda!='N' && zgoda!='T')
            cout << "Wybierz T lub N!" << endl;

    }while(zgoda!='N' && zgoda!='T');


    }

    cout << "Dziekuje za gre!";
    char pomoc;
    cin >> pomoc;
    return 0;
}
