#ifndef ARCONDICIONADO_H
#define ARCONDICIONADO_H

#include <iostream>

using namespace std;

class ArCondicionado
{
private:
    unsigned int _potencia;
    float _sensor;

public:
    ArCondicionado(float temp){
        _potencia = 0;
        _sensor = temp;
    }

    void setPotencia(unsigned int potencia){
        if(potencia <=  10){
            _potencia = potencia;
        }
        else{
            cerr << "Valor " << potencia << "inválido" << endl;
            cerr << "Potência máxima: 10" << endl;
        }
    }

    unsigned int getPotencia(){
        return _potencia;
    }

    float getSensor(){
        return _sensor;
    }

    float calculaTemperatura(){
        return _sensor - 1.8*_potencia;
    }

};

#endif // ARCONDICIONADO_H
