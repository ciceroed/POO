#include <array>
#include <cmath>
#include <iostream>

#include "circulo.h"

using namespace std;

float Circulo::calcularAreaCirculo(float raio){
    return raio * raio * M_PI;
}

float Circulo::calcularDistanciaCentro(Circulo c){

    return sqrt(pow((this->_centro[0] - c._centro[0]), 2) + pow((this->_centro[1] - c._centro[1]), 2));
}

float Circulo::calcularCircunferencia(){
    return 2 * M_PI * _raio;
}

void Circulo::aumentaRaio(float taxaAumento){
    _raio = _raio * taxaAumento;
    _area = calcularAreaCirculo(_raio);
}

void Circulo::printArea(){
    cout << "Area = " << _area << endl;
}

void Circulo::printCentro(){
    cout << "Centro = {"<< _centro[0] << "," << _centro[1] << "}" << endl;
}

void Circulo::printRaio(){
    cout << "Raio = " << _raio << endl;
}

void Circulo::printDistanciaCentro(Circulo c){
    cout << "Distância entre pontos = " << this->calcularDistanciaCentro(c) << endl;
}

void Circulo::printCircunferencia(){
    cout << "Circunferencia = " << this->calcularCircunferencia() << endl;
}
