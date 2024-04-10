#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela

typedef struct RabotnaNedela{
int casovi[DENOVI];
int br_nedela;
}RN;

// ovde strukturata Rabotnik

typedef struct Rabotnik{
char ime[100];
RN nedeli[NEDELI];
}R;

// ovde funkciite
int maxNedela(R rabotnik)
{
    int maxC = 0;
    int maxI = 0;
    int max_nedela = 0;
    for(int i=0; i<NEDELI; i++)
    {
        for(int j=0; j<DENOVI; j++)
        if(rabotnik.nedeli[i].casovi[j] > maxC)
        {
            maxC = rabotnik.nedeli[i].casovi[j];
            maxI = i;
            max_nedela = rabotnik.nedeli[i].br_nedela;
        }
    }
    return max_nedela;
}

void table(R *rabotnik, int n)
{
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(int i=0; i<n; i++)
    {
        printf("%s\t", rabotnik[i].ime);
        for(int j=0; j<NEDELI; j++)
        {
            printf("%d\t", rabotnik[i].nedeli[j].casovi);
        }
        printf("\n");
    }
}



int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(rabotnici[n / 2]));
    return 0;
}
