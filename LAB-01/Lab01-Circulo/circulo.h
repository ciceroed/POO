#ifndef CIRCULO_H
#define CIRCULO_H

#include <array>

using namespace std;

class Circulo
{
private:
    float _area;
    float _raio;
    array <float, 2> _centro;

    float calcularAreaCirculo(float raio);
    float calcularDistanciaCentro(Circulo c);
    float calcularCircunferencia();

public:
    Circulo(float raio, array <float, 2> centro){
        _raio = raio;
        _centro[0] = centro [0];
        _centro[1] = centro[1];
        _area = calcularAreaCirculo(raio);
    }

    void setRaio(float raio){
        _raio = raio;
        _area = calcularAreaCirculo(raio);
    }

    void setCentro(array <float, 2> centro){
        _centro[0] = centro[0];
        _centro[1] = centro[1];
    }

    void aumentaRaio(float taxaAumento);
    void printRaio();
    void printCentro();
    void printArea();
    void printDistanciaCentro(Circulo c);
    void printCircunferencia();
};

#endif // CIRCULO_H
