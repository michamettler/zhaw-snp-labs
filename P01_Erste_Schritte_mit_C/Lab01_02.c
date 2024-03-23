#include <stdio.h>
#define NUM_ROWS 8
#include <stdlib.h>

int main() {
    double conversionRate;
    printf("Enter conversion rate (1.00 BTC -> CHF): ");
    scanf("%lf", &conversionRate);

    printf("\n");
    for (int i = 1; i <= NUM_ROWS; i++) {
        int chf = i * 200;
        double btc = chf / conversionRate;
        printf("%5d CHF\t<-->\t%0.5f BTC\n", chf, btc);
    }

    return EXIT_SUCCESS;
}