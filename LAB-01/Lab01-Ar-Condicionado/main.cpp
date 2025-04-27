#include <iostream>

#include "arcondicionado.h"

using namespace std;

int main()
{
    float temperatura;
    ArCondicionado c1(25), c2(31);

    cout << "Condicionadores criados." << endl;

    c1.setPotencia(5);
    cout << "Potência C1: " << c1.getPotencia() << endl;
    cout << "Temperatura inicial C1: " << c1.getSensor() << endl;

    temperatura = c1.calculaTemperatura();
    cout << "Temperatura C1 ligado: " << temperatura << endl;

    c2.setPotencia(10);
    cout << "Potência C2: " << c2.getPotencia() << endl;
    cout << "Temperatura inicial C2: " << c2.getSensor() << endl;

    temperatura = c2.calculaTemperatura();
    cout << "Temperatura C2 ligado: " << temperatura << endl;
}
