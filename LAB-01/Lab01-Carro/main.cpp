#include <iostream>

#include "carro.h"

using namespace std;

int main()
{
    Carro c1;

    cout << "Combustível Inicial: " << c1.getCombustivel() << endl;
    cout << "Quilometragem Inicial: " << c1.getQuilometragem() << endl;

    c1.percorrerDistancia(15);
    cout << "Distancia percorrida: " << c1.getQuilometragem() << endl;
    cout << "Combustível Atual: " << c1.getCombustivel() << endl;

    c1.percorrerDistancia(700);
    cout << "Distancia percorrida: " << c1.getQuilometragem() << endl;
    cout << "Combustível Atual: " << c1.getCombustivel() << endl;

    c1.abastecer(10);
    cout << "Combustível Atual: " << c1.getCombustivel() << endl;

    c1.percorrerDistancia(300);
    cout << "Distancia percorrida: " << c1.getQuilometragem() << endl;
    cout << "Combustível Atual: " << c1.getCombustivel() << endl;
}
