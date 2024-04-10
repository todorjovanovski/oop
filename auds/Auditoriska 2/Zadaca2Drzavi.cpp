#include <iostream>
using namespace std;

struct grad{
    char ime[100];
    int ziteli;
};

struct pretsedatel{
    char ime[100];
    char partija[100];
};

struct drzava{
    char ime[100];
    char brZiteli;
    grad glavenGrad;
    pretsedatel pres;
    void print()
    {
        cout<<ime<<" "<<brZiteli<<endl;
        cout<<pres.ime<<" - "<<pres.partija<<" "<<endl;
        cout<<glavenGrad.ime<<" "<<glavenGrad.ziteli<<endl;
    }
};

void read(drzava drzavi[], int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>drzavi[i].ime>>drzavi[i].brZiteli;
        cin>>drzavi[i].pres.ime>>drzavi[i].pres.partija;
        cin>>drzavi[i].glavenGrad.ime>>drzavi[i].glavenGrad.ziteli;

    }
}

void maxziteli(drzava drzavi[], int n)
{
    drzava max = drzavi[0];
    for(int i=0; i<n; i++)
    {
        if(drzavi[i].glavenGrad.ziteli > max.glavenGrad.ziteli)
        {
            max = drzavi[i];
        }
    }
    cout<<"Ime na pretsedatel na drzava so glaven grad so najmnogu ziteli: "<<max.pres.ime;
}

int main()
{
    drzava drzavi[100];
    int n;
    cin>>n;

    read(drzavi, n);

    for(int i=0; i<n; i++)
    {
        drzavi[i].print();
    }

    maxziteli(drzavi, n);

    return 0;
}
