#include<iostream>
#include <cstring>
using namespace std;

struct Voz{
char relacija[50];
float kilometri;
int patnici;
};

struct ZeleznickaStanica{
char grad[20];
Voz vozovi[30];
int broj;
};

void najkratkaRelacija(ZeleznickaStanica * zs, int n, char * gr)
{
    int min_km = 10000;
    int min_j = 0, min_i = 0;
    for(int i=0; i<n; i++)
    {
       if(strcmp(zs[i].grad, gr) == 0)
        {
            for(int j=0; j<zs[i].broj; j++)
            {
                if(zs[i].vozovi[j].kilometri <= min_km)
                {
                    min_km = zs[i].vozovi[j].kilometri;
                    min_j = j;
                    min_i = i;
                }
            }
        }
    }
    cout<<"Najkratka relacija: "<<zs[min_i].vozovi[min_j].relacija<<" ("<<min_km<<" km)"<<endl;
//zs[min_i].vozovi[min_j].kilometri
}

int main(){

    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        cin>>zStanica[i].grad>>zStanica[i].broj;
        for(int j=0; j<zStanica[i].broj; j++)
        {
            cin>>zStanica[i].vozovi[j].relacija;
            cin>>zStanica[i].vozovi[j].kilometri;
            cin>>zStanica[i].vozovi[j].patnici;
        }
    }

    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
