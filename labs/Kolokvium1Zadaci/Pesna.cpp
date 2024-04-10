#include <iostream>
#include <cstring>

using namespace std;

enum tip{
pop, rap, rok
};

class Pesna{
private:
    char * ime;
    int vremetraenje;
    tip zanr;
public:
    Pesna(char * ime = "", int vremetraenje = 0, tip zanr = pop)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->vremetraenje = vremetraenje;
        this->zanr = zanr;
    }
    Pesna(const Pesna &p)
    {
        ime = new char[strlen(p.ime) + 1];
        strcpy(ime, p.ime);
        vremetraenje = p.vremetraenje;
        zanr = p.zanr;
    }
    Pesna& operator=(const Pesna &p)
    {
        if(this!=&p)
        {
            delete [] ime;
            ime = new char[strlen(p.ime) + 1];
            strcpy(ime, p.ime);
            vremetraenje = p.vremetraenje;
            zanr = p.zanr;
        }
        return *this;
    }
    ~Pesna()
    {
        delete [] ime;
    }

    void pecati()
    {
        cout<<"\""<<ime<<"\""<<"-"<<vremetraenje<<"min"<<endl;
    }
    friend class CD;
};

class CD{
private:
    Pesna * pesni;
    int br_pesni;
    int max_vremetraenje;
public:
    CD(int max_vremetraenje = 0, Pesna * pesni = 0, int br_pesni = 0)
    {
        this->max_vremetraenje = max_vremetraenje;
        this->br_pesni = br_pesni;
        if(br_pesni <= 10)
        {
            this->pesni = new Pesna[br_pesni];
            for(int i=0; i<br_pesni; i++)
            {
                this->pesni[i] = pesni[i];
            }
        }
    }
    CD(const CD &c)
    {
        max_vremetraenje = c.max_vremetraenje;
        br_pesni = c.br_pesni;
        pesni = new Pesna[c.br_pesni];
        for(int i=0; i<br_pesni; i++)
        {
            pesni[i] = c.pesni[i];
        }
    }
    CD& operator=(const CD &c)
    {
        if(this!=&c)
        {
            max_vremetraenje = c.max_vremetraenje;
            br_pesni = c.br_pesni;
            pesni = new Pesna[c.br_pesni];
            for(int i=0; i<br_pesni; i++)
            {
                pesni[i] = c.pesni[i];
            }
        }
        return *this;
    }
    ~CD()
    {
        if(br_pesni)
        {
            delete [] pesni;
        }
    }

    Pesna getPesna(int i)
    {
        return pesni[i];
    }
    int getBroj()
    {
        return br_pesni;
    }
    void dodadiPesna(Pesna p)
    {
        if(br_pesni < 10 && max_vremetraenje > p.vremetraenje)
        {
            Pesna * temp = new Pesna[br_pesni + 1];
            for(int i=0; i<br_pesni; i++)
            {
                temp[i] = pesni[i];
            }
            temp[br_pesni++] = p;
            delete [] pesni;
            pesni = temp;
            max_vremetraenje -= p.vremetraenje;
        }
    }
    void pecatiPesniPoTip(tip t)
    {
        for(int i=0; i<br_pesni; i++)
        {
            if(pesni[i].zanr == t)
            {
                pesni[i].pecati();
            }
        }
    }
};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}
