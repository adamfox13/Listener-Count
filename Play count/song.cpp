#include <iostream>
#include <iomanip>
#include <limits>
#include "song.h"
using namespace std;
Song::Song(){
    title="";
    artist="";
    genre="";
}
Song::Song(string t, string a, string g){
    title=t;
    artist=a;
    genre=g;
}
void Song::setTitle(string t){
    title=t;
}
void Song::setArtist(string a){
    artist=a;
}
void Song::setGenre(string g){
    genre=g;
}
string Song::getTitle(){
    return title;
}
string Song::getArtist(){
    return artist;
}
string Song::getGenre(){
    return genre;
}