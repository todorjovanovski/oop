#include<iostream>
#include<cstring>

using namespace std;


class InvalidDateException{
private:
    int den, mesec, godina;
public:
    InvalidDateException(int den, int mesec, int godina)
    {
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
    }

    void message()
    {
        cout<< "Invalid Date " <<den<< "/" <<mesec<< "/" <<godina<<endl;
    }


};

class NotSupportedCurrencyException{
private:
    char currency[50];
public:
    NotSupportedCurrencyException(char * currency = "")
    {
        strcpy(this->currency, currency);
    }

    void message()
    {
        cout<<currency<< " is not a supported currency"<<endl;
    }


};


class Transakcija{
protected:
    int den, mesec, godina;
    double iznos;
public:
    static double EUR;
    static double USD;
    Transakcija(int den = 0, int mesec = 0, int godina = 0, double iznos = 0)
    {
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
        this->iznos = iznos;
        if(den < 1 || den > 31 || mesec < 1 || mesec > 12)
        {
            throw InvalidDateException(den, mesec, godina);
        }
    }

    static void setEUR(double newEur)
    {
        EUR = newEur;
    }
    static void setUSD(double newUSD)
    {
        USD = newUSD;
    }

    virtual double voDenari() = 0;
    virtual void pecati() = 0;
    virtual double voEvra() = 0;
    virtual double voDolari() = 0;
};
double Transakcija::EUR = 61;
double Transakcija::USD = 50;


class DenarskaTransakcija: public Transakcija{
public:
    DenarskaTransakcija(int den = 0, int mesec = 0, int godina = 0, double iznos = 0) : Transakcija(den, mesec, godina, iznos){}

    double voDenari()
    {
        return iznos;
    }
    double voEvra()
    {
        return iznos/EUR;
    }
    double voDolari()
    {
        return iznos/USD;
    }
    void pecati()
    {
          cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" MKD"<<endl;
    }
};

class DeviznaTransakcija: public Transakcija{
private:
    char valuta[3];
public:
    DeviznaTransakcija(int den = 0, int mesec = 0, int godina = 0, double iznos = 0,
    char * valuta = "") : Transakcija(den, mesec, godina, iznos)
    {
        strcpy(this->valuta, valuta);
        if(strcmp(valuta, "USD") != 0 && strcmp(valuta, "EUR") != 0)
        {
            throw NotSupportedCurrencyException(valuta);
        }
    }

    double voDenari()
    {
        if(strcmp(valuta, "USD") == 0)
        {
            return iznos * USD;
        }
        else if(strcmp(valuta, "EUR") == 0)
        {
            return iznos * EUR;
        }
    }
    double voEvra()
    {
        if(strcmp(valuta, "EUR") == 0)
        {
            return iznos;
        }
        else if(strcmp(valuta, "USD") == 0)
        {
            return iznos/USD*EUR;
        }
    }
    double voDolari()
    {
        if(strcmp(valuta, "USD") == 0)
        {
            return iznos;
        }
        else if(strcmp(valuta, "EUR") == 0)
        {
            return iznos/EUR*USD;
        }
    }
    void pecati()
    {
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" "<<valuta<<endl;
    }
};


class Smetka{
private:
    Transakcija ** transakcii;
    int n;
    char brojSmetka[15];
    double saldo;
public:
    Smetka(char *brojSmetka = "", double saldo = 0, int n = 0, Transakcija **transakcii = 0)
    {
        strcpy(this->brojSmetka, brojSmetka);
        this->saldo = saldo;
        this->n = n;
        this->transakcii = new Transakcija*[n];
        for(int i=0; i<n; i++)
        {
            this->transakcii[i] = transakcii[i];
        }
    }
    Smetka(const Smetka &s)
    {
        strcpy(this->brojSmetka, s.brojSmetka);
        this->saldo = s.saldo;
        this->n = s.n;
        this->transakcii = new Transakcija*[s.n];
        for(int i=0; i<n; i++)
        {
            this->transakcii[i] = s.transakcii[i];
        }
    }
    Smetka& operator=(const Smetka &s)
    {
        if(this!=&s)
        {
            strcpy(this->brojSmetka, s.brojSmetka);
            this->saldo = s.saldo;
            this->n = s.n;
            delete [] transakcii;
            this->transakcii = new Transakcija*[s.n];
            for(int i=0; i<n; i++)
            {
                this->transakcii[i] = s.transakcii[i];
            }
        }
        return * this;
    }
    ~Smetka()
    {
        delete [] transakcii;
    }

    double saldoBraleMKD()
    {
        double novoSaldo = saldo;
        for(int i=0; i<n; i++)
        {
            novoSaldo += transakcii[i]->voDenari();
        }
        return novoSaldo;
    }

    Smetka& operator +=(Transakcija *t)
    {
        Transakcija ** temp = new Transakcija*[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = transakcii[i];
        }
        temp[n++] = t;
        delete [] transakcii;
        transakcii = temp;
        return * this;
    }
    void izvestajVoDenari()
    {
        cout<< "Korisnikot so smetka: " <<brojSmetka<< " ima momentalno saldo od " <<saldoBraleMKD()<< " MKD"<<endl;
    }
    void izvestajVoEvra()
    {
        cout<< "Korisnikot so smetka: " <<brojSmetka<< " ima momentalno saldo od " <<saldoBraleMKD()/Transakcija::EUR<< " EUR"<<endl;
    }
    void izvestajVoDolari()
    {
        cout<< "Korisnikot so smetka: " <<brojSmetka<< " ima momentalno saldo od " <<saldoBraleMKD()/Transakcija::USD<< " USD"<<endl;
    }
    void pecatiTransakcii()
    {
        for(int i=0; i<n; i++)
        {
            transakcii[i]->pecati();
        }
    }
};


int main () {

	Smetka s ("300047024112789",1500);

	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [3];

	cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		if (tip==2){
			cin>>valuta;
			try{
            Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);
			s+=t;
			}
			catch(NotSupportedCurrencyException error)
			{
			    error.message();
			}
			catch(InvalidDateException error)
			{
			    error.message();
			}

            //delete t;
		}
		else {
            try{
			Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);
			s+=t;
            }
            catch(InvalidDateException error)
            {
                error.message();
            }

            //delete t;
		}

	}
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



	return 0;
}
