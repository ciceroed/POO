#ifndef TELEVISAO_H
#define TELEVISAO_H

using namespace std;

class Televisao
{
private:
    int _volume;
    int _canal;

public:
    Televisao(int volume = 0, int canal = 0): _volume(volume), _canal(canal){}

    void incrementVolume(){
        if(_volume < 100){
            _volume++;
        }
    }
    void decrementVolume(){
        if(_volume > 0){
            _volume--;
        }
    }
    void incrementChannel(){
        if(_canal < 75){
            _canal++;
        }
    }
    void decrementChannel(){
        if(_canal){
            _canal--;
        }
    }
    void setChannel(int canal){
        if(canal > 0 && canal < 75){
            _canal = canal;
        }
        else{
            cerr << "Error: Invalid channel selection" << endl;
        }
    }
    int getChannel(){
        return _canal;
    }
    int getVolume(){
        return _volume;
    }
};

#endif // TELEVISAO_H
