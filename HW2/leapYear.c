#include <stdio.h>

//Given a year number, determines whether or not the year is a leap year.

int main(void) {
    //We'll need to store the user's input
    int userYear = 0;

    //Ask user for input
    printf("Please enter a year: ");
    scanf("%d", &userYear);

    //Check if it is a leap-year
    if ((userYear % 400) == 0) {
        printf("%d is a leap year.\n", userYear);
    } else if ((userYear%4 == 0) && !(userYear%100 == 0) ) {
        printf("%d is a leap year.\n", userYear);
    } else {
        printf("%d is not a leap year.\n", userYear);
    }

    return 0;
}