#include "definicje.hpp"

//kod 0 = 4
//kod ░ = 176
bool wygrana = false;
int x;
int y;

char Xx = 'X';
char Oo = 'O';


int main()
{
     char pomoc;
    srand(time(NULL));

    char zgoda = 'T';

    while(zgoda=='T')
        {

        system("cls");
        wygrana = false;
        cout << "Witaj w grze w kulki xD" << endl << endl/* << "\a" */ ;
        unsigned char plansza[12][12];
        wypelnijplansze(plansza);

        for(int g=1; g<11; g++) //tło
            {
                for(int h=1; h<11; h++)
                {
                    plansza[g][h] = 176;
                }
            }

        wybierzskin(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        wybierzskin(2);

        kropki(4);
        system("cls");

        do
        {

            gracz(plansza, 1);
            sprawdzenie(plansza);
            if(wygrana==true) break;

            else
            {
           // kropki(2);
            system("cls");
            }

        if(!sprawdzPlansze(plansza))
            {
            cout << "Koniec gry, plansza jest pelna" << endl;
            break;
            }


        gracz(plansza, 2);
        sprawdzenie(plansza);

        if(!sprawdzPlansze(plansza))
            {
            cout << "Koniec gry, plansza jest pelna" << endl;
            break;
            }

        if(wygrana == false)
        {
            // kropki(2);
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
    cin >> pomoc;
    return 0;
}