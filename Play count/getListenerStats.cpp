#include <iostream>
#include "listener.h"
using namespace std;
string toLower(string c){
    int a=c.size();
    for (int w=0;w<a;w++){
        if (int(c[w])>=97 and int(c[w])<=122){
            c[w]=char(c[w]);
        }
        else if (int(c[w]>=65)and int(c[w]<=90)){
            c[w]=char(int(c[w])+32);
        }
    }
    return c;
}
double avglistens(string listenerName, Listener listeners[], int numListenersStored, int numSongs){
    double a=0;
    double u=0;
    double tot=0;
    for (int x=0;x<numListenersStored;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            for (int y=0;y<numSongs;y++){
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
int getListenerStats(string listenerName, Listener listeners[], int numListenersStored, int numSongs){
    double b=0;
    if (numSongs<1){
        cout<<listenerName<<" has not listened to any songs"<<endl;
        return 0;
    }
    for (int x=0;x<numListenersStored;x++){
        if (toLower(listenerName)==toLower(listeners[x].getListenerName())){
            b+=1;
            double d=avglistens(listenerName, listeners, numListenersStored, numSongs);
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
    listeners[0].setListenerName("Adam");
    listeners[0].setPlayCountAt(0,1);
    listeners[0].setPlayCountAt(1,4);
    listeners[0].setPlayCountAt(2,2);
    listeners[1].setListenerName("Tyler");
    listeners[2].setListenerName("Benji");
    listeners[2].setPlayCountAt(0,0);
    listeners[2].setPlayCountAt(1,0);
    listeners[2].setPlayCountAt(2,0);
    cout<< getListenerStats("Adam", listeners, 3, 3)<<endl;
    cout<< getListenerStats("Tyler", listeners, 3, 3)<<endl;
    cout<< getListenerStats("Benji", listeners, 3, 3)<<endl;
}