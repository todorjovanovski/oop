#include <stdio.h>

typedef struct date
{
    int godina;
    int mesec;
    int den;
}date;

int sporedi(date d1, date d2)
{
    if(d1.godina > d2.godina)
    {
        return 1;
    }
    else if(d1.godina < d2.godina)
    {
        return -1;
    }
    else{
        if (d1.mesec > d2.mesec)
        {
            return 1;
        }
        else if(d1.mesec < d2.mesec)
        {
            return -1;
        }
        else{
            if(d1.den > d2.den)
            {
                return 1;
            }
            else if(d1.den < d2.den)
            {
                return -1;
            }
            else return 0;
        }
    }
}

int razlika(date d1, date d2)
{
    int diff = d1.den - d2.den;
    diff += (d1.mesec - d2.mesec) * 30;
    diff += (d1.godina - d2.godina) * 365;

    return diff;
}

int main()
{
    date d1, d2;

    scanf("%d.%d.%d", &d1.den, &d1.mesec, &d1.godina);
    scanf("%d.%d.%d", &d2.den, &d2.mesec, &d2.godina);

    if(sporedi(d1, d2) == 1)
    {
        int diff = razlika(d1, d2);
        printf("Razlika vo denovi: %d", diff);
    }
    else if(sporedi(d1, d2) == -1)
    {
        int diff = razlika(d2, d1);
        printf("Razlika vo denovi: %d", diff);
    }
    else{
        printf("Datumite se ednakvi.");
    }

    return 0;
}
