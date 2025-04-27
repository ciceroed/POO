#include <iostream>

#include "circulo.h"

int main()
{
    Circulo a(1, {1,1});
    Circulo b(1, {2,2});

    cout << "Raio do circulo A: " << endl;
    a.printRaio();

    cout << "Centro do circulo A: " << endl;
    a.printCentro();

    cout << "Area do circulo A: " << endl;
    a.printArea();

    cout << "Circunferencia do circulo A: " << endl;
    a.printCircunferencia();

    cout << "Distancia entre centros de A e B: " << endl;
    a.printDistanciaCentro(b);

    cout << "Aumentando raio do circulo A em 70%..." << endl;
    a.aumentaRaio(1.7);
    a.printRaio();
    a.printArea();

    cout << "Reposicionando circulo A..." << endl;
    a.setCentro({1,2});
    a.printCentro();
    a.printDistanciaCentro(b);
}
