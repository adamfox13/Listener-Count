#include <iostream>
#include "song.h"
using namespace std;
void printAllSongs(Song songs[], int numsongs){
    if (numsongs<=0){
        cout<<"No songs are stored"<<endl;
    }
    else{
        cout<<"Here is a list of songs"<<endl;
        for (int x=0;x<numsongs;x++){
            cout<<songs[x].getTitle()<<" is by "<<songs[x].getArtist()<<endl;
        }
    }
}
int main(){
    Song songs[3];
    songs[0].setTitle("No Role Modelz");
    songs[0].setArtist("J. Cole");
    songs[1].setTitle("Moon");
    songs[1].setArtist("Kanye West");
    songs[2].setTitle("Orange Soda");
    songs[2].setArtist("Baby Keem");
    printAllSongs(songs, 3);
}