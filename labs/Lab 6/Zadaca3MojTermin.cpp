#include <iostream>
#include <cstring>

using namespace std;


class Lekar{
protected:
    int faksimil;
    char ime[11], prezime[11];
    double pocetna_plata;
public:
    Lekar(int faksimil = 0, char * ime = "", char * prezime = "", double pocetna_plata = 0)
    {
        this->faksimil = faksimil;
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->pocetna_plata = pocetna_plata;
    }
    Lekar& operator=(const Lekar &l)
    {
        if(this!=&l)
        {
            this->faksimil = l.faksimil;
            strcpy(this->ime, l.ime);
            strcpy(this->prezime, l.prezime);
            this->pocetna_plata = l.pocetna_plata;
        }
        return *this;
    }

    double plata()
    {
        return pocetna_plata;
    }
    void pecati()
    {
        cout<<faksimil<<": "<<ime<<" "<<prezime<<endl;
    }
};

class MaticenLekar: public Lekar{
private:
    int br_pacienti;
    double * kotizacii;
public:
    MaticenLekar(int faksimil = 0, char * ime = "", char * prezime = "", double pocetna_plata = 0,
    int  br_pacienti = 0, double * kotizacii = 0) : Lekar(faksimil, ime, prezime, pocetna_plata)
    {
        this->br_pacienti = br_pacienti;
        this->kotizacii = new double[br_pacienti];
        for(int i=0; i<br_pacienti; i++)
        {
            this->kotizacii[i] = kotizacii[i];
        }
    }
    MaticenLekar(const Lekar &l, int br_pacienti = 0, double * kotizacii = 0) : Lekar(l)
    {
        this->br_pacienti = br_pacienti;
        this->kotizacii = new double[br_pacienti];
        for(int i=0; i<br_pacienti; i++)
        {
            this->kotizacii[i] = kotizacii[i];
        }
    }
    MaticenLekar(const MaticenLekar &ml) : Lekar(faksimil, ime, prezime, pocetna_plata)
    {
        this->br_pacienti = ml.br_pacienti;
        this->kotizacii = new double[ml.br_pacienti];
        for(int i=0; i<br_pacienti; i++)
        {
            this->kotizacii[i] = ml.kotizacii[i];
        }
    }
    MaticenLekar& operator=(const MaticenLekar &ml)
    {
        Lekar::operator=(ml);
        if(this!=&ml)
        {
            this->br_pacienti = ml.br_pacienti;
            delete [] kotizacii;
            this->kotizacii = new double[ml.br_pacienti];
            for(int i=0; i<br_pacienti; i++)
            {
                this->kotizacii[i] = ml.kotizacii[i];
            }
        }
        return *this;
    }
    ~MaticenLekar()
    {
        delete [] kotizacii;
    }

    double prosek()
    {
        double avg = 0;
        for(int i=0; i<br_pacienti; i++)
        {
            avg += kotizacii[i];
        }
        return (double)avg/br_pacienti;
    }
    double plata()
    {
        return (double)(Lekar::plata() + prosek()*0.3);
    }
    void pecati()
    {
        Lekar::pecati();
        cout<< "Prosek na kotizacii: "<< prosek() <<endl;
    }
};


int main() {
	int n;
	cin>>n;
	int pacienti;
	double kotizacii[100];
	int faksimil;
	char ime [20];
	char prezime [20];
	double osnovnaPlata;

	Lekar * lekari = new Lekar [n];
	MaticenLekar * maticni = new MaticenLekar [n];

	for (int i=0;i<n;i++){
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
	}

	for (int i=0;i<n;i++){
		cin >> pacienti;
		for (int j=0;j<pacienti;j++){
			cin >> kotizacii[j];
		}
		maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
	}

	int testCase;
	cin>>testCase;

	if (testCase==1){
		cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){
			lekari[i].pecati();
			cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
		}
	}
	else {
		cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){
			maticni[i].pecati();
			cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
		}
	}

	delete [] lekari;
	delete [] maticni;

	return 0;
}
