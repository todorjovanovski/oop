#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


class Igrachka {
public:
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    Forma(char * boja = "", int gustina = 0)
    {
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }
};

class Kocka : public Igrachka, public Forma{
private:
    int visina, sirina, dlabocina;
public:
    Kocka(char * boja = "", int gustina = 0, int visina = 0, int sirina = 0, int dlabocina = 0)
    : Forma(boja, gustina)
    {
        this->visina = visina;
        this->sirina = sirina;
        this->dlabocina = dlabocina;
    }

    float getVolumen()
    {
        return visina * sirina * dlabocina;
    }
    float getPlostina()
    {
        return 2*visina*sirina + 2*visina*dlabocina + 2*sirina*dlabocina;
    }
    float getMasa()
    {
        return getVolumen()*gustina;
    }
};

class Topka : public Igrachka, public Forma{
private:
    int radius;
public:
    Topka(char * boja = "", int gustina = 0, int radius = 0) : Forma(boja, gustina)
    {
        this->radius = radius;
    }

    float getVolumen()
    {
        return (float)4/3*3.14*radius*radius*radius;
    }
    float getPlostina()
    {
        return (float)4*3.14*radius*radius;
    }
    float getMasa()
    {
        return getVolumen()*gustina;
    }
};


void vkupnaMasaIgracki(Igrachka **niza, int n, Kocka *k)
{
    double masa = 0;
    for(int i=0; i<n; i++)
    {
        masa += niza[i]->getMasa();
    }

    if(masa > k->getMasa())
    {
        cout<<"DA"<<endl;
    }
    else{
        cout<<"NE"<<endl;
    }
}

void razlikaVoVolumen(Igrachka **niza, int n, Kocka *k)
{
    double maxVolumen = 0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->getVolumen() > maxVolumen)
        {
            maxVolumen = niza[i]->getVolumen();
        }
    }
    double razlika = abs(maxVolumen - k->getVolumen());
    cout<<"Razlikata e: "<<razlika<<endl;
}

void razlikaVoPlostina(Igrachka **niza, int n, Kocka *k)
{
    double minPlostina = niza[0]->getPlostina();
    for(int i=0; i<n; i++)
    {
        if(niza[i]->getPlostina() < minPlostina)
        {
            minPlostina = niza[i]->getPlostina();
        }
    }
    double razlika = abs(minPlostina - k->getPlostina());
    cout<<"Razlikata e: "<<razlika<<endl;
}

int main(){
	//vnesi informacii za kupche
	int n;
	cin>>n;
	Igrachka **kupche = new Igrachka*[n];

    char boja[50];
    int gustina, type;
    int visina, sirina, dlabocina;
    int radius;

	for(int i=0; i<n; i++)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>boja>>gustina>>radius;
            kupche[i] = new Topka(boja, gustina, radius);
        }
        else if(type == 2)
        {
            cin>>boja>>gustina>>visina>>sirina>>dlabocina;
            kupche[i] = new Kocka(boja, gustina, visina, sirina, dlabocina);
        }
    }

    //vnesi informacii za igrachkata na Petra
    cin>>boja>>gustina>>visina>>sirina>>dlabocina;
    Kocka * petra = new Kocka(boja, gustina, visina, sirina, dlabocina);

	//baranje 1
    vkupnaMasaIgracki(kupche, n, petra);

	//baranje 2
	razlikaVoVolumen(kupche, n, petra);

    //dopolnitelno baranje 2
    razlikaVoPlostina(kupche, n, petra);

    for(int i=0; i<n; i++)
    {
        delete kupche[i];
    }
    delete [] kupche;

    delete [] petra;

	return 0;
}
