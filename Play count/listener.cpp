#include <iostream>
#include "listener.h"
using namespace std;
Listener::Listener(){
    listenerName="";
    for(int i=0;i<50;i++){
        playCount[i]=0;
    }
}
Listener::Listener(string ln, int pc[], int psize){
    listenerName=ln;
    if (psize<size){
        for (int i=0;i<psize;i++){
            playCount[i]=pc[i];
        }
        for (int x=psize;x<size;x++){
            playCount[x]=0;
        }
    }
    else{
        for (int i=0;i<psize;i++){
            playCount[i]=pc[i];
        }
    }
}
string Listener::getListenerName(){
    return listenerName;
}
void Listener::setListenerName(string ln){
    listenerName=ln;
}
int Listener::getPlayCountAt(int index){
    if (index>size-1 or index<0){
        return -1;
    }
    else{
        return playCount[index];
    }
}
bool Listener::setPlayCountAt(int index, int value){
    if (index<size and index>0 and value>0){
        playCount[index]=value;
        return true;
    }
    else{
        return false;
    }
}
int Listener::totalPlayCount(){
    int a=0;
    for (int i=0;i<size;i++){
        a+=playCount[i];
    }
    return a;
}
int Listener::getNumUniqueSongs(){
    int nus=0;
    for (int i=0;i<size;i++){
        if (playCount[i]>=1){
            nus++;
        }
    }
    return nus;
}
int Listener::getSize(){
    return size;
}