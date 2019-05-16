#ifndef definicje_hpp
#define definicje_hpp

#include <cstdlib> // losowanko
#include <iostream> //cin cout
#include <iomanip> // ³adne wyœwietlanie
#include <chrono> // zatrzymywanie
#include <ctime> // losowanie
#include <thread> // zatrzymywanie
#include <random> // losowanko (u mnie nie potrzeba ale w szkole tak)
#include <windows.h> // beep
#include <conio.h> //muzyka

using namespace std;

int sprawdzenie(unsigned char plansza[12][12]);
void kropki(int l);
int wypelnijplansze(unsigned char plansza[12][12]);
void planszuj(unsigned char plansza[12][12]);
int komputer(unsigned char plansza[12][12]);
int gracz(unsigned char plansza[12][12], int gracz);
bool sprawdzPlansze(unsigned char plansza[12][12]);
void wybierzskin(int g);


#endif
