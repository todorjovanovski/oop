#include <iostream>
#include <cstring>
using namespace std;

class Ekipa{
private:
    char ime[50];
    char grad[50];
    int godina;
public:
    Ekipa(char * ime = "", char * grad = "", int godina = 0)
    {
        strcpy(this->ime, ime);
        strcpy(this->grad, grad);
        this->godina = godina;
    }
    Ekipa(const Ekipa &team)
    {
        strcpy(ime, team.ime);
        strcpy(grad, team.grad);
        godina = team.godina;
    }
    ~Ekipa(){}

    char * getIme()
    {
        return ime;
    }
};

class Natprevar{
private:
    Ekipa domakin;
    Ekipa gostin;
    int golovi_domakin;
    int golovi_gostin;
public:
    Natprevar(Ekipa d, Ekipa g, int gd, int gg)
    {
        domakin = d;
        gostin = g;
        golovi_domakin = gd;
        golovi_gostin = gg;
    }

    int getGoloviDomakin()
    {
        return golovi_domakin;
    }
    int getGoloviGostin()
    {
        return golovi_gostin;
    }
    Ekipa getDomakin()
    {
        return domakin;
    }
    Ekipa getGostin()
    {
        return gostin;
    }
};

int revans(Natprevar n1, Natprevar n2)
{
    if(strcmp(n1.getDomakin().getIme(), n2.getGostin().getIme()) == 0 &&
       strcmp(n1.getGostin().getIme(), n2.getDomakin().getIme()) == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

Ekipa duel(Natprevar n1, Natprevar n2)
{
    if(revans(n1, n2))
    {
        int e1golovi = n1.getGoloviDomakin() + n2.getGoloviGostin();
        int e2golovi = n1.getGoloviGostin() + n2.getGoloviDomakin();
        if(e1golovi > e2golovi)
        {
            return n1.getDomakin();
        }
        else if(e1golovi < e2golovi)
        {
            return n1.getGostin();
        }
        else{
            cout<<"Nereseno."<<endl;
            return 0;
        }
    }
    else{
        cout<<"Ne se sovpagjaat."<<endl;
        return 0;
    }
}

int main()
{
    char ime[50], grad[50];
    int godina;

    cout<<"Vnesi podatoci za prva ekipa:"<<endl;
    cin>>ime>>grad>>godina;
    Ekipa e1(ime, grad, godina);

    cout<<"Vnesi podatoci za vtora ekipa:"<<endl;
    cin>>ime>>grad>>godina;
    Ekipa e2(ime, grad, godina);

    Natprevar n1(e1, e2, 1, 2);
    Natprevar n2(e2, e1, 1, 2);

    cout<<duel(n1, n2).getIme();

    return 0;
}
