#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

//kod 0 = 48
//kod ░ = 176
using namespace std;
bool wygrana = false;

void kropki(int l)
{
    for(int i=0; i<l; i++){
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int wypelnijplansze(unsigned char plansza[16][16])
{
   for(int g=0; g<16; g++)
        {
        for(int h=0; h<16; h++)
        {
            plansza[g][h]='0';
        }
    }
}

void planszuj(unsigned char plansza[16][16])
{
    cout << " ";
    for(int f=0; f<10; f++)
            {
                cout << setw(1) << "|" << f;
            }
    cout << "|" << endl;

    for(int g=3; g<13; g++)
        {
            cout << g-3;
            for(int h=3; h<13; h++)
            {
                cout << setw(1) << "|" << plansza[g][h];
            }
            cout << "|" << endl;
        }
    cout << endl;
}

void gracz(unsigned char plansza[16][16])
{
    int x;
    int y;
    bool b = 1;

    do{
    cout << "Gdzie chcesz postawic swoja kulke? Podaj wspolrzedne [wiersz i kolumna]: ";
    cin >> y;
    cin >> x;
    x = x+3;
    y = y+3;
    if((plansza[y][x] == 176) && (plansza[y+1][x] == '0' || plansza[y+1][x] == 'O' || plansza[y+1][x] == 'Q'))
        {
            plansza[y][x] = 'Q';
            b = 0;
        }
    else
    {
            cout << "Sprobuj jeszcze raz: " << endl;
    }
    }while(b==1);
}

int komputer(unsigned char plansza[16][16])
{
    int x, y;
    int M = 0;
    bool b = 1;
    do{
    x = (std::rand() % 10) + 3;
    y = (std::rand() % 10) + 3;

    if((plansza[y][x] == 176) && (plansza[y+1][x] == '0' || plansza[y+1][x] == 'O' || plansza[y+1][x] == 'Q'))
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
    unsigned char plansza[16][16];
    wypelnijplansze(plansza);

    for(int g=3; g<13; g++)
        {
        for(int h=3; h<13; h++)
        {
            plansza[g][h] = 176;
            cout << "|" << plansza[g][h];
        }
        cout << "|" << endl;
    }
    cout << endl;

    do{

    gracz(plansza);
    planszuj(plansza);
    komputer(plansza);
    planszuj(plansza);
    cout << "Uwaga, czyszczenie konsoli za 8 sekund!" << endl;
    kropki(3);
    system("cls");

    }while(wygrana==false);

    return 0;
}
