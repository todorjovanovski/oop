#include <stdio.h>

typedef struct grad{
    char ime[50];
    long ziteli;
}grad;

typedef struct pretsedatel{
    char ime[50];
    char partija[50];
}pres;

typedef struct drzava{
    char ime[50];
    pres pretsedatel;
    long ziteli;
    grad glaven_grad;
}drzava;

int main()
{
    drzava drzavi[50];
    int n, max_i;
    long max;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        //drzava
        scanf("%s", drzavi[i].ime);
        scanf("%ld", &drzavi[i].ziteli);

        //grad
        scanf("%s", drzavi[i].glaven_grad.ime);
        scanf("%ld", &drzavi[i].glaven_grad.ziteli);

        //pretsedatel
        scanf("%s", drzavi[i].pretsedatel.ime);
        scanf("%s", drzavi[i].pretsedatel.partija);
    }
    max_i = 0;
    max = drzavi[0].glaven_grad.ziteli;

    for(int i=1; i<n; i++)
    {
        if(drzavi[i].glaven_grad.ziteli > max)
        {
            max = drzavi[i].glaven_grad.ziteli;
            max_i = i;
        }
    }
    printf("Ime na pretsedatel na drzava so najmnogu ziteli vo glavniot grad: %s", drzavi[max_i].pretsedatel.ime);

    return 0;
}
