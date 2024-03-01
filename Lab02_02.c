#include <stdio.h>
#include <stdlib.h>

enum month_t { JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

struct date_t
{
    int day;
    int month;
    int year;
};

int is_leap_year(const struct date_t date)
{
    return date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0);
}

int is_gregorian_date(const struct date_t date)
{
    if (date.year == 1582)
    {
        return date.month >= 10 && date.day >= 15;
    }
    return date.year > 1582 && date.year <= 9999;
}

int get_month_length(const struct date_t date)
{
    switch (date.month)
    {
    case JAN:
        return 31;
    case FEB:
        return is_leap_year(date) ? 29 : 28;
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
        return 0;
    }
}

int is_valid_date(const struct date_t date)
{
    return is_gregorian_date(date) && get_month_length(date) > 0 && date.day >= 1 && date.day <= get_month_length(date);
}

int main(int argc, char* argv[])
{
    struct date_t date;
    printf("Please enter a date in YYYY-MM-DD format: \n");

    if (scanf("%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return EXIT_FAILURE;
    }

    printf("Parsed date: %d-%02d-%02d\n", date.year, date.month, date.day);
    {
        char* valid = is_valid_date(date) ? "Ja" : "Nein";
        printf("Datum ist gültig: %s", valid);
        return EXIT_SUCCESS;
    }
}
