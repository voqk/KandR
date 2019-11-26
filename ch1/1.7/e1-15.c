#include <stdio.h>

float toCelsius(float fahr);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ... 300; floating-point version */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
        fahr = fahr + step;
    }
}

float toCelsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}