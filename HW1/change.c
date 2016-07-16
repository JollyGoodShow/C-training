#include<stdio.h>
/*
   Using 100, 50, 20, 10, 5, and 1 dollar bills, gives change using the fewest number of bills.
*/

int main(void) {
   int userDollars = 1234;
   int numHundreds = 0;
   int numFifties = 0;
   int numTwenties = 0;
   int numTens = 0;
   int numFives = 0;
   int numOnes = 0;
   printf("Please enter the amount of money you wish to withdraw: ");
   scanf("%d", &userDollars);
   printf("\n");

   //now I need to see how many times 100 goes into userDollars
   numHundreds = userDollars / 100;
   //Now that I have the number of hundreds, how much to I have left to split up?
   userDollars = (userDollars % 100);

   numFifties = userDollars / 50;
   userDollars = (userDollars % 50);

   numTwenties = userDollars / 20;
   userDollars = (userDollars % 20);

   numTens = userDollars/10;
   userDollars = userDollars%10;

   numFives = userDollars/5;
   userDollars %= 5;

   numOnes = userDollars;
   userDollars -= numOnes;

   printf("You recieved %d hundred(s)\n", numHundreds);
   printf("You recieved %d fifty(s)\n", numFifties);
   printf("You recieved %d twenty(s)\n", numTwenties);
   printf("You recieved %d ten(s)\n", numTens);
   printf("You recieved %d five(s)\n", numFives);
   printf("You recieved %d one(s)\n", numOnes);



  return 0;

}