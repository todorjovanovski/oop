#include<iostream>
#include<cstring>

using namespace std;


class ImaMasa{
public:
    virtual double vratiMasa() = 0;
    virtual void pecati() = 0;
};

class PaketPijalok : public ImaMasa{
private:
    double volumeEden;
    int kolicina;
    static double gustina;
    static double ambalazaMasa;
public:
    PaketPijalok(double volumeEden = 0, int kolicina = 0)
    {
        this->volumeEden = volumeEden;
        this->kolicina = kolicina;
    }

    double vratiMasa()
    {
        return (volumeEden * gustina * ambalazaMasa );
    }

    int getKolicina()
    {
        return kolicina;
    }
};
double PaketPijalok::ambalazaMasa = 0.2;
double PaketPijalok::gustina = 0.8;


class PaketSok: public PaketPijalok{
private:
    bool daligaziran;
public:
    PaketSok(double volumeEden = 0, int kolicina = 0, bool daligaziran = false) : PaketPijalok(volumeEden, kolicina)
    {
        this->daligaziran = daligaziran;
    }

    double vratiMasa()
    {
        if(daligaziran)
        {
            return (PaketPijalok::vratiMasa() + 0.1) * getKolicina();
        }
        else{
            return PaketPijalok::vratiMasa() * getKolicina();
        }
    }

    void pecati()
    {
        cout<<"Paket sok"<<endl;
        cout<<"kolicina "<<getKolicina()<<", so po "<<PaketPijalok::vratiMasa()<<" l(dm3)"<<endl;
    }
};


class PaketVino: public PaketPijalok{
private:
    double procentAlkohol;
public:
    PaketVino(double volumeEden = 0, int kolicina = 0, double procentAlkohol = 0) : PaketPijalok(volumeEden, kolicina)
    {
        this->procentAlkohol = procentAlkohol;
    }

    double vratiMasa()
    {
        return PaketPijalok::vratiMasa()*getKolicina() * (0.9 + procentAlkohol);
    }

    void pecati()
    {
        cout<<"Paket vino"<<endl;
        cout<<"kolicina "<<getKolicina()<<", "<<getProcentAlkohol()<<"% alkohol od po "<<PaketPijalok::vratiMasa()<<" l(dm3)"<<endl;
    }

    double getProcentAlkohol()
    {
        return procentAlkohol*100;
    }

};


class Kamion{
private:
    char registracija[50];
    char vozach[50];
    ImaMasa **paketi;
    static int n;
public:
    Kamion(char * registracija = "", char * vozach = "", ImaMasa ** paketi = 0)
    {
        strcpy(this->registracija, registracija);
        strcpy(this->vozach, vozach);
        this->paketi = new ImaMasa * [n];
        for(int i=0; i<n; i++)
        {
            this->paketi[i] = paketi[i];
        }
    }
    Kamion(const Kamion &k)
    {
        strcpy(this->registracija, k.registracija);
        strcpy(this->vozach, k.vozach);
        this->paketi = new ImaMasa * [k.n];
        for(int i=0; i<n; i++)
        {
            this->paketi[i] = k.paketi[i];
        }
    }
    Kamion& operator=(const Kamion &k)
    {
        if(this!=&k)
        {
            strcpy(this->registracija, k.registracija);
            strcpy(this->vozach, k.vozach);
            delete [] paketi;
            this->paketi = new ImaMasa * [k.n];
            for(int i=0; i<n; i++)
            {
                this->paketi[i] = k.paketi[i];
            }
        }
        return * this;
    }
    ~Kamion()
    {
        delete [] paketi;
    }
    void registriraj(char * registracija)
    {
        strcpy(this->registracija, registracija);
    }
    void dodadiElement(ImaMasa *nov)
    {
        ImaMasa ** temp = new ImaMasa*[n++];
        for(int i=0; i<n; i++)
        {
            temp[i] = paketi[i];
        }
        temp[n++] = nov;
        delete [] paketi;
        paketi = temp;
    }
    double vratiVkupnaMasa()
    {
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += paketi[i]->vratiMasa();
        }
        return sum;
    }
    void pecati()
    {
        cout<<"Kamion so registracija "<<registracija<<" i vozac "<<vozach<<" prenesuva: "<<endl;
        for(int i=0; i<n; i++)
        {
            paketi[i]->pecati();
        }
    }
    Kamion pretovar(char * registracija, char * vozach)
    {

    }


};
int Kamion::n = 0;


int main()
{
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;

            cin>>reg;
            cin>>ime;
            Kamion A(reg, ime);
            ImaMasa **d = new ImaMasa*[5];
            cin>>vol>>kol;
            cin>>g;
            d[0] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[1] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>proc;
            d[2] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol;
            cin>>g;
            d[3] = new PaketSok(vol, kol, g);
            cin>>vol>>kol;
            cin>>proc;
            d[4] = new PaketVino(vol, kol, proc);

            A.dodadiElement(d[0]);
            A.dodadiElement(d[1]);
            A.dodadiElement(d[2]);
            A.dodadiElement(d[3]);
            A.dodadiElement(d[4]);
            A.pecati();
            cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
            cin>>reg;
            cin>>ime;
            Kamion B = A.pretovar(reg, ime);
            B.pecati();
            cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;

}
