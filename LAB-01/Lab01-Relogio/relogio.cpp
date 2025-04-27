#include "relogio.h"

void Relogio::setHorario(int horas, int minutos, int segundos){

    if(horas >= 24){
        horas = 0;
    }
    if(minutos >= 60){
        minutos = 0;
    }
    if(segundos >= 60){
        segundos = 0;
    }

    _horas = horas;
    _minutos = minutos;
    _segundos = segundos;
}

void Relogio::getHorario(int &horas, int &minutos, int &segundos){
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}


void Relogio::tick(){
    if (_segundos < 59){
        _segundos++;
    }
    else{
        _segundos = 0;
        if(_minutos < 59){
            _minutos++;
        }
        else{
            _minutos = 0;
            _horas++;
            if(_horas >= 24){
                _horas = 0;
            }
        }
    }
}
