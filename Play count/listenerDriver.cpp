#include <iostream>
#include "listener.h"
using namespace std;
int main(){
    Listener listener= Listener();
    int playCount[] = {3,4,5};
    Listener listener= Listener("Al", playCount, 3);
    cout << listener.getListenerName() << endl;
    cout << "getPlayCountAt(0) = " << listener.getPlayCountAt(0) << endl;
    for(int i=0; i<listener.getSize();i+=10){
        listener.setPlayCountAt(i,i);
    }
    cout << listener.getListenerName() << "'s Total Song Count is: " << listener.totalPlayCount() << endl;
}