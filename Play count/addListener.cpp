#include <iostream>
#include "listener.h"
using namespace std;
string toLower(string c){
    int a=c.size();
    for (int w=0;w<a;w++){
        if (int(c[w])>=97 and int(c[w])<=122){
            c[w]=char(c[w]);
        }
        else if (int(c[w]>=65)and int(c[w]<=90)){
            c[w]=char(int(c[w])+32);
        }
    }
    return c;
}
int addListener(string listenerName, Listener listeners[], int numSongs, int numListenersStored, int listenerArrSize){
    if (numListenersStored>=listenerArrSize){
        return -1;
    }
    for (int x=0;x<numListenersStored;x++){
        if(toLower(listenerName)==toLower(listeners[x].getListenerName())){
            return -2;
        }
    }
    if (listenerName==""){
        return -3;
    }
    if (numListenersStored<listenerArrSize){
        int playCount[numSongs];
        for (int q=0;q<numSongs;q++){
            playCount[q]=0;
        }
        listeners[numListenersStored++]=Listener(listenerName,playCount,numSongs);
    }
    return numListenersStored;
}
int main(){
    Listener listeners[2];
    int listenerArrSize=2;
    int numSongs=5;
    listeners[0].setListenerName("Adam");
    for(int i=0; i<numSongs; i++) {
        listeners[0].setPlayCountAt(i, i);
    }
    int numListenersStored = 1;
    cout<<addListener("James", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;
}