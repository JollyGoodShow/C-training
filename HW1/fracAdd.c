#include<stdio.h>

//Program asks user for two fractions, and then adds them together.

int main(void) {
    //We'll need some variables
    int frac1Numerator = 0;
    int frac1Denom = 1;
    int frac2Numerator = 0;
    int frac2Denom = 1;
    int commonDenom = 1;
    int newNumerator = 0;

    //User input
    printf("Please enter the first fraction to be added: ");
    scanf("%d / %d", &frac1Numerator, &frac1Denom);

    printf("Please enter the second fraction to be added: ");
    scanf("%d / %d", &frac2Numerator, &frac2Denom);

    //Find common denominator
    commonDenom = frac1Denom * frac2Denom;

    //Add altered numerators
    newNumerator = (frac1Denom * frac2Numerator) + (frac2Denom * frac1Numerator);

    printf("%d/%d + %d/%d = %d/%d", frac1Numerator, frac1Denom, frac2Numerator, frac2Denom, newNumerator, commonDenom);

    return 0;
}