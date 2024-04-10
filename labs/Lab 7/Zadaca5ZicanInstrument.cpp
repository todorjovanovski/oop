#include <iostream>
#include <cstring>

using namespace std;


class ZicanInstrument{
protected:
    char instrument[20];
    int strings;
    double price;
public:
    ZicanInstrument(char *instrument = "", int strings = 0, double price = 0)
    {
        strcpy(this->instrument, instrument);
        this->strings = strings;
        this->price = price;
    }

    virtual double cena() = 0;

    friend bool operator==(ZicanInstrument & i1, ZicanInstrument & i2);
};

bool operator==(ZicanInstrument & i1, ZicanInstrument & i2)
{
    if(i1.strings == i2.strings)
        return true;
    else
        return false;
}


class Mandolina : public ZicanInstrument{
private:
    char form[20];
public:
    Mandolina(char *instrument = "", int strings = 0, double price = 0,
    char *form = "") : ZicanInstrument(instrument, strings, price)
    {
        strcpy(this->form, form);
    }

    double cena()
    {
        if(strcmp(form, "Neapolitan") == 0)
            return price*1.15;
        else return price;
    }

    friend ostream& operator<<(ostream & os, Mandolina & m)
    {
        os<<m.instrument<< " " <<m.strings<< " " <<m.price<< " " <<m.form<<endl;
        return os;
    }
};


class Violina : public ZicanInstrument{
private:
    double size;
public:
    Violina(char *instrument = "", int strings = 0, double price = 0,
    double size = 0) : ZicanInstrument(instrument, strings, price)
    {
        this->size = size;
    }

    double cena()
    {
        if(size == 0.25)
            return price*1.1;
        else if(size == 1)
            return price*1.2;
        else
            return price;
    }
    friend ostream& operator<<(ostream & os, Violina & v)
    {
        os<<v.instrument<< " " <<v.strings<< " " <<v.price<< " " <<v.size<<endl;
        return os;
    }
};


void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **ins, int n)
{
    for(int i=0; i<n; i++)
    {
        if(*ins[i] == zi)
        {
            cout<<ins[i]->cena()<<endl;
        }
    }
}


int main() {
	char ime[20];
	int brojZici;
	float cena;
	char forma[20];
	cin >> ime >> brojZici >> cena >> forma;
	Mandolina m(ime, brojZici, cena, forma);
	int n;
	cin >> n;
	ZicanInstrument **zi = new ZicanInstrument*[2 * n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina;
		cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}
	pecatiInstrumenti(m, zi, 2 * n);
	for(int i = 0; i < 2 * n; ++i) {
		delete zi[i];
	}
	delete [] zi;
	return 0;
}
