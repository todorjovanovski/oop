#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Laptop{
char firma[100];
float golemina;
int touch;
int cena;
}laptop;

typedef struct ITStore{
char ime[100];
char lokacija[100];
laptop laptopi[100];
int n;
}ITStore;

void print(ITStore * prodavnici, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %s\n", prodavnici[i].ime, prodavnici[i].lokacija);
        for(int j=0; j<prodavnici[i].n; j++)
        {
            int gol = (int)prodavnici[i].laptopi[j].golemina;
            if(prodavnici[i].laptopi[j].golemina > gol)
            {
                printf("%s %.1f %d\n", prodavnici[i].laptopi[j].firma, prodavnici[i].laptopi[j].golemina, prodavnici[i].laptopi[j].cena);
            }
            else{
                printf("%s %.f %d\n", prodavnici[i].laptopi[j].firma, prodavnici[i].laptopi[j].golemina, prodavnici[i].laptopi[j].cena);
            }

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
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d", prodavnici[minI].ime, prodavnici[minI].lokacija, najeftina);
}


int main() {
    ITStore s[100];
    int n;
    scanf("%d",&n); //broj na IT prodavnici

    char ime[100], lokacija[100];
    char firma[100];
    float golemina;
    int cena;
    int touch;
    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    int i, j;
    for(i=0; i<n; i++)
    {
        scanf("%s", s[i].ime);
        scanf("%s", s[i].lokacija);
        scanf("%d", &s[i].n);
        for(j=0; j<s[i].n; j++)
        {
            scanf("%s", s[i].laptopi[j].firma);
            scanf("%f", &s[i].laptopi[j].golemina);
            scanf("%d", &s[i].laptopi[j].touch);
            scanf("%d", &s[i].laptopi[j].cena);
        }
    }

    //pecatenje na site prodavnici
    print(s, n);




    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}
