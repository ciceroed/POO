#ifndef ELEVADOR_H
#define ELEVADOR_H


class Elevador
{
private:
    int _andarAtual;
    int _totalAndares;
    int _capacidade;
    int _qtdPessoas;

public:
    Elevador(int totalAndares,int capacidade);

    void entra();

    void sai();

    void sobe();

    void desce();

    int getAndarAtual(){
        return this->_andarAtual;
    }

    int getTotalAndares(){
        return this->_totalAndares;
    }

    int getCapacidade(){
        return this->_capacidade;
    }

    int getQtdPessoas(){
        return this->_qtdPessoas;
    }
};

#endif // ELEVADOR_H
