#ifndef CARRO_H
#define CARRO_H

class Carro
{
private:
    float _combustivel;      // Medida em Litros
    float _consumo;     // Medida em km/L
    float _capTanque;   // Capacidade máxima do tanque em L
    float _quilometragem;

public:
    Carro(float comb = 50, float consumo = 15, float maxTanque = 50, float quilometragem = 0);

    void abastecer(float combustivel);

    void percorrerDistancia(float quilometragem);

    float getQuilometragem(){
        return _quilometragem;
    }

    float getCombustivel(){
        return _combustivel;
    }
};

#endif // CARRO_H
