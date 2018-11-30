#include "definicje.hpp"

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
