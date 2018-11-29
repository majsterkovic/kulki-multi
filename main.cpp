#include "definicje.hpp"

//kod 0 = 48
//kod ░ = 176
bool wygrana = false;

void kropki(int l)
{
    for(int i=0; i<l; i++){
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int wypelnijplansze(unsigned char plansza[12][12])
{
   for(int g=0; g<12; g++)
        {
        for(int h=0; h<12; h++)
        {
            plansza[g][h]='0';
        }
    }
}

void planszuj(unsigned char plansza[12][12])
{
    cout << " ";
    for(int f=0; f<10; f++)
            {
                cout << setw(1) << "|" << f;
            }
    cout << "|" << endl;

    for(int g=1; g<11; g++)
        {
            cout << g-1;
            for(int h=1; h<11; h++)
            {
                cout << setw(1) << "|" << plansza[g][h];
            }
            cout << "|" << endl;
        }
    cout << endl;
}

void gracz(unsigned char plansza[12][12])
{
    int x;
    int y;
    bool b = 1;

    do{
    cout << "Gdzie chcesz postawic swoja kulke? Podaj wspolrzedne [wiersz i kolumna]: ";
    cin >> y;
    cin >> x;
    x = x+1;
    y = y+1;
    if((plansza[y][x] == 176) && (plansza[y+1][x] == '0' || plansza[y+1][x] == 'O' || plansza[y+1][x] == 'X'))
        {
            plansza[y][x] = 'X';
            b = 0;
        }
    else
    {
            cout << "Sprobuj jeszcze raz: " << endl;
    }
    }while(b==1);
}

int komputer(unsigned char plansza[12][12])
{
    int x, y;
    int M = 0;
    bool b = 1;
    do{
    x = (std::rand() % 10) + 1;
    y = (std::rand() % 10) + 1;

    if((plansza[y][x] == 176) && (plansza[y+1][x] == '0' || plansza[y+1][x] == 'O' || plansza[y+1][x] == 'X'))
        {
            plansza[y][x] = 'O';
            b = 0;
        }
    else
    {
        M++;
        if(M==999)
        {
            cout << endl << endl << "Przykro mi, cos jest nie tak, PRZERWIJ GRE" << endl;;
        }
    }

    }while(b==1 && M<1000);

}

int main()
{
    srand(time(NULL));
    cout << "Witaj w grze w kulki xD" << endl;
    unsigned char plansza[12][12];
    wypelnijplansze(plansza);

    for(int g=1; g<11; g++)
        {
        for(int h=1; h<11; h++)
        {
            plansza[g][h] = 176;
            cout << "|" << plansza[g][h];
        }
        cout << "|" << endl;
    }
    cout << endl;

    do{

    //cout << "\a";
    Beep(1244, 1000);
    gracz(plansza);
    planszuj(plansza);
    sprawdzenie(plansza);
    if(wygrana==true) break;
    komputer(plansza);
    planszuj(plansza);
    sprawdzenie(plansza);
    // cout << "Uwaga, czyszczenie konsoli za 8 sekund!" << endl;
    kropki(3);
    // system("cls");
    }while(wygrana==false);

    
    cout << "Dziekuje za gre!";
    char pomoc;
    cin >> pomoc;
    return 0;
}
