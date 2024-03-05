#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ } month_t;

typedef enum { SUN = 0, MON, TUE, WED, THU, FRI, SAT } weekday_t;

typedef struct {
    int day;
    int month;
    int year;
} date_t;

int is_leap_year(const date_t date) {
    return date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0);
}

int is_gregorian_date(const date_t date) {
    if (date.year == 1582) {
        return date.month >= 10 && date.day >= 15;
    }
    return date.year > 1582 && date.year <= 9999;
}

int get_month_length(const date_t date) {
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

int is_valid_date(const date_t date) {
    return is_gregorian_date(date) && get_month_length(date) > 0 && date.day >= 1 && date.day <= get_month_length(date);
}

weekday_t calculate_weekday(const date_t date) {
    assert(is_valid_date(date));
    const int m = 1 + (date.month + 9) % 12;
    const int a = date.month < MAR ? date.year - 1 : date.year;
    const int y = a % 100;
    const int c = a / 100;

    return ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
}

void print_weekday(const weekday_t day) {
    const char *weekdays[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    if (day <= SAT) {
        printf(weekdays[day]);
    } else {
        assert(!" day is out-of-range");
    }
}

int main(int argc, char *argv[]) {
    date_t date;
    printf("Enter date (yyyy-mm-dd): \n");

    if (scanf("%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        fprintf(stderr, "Invalid format.\n"
                "The selected date (yyyy-mm-dd) has to be Gregorian (after 15. October 1582 (inclusive)).");
        return EXIT_FAILURE;
    }

    if (is_valid_date(date)) {
        printf("%d-%d-%d is a ", date.year, date.month, date.day);
        print_weekday(calculate_weekday(date));
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Invalid date.\n"
                "The selected date (yyyy-mm-dd) has to be Gregorian (after 15. October 1582 (inclusive)).");
        return EXIT_FAILURE;
    }
}
