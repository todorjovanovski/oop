#include <iostream>
#include <cstring>

using namespace std;

//Vasiot kod tuka

class Pica{
private:
    char vid[15];
    int cena;
    char * sostojki;
    int popust;
public:
    Pica(char * vid = "", int cena = 0, char * sostojki = "", int popust = 0)
    {
        strcpy(this->vid, vid);
        this->cena = cena;
        this->sostojki = new char [strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
        this->popust = popust;
    }
    Pica(const Pica &p)
    {
        strcpy(vid, p.vid);
        cena = p.cena;
        sostojki = new char [strlen(p.sostojki) + 1];
        strcpy(sostojki, p.sostojki);
        popust = p.popust;
    }
    Pica& operator=(const Pica &p)
    {
        if(this!=&p)
        {
            strcpy(vid, p.vid);
            cena = p.cena;
            delete [] sostojki;
            sostojki = new char [strlen(p.sostojki) + 1];
            strcpy(sostojki, p.sostojki);
            popust = p.popust;
        }
        return *this;
    }
    ~Pica()
    {
        delete [] sostojki;
    }

    bool istiSe(Pica p)
    {
        if(strcmp(sostojki, p.sostojki) == 0) return true;
        else return false;
    }
    void pecati()
    {
        cout<<vid<<" - "<<sostojki<<", "<<cena;
    }
    int getPopust()
    {
        return popust;
    }
    int getCena()
    {
        return cena;
    }

};

class Picerija{
private:
    char ime[15];
    Pica * pici;
    int br_pici;
public:
    Picerija(char * ime = "", Pica * pici = 0, int br_pici = 0)
    {
        strcpy(this->ime, ime);
        this->br_pici = br_pici;
        this->pici = new Pica[br_pici];
        for(int i=0; i<br_pici; i++)
        {
            this->pici[i] = pici[i];
        }
    }
    Picerija(const Picerija &p)
    {
        strcpy(ime, p.ime);
        br_pici = p.br_pici;
        pici = new Pica[p.br_pici];
        for(int i=0; i<br_pici; i++)
        {
            pici[i] = p.pici[i];
        }
    }
    Picerija& operator=(const Picerija &p)
    {
        if(this!=&p)
        {
            strcpy(ime, p.ime);
            br_pici = p.br_pici;
            delete [] pici;
            pici = new Pica[p.br_pici];
            for(int i=0; i<br_pici; i++)
            {
                pici[i] = p.pici[i];
            }
        }
        return *this;
    }
    ~Picerija()
    {
        delete [] pici;
    }
    void setIme(char * i)
    {
        strcpy(ime, i);
    }
    char * getIme()
    {
        return ime;
    }

    void dodadi(Pica P)
    {
        int check = 0;
        for(int i=0; i<br_pici; i++)
        {
            if(pici[i].istiSe(P))
            {
                check = 1;
            }
        }
        if(check == 0)
        {
            Pica * temp = new Pica[br_pici + 1];
            for(int i=0; i<br_pici; i++)
            {
                temp[i] = pici[i];
            }
            temp[br_pici++] = P;
            delete [] pici;
            pici = temp;
        }
    }
    void piciNaPromocija()
    {
        for(int i=0; i<br_pici; i++)
        {
            if(pici[i].getPopust() > 0)
            {
                pici[i].pecati();
                cout<<" "<<pici[i].getCena()-((float)pici[i].getCena()/100*pici[i].getPopust())<<endl;
            }
        }
    }

};

int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}
