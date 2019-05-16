#include "definicje.hpp"

void kropki(int l)
{
    cout << "Uwaga, czyszczenie konsoli za " << l << " sekund(y)!" << endl;
    for(int i=0; i<l; i++){
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
