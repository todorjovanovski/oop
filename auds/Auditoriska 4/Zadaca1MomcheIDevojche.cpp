#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Momche{
private:
    char ime[50];
    char prezime[50];
    int godini;
public:
    Momche(char * ime = "", char * prezime = "", int godini = 0)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->godini = godini;
    }
    Momche(const Momche &m)
    {
        strcpy(ime, m.ime);
        strcpy(prezime, m.prezime);
        godini = m.godini;
    }
    ~Momche(){}

    int getGodini()
    {
        return godini;
    }
    void print()
    {
        cout<<"Momche: "<<ime<<" "<<prezime<<" "<<godini;
    }

};

class Devojche{
private:
    char ime[50];
    char prezime[50];
    int godini;
public:
    Devojche(char * ime = "", char * prezime = "", int godini = 0)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->godini = godini;
    }
    Devojche(const Devojche &m)
    {
        strcpy(ime, m.ime);
        strcpy(prezime, m.prezime);
        godini = m.godini;
    }
    ~Devojche(){}

    int getGodini()
    {
        return godini;
    }
    void print()
    {
        cout<<"Devojche: "<<ime<<" "<<prezime<<" "<<godini;
    }
};

class Sredba{
private:
    Momche m;
    Devojche d;
public:
    Sredba(Momche m, Devojche d)
    {
        this->m = m;
        this->d = d;
    }

    void print()
    {
        cout<<"Sredba:"<<endl;
        m.print();
        cout<<" ";
        d.print();
    }
    void daliSiOdgovaraat()
    {
        if(abs(m.getGodini() - d.getGodini()) <= 5)
        {
            cout<<"\nSi odgovaraat";
        }
        else{
            cout<<"\nNe si odgovaraat";
        }
    }
};

int main()
{
    char ime[50], prezime[50];
    int godini;

    cout<<"Vnesi podatoci za momche:"<<endl;
    cin>>ime>>prezime>>godini;
    Momche m(ime, prezime, godini);

    cout<<"Vnesi podatoci za devojche:"<<endl;
    cin>>ime>>prezime>>godini;
    Devojche d(ime, prezime, godini);

    Sredba s(m, d);
    s.print();
    s.daliSiOdgovaraat();

    return 0;
}
