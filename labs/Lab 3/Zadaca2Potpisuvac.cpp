#include <iostream>
#include <cstring>
using namespace std;

class Potpisuvac{
private:
    char ime[20];
    char prezime[20];
    char embg[14];
public:
    Potpisuvac(){}
    Potpisuvac(char * ime, char * prezime, char * embg)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        strcpy(this->embg, embg);
    }
    Potpisuvac(const Potpisuvac &p)
    {
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
        strcpy(embg, p.embg);
    }

    char * getEmbg()
    {
        return embg;
    }
};

class Dogovor{
private:
    int broj;
    char kategorija[50];
    Potpisuvac potpisuvaci[3];
public:
    Dogovor(){}
    Dogovor(int broj, char * kategorija, Potpisuvac potpisuvaci[])
    {
        this->broj = broj;
        strcpy(this->kategorija, kategorija);
        for(int i=0; i<3; i++)
        {
            this->potpisuvaci[i] = potpisuvaci[i];
        }
    }

    bool proverka()
    {
        for(int i=0; i<2; i++)
        {
            for(int j=i+1; j<3; j++)
            {
                if(strcmp(potpisuvaci[i].getEmbg(), potpisuvaci[j].getEmbg()) == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
