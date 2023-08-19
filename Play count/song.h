#include <string>
using namespace std;
class Song{
    private:
    string title;
    string artist;
    string genre;

    public:
    Song();
    Song(string t, string a, string g);

    string getTitle();
    void setTitle(string t);
    string getArtist();
    void setArtist(string a);
    string getGenre();
    void setGenre(string g);
};