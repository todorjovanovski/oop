#include <iostream>
#include <cstring>

using namespace std;

enum Tip{
LINUX, UNIX, WINDOWS
};

class OperativenSistem{
private:
    char * ime;
    float verzija;
    Tip vid;
    float golemina;
public:
    OperativenSistem(char * ime = "", float verzija = 0, Tip vid = LINUX, float golemina = 0)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->vid = vid;
        this->golemina = golemina;
    }
    OperativenSistem(const OperativenSistem &os)
    {
        ime = new char[strlen(os.ime) + 1];
        strcpy(ime, os.ime);
        verzija = os.verzija;
        vid = os.vid;
        golemina = os.golemina;
    }
    OperativenSistem& operator=(const OperativenSistem &os)
    {
        if(this!=&os)
        {
            delete [] ime;
            ime = new char[strlen(os.ime) + 1];
            strcpy(ime, os.ime);
            verzija = os.verzija;
            vid = os.vid;
            golemina = os.golemina;
        }
        return *this;
    }
    ~OperativenSistem()
    {
        delete [] ime;
    }

    bool ednakviSe(const OperativenSistem &os)
    {
        if(strcmp(ime, os.ime) == 0 &&
           verzija == os.verzija &&
           vid == os.vid && golemina == os.golemina) return true;
        else return false;
    }
    int sporediVerzija(const OperativenSistem &os)
    {
        if(verzija == os.verzija) return 0;
        else if(verzija < os.verzija) return -1;
        else return 1;
    }
    bool istaFamilija(const OperativenSistem &sporedba)
    {
        if(strcmp(ime, sporedba.ime) == 0 &&
           vid == sporedba.vid) return true;
        else return false;
    }
    void pecati()
    {
        cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<vid<<" Golemina:"<<golemina<<"GB"<<endl;
    }


};

class Repozitorium{
private:
    char ime[20];
    OperativenSistem * sistemi;
    int br_os;
public:
    Repozitorium(const char * ime, OperativenSistem * sistemi = 0, int br_os = 0)
    {
        strcpy(this->ime, ime);
        this->br_os = br_os;
        this->sistemi = new OperativenSistem[br_os];
        for(int i=0; i<br_os; i++)
        {
            this->sistemi[i] = sistemi[i];
        }
    }
    Repozitorium(const Repozitorium &r)
    {
        strcpy(ime, r.ime);
        br_os =  r.br_os;
        sistemi = new OperativenSistem[r.br_os];
        for(int i=0; i<br_os; i++)
        {
            sistemi[i] = r.sistemi[i];
        }
    }
    Repozitorium& operator=(const Repozitorium &r)
    {
        if(this!=&r)
        {
            strcpy(ime, r.ime);
            br_os =  r.br_os;
            delete [] sistemi;
            sistemi = new OperativenSistem[r.br_os];
            for(int i=0; i<br_os; i++)
            {
                sistemi[i] = r.sistemi[i];
            }
        }
        return *this;
    }
    ~Repozitorium()
    {
        delete [] sistemi;
    }

    void izbrishi(const OperativenSistem &operativenSistem)
    {
        int newBr_os = 0;
        for(int i=0; i<br_os; i++)
        {
            if(sistemi[i].ednakviSe(operativenSistem) == false)
            {
                newBr_os++;
            }
        }
        OperativenSistem * temp = new OperativenSistem[newBr_os];
        int j = 0;
        for(int i=0; i<br_os; i++)
        {
            if(sistemi[i].ednakviSe(operativenSistem) == false)
            {
                temp[j++] = sistemi[i];
            }
        }
        delete [] sistemi;
        sistemi = temp;
        br_os = newBr_os;
    }
    void dodadi(const OperativenSistem &nov)
    {
        int check = 0;
        for(int i=0; i<br_os; i++)
        {
            if(sistemi[i].istaFamilija(nov) && sistemi[i].sporediVerzija(nov) == -1)
            {
                sistemi[i] = nov;
                check = 1;
            }
        }
        if(check == 0)
        {
            OperativenSistem * temp = new OperativenSistem[br_os + 1];
            for(int i=0; i<br_os; i++)
            {
                temp[i] = sistemi[i];
            }
            temp[br_os++] = nov;
            delete [] sistemi;
            sistemi = temp;
        }
    }
    void pecatiOperativniSistemi()
    {
        cout<<"Repozitorium: "<<ime<<endl;
        for(int i=0; i<br_os; i++)
        {
            sistemi[i].pecati();
        }
    }


};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
