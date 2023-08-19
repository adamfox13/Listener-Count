#include <iostream>
#include "songp.h"
using namespace std;
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
int frequentGenreSongs(Song songs[], int numSongsStored){
    if (songs==NULL){
        return 0;
    }
    if (numSongsStored<=0){
        return 0;
    }
    else{
        string arr[numSongsStored];
        int freq[numSongsStored];
        int max=0;
        for (int x=0;x<numSongsStored;x++){
            string a=songs[x].getGenre();
            arr[x]=a;
            int b=countGenre(a,songs,numSongsStored);
            freq[x]=b;
            if (b>max){
                max=b;
            }
        }
        return max;
    }
}
int main(){
    Song songs[50];
    int numSongsStored=0;
    int songsArrSize=50;
    numSongsStored=readSongs("songs.txt", songs, numSongsStored, songsArrSize);
    cout<<frequentGenreSongs(songs,numSongsStored)<<endl;
}