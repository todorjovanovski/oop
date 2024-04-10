#include <iostream>
#include <cstring>

using namespace std;

class TennisPlayer{
protected:
    char ime[100];
    char prezime[100];
    bool igraVoLiga;
public:
    TennisPlayer(char *ime = "", char *prezime = "", bool igraVoLiga = false)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->igraVoLiga = igraVoLiga;
    }

    friend ostream& operator<<(ostream& os, TennisPlayer& t)
    {
        os<<"Tennis player:"<<endl;
        os<<t.ime<< " " <<t.prezime<< " - " <<t.igraVoLiga<<endl;
        return os;
    }
};

class RankedTennisPlayer : public TennisPlayer{
private:
    int rank;
public:
    RankedTennisPlayer(char *ime = "", char *prezime = "", bool igraVoLiga = false,
                       int rank = 0) : TennisPlayer(ime, prezime, igraVoLiga)
    {
        this->rank = rank;
    }

    friend ostream & operator<<(ostream& os, RankedTennisPlayer& r)
    {
        os<< "Ranked tennis player:" <<endl;
        //os<< TennisPlayer(r);
        os<< "Rank: " <<r.rank<<endl;
        return os;
    }
};

int main()
{
    TennisPlayer rf("Roger", "Federer");
    TennisPlayer nd("Novak", "Djokovic");

    cout<<rf<<nd;

    RankedTennisPlayer rn("Rafael", "Nadal", true, 2);
    cout<<rn;
    TennisPlayer tp = rn;
    cout<<tp;
}
