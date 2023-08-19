#include <string>
using namespace std;
class Listener{
    private:
    string listenerName;
    static const int size=50;
    int playCount[size];

    public:
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