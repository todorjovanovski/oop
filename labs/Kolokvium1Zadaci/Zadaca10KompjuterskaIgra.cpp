#include <iostream>
#include <cstring>

using namespace std;

struct Igrac{
char ime[15];
int nivo, poeni;
};

struct KompjuterskaIgra{
char igra[20];
Igrac igraci[30];
int n;
};

void NajdobarIgrac(KompjuterskaIgra *lista, int n)
{
    int maxPopularnost = 0, maxPoeni = 0, maxLvl = 0, maxI = 0, maxJ = 0;
    for(int i=0; i<n; i++)
    {
        if(lista[i].n > maxPopularnost)
        {
            for(int j=0; j<lista[i].n; j++)
            {
                if(lista[i].igraci[j].poeni > maxPoeni)
                {
                    maxPoeni = lista[i].igraci[j].poeni;
                    maxI = i;
                    maxJ = j;
                    maxLvl = lista[i].igraci[j].nivo;
                }
                else if(maxPoeni == lista[i].igraci[j].poeni && maxLvl < lista[i].igraci[j].nivo)
                {
                    maxLvl = lista[i].igraci[j].nivo;
                    maxI = i;
                    maxJ = j;
                }
            }
            maxPopularnost = lista[i].n;
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<lista[maxI].igraci[maxJ].ime<<" koj ja igra igrata "<<lista[maxI].igra<<endl;
}

int main()
{
    int n;
    cin>>n;

    KompjuterskaIgra igri[n];

    for(int i=0; i<n; i++)
    {
        cin>>igri[i].igra>>igri[i].n;
        for(int j=0; j<igri[i].n; j++)
        {
            cin>>igri[i].igraci[j].ime>>igri[i].igraci[j].nivo>>igri[i].igraci[j].poeni;
        }
    }
    NajdobarIgrac(igri, n);

    return 0;
}
