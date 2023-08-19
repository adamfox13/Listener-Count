#include <iostream>
#include "listener.h"
#include "songp2.h"
using namespace std;
string toLower(string c){
    for (int w=0;w<c.size();w++){
        if (int(c[w])>=97 and int(c[w])<=122){
            c[w]=char(c[w]);
        }
        else if (int(c[w]>=65)and int(c[w]<=90)){
            c[w]=char(int(c[w])+32);
        }
    }
    return c;
}
int getSongPlayCount(string listenerName, string songName, Listener listeners[], Song songs[], int listenerArrSize, int songsStored){
    int a=-1;
    int b=-1;
    int c=0;
    for (int x=0;x<listenerArrSize;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            a=x;
        }
    }
    for (int y=0;y<songsStored;y++){
        if (toLower(songName)==toLower(songs[y].getTitle())){
            b=y;
        }
    }
    if (a==-1 and b==-1){
        return -3;
    }
    if (a==-1 || listeners[0].getListenerName()==""){
        return -2;
    }
    if (b==-1 || songs[0].getTitle()==""){
        return -1;
    }
    c=int(listeners[a].getPlayCountAt(b));
    return c;
}
int main(){
    Song songs[50];
    int numSongsStored = readSongs("songs.txt", songs, 0, 50);
    int numListenersStored = 0;
    int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored = readListenerInfo("listenerInfo.txt", listener, numListenersStored, listenerArrSize, 50);
    cout<<getSongPlayCount("Adam", "Stay Down", listener, songs, numListenersStored, numSongsStored)<<endl;
}