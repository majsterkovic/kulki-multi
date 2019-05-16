#include "definicje.hpp"

extern unsigned char Xx;
extern unsigned char Oo;

void wybierzskin(int g)
{
   char decyzja;
   unsigned char skin[8] = {254, 209, 226, 206, 207, 246, 158, 174};
   short wyb = 0;
   cout << endl << "Witaj graczu numer " << g << endl << "Czy czy chcesz zmienic wyglad swojego znaku? (T/N) " << endl;
   do
    {
        cin >> decyzja;

        if(decyzja!='N' && decyzja!='T')
            cout << "Wybierz T lub N!" << endl;
    }while(decyzja!='N' && decyzja!='T');

    if(decyzja == 'N')
        return;
    else
    {
        cout << "Oto moje skiny: "
        << endl << "1. " << static_cast<unsigned char>(254) //
        << endl << "2. " << static_cast<unsigned char>(209) //
        << endl << "3. " << static_cast<unsigned char>(226) //
        << endl << "4. " << static_cast<unsigned char>(206) //
        << endl << "5. " << static_cast<unsigned char>(207) //
        << endl << "6. " << static_cast<unsigned char>(246) //
        << endl << "7. " << static_cast<unsigned char>(158) //
        << endl << "8. " << static_cast<unsigned char>(174) //
        << endl << "Wybierz swoj skin (inna liczba, np. 0 oznacza, ze nie zmieniasz skina)" << endl << "Nie mozesz wybrac takiego samego skina jak inny gracz!" << endl;

        cin >> wyb;

        if(wyb >8 && wyb < 1)
        {
            cout << "Nie ma takiego skina. Dostajesz skin domyslny" << endl;
            return;
        }
        else
        {
            if(g == 1)
            Xx = skin[wyb-1];
            if(g == 2 && Xx == skin[wyb-1])
            {
                cout << "Ktos ma juz tego skina, dostajesz skin domyslny" << endl;
                return;
            }
            else if(g == 2)
            Oo = skin[wyb-1];
        }
    }
    return;
}


