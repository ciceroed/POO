#include <iostream>

#include "elevador.h"

using namespace std;

int main()
{
    Elevador elevador(3, 8);

    int andares = elevador.getTotalAndares();
    int cap = elevador.getCapacidade();

    cout << "Andar Atual: " << elevador.getAndarAtual() << endl;
    cout << "Numero de Andares: " << elevador.getTotalAndares() << endl;
    cout << "Capacidade: " << elevador.getCapacidade() << endl;
    cout << "Pessoas dentro do elevador: " << elevador.getQtdPessoas() << endl;


    for(int i = 0; i <= andares; i++){
        elevador.sobe();La
    }

    cout << "Andar Atual: " << elevador.getAndarAtual() << endl;

    for(int i = 0; i <= andares; i++){
        elevador.desce();
    }

    cout << "Andar Atual: " << elevador.getAndarAtual() << endl;

    for(int i = 0; i <= cap; i++){
        elevador.entra();
    }

    cout << "Pessoas dentro do elevador: " << elevador.getQtdPessoas() << endl;

    for(int i = 0; i <= cap; i++){
        elevador.sai();
    }

    cout << "Pessoas dentro do elevador: " << elevador.getQtdPessoas() << endl;
}
