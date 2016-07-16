#include<stdio.h>

/*
   Give the positions and velocities of two trains, program calculates
   the time till collision, and the location of collision.
   Mario d'Andrea, 4/8/2016.
*/

int main(void) {
    //we'll need the trains' positions and velocities.
    double train1Position = 0;
    double train1Speed = 0;
    double train2Position = 0;
    double train2Speed = 0;
    //We'll also use time and position variables for our output.
    double collisionTime = 0;
    double collisionPosition = 0;

    //Ask user to input initial values
    printf("Please enter the starting position of train 1: ");
    scanf("%lf", &train1Position);

    printf("\nPlease enter the speed of train 1: ");
    scanf("%lf", &train1Speed);

    printf("\nPlease enter the starting position of train 2: ");
    scanf("%lf", &train2Position);

    printf("\nPlease enter the speed of train 2: ");
    scanf("%lf", &train2Speed);

    /*Calculate the time till collision. They start at t = 0, and are seperated
    an initial distance (train1Position - train2Position), moving towards each
    other with speed (train1Speed + train2Speed). time = distance/speed*/

    collisionTime = (train2Position - train1Position) / (train1Speed + train2Speed);
    collisionPosition = ( (train1Speed)/(train1Speed + train2Speed) ) * (train2Position - train1Position) + train1Position;
    printf("The two trains will collide in %.2lf hours, %.2lf miles down the track", collisionTime, collisionPosition);

    return 0;
}