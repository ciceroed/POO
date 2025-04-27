#include "carro.h"

Carro::Carro(float comb, float consumo, float maxTanque, float quilometragem){

    _quilometragem = quilometragem;
    _capTanque = maxTanque;
    _consumo = consumo;

    if (comb <= maxTanque){
        _combustivel = comb;
    }
    else{
        _combustivel = 0;
    }
}

void Carro::abastecer(float combustivel){

    float tmp = _combustivel + combustivel;

    if(tmp <= _capTanque){
        _combustivel = tmp;
    }
    else{
        _combustivel = _capTanque;
    }
}

void Carro::percorrerDistancia(float distancia){
    float combustivelNecessario = distancia / _consumo;
    if(combustivelNecessario <= _combustivel){
        _quilometragem += distancia;
        _combustivel -= combustivelNecessario;
    }
    else{
        _quilometragem += _consumo * _combustivel;
        _combustivel = 0;
    }
}
