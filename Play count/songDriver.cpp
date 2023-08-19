#include <iostream>
using namespace std;
#include "song.h"
int main(){
    string title="Bohemian Rhapsody";
    string artist = "Queen";
    string genre = "Rock";
    Song s=Song(title, artist, genre);
    cout<<s.getTitle()<<endl;
    cout<<s.getArtist()<<endl;
    cout<<s.getGenre()<<endl;
}