#include <iostream>
#include <cstring>

using namespace std;

struct Laptop{
char firma[100];
float golemina;
int touch;
int cena;
};

struct ITStore{
char ime[100];
char lokacija[100];
Laptop laptopi[100];
int n;
};

void print(ITStore * prodavnici, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<prodavnici[i].ime<<" "<<prodavnici[i].lokacija<<endl;
        for(int j=0; j<prodavnici[i].n; j++)
        {
            cout<<prodavnici[i].laptopi[j].firma<<" "<<prodavnici[i].laptopi[j].golemina<<" "<<prodavnici[i].laptopi[j].cena<<endl;
        }
    }
}

void najeftina_ponuda(ITStore * prodavnici, int n)
{
    int najeftina = 99999;
    int minI = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<prodavnici[i].n; j++)
        {
            if(prodavnici[i].laptopi[j].cena < najeftina && prodavnici[i].laptopi[j].touch == 1)
            {
                najeftina = prodavnici[i].laptopi[j].cena;
                minI = i;
            }
        }
    }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl;
    cout<<prodavnici[minI].ime<<" "<<prodavnici[minI].lokacija<<endl;
    cout<<"Najniskata cena iznesuva: "<<najeftina<<endl;
}


int main() {
    ITStore s[100];
    int n;
    cin>> n; //broj na IT prodavnici

//    char ime[100], lokacija[100];
//    char firma[100];
//    float golemina;
//    int cena;
//    int touch;
    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    int i, j;
    for(i=0; i<n; i++)
    {
        cin>>s[i].ime>>s[i].lokacija>>s[i].n;
        for(j=0; j<s[i].n; j++)
        {
            cin>>s[i].laptopi[j].firma;
            cin>>s[i].laptopi[j].golemina;
            cin>>s[i].laptopi[j].touch;
            cin>>s[i].laptopi[j].cena;
        }
    }

    //pecatenje na site prodavnici
    print(s, n);


    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}
