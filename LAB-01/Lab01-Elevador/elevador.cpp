#include "elevador.h"
#include <iostream>

using namespace std;

Elevador::Elevador(int totalAndares, int capacidade)
{
    this->_andarAtual = 0;
    this->_qtdPessoas = 0;
    this->_capacidade = capacidade;
    this->_totalAndares = totalAndares;
}

void Elevador::entra(){

    if(this->_qtdPessoas < this->_capacidade){
        this->_qtdPessoas++;
    }
    else{
        cout << "Capacidade máxima atingida" << endl;
    }
}

void Elevador::sai(){

    if(this->_qtdPessoas > 0){
        this->_qtdPessoas--;
    }
    else{
        cout << "Elevador vazio" << endl;
    }
}

void Elevador::desce(){

    if(this->_andarAtual > 0){
        this->_andarAtual--;

        cout << "Descendo..." << endl;
    }
    else{
        cout << "Elevador no térreo" << endl;
    }
}

void Elevador::sobe(){
    if(this->_andarAtual < this->_totalAndares){
        this->_andarAtual++;

        cout << "Subindo..." << endl;
    }
    else{
        cout << "Elevador na cobertura" << endl;
    }
}
