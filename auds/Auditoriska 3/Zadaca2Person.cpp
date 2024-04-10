#include <iostream>
#include <cstring>
using namespace std;

enum position{
    vraboten, shef, direktor
};

class Person{
private:
    char ime[50];
    int plata;
    position pos;
public:
    Person(){}
    /*Person(char * name, int salary, position p){
        strcpy(name, ime);
        plata = salary;
        pos = p;
    }*/
    ~Person(){}

    void setIme(char * name)
    {
        strcpy(ime, name);
    }
    void setPlata(int salary)
    {
        plata = salary;
    }
    void setPozicija(position p)
    {
        pos = p;
    }

    char * getIme()
    {
        return ime;
    }
    int getPlata()
    {
        return plata;
    }
    position getPozicija()
    {
        return pos;
    }
};

void sort(Person niza[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(niza[i].getPlata() < niza[j].getPlata())
            {
                Person temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
}

int main()
{
    Person vraboteni[100];
    char ime[100];
    int plata, pozicija;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>ime>>plata>>pozicija;
        vraboteni[i].setIme(ime);
        vraboteni[i].setPlata(plata);
        vraboteni[i].setPozicija((position) pozicija);
    }
    sort(vraboteni, n);

    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". "<<vraboteni[i].getIme()<<" "<<vraboteni[i].getPlata()<<" "<<vraboteni[i].getPozicija()<<endl;
    }

    return 0;
}
