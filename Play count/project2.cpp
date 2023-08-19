#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <fstream>
#include <string>
using namespace std;
class Listener{
    public:
    string listenerName;
    static const int size=50;
    int playCount[size];
    Listener();
    Listener(string ln, int pc[],int psize);

    string getListenerName();
    void setListenerName(string ln);
    int getPlayCountAt(int index);
    bool setPlayCountAt(int index, int value);
    int totalPlayCount();
    int getNumUniqueSongs();
    int getSize();
};
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
    if (index<size and index>=0 and value>0){
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
class Song{
    public:
    string title;
    string artist;
    string genre;
    Song();
    Song(string t, string a, string g);

    string getTitle();
    void setTitle(string t);
    string getArtist();
    void setArtist(string a);
    string getGenre();
    void setGenre(string g);
};
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
int split(string a,char s,string tem[],int len){
    int size=a.length();
    if (size<=0){
        return 0;
    }
    int l=0;
    int t=0;
    for(int q=0;q<size;q++){
        if(a[q]==s){
            tem[t]=a.substr(l,q-l);
            l=q+1;
            t++;
            if(t==len){
                break;
        }
        }
    }
    if(t<=len){
        tem[t]=a.substr(l,size-l);
        t++;
    }
    if(t>len){
        return -1;
    }
    return t;
}
int getSongPlayCount(string listenerName, string songName, Listener listeners[], Song songs[], int listenerArrSize, int numSongsStored){
    int a=-1;
    int b=-1;
    for (int x=0;x<listenerArrSize;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            a=x;
        }
    }
    for (int y=0;y<numSongsStored;y++){
        if (toLower(songName)==toLower(songs[y].getTitle())){
            b=y;
        }
    }
    if (a==-1 and b==-1){
        return -3;
    }
    if (a==-1 or listeners[0].getListenerName()==""){
        return -2;
    }
    if (b==-1 or songs[0].getTitle()==""){
        return -1;
    }
    return listeners[a].getPlayCountAt(b);
}
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
void printAllSongs(Song songs[], int numSongsStored){
    string c;
    if (numSongsStored<1){
        cout<<"No songs are stored"<<endl;
    }
    else{
        cout<<"Here is a list of songs"<<endl;
        for (int x=0;x<numSongsStored;x++){
            cout<<songs[x].getTitle()<<" is by "<<songs[x].getArtist()<<endl;
        }
    }
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
int addListener(string listenerName, Listener listeners[], int numSongsStored, int numListenersStored, int listenerArrSize){
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
        int playCount[numSongsStored];
        for (int q=0;q<numSongsStored;q++){
            playCount[q]=0;
        }
        listeners[numListenersStored++]=Listener(listenerName,playCount,numSongsStored);
    }
    return numListenersStored;
}
double avglistens(string listenerName, Listener listeners[], int numListenersStored, int numSongsStored){
    double a=0;
    double u=0;
    double tot=0;
    for (int x=0;x<numListenersStored;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            for (int y=0;y<numSongsStored;y++){
                if (listeners[x].getPlayCountAt(y)>0){
                    tot+=listeners[x].getPlayCountAt(y);
                    u+=1;
                }
            }
        }
    }
    if (u<=0){
        return 0;
    }
    else{
        double avg=tot/u;
        return avg;
    }
}
int getListenerStats(string listenerName, Listener listeners[], int numListenersStored, int numSongsStored){
    double b=0;
    if (numSongsStored<1){
        cout<<listenerName<<" has not listened to any songs"<<endl;
        return 0;
    }
    for (int x=0;x<numListenersStored;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            b+=1;
            double d=avglistens(listenerName, listeners, numListenersStored, numSongsStored);
            if (d==0){
                cout<<listenerName<<" has not listened to any songs."<<endl;
                return 0;
            }
            cout<<listenerName<<" listened to "<<listeners[x].getNumUniqueSongs()<<" songs."<<endl;
            cout<<listenerName<<"'s average number of listens was ";
            std::cout<<std::fixed<<std::setprecision(2)<<d<<endl;

            return 1;
        }
    }
    if (b<=0){
        cout<<listenerName<<" does not exist."<<endl;
        return -3;
    }
}

