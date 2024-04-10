#include <iostream>
#include <cstring>
using namespace std;

enum zanr{
akcija, komedija, drama
};

class Film{
private:
    char * ime;
    int memorija;
    zanr tip;
public:
    Film(char * ime = "", int memorija = 0, zanr tip = akcija)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->memorija = memorija;
        this->tip = tip;
    }
    Film(const Film &f)
    {
        ime = new char[strlen(f.ime) + 1];
        strcpy(ime, f.ime);
        memorija = f.memorija;
        tip = f.tip;
    }
    Film& operator=(const Film &f)
    {
        if(this!=&f)
        {
            delete [] ime;
            ime = new char[strlen(f.ime) + 1];
            strcpy(ime, f.ime);
            memorija = f.memorija;
            tip = f.tip;
        }
        return *this;
    }
    ~Film()
    {
        delete [] ime;
    }

    void pecati()
    {
        cout<<memorija<<"MB-"<<"\""<<ime<<"\""<<endl;
    }
    zanr getZanr()
    {
        return tip;
    }
    int getMemorija()
    {
        return memorija;
    }
};

class DVD{
private:
    Film * filmovi;
    int br_filmovi;
    int kapacitet;
public:
    DVD(int kapacitet = 0, int br_filmovi = 0, Film * filmovi = 0)
    {
        this->kapacitet = kapacitet;
        this->br_filmovi = br_filmovi;
        if(br_filmovi <= 5)
        {
            this->filmovi = new Film[br_filmovi];
            for(int i=0; i<br_filmovi; i++)
            {
                this->filmovi[i] = filmovi[i];
            }
        }
    }
    DVD(const DVD &d)
    {
        kapacitet = d.kapacitet;
        br_filmovi = d.br_filmovi;
        if(br_filmovi <= 5)
        {
            filmovi = new Film[d.br_filmovi];
            for(int i=0; i<br_filmovi; i++)
            {
                filmovi[i] = d.filmovi[i];
            }
        }
    }
    DVD& operator=(const DVD &d)
    {
        if(this!=&d)
        {
            kapacitet = d.kapacitet;
            br_filmovi = d.br_filmovi;
            if(br_filmovi <= 5)
            {
                delete [] filmovi;
                filmovi = new Film[d.br_filmovi];
                for(int i=0; i<br_filmovi; i++)
                {
                    filmovi[i] = d.filmovi[i];
                }
            }
        }
    }
    ~DVD()
    {
        delete [] filmovi;
    }

    void dodadiFilm(Film f)
    {
        if(br_filmovi<5 && kapacitet>=f.getMemorija())
        {
            Film * temp = new Film[br_filmovi + 1];
            for(int i=0; i<br_filmovi; i++)
            {
                temp[i] = filmovi[i];
            }
            temp[br_filmovi++] = f;
            delete [] filmovi;
            filmovi = temp;
        }
        kapacitet -= f.getMemorija();
    }
    void pecatiFilmoviDrugZanr(zanr z)
    {
        for(int i=0; i<br_filmovi; i++)
        {
            //if(filmovi[i].getZanr() != akcija && filmovi[i].getZanr() != komedija && filmovi[i].getZanr() != drama)
            if(filmovi[i].getZanr() != z)
            {
                filmovi[i].pecati();
            }
        }
    }
    float procentNaMemorijaOdZanr(zanr z)
    {
        int zbir_memorija = 0;
        int suma = 0;
        for(int i=0; i<br_filmovi; i++)
        {
            suma+=filmovi[i].getMemorija();
            if(filmovi[i].getZanr() == z)
                zbir_memorija += filmovi[i].getMemorija();
        }
        return (float)zbir_memorija/suma*100;
    }
    int getBroj()
    {
        return br_filmovi;
    }
    Film getFilm(int i)
    {
        return filmovi[i];
    }



};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";

	}

    return 0;
}
