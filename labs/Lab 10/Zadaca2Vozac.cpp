#include <iostream>
#include <cstring>

using namespace std;


class Vozac{
protected:
    char name[101];
    int age, races;
    bool veteran;
public:
    Vozac(char * name, int age, int races, bool veteran)
    {
        strcpy(this->name, name);
        this->age = age;
        this->races = races;
        this->veteran = veteran;
    }

    virtual double income() = 0;
    virtual double tax() = 0;

    friend bool operator==(Vozac &v1, Vozac &v2);
    friend ostream& operator<<(ostream& os, Vozac& v);
};

bool operator==(Vozac &v1, Vozac &v2)
{
    if(v1.income() == v2.income())
        return true;
    else
        return false;
}

ostream& operator<<(ostream& os, Vozac& v)
{
    os<<v.name<<endl;
    os<<v.age<<endl;
    os<<v.races<<endl;
    if(v.veteran == true)
    {
        os<< "VETERAN" <<endl;
    }
    return os;
}


class Avtomobilist: public Vozac{
private:
    double price;
public:
    Avtomobilist(char * name, int age, int races, bool veteran,
    double price) : Vozac(name, age, races, veteran)
    {
        this->price = price;
    }

    double income()
    {
        return (double)price/5;
    }
    double tax()
    {
        if(races > 10)
        {
            return income()*0.15;
        }
        else
        {
            return income()*0.1;
        }
    }
};


class Motociklist: public Vozac{
private:
    int power;
public:
    Motociklist(char * name, int age, int races, bool veteran,
    int power) : Vozac(name, age, races, veteran)
    {
        this->power = power;
    }

    double income()
    {
        return (double)power * 20;
    }
    double tax()
    {
        if(veteran)
        {
            return income()*0.25;
        }
        else
        {
            return income()*0.2;
        }
    }
};

int soIstaZarabotuvachka(Vozac ** drivers, int n, Vozac * v1)
{
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        if(*drivers[i] == *v1)
        {
            counter++;
        }
    }
    return counter;
}

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->tax() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
