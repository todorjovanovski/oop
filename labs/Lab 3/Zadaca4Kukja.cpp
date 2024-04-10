#include <iostream>
#include <cstring>
using namespace std;

class Masa{
private:
    int dolzina;
    int sirina;
public:
    Masa(){}
    Masa(int sirina, int dolzina)
    {
        this->dolzina = dolzina;
        this->sirina = sirina;
    }

    void pecati()
    {
        cout<<" Masa: "<<sirina<<" "<<dolzina<<endl;
    }

};

class Soba{
private:
    Masa m;
    int dolzina, sirina;
public:
    Soba(){}
    Soba(int sirina, int dolzina, Masa m)
    {
        this->sirina = sirina;
        this->dolzina = dolzina;
        this->m = m;
    }

    void pecati()
    {
        cout<<" Soba: "<<sirina<<" "<<dolzina;
        m.pecati();
    }

};

class Kukja{
private:
    Soba s;
    char adresa[50];
public:
    Kukja(){}
    Kukja(Soba s, char * adresa)
    {
        this->s = s;
        strcpy(this->adresa, adresa);
    }
    ~Kukja(){}

    void pecati()
    {
        cout<<"Adresa: "<<adresa;
        s.pecati();
    }

};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}

    return 0;
}
