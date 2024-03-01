#include <stdio.h>
#include <stdlib.h>

enum month_t { JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

struct date_t {
    int day;
    int month;
    int year;
};

int is_leap_year(const struct date_t date) {
    return date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0);
}

int is_gregorian_date(const struct date_t date) {
    if (date.year == 1582) {
        return date.month >= 10 && date.day >= 15;
    }
    return date.year > 1582 && date.year <= 9999;
}

int get_month_length(const struct date_t date) {
    switch (date.month) {
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

int is_valid_date(const struct date_t date) {
    return is_gregorian_date(date) && get_month_length(date) > 0 && date.day >= 1 && date.day <= get_month_length(date);
}

int main(int argc, char *argv[]) {
    struct date_t date;
    printf("Bitte Datum eingeben (yyyy-mm-dd): \n");

    if (scanf("%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        fprintf(stderr, "Falsches Format.\n"
                "Das gewaehlte Datum muss Gregorianisch sein, d.h. ab 15. Oktober 1582 (inklusive)"
                "und das Format (yyyy-mm-dd) haben.");
        return EXIT_FAILURE;
    }

    if (is_valid_date(date)) {
        printf("Datum ist valid.");
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Invalides Datum.\n"
                "Das gewaehlte Datum muss Gregorianisch sein, d.h. ab 15. Oktober 1582 (inklusive).");
        return EXIT_FAILURE;
    }
}
