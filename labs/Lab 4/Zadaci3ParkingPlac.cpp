#include<iostream>
#include<cstring>

using namespace std;

// вашиот код
class Avtomobil{
private:
    char boja[20];
    char brend[20];
    char model[20];
public:
    Avtomobil(char * boja = "", char * brend = "", char * model = "")
    {
        strcpy(this->boja, boja);
        strcpy(this->brend, brend);
        strcpy(this->model, model);
    }
    Avtomobil(const Avtomobil &car)
    {
        strcpy(boja, car.boja);
        strcpy(brend, car.brend);
        strcpy(model, car.model);
    }
    Avtomobil& operator=(const Avtomobil &car)
    {
        if(this!=&car)
        {
            strcpy(boja, car.boja);
            strcpy(brend, car.brend);
            strcpy(model, car.model);
        }
        return *this;
    }
    ~Avtomobil(){}
    void print()
    {
        cout<<boja<<" "<<brend<<" "<<model<<endl;
    }

};

class ParkingPlac{
private:
    char adresa[20];
    char * id;
    int cena;
    int zarabotka;
    Avtomobil * avtomobili;
    int br_parkirani;
public:
    ParkingPlac(char * adresa = "", char * id = "", int cena = 0, int zarabotka = 0, Avtomobil * avtomobili = 0, int br_parkirani = 0)
    {
        strcpy(this->adresa, adresa);
        this->id = new char[strlen(id)+1];
        strcpy(this->id, id);
        this->cena = cena;
        this->zarabotka = zarabotka;
        this->br_parkirani = br_parkirani;
        this->avtomobili = new Avtomobil[br_parkirani];
        for(int i=0; i<br_parkirani; i++)
        {
            this->avtomobili[i] = avtomobili[i];
        }
    }
    ParkingPlac(const ParkingPlac &p)
    {
        strcpy(adresa, p.adresa);
        id = new char[strlen(p.id)+1];
        strcpy(id, p.id);
        cena = p.cena;
        zarabotka = p.zarabotka;
        br_parkirani = p.br_parkirani;
        avtomobili = new Avtomobil[p.br_parkirani];
        for(int i=0; i<br_parkirani; i++)
        {
            avtomobili[i] = p.avtomobili[i];
        }
    }
    ParkingPlac& operator=(const ParkingPlac &p)
    {
        if(this!=&p)
        {
            strcpy(adresa, p.adresa);
            delete [] id;
            id = new char[strlen(p.id)+1];
            strcpy(id, p.id);
            cena = p.cena;
            zarabotka = p.zarabotka;
            br_parkirani = p.br_parkirani;
            delete [] avtomobili;
            avtomobili = new Avtomobil[p.br_parkirani];
            for(int i=0; i<br_parkirani; i++)
            {
                avtomobili[i] = p.avtomobili[i];
            }
        }
        return *this;
    }
    ~ParkingPlac()
    {
        delete [] id;
        delete [] avtomobili;
    }

    char * getId()
    {
        return id;
    }
    int platiCasovi(int casovi)
    {
        zarabotka+=cena*casovi;
        return cena*casovi;
    }
    bool daliIstaAdresa(ParkingPlac p)
    {
        if(strcmp(adresa, p.adresa) == 0) return true;
        else return false;
    }
    void parkirajVozilo(Avtomobil novoVozilo)
    {
        Avtomobil * temp = new Avtomobil[br_parkirani + 1];
        for(int i=0; i<br_parkirani; i++)
        {
            temp[i] = avtomobili[i];
        }
        temp[br_parkirani++] = novoVozilo;
        delete [] avtomobili;
        avtomobili = temp;
    }
    void pecati()
    {
        if(zarabotka == 0)
        {
            cout<<id<<" "<<adresa<<endl;
        }
        else{
            cout<<id<<" "<<adresa<<" - "<<zarabotka<<" denari"<<endl;
        }
    }
    void pecatiParkiraniVozila()
    {
        cout<<"Vo parkingot se parkirani slednite vozila:"<<endl;
        for(int i=0; i<br_parkirani; i++)
        {
            cout<<i+1<<".";
            avtomobili[i].print();
        }
    }


};

int main(){

	ParkingPlac p[100];
	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa, 50);
			cin>>id>>cenacas;

			ParkingPlac edna(adresa,id,cenacas);

	        p[i]=edna;
		}

		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;

	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}
	return 0;
}
