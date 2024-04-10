#include <iostream>
#include <cstring>
using namespace std;

class Rabotnik{
private:
    char ime[50], prezime[50];
    int plata;
public:
    Rabotnik(){}
    Rabotnik(char * ime, char * prezime, int plata)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }

    int getPlata()
    {
        return plata;
    }
    void pecati()
    {
        cout<<ime<<" "<<prezime<<" "<<plata<<endl;
    }
};

class Fabrika{
private:
    Rabotnik rabotnici[100];
    int broj_vraboteni;
public:
    Fabrika(){}
    Fabrika(Rabotnik * rabotnici, int broj_vraboteni)
    {
        this->broj_vraboteni = broj_vraboteni;
        for(int i=0; i<broj_vraboteni; i++)
        {
            this->rabotnici[i] = rabotnici[i];
        }
    }

    void pecatiVraboteni()
    {
        for(int i=0; i<broj_vraboteni; i++)
        {
            rabotnici[i].pecati();
        }
    }

    void pecatiSoPlata(int plata)
    {
        for(int i=0; i<broj_vraboteni; i++)
        {
            if(rabotnici[i].getPlata() >= plata)
            {
                rabotnici[i].pecati();
            }
        }
    }
};


int main()
{
    int n;
    cin>>n;

    char ime[50], prezime[50];
    int plata, minimalna_plata;

    Rabotnik rabotnici[n];
    for(int i=0; i<n; i++)
    {
        cin>>ime>>prezime>>plata;
        rabotnici[i] = Rabotnik(ime, prezime, plata);
    }
    cin>>minimalna_plata;

    Fabrika f1(rabotnici, n);
    cout<< "Site vraboteni:"<<endl;
    f1.pecatiVraboteni();
    cout<< "Vraboteni so plata povisoka od "<<minimalna_plata<<" :"<<endl;
    f1.pecatiSoPlata(minimalna_plata);

    return 0;

}
