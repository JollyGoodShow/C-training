#include <stdio.h>

//prints a user-specified number of levels of pascal's traingle
//Mario D'Andrea, 2016

void printTriangle(int);

int main(void) {
    int userRows = 0;             //Ask user for a # of rows to display

    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &userRows);

    printTriangle(userRows);      //Function does all the work

    return 0;
}


void printTriangle(int numRows) {

    int currentRow[numRows + 1];     //Prepare an array large enough to hold the bottom row
    int previousRow[numRows + 1];    //Store previous row to calculate next row
    int i = 0; int j = 0; int k = 0; //Iteration variables

    for (i=0; i<=numRows; i++) {     //Preset arrays to zero to avoid bugs
        currentRow[i] = 0;
        previousRow[i] = 0;
    }

    printf("1\n");                   //Assume user enters at least "1"
    previousRow[0] = 1;
    previousRow[1] = 1;

    if (numRows >= 2) {

        for(i=2; i<=numRows; i++) {  //Loops through the number of rows

            currentRow[0] = 1;       //Begins each row with a 1
            printf("1 ");

            for (j=1; j<(i-1); j++) {  //Loops for the non-1 elements
                //Construct current row from previous row
                currentRow[j] = previousRow[j-1] + previousRow[j];
                printf("%d ", currentRow[j]);
            }

            currentRow[i-1] = 1;     //Ends each row with a 1
            printf("1\n");

            for (k=0; k<=numRows; k++) {  //Make the current row the previous row
                previousRow[k] = currentRow[k];
            }
        }
    }
    return;
}