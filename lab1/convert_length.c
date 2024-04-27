#include <stdio.h>

void convertMeterToKilometer(double meter) {
    double kilometer = meter / 1000.0;
    printf("%.2lf meters is equal to %.2lf kilometers\n", meter, kilometer);
}

int main() {
    double meter;
    printf("Enter length in meters: ");
    scanf("%lf", &meter);
    convertMeterToKilometer(meter);
    return 0;
}
