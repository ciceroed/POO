#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio
{
private:
    int _horas;
    int _minutos;
    int _segundos;

public:
    Relogio(int horas = 0, int minutos = 0, int segundos = 0)
        : _horas(horas),
        _minutos(minutos),
        _segundos(segundos){}

    void setHorario(int horas, int minutos, int segundos);

    void getHorario(int &horas, int &minutos, int &segundos);

    void tick();
};

#endif // RELOGIO_H
