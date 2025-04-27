#include <iostream>
#include <iomanip>

#include "relogio.h"

using namespace std;

int main()
{
    int horas, minutos, segundos;

    Relogio relogio;

    relogio.getHorario(horas, minutos, segundos);

    cout << setfill('0') << setw(2) << horas << ":"
         << setfill('0') << setw(2) << minutos << ":"
         << setfill('0') << setw(2) << segundos << endl;

    relogio.setHorario(17, 52, 31);

    relogio.getHorario(horas, minutos, segundos);

    cout << setfill('0') << setw(2) << horas << ":"
         << setfill('0') << setw(2) << minutos << ":"
         << setfill('0') << setw(2) << segundos << endl;

    for(int i = 0; i < 600; i++){
        relogio.tick();

        relogio.getHorario(horas, minutos, segundos);
    }

    relogio.getHorario(horas, minutos, segundos);

    cout << setfill('0') << setw(2) << horas << ":"
         << setfill('0') << setw(2) << minutos << ":"
         << setfill('0') << setw(2) << segundos << endl;
}
