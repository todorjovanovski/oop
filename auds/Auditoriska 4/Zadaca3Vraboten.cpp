#include <iostream>
#include <cstring>
using namespace std;

class Datum{
private:
    int den, mesec, godina;
public:
    Datum(int den = 0, int mesec = 0, int godina = 0)
    {
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
    }
    Datum(const Datum &d)
    {
        den = d.den;
        mesec = d.mesec;
        godina = d.godina;
    }

    int get_den()
    {
        return den;
    }
    int get_mesec()
    {
        return mesec;
    }
    int get_godina()
    {
        return godina;
    }
    void print()
    {
        cout<<den<<"."<<mesec<<"."<<godina<<"."<<endl;
    }
};

class Vraboten{
private:
    char ime[20];
    int plata;
    Datum data;
public:
    Vraboten(char * ime = "", int plata = 0, Datum data = 0)
    {
        strcpy(this->ime, ime);
        this->plata = plata;
        this->data = data;
    }

    int get_plata()
    {
        return plata;
    }
    Datum getDate()
    {
        return data;
    }
    void print()
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Plata: "<<plata<<endl;
        cout<<"Data na ragjanje: ";
        data.print();
        cout<<endl;
    }
};

Vraboten najgolema_plata(Vraboten vraboteni [], int n)
{
    Vraboten max = vraboteni[0];
    for(int i=0; i<n; i++)
    {
        if(vraboteni[i].get_plata()>max.get_plata())
        {
            max = vraboteni[i];
        }
    }
    return max;
}

int sporedba(Datum d1, Datum d2)
{
    if(d1.get_godina() > d2.get_godina())
    {
        return 1;
    }
    else if(d1.get_godina() < d2.get_godina())
    {
        return 2;
    }
    else{
        if(d1.get_mesec() > d2.get_mesec())
        {
            return 1;
        }
        else if(d1.get_mesec() < d2.get_mesec())
        {
            return 2;
        }
        else{
            if(d1.get_den() > d2.get_den())
            {
                return 1;
            }
            else if(d1.get_den() < d2.get_den())
            {
                return 2;
            }
            else{
                return 0;
            }
        }
    }
}

Vraboten najmlad(Vraboten vraboteni [], int n)
{
    Vraboten min = vraboteni[0];
    for(int i=0; i<n; i++)
    {
        if(sporedba(min.getDate(), vraboteni[i].getDate()) == 2)
        {
            min = vraboteni[i];
        }
    }
    return min;
}

int main()
{
    Datum d1(1, 1, 1990);
    Datum d2(2, 2, 1992);
    Datum d3(3, 3, 1993);

    Vraboten vraboteni[3];
    Vraboten v1("Aleksandar", 40000, d1);
    Vraboten v2("Todor", 50000, d2);
    Vraboten v3("Spase", 30000, d3);
    vraboteni[0]= v1;
    vraboteni[1]= v2;
    vraboteni[2]= v3;

    cout<<"Najmlad vraboten: "<<endl;
    najmlad(vraboteni, 3).print();

    cout<<"Najplaten vraboten: "<<endl;
    najgolema_plata(vraboteni, 3).print();

    return 0;
}
