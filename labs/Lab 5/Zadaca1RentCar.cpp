#include <iostream>
#include <cstring>

using namespace std;

class Automobile{
private:
    char * marka;
    int * registracija;
    int topSpeed;
public:
    Automobile(char * marka = "", int * registracija = 0, int topSpeed = 0)
    {
//        cout<<"Povikan e kosntruktor"<<endl;
        this->marka = new char[strlen(marka) + 1];
        strcpy(this->marka, marka);
        this->registracija = new int[5];
        for(int i=0; i<5; i++)
        {
            this->registracija[i] = registracija[i];
        }
        this->topSpeed = topSpeed;
    }
    Automobile(const Automobile &a)
    {
        this->marka = new char[strlen(a.marka) + 1];
        strcpy(this->marka, a.marka);
        for(int i=0; i<5; i++)
        {
            this->registracija[i] = a.registracija[i];
        }
        this->topSpeed = a.topSpeed;
    }
    Automobile& operator=(const Automobile &a)
    {
        if(this!=&a)
        {
            delete [] marka;
            this->marka = new char[strlen(a.marka) + 1];
            strcpy(this->marka, a.marka);
            delete [] registracija;
            for(int i=0; i<5; i++)
            {
                this->registracija[i] = a.registracija[i];
            }
            this->topSpeed = a.topSpeed;
        }
        return *this;
    }
    ~Automobile()
    {
        delete [] marka;
        delete [] registracija;
    }

    char * getMarka() const
    {
        return marka;
    }

    int getTopSpeed()
    {
        return topSpeed;
    }

    bool operator==(const Automobile &a)
    {
        for(int i=0; i<5; i++)
        {
            if(registracija[i] != a.registracija[i])
                return false;
        }
        return true;
    }

    friend ostream& operator<<(ostream& out, const Automobile& a);

};

ostream& operator<<(ostream& out, const Automobile& a)
{
    out<<"Marka: "<<a.marka<<" Registracija: [ ";
    for(int i=0; i<5; i++)
    {
        out<<a.registracija[i]<<" ";
    }
    out<<"]"<<endl;
    return out;
}

class RentACar{
private:
    char agencija[100];
    Automobile * avtomobili;
    int n;
public:
    RentACar(char * agencija = "", Automobile * avtomobili = 0, int n = 0)
    {
        strcpy(this->agencija, agencija);
        this->n = n;
        this->avtomobili = new Automobile[n];
        for(int i=0; i<n; i++)
        {
            this->avtomobili[i] = avtomobili[i];
        }
    }
    RentACar(const RentACar &r)
    {
        strcpy(agencija, r.agencija);
        this->n = r.n;
        this->avtomobili = new Automobile[r.n];
        for(int i=0; i<n; i++)
        {
            this->avtomobili[i] = r.avtomobili[i];
        }
    }
    RentACar& operator=(const RentACar &r)
    {
        if(this!=&r)
        {
            strcpy(agencija, r.agencija);
            this->n = r.n;
            delete [] avtomobili;
            this->avtomobili = new Automobile[r.n];
            for(int i=0; i<n; i++)
            {
                this->avtomobili[i] = r.avtomobili[i];
            }
        }
        return * this;
    }
    ~RentACar()
    {
        delete [] avtomobili;
    }

    RentACar& operator +=(const Automobile &a)
    {
        Automobile * temp = new Automobile[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i] = avtomobili[i];
        }
        temp[n++] = a;
        delete [] avtomobili;
        avtomobili = temp;
        return *this;
    }

    RentACar& operator -=(const Automobile &a)
    {
        int newN = 0;
        for(int i=0; i<n; i++)
        {
            if(!(avtomobili[i] == a))
            {
                newN++;
            }
        }
        if(newN)
        {
            Automobile * temp = new Automobile[newN];
            for(int i=0, j=0; i<n; i++)
            {
                if(!(avtomobili[i] == a))
                {
                    temp[j++] = avtomobili[i];
                }
            }
            delete [] avtomobili;
            n = newN;
            avtomobili = temp;
        }
        return *this;
    }

    void pecatiNadBrzina(int max)
    {
        cout<<agencija<<endl;
        for(int i=0; i<n; i++)
        {
            if(avtomobili[i].getTopSpeed() > max)
            {
                cout<<avtomobili[i];
            }
        }
    }
};


int main()
{
   RentACar agencija("FINKI-Car");
   int n;
   cin>>n;

   for (int i=0;i<n;i++)
   {
    	char marka[100];
    	int regisracija[5];
    	int maximumBrzina;

       	cin>>marka;

       	for (int i=0;i<5;i++)
        {
            cin>>regisracija[i];
        }


    	cin>>maximumBrzina;

       	Automobile nov=Automobile(marka,regisracija,maximumBrzina);

       	cout<<nov;

    	//dodavanje na avtomobil
       	agencija+=nov;

//        cout<<"error";
   }


    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
    cin>>regisracija[i];
    cin>>maximumBrzina;

    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);



    //brishenje na avtomobil
    agencija-=greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}
