#include <stdio.h>

typedef struct vector{
    float x;
    float y;
    float z;
}vector;

float skalaren_proizvod(vector v1, vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vector vektorski_prozivod(vector v1, vector v2)
{
    vector rezultat;
    rezultat.x = v1.y * v2.z - v1.z * v2.y;
    rezultat.y = v1.x * v2.z - v1.z * v2.x;
    rezultat.z = v1.x * v2.y - v1.y * v2.x;
    return rezultat;
}

int main()
{
    vector v1 = {1.4, 5.5, 8.2};
    vector v2 = {2.5, 1.3, 3.2};

    vector rez = vektorski_prozivod(v1, v2);

    printf("Skalaren: %.2f\n", skalaren_proizvod(v1, v2));
    printf("Vektorski: [%.2f, %.2f, %.2f]", rez.x, rez.y, rez.z);

    return 0;
}
