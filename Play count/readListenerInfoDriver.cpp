#include <iostream>
#include "listener.h"
using namespace std;
int readListenerInfo(string f, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol){
    if (numListenersStored>=listenerArrSize){
        return -2;
    }
    ifstream myFile;
    myFile.open(f);
    if(myFile.fail()){
        return -1;
    }
    string x;
    string l[100];
    while (listenerArrSize>numListenersStored){
        while (getline(myFile, x)) {
            for (int q=0;q<100;q++){
                l[q]="";
            }
            if(x==""){
                return 0;
            }
            split(x,',',l,51);
            Listener listener;
            listener.listenerName=l[0];
            int a=0;
            for (int c=1;c<51;c++){
                if (l[c]==""){
                    continue;
                }
                else{
                    listener.playCount[c-1]=stoi(l[c]);
                    a+=1;
                    if (maxCol<a){
                        break;
                    }
                }
            }
            listeners[numListenersStored]=listener;
            numListenersStored+=1;
            if(numListenersStored==listenerArrSize){
                return numListenersStored;
            }
        }
        return numListenersStored;
    }
}
int main(){
    int numListenersStored = 0;
    int listenerArrSize = 50;
    int maxColumns = 51;
    numListenersStored = readListenerInfo("Playlist.txt", listener, numListenersStored, listenerArrSize, maxColumns);
    cout<<numListenersStored<<endl;
}