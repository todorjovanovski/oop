#include <iostream>
#include <cstring>
using namespace std;

struct student{
    char ime[100];
    char prezime[100];
    int indeks;
    int bodovi;
    void print()
    {
        cout<<ime<<" "<<prezime<<"\n"<<indeks<<"\t"<<bodovi<<endl;
    }
};

void normalize(char *str)
{
    str[0] = toupper(str[0]);
    for(int i=1; i<strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void sort(student niza[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(niza[i].bodovi < niza[j].bodovi)
            {
                student temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
}

void read(student &s)
{
    cin>>s.ime>>s.prezime;
    normalize(s.ime);
    normalize(s.prezime);
    cin>>s.indeks;
    int z1, z2, z3, z4;
    cin>>z1>>z2>>z3>>z4;
    s.bodovi = z1 + z2 + z3 +z4;
}

int main()
{
    student studenti[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        read(studenti[i]);
    }
    sort(studenti, n);

    for(int i=0; i<n; i++)
    {
        studenti[i].print();
    }
    return 0;
}
