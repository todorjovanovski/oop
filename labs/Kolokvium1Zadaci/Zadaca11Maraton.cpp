#include <iostream>
#include <string.h>

using namespace std;

// vashiot kod ovde
class Ucesnik{
private:
    char * ime;
    bool pol;
    int vozrast;
public:
    Ucesnik(char * ime ="", bool pol = true, int vozrast = 0)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }
    Ucesnik(const Ucesnik &u)
    {
        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
        pol = u.pol;
        vozrast = u.vozrast;
    }
    Ucesnik& operator=(const Ucesnik &u)
    {
        if(this!=&u)
        {
            delete [] ime;
            ime = new char[strlen(u.ime) + 1];
            strcpy(ime, u.ime);
            pol = u.pol;
            vozrast = u.vozrast;
        }
        return * this;
    }
    ~Ucesnik()
    {
        delete [] ime;
    }

    bool operator>(const Ucesnik &u)
    {
        if(vozrast > u.vozrast)
        {
            return true;
        }
        else return false;
    }

    friend class Maraton;
    friend ostream& operator<<(ostream& os, const Ucesnik &u);


};

class Maraton{
private:
    char lokacija[100];
    Ucesnik * ucesnici;
    int n;
public:
    Maraton(char * lokacija = "", Ucesnik * ucesnici = 0, int n = 0)
    {
        strcpy(this->lokacija, lokacija);
        this->n = n;
        this->ucesnici = new Ucesnik[n];
        for(int i=0; i<n; i++)
        {
            this->ucesnici[i] = ucesnici[i];
        }
    }
    Maraton(const Maraton &m)
    {
        strcpy(lokacija, m.lokacija);
        n = m.n;
        ucesnici = new Ucesnik[m.n];
        for(int i=0; i<n; i++)
        {
            ucesnici[i] = m.ucesnici[i];
        }
    }
    Maraton& operator=(const Maraton &m)
    {
        if(this!=&m)
        {
            strcpy(lokacija, m.lokacija);
            n = m.n;
            delete [] ucesnici;
            ucesnici = new Ucesnik[m.n];
            for(int i=0; i<n; i++)
            {
                ucesnici[i] = m.ucesnici[i];
            }
        }
        return *this;
    }
    Maraton& operator+=(const Ucesnik &nov)
    {
        Ucesnik * temp = new Ucesnik[n + 1];
        for(int i=0; i<n; i++)
        {
            temp[i] = ucesnici[i];
        }
        temp[n++] = nov;
        delete [] ucesnici;
        ucesnici = temp;
        return * this;
    }
    ~Maraton()
    {
        delete [] ucesnici;
    }

    float prosecnoVozrast()
    {
        int zbir = 0;
        for(int i=0; i<n; i++)
        {
            zbir += ucesnici[i].vozrast;
        }
        return (float)zbir/n;
    }
    void pecatiPomladi(Ucesnik &u)
    {
        for(int i=0; i<n; i++)
        {
            if(ucesnici[i].vozrast < u.vozrast)
            {
                cout<<ucesnici[i];
            }
        }
    }


};

ostream& operator<<(ostream& os, const Ucesnik &u)
{
    os<<u.ime<<endl;
    if(u.pol == 0)
    {
        os<<"zhenski"<<endl;
    }
    else{
        os<<"mashki"<<endl;
    }
    os<<u.vozrast<<endl;
    return os;
}

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}
