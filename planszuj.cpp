#include "definicje.hpp"

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
