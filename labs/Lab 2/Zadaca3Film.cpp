#include <iostream>
#include <cstring>
using namespace std;

class Film{
private:
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;
public:
    Film(){}
    Film(char * _ime, char * _reziser, char * _zanr, int _godina)
    {
        strcpy(ime, _ime);
        strcpy(reziser, _reziser);
        strcpy(zanr, _zanr);
        godina = _godina;
    }
    int getGodina()
    {
        return godina;
    }
    void print()
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Reziser: "<<reziser<<endl;
        cout<<"Zanr: "<<zanr<<endl;
        cout<<"Godina: "<<godina<<endl;
    }
};

void pecati_po_godina(Film * f, int n, int godina)
{
    for(int i=0; i<n; i++)
    {
        if(f[i].getGodina() == godina)
        {
            f[i].print();
        }
    }
}

int main() {
 	int n;
 	cin >> n;
 	Film filmovi[100];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		filmovi[i] = Film(ime, reziser, zanr, godina);
 		//da se kreira soodveten objekt
 	}
 	int godina;
 	cin >> godina;
 	pecati_po_godina(filmovi, n, godina);
 	//da se povika funkcijata pecati_po_godina
 	return 0;
 }
