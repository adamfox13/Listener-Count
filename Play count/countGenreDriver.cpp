#include <iostream>
#include "songp.h"
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
int countGenre(string genre, Song songs[], int numSongsStored){
    int total=0;
    string c;
    for (int x=0;x<numSongsStored;x++){
        c=songs[x].getGenre();
        if (toLower(c)==toLower(genre)){
            total+=1;
        }
    }
    if (total==0){
        return 0;
    }
    else{
        return total;
    }
}
int main(){
    numSongsStored=readSongs("songs1.txt", songs, numSongsStored, songArrSize);
    cout<<countGenre("Rock", songs, numSongsStored)<<endl;
}
