#include <iostream>

#include "televisao.h"

using namespace std;

int main(){
    Televisao tv;

    cout << "Canal: " << tv.getChannel() << endl;
    cout << "Volume: " << tv.getVolume() << endl;

    for(int i=0; i < 101; i++){
        tv.incrementChannel();
        tv.incrementVolume();
    }
    cout << "Canal: " << tv.getChannel() << endl;
    cout << "Volume: " << tv.getVolume() << endl;

    for(int i=0; i < 101; i++){
        tv.decrementChannel();
        tv.decrementVolume();
    }

    cout << "Canal: " << tv.getChannel() << endl;
    cout << "Volume: " << tv.getVolume() << endl;

    tv.setChannel(45);

    cout << "Canal: " << tv.getChannel() << endl;

    tv.setChannel(90);
}
