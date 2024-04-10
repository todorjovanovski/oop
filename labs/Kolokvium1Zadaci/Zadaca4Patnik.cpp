#include<iostream>
#include<cstring>
using namespace std;

class Patnik{
private:
    char ime[100];
    int vagon;
    bool velosiped;
public:
    Patnik(char * ime = "", int vagon = 0, bool velosiped = false)
    {
        strcpy(this->ime, ime);
        this->vagon = vagon;
        this->velosiped = velosiped;
    }
    Patnik(const Patnik &p)
    {
        strcpy(ime, p.ime);
        vagon = p.vagon;
        velosiped = p.velosiped;
    }
    ~Patnik(){}

    int getVagon() const
    {
        return vagon;
    }
    bool getVelosiped() const
    {
        return velosiped;
    }

    friend ostream& operator<<(ostream& os, const Patnik& p);

};

ostream& operator<<(ostream& os, const Patnik& p)
{
    os<<p.ime<<endl;
    os<<p.vagon<<endl;
    os<<p.velosiped<<endl;
    return os;
}

class Voz{
private:
    char destinacija[100];
    Patnik * patnici;
    int n;
    int velosipedi;
public:
    Voz(char * destinacija = "",  int velosipedi = 0, Patnik * patnici = 0, int n = 0)
    {
        strcpy(this->destinacija, destinacija);
        this->n = n;
        this->patnici = new Patnik[n];
        for(int i=0; i<n; i++)
        {
            this->patnici[i] = patnici[i];
        }
        this->velosipedi = velosipedi;
    }
    Voz(const Voz &v)
    {
        strcpy(destinacija, v.destinacija);
        n = v.n;
        patnici = new Patnik[v.n];
        for(int i=0; i<n; i++)
        {
            patnici[i] = v.patnici[i];
        }
        velosipedi = v.velosipedi;
    }
    Voz& operator=(const Voz &v)
    {
        if(this!=&v)
        {
            strcpy(destinacija, v.destinacija);
            n = v.n;
            delete [] patnici;
            patnici = new Patnik[v.n];
            for(int i=0; i<n; i++)
            {
                patnici[i] = v.patnici[i];
            }
            velosipedi = v.velosipedi;
        }
        return *this;
    }

    void patniciNemaMesto()
    {
        int prva = 0, vtora = 0;
        for(int i=0; i<n; i++)
        {
            if(patnici[i].getVagon() == 1 && patnici[i].getVelosiped() == true)
            {
                prva++;
            }
            else if(patnici[i].getVagon() == 2 && patnici[i].getVelosiped() == true)
            {
                vtora++;
            }
        }

        for(int i=0; i<velosipedi; i++)
        {
            if(prva > 0)
            {
                prva--;
            }
            else if(vtora > 0)
            {
                vtora--;
            }
        }
        cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<prva<<endl;
        cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<vtora<<endl;
    }

    Voz& operator+=(const Patnik &p)
    {
        int temp = velosipedi;
        if(p.getVelosiped())
        {
            if(temp > 0)
            {
                Patnik * temp = new Patnik[n+1];
                for(int i=0; i<n; i++)
                {
                    temp[i] = patnici[i];
                }
                temp[n++] = p;
                delete [] patnici;
                patnici = temp;
                temp--;
            }
        }
        else{
            Patnik * temp = new Patnik[n+1];
            for(int i=0; i<n; i++)
            {
                temp[i] = patnici[i];
            }
            temp[n++] = p;
            delete [] patnici;
            patnici = temp;
        }
    }

    friend ostream& operator<<(ostream& os, const Voz& v);
};

ostream& operator<<(ostream& os, const Voz& v)
{
    os<<v.destinacija<<endl;
    for(int i=0; i<v.n; i++)
    {
        cout<<v.patnici[i]<<endl;
    }
    return os;
}

int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}
