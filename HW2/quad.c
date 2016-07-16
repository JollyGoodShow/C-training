#include<stdio.h>
#include<math.h>

//Finds the real roots of a quadratic equation.

int main(void) {
    //Store user input of equation of form ax^2 + bx + c = 0
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double discriminant = 0.0;
    int numRealRoots = 0;
    double root1 = 0;
    double root2 = 0;

    //Get user input
    printf("Given a quadratic equation of the form ax^2 + bx + c = 0\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    //Calculate discriminant
    discriminant = b*b - 4.0 * a * c;
    //Determine number of roots using discriminant
    if (discriminant > 0.000001) {
        numRealRoots = 2;
    } else if (discriminant < -0.000001) {
        numRealRoots = 0;
    } else {
        numRealRoots = 1;
    }

    //Plug positive discriminant into formula to find real roots
    if (numRealRoots > 0) {
        root1 = ((-b) + sqrt(discriminant))/(2*a);
        root2 = ((-b) - sqrt(discriminant))/(2*a);
    }
    //Print back to user
    if (numRealRoots == 2) {
        printf("There are 2 real solutions\nsolution 1: %.2f\n solution 2: %.2f\n", root1, root2);
    } else if (numRealRoots == 1) {
        printf("There is one real solution: %.2f", root1);
    } else {
        printf("There are no real solutions");
    }

    return 0;
}