#include <stdio.h>

//Add two matrices together, Mario D'Andrea 2016

void matrixAdd(int, int);

int main(void) {
    int userRows = 0;
    int userColumns = 0;

    printf("Please enter the number of rows: ");
    scanf("%d", &userRows);
    printf("Please enter the numnber of columns: ");
    scanf("%d", &userColumns);

    matrixAdd(userRows, userColumns);

    return 0;
}


void matrixAdd(int userRows, int userColumns) {
    int i = 0; int j = 0;

    int matrixA[userRows][userColumns];
    int matrixB[userRows][userColumns];
    int matrixC[userRows][userColumns];

    printf("Enter matrix A\n");
    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("Enter matrix B\n");
    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("A + B =\n");
    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    return;
}

