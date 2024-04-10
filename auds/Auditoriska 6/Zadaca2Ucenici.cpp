#include <iostream>
#include <cstring>

using namespace std;

class Ucenik{
private:
    char * ime;
    float prosek;
    int godina;
public:
    Ucenik(char * ime = "", float prosek = 0, int godina = 0)
    {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->prosek = prosek;
        this->godina = godina;
    }
    ~Ucenik()
    {
        delete [] ime;
    }
    Ucenik(const Ucenik &u)
    {
        this->ime = new char[strlen(u.ime)+1];
        strcpy(this->ime, u.ime);
        this->prosek = u.prosek;
        this->godina = u.godina;
    }
    Ucenik& operator=(const Ucenik &u)
    {
        if(this!=&u)
        {
            delete [] ime;
            this->ime = new char[strlen(u.ime)+1];
            strcpy(this->ime, u.ime);
            this->prosek = u.prosek;
            this->godina = u.godina;
        }
        return *this;
    }
    Ucenik &operator++()
    {
        godina++;
        return *this;
    }
    Ucenik &operator++(int)
    {
        Ucenik temp(*this);
        godina++;
        return temp;
    }

    float getProsek()
    {
        return prosek;
    }

    friend ostream& operator<<(ostream& os, const Ucenik &u)
    {
        os<< "Ime: " << u.ime << " Godina: " << u.godina << " Prosek: " << u.prosek << endl;
        return os;
    }

    bool operator>(Ucenik &u)
    {
        if(prosek > u.prosek)
            return true;
        else
            return false;
    }

};


class Paralelka{
private:
    Ucenik * ucenici;
    int n;
public:
    Paralelka(Ucenik * ucenici = 0, int n = 0)
    {
        this->n = n;
        this->ucenici = new Ucenik[n];
        for(int i=0; i<n; i++)
        {
            this->ucenici[i] = ucenici[i];
        }
    }
    Paralelka(const Paralelka& p)
    {
        this->n = p.n;
        this->ucenici = new Ucenik[p.n];
        for(int i=0; i<n; i++)
        {
            this->ucenici[i] = p.ucenici[i];
        }
    }
    Paralelka& operator=(const Paralelka& p)
    {
        if(this!=&p)
        {
            this->n = p.n;
            delete [] ucenici;
            this->ucenici = new Ucenik[p.n];
            for(int i=0; i<n; i++)
            {
                this->ucenici[i] = p.ucenici[i];
            }
        }
        return *this;
    }
    ~Paralelka()
    {
        delete [] ucenici;
    }

    Paralelka& operator+=(Ucenik u)
    {
        Ucenik * temp = new Ucenik[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = ucenici[i];
        }
        temp[n++] = u;
        delete [] ucenici;
        ucenici = temp;
        return *this;
    }
    Paralelka& operator++()
    {
        for(int i=0; i<n; i++)
        {
            ucenici[i]++;
        }
        return *this;
    }
    Paralelka& operator++(int)
    {
        Paralelka temp(*this);
        for(int i=0; i<n; i++)
        {
            ucenici[i]++;
        }
        return temp;
    }

    void nagradi()
    {
        for(int i=0; i<n; i++)
        {
            if(ucenici[i].getProsek() == 10.0)
            {
                cout<<ucenici[i];
            }
        }
    }
    void najvisokProsek()
    {
        Ucenik maxP = ucenici[0];
        for(int i=0; i<n; i++)
        {
            if(ucenici[i] > maxP)
            {
                maxP = ucenici[i];
            }
        }
        cout << "Najvisok prosek: " << maxP<<endl;
    }

    friend ostream& operator<<(ostream &os, Paralelka &p)
    {
        for(int i=0; i<p.n; i++)
        {
            os<<p.ucenici[i];
        }
        return os;
    }
};


int main()
{
    Ucenik u1("Martina Martinovska", 9.5, 3);
    Ucenik u2("Darko Darkoski", 7.3, 2);
    Ucenik u3("Angela Angelovska", 10, 3);

    Paralelka p;
    p += u1;
    p += u2;
    p += u3;
    cout << p;
    cout << "Nagradeni:" << endl;
    p.nagradi();
    cout << endl;
    p.najvisokProsek();
    cout << endl;
    u2++;
    cout << p;
    cout << endl;
    p++;
    cout << p;

    return 0;
}
