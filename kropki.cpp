#include "definicje.hpp"

void kropki(int l)
{
    for(int i=0; i<l; i++){
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
