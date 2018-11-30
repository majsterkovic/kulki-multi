#include "definicje.hpp"

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
