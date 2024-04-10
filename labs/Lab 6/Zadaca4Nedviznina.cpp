#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina{
protected:
    char * adresa;
    int kvadratura;
    int cena_kvadrat;
public:
    Nedviznina(char * adresa = "", int kvadratura = 0, int cena_kvadrat = 0)
    {
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
        this->kvadratura = kvadratura;
        this->cena_kvadrat = cena_kvadrat;
    }
    Nedviznina(const Nedviznina &n)
    {
        this->adresa = new char[strlen(n.adresa) + 1];
        strcpy(this->adresa, n.adresa);
        this->kvadratura = n.kvadratura;
        this->cena_kvadrat = n.cena_kvadrat;
    }
    Nedviznina& operator=(const Nedviznina &n)
    {
        if(this!=&n)
        {
            delete [] adresa;
            this->adresa = new char[strlen(n.adresa) + 1];
            strcpy(this->adresa, n.adresa);
            this->kvadratura = n.kvadratura;
            this->cena_kvadrat = n.cena_kvadrat;
        }
        return *this;
    }
    ~Nedviznina()
    {
        delete [] adresa;
    }

    virtual char * getAdresa()
    {
        return adresa;
    }
    int cena()
    {
        return kvadratura*cena_kvadrat;
    }
    double danokNaImot()
    {
        return cena()*0.05;
    }
    void pecati()
    {
        cout<<adresa<<", Kvadratura: "<<kvadratura<<", Cena po Kvadrat: "<<cena_kvadrat;
    }


    friend istream& operator>>(istream& is, Nedviznina &n);
};

istream& operator>>(istream& is, Nedviznina &n)
{
    is>>n.adresa>>n.kvadratura>>n.cena_kvadrat;
    return is;
}


class Vila: public Nedviznina{
private:
    int danok_na_luksuz;
public:
    Vila(char * adresa = "", int kvadratura = 0, int cena_kvadrat = 0,
    int danok_na_luksuz = 0) : Nedviznina(adresa, kvadratura, cena_kvadrat)
    {
        this->danok_na_luksuz = danok_na_luksuz;
    }
    Vila(const Vila &v) : Nedviznina(adresa, kvadratura, cena_kvadrat)
    {
        danok_na_luksuz = v.danok_na_luksuz;
    }
    Vila& operator=(const Vila &v)
    {
        Nedviznina::operator=(v);
        if(this!=&v)
        {
            danok_na_luksuz = v.danok_na_luksuz;
        }
        return *this;
    }

    double danokNaImot()
    {
        return Nedviznina::danokNaImot()*(danok_na_luksuz/5 + 1);
    }
    void pecati()
    {
        Nedviznina::pecati();
        cout<<", Danok na luksuz: "<<danok_na_luksuz<<endl;
    }

    friend istream& operator>>(istream& is, Vila &v);

};

istream& operator>>(istream& is, Vila &v)
{
    is>>v.adresa>>v.kvadratura>>v.cena_kvadrat;
    is>>v.danok_na_luksuz;
    return is;
}


int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"\nDanok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}
