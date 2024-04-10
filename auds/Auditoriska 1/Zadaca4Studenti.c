#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
    char ime[50];
    char prezime[50];
    int indeks;
    int poeni;
}student;

void pocetna_bukva(char * str)
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
            if(niza[i].poeni < niza[j].poeni)
            {
                student temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
}

int main()
{
    student niza[100];
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", niza[i].ime);
        scanf("%s", niza[i].prezime);
        scanf("%d", &niza[i].indeks);
        int zadaca;
        niza[i].poeni = 0;
        for(int j=0; j<4; j++)
        {
            scanf("%d", &zadaca);
            niza[i].poeni += zadaca;
        }

        pocetna_bukva(niza[i].ime);
        pocetna_bukva(niza[i].prezime);
    }
    sort(niza, n);

    for(int i=0; i<n; i++)
    {
        printf("%d. %s %s %d: %d\n", i+1, niza[i].ime, niza[i].prezime, niza[i].indeks, niza[i].poeni);
    }

    return 0;
}
