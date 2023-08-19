#include <iostream>
#include "song.h"
#include <fstream>
using namespace std;
int readSongs(string f, Song songs[], int numSongsStored, int songArrSize){
    if(numSongsStored>=songArrSize){
        return -2;
    }
    ifstream myFile;
    myFile.open(f);
    if(myFile.fail()){
        return -1;
    }
    string x;
    while (songArrSize>=numSongsStored){
        while (getline(myFile, x)) {
            if(x.empty()){
                continue;
            }
            string a[50];
            split(x,',',a,50);
            Song song; 
            song.title=a[0];
            song.artist=a[1];
            song.genre=a[2];
            songs[numSongsStored]=song;
            numSongsStored+=1;
            if(numSongsStored>=songArrSize){
                return numSongsStored;
    }
        }
        return numSongsStored;
    }
}
int main(){
    cout<<readSongs("songs_mini_test.txt", songs, 0, 50)<<endl;
}