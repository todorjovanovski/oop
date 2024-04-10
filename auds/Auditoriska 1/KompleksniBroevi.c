#include <stdio.h>
#include <math.h>

typedef struct kompleksen{
    float r;
    float i;
}kompleksen;

kompleksen sum(kompleksen k1, kompleksen k2)
{
    kompleksen rez;
    rez.r = k1.r + k2.r;
    rez.i = k1.i + k2.i;
    return rez;
}

kompleksen div(kompleksen k1, kompleksen k2)
{
    kompleksen rez;
    rez.r = k1.r - k2.r;
    rez.i = k1.i - k2.i;
    return rez;
}

kompleksen multiply(kompleksen k1, kompleksen k2)
{
    kompleksen rez;
    rez.r = k1.r * k2.r - k1.i * k2.i;
    rez.i = k1.r * k2.i + k1.i * k2.r;
    return rez;
}

void print(kompleksen broj)
{
    printf("%.2f", broj.r);
    if(broj.i >= 0)
    {
        printf("+j%.2f", broj.i);
    }
    else{
        printf("-j%.2f", fabs(broj.i));
    }
    printf("\n");
}

int main()
{
    kompleksen k1, k2;
    scanf("%f %f", &k1.r, &k1.i);
    scanf("%f %f", &k2.r, &k2.i);

    printf("Sobiranje: ");
    print(sum(k1, k2));

    printf("Odzemanje: ");
    print(div(k1, k2));

    printf("Mnozenje: ");
    print(multiply(k1, k2));

    return 0;
}
