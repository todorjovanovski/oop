#include <iostream>
#include <cstring>

using namespace std;


class Ekipa{
protected:
    char ime[15];
    int pobedi, porazi;
public:
    Ekipa(char * ime = "", int pobedi = 0, int porazi = 0)
    {
        strcpy(this->ime, ime);
        this->pobedi = pobedi;
        this->porazi = porazi;
    }

    void pecati()
    {
        cout << "Ime: " << ime << " Pobedi: " << pobedi << " Porazi: " << porazi;
    }
};


class FudbalskaEkipa: public Ekipa{
private:
    int zolti;
    int crveni;
    int nereseni;
public:
    FudbalskaEkipa(char * ime = "", int pobedi = 0, int porazi = 0,
    int zolti = 0, int crveni = 0, int nereseni = 0) : Ekipa(ime, pobedi, porazi)
    {
        this->zolti = zolti;
        this->crveni = crveni;
        this->nereseni = nereseni;
    }

    int getPoeni()
    {
        return pobedi*3 + nereseni;
    }
    void pecati()
    {
        Ekipa::pecati();
        cout<< " Nereseni: " << nereseni << " Poeni: " << getPoeni() << endl;
    }
};


int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}
