#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo{
private:
    char * ime;
    int turi, clenovi;
public:
    PlDrustvo(char * ime = "", int turi = 0, int clenovi = 0)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->turi = turi;
        this->clenovi = clenovi;
    }
    ~PlDrustvo()
    {
        delete [] ime;
    }
    PlDrustvo(const PlDrustvo &p)
    {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        this->turi = p.turi;
        this->clenovi = p.clenovi;
    }
    PlDrustvo& operator=(const PlDrustvo &p)
    {
        if(this!=&p)
        {
            delete [] ime;
            this->ime = new char[strlen(p.ime) + 1];
            strcpy(this->ime, p.ime);
            this->turi = p.turi;
            this->clenovi = p.clenovi;
        }
        return *this;
    }

    bool operator<(PlDrustvo &p)
    {
        if(clenovi < p.clenovi)
            return true;
        else
            return false;
    }

    bool operator>(PlDrustvo &p)
    {
        if(clenovi > p.clenovi)
            return true;
        else
            return false;
    }

    PlDrustvo operator+(PlDrustvo &p)
    {
        if(*this > p)
        {
            PlDrustvo temp(ime, turi, clenovi + p.clenovi);
            return temp;
        }
        else{
            PlDrustvo temp(p.ime, p.turi, clenovi + p.clenovi);
            return temp;
        }
    }

    int getClenovi()
    {
        return clenovi;
    }

    friend ostream& operator<<(ostream& os, PlDrustvo &p);
};

ostream& operator<<(ostream& os, PlDrustvo &p)
{
    os << "Ime: " << p.ime << " Turi: " << p.turi << " Clenovi: " <<p.clenovi << endl;
    return os;
}


void najmnoguClenovi(PlDrustvo * niza, int n)
{
    int maxI = 0;
    int maxClenovi = 0;
    for(int i=0; i<n; i++)
    {
        if(niza[i].getClenovi() > maxClenovi)
        {
            maxClenovi = niza[i].getClenovi();
            maxI = i;
        }
    }
    cout<< "Najmnogu clenovi ima planinarskoto drustvo: "<<niza[maxI];
}

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;
   	}

    pl = drustva[0] + drustva[1];
    cout<<pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
