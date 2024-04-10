#include <stdio.h>
#include <string.h>

typedef struct Vozenje{
char ime[100];
int traenje;
float cena;
int daliPopust;
}Vozenje;

typedef struct ZabavenPark{
char ime[100], lokacija[100];
Vozenje niza[100];
int n;
}ZabavenPark;

void pecati(ZabavenPark * niza, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %s\n", niza[i].ime, niza[i].lokacija);
        for(int j=0; j<niza[i].n; j++)
        {
            printf("%s %d %.2f\n", niza[i].niza[j].ime, niza[i].niza[j].traenje, niza[i].niza[j].cena);
        }
    }
}

void najdobar_park(ZabavenPark * niza, int n)
{
    int najeftin = 0;
    int max_i = 0;
    int max_vreme = 0;

    for(int i=0; i<n; i++)
    {
        int vreme = 0;
        int brojac = 0;
        for(int j=0; j<niza[i].n; j++)
        {
            if(niza[i].niza[j].daliPopust == 1)
            {
                brojac++;
            }
            vreme += niza[i].niza[j].traenje;
        }
        if(brojac > najeftin)
        {
            najeftin = brojac;
            max_i = i;
            max_vreme = vreme;
        }
        else if(brojac == najeftin && vreme > max_vreme)
        {
            max_i = i;
            max_vreme = vreme;
        }
    }
    printf("Najdobar park: %s %s", niza[max_i].ime, niza[max_i].lokacija);

}

int main()
{
	int i, j, n, broj;
	//kreiraj niza od maksimum 100 zabavni parkovi
	ZabavenPark ff[100];
	scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++){
		//ime na festivalot
		scanf("%s", ff[i].ime);
        //mesto
		scanf("%s", ff[i].lokacija);
		//broj na filmovi
		scanf("%d", &ff[i].n);

		for (j = 0; j < ff[i].n; j++){
			scanf("%s", ff[i].niza[j].ime);  			/* Ime na filmot */
			scanf("%d", &ff[i].niza[j].traenje); 		/* Vremetraenje   */
			scanf("%f", &ff[i].niza[j].cena); 	/* Cena */
            scanf("%d", &ff[i].niza[j].daliPopust);	/* daliPopust */

		}


			}
    pecati(ff,n);
    najdobar_park(ff,n);

	return 0;
}
