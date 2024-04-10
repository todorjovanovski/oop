#include <stdio.h>

typedef struct proizvodi{
    char ime[50];
    float cena;
    float kolicina;
}proizvodi;

int main()
{
    int n;
    float total;
    scanf("%d", &n);

    proizvodi p[100];

    for(int i=0; i<n; i++)
    {
        scanf("%s", p[i].ime);
        scanf("%f", &p[i].cena);
        scanf("%f", &p[i].kolicina);

        total += p[i].cena * p[i].kolicina;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d. %s\t%.2f x %.1f = %.2f\n", i+1, p[i].ime, p[i].cena, p[i].kolicina, p[i].cena * p[i].kolicina);
    }
    printf("Total: %.2f", total);

    return 0;
}