int main(){
    int songArrSize=50;
    int maxCol=51;
    int numListenersStored;
    int listenerArrSize=100;
    int numSongsStored;
    string songName;
    string genre;
    string listenerName;
    Song songs[50];
    Listener listeners[100];
    int a;
    int z;
    string f;
    cout<<"Select a numerical option:\n======Main Menu=====\n1. Read songs from file\n2. Print all songs\n3. Song-count by genre\n4. Songs from most common genre\n5. Add listener\n6. Read listens from file\n7. Get number of listens by a listener\n8. Get listener statistics\n9. Quit"<<endl;
    cin>>a;
    while (a!=9){
        if (a==1){
            cout<<"Enter a song file name: "<<endl;
            cin>>f;
            z=readSongs(f, songs, numSongsStored, songArrSize);
            if (z==-1){
                cout<<"No songs saved to the database."<<endl;
            }
            else if (z==-2){
                cout<<"Database is already full. No songs were added."<<endl;
            }
            else if (z==songArrSize){
                cout<<"Total songs in the database: "<<z<<endl;
                cout<<"Database is full. Some songs may have not been added."<<endl;
            }
            else{
                cout<<"Total songs in the database: " <<z<<endl;
            }
        }
        else if (a==2){
            printAllSongs(songs, z);
        }
        else if (a==3){
            cout<<"Genre: "<<endl;
            cin>>genre;
            cout<<"Total "<<genre<<" songs in the database: "<<countGenre(genre, songs, numSongsStored)<<endl;
        }
        else if(a==4){
            cout<<"Number of songs in most common Genre: "<<frequentGenreSongs(songs, z)<<endl;
        }
        else if(a==5){
            cout<<"Enter a listener name: ";
            cin>>listenerName;
            int c=addListener(listenerName,listeners, numSongsStored, numListenersStored, listenerArrSize);
            if (c==-1){
                cout<<"Database is already full. Listener cannot be added."<<endl;
            }
            else if (c==-2){
                cout<<"Listener already exists."<<endl;
            }
            else if (c==-3){
                cout<<"The listenerName is empty."<<endl;
            }
            else{
                cout<<"Welcome, "<<listenerName<<"!"<<endl;
            }
        }
        else if(a==6){
            cout<<"Enter the listener info file name: "<<endl;
            cin>>f;
            int y=readListenerInfo(f,listeners, numListenersStored, listenerArrSize, maxCol);
            if (y==-1){
                cout<<"Nothing saved to the database."<<endl;
            }
            else if (y==-2){
                cout<<"Database is already full. Nothing was added."<<endl;
            }
            else if(y==listenerArrSize){
                cout<<"Database is full. Some listeners may have not been added."<<endl;
            }
            else{
                cout<<"Total listeners in the database: "<<y<<endl;
            }
        }
        else if(a==7){
            cout<<"Enter a listener name: ";
            cin>>listenerName;
            cout<<"Enter a song name: ";
            cin>>songName;
            int g=getSongPlayCount(listenerName, songName, listeners, songs, listenerArrSize,  numSongsStored);
            if (g==-1){
                cout<<songName<<" does not exist."<<endl;
            }
            else if(g==-2){
                cout<<listenerName<<" does not exist."<<endl;
            }
            else if(g==-3){
                cout<<listenerName<<" and "<<songName<<" do not exist."<<endl;
            }
            else{
                cout<<listenerName<<" has listened to "<<songName<<" "<<g<<" times."<<endl;
            }
        }
        else if(a==8){
            cout<<"Enter a listener name:";
            cin>>listenerName;
            cout<<getListenerStats(listenerName, listeners, numListenersStored, numSongsStored);
        }
        else{
            cout<<"Invalid input."<<endl;
        }
        cout<<"Select a numerical option:\n======Main Menu=====\n1. Read songs from file\n2. Print all songs\n3. Song-count by genre\n4. Songs from most common genre\n5. Add listener\n6. Read listens from file\n7. Get number of listens by a listener\n8. Get listener statistics\n9. Quit"<<endl;
        cin>>a;
    }
    cout<<"Good bye!"<<endl;
}