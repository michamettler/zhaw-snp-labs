#include <stdio.h>
#include <stdlib.h>

enum month_t { JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

int gibIntWert(const char* mode, int const min, const int max)
{
    while (1)
    {
        printf("Enter %s (%d - %d):\n", mode, min, max);
        char inputBuffer[10];
        if (fgets(inputBuffer, 5, stdin) != NULL)
        {
            const int input = atoi(inputBuffer);
            if (input >= min && input <= max)
            {
                return input;
            }
            printf("Invalid range (%d - %d). Try again.\n", min, max);
        }
    }
}

int istSchaltjahr(int jahr)
{
    return jahr % 4 == 0 && (jahr % 100 != 0 || jahr % 400 == 0);
}

int tageProMonat(int jahr, int monat)
{
    switch (monat)
    {
    case JAN:
        return 31;
    case FEB:
        return istSchaltjahr(jahr) ? 29 : 28;
    case MAR:
        return 31;
    case APR:
        return 30;
    case MAI:
        return 31;
    case JUN:
        return 30;
    case JUL:
        return 31;
    case AUG:
        return 31;
    case SEP:
        return 30;
    case OKT:
        return 31;
    case NOV:
        return 30;
    case DEZ:
        return 31;
    default:
        (void)printf("Der Monat %d konnte nicht gefunden werden.", monat);
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int monat, jahr;

    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr = gibIntWert("Jahr", 1600, 9999);

    //  Ausgabe zum Test
    (void)printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    (void)printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    (void)printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));

    return 0;
}
