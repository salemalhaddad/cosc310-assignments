#include <stdio.h>

void convertFahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius\n", fahrenheit, celsius);
}

int main() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    convertFahrenheitToCelsius(fahrenheit);
    return 0;
}
