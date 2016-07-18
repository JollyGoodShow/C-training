#include <stdio.h>
#include <stdlib.h>

//Add two matrices together, Mario D'Andrea 2016

void matrixAdd(int, int);

int main(void) {
    int userRows = 0;
    int userColumns = 0;
    
    //get user input for the size
    printf("Please enter the number of rows: ");
    scanf("%d", &userRows);
    printf("Please enter the number of columns: ");
    scanf("%d", &userColumns);
    
    //Adds and prints result
    matrixAdd(userRows, userColumns);
    
    return 0;
}


void matrixAdd(int userRows, int userColumns) {
	
    int i, j;
    int** matrixPtrA = NULL; //pointers to pointers of ints
    int** matrixPtrB = NULL;
    int** matrixPtrC = NULL;
    
    matrixPtrA = (int**)malloc(userRows * sizeof(int *)); //allocate memory for pointers
    matrixPtrB = (int**)malloc(userRows * sizeof(int *));
    matrixPtrC = (int**)malloc(userRows * sizeof(int *));
    
    for (i=0; i<userRows; i++) {
		matrixPtrA[i] = (int*)malloc(userColumns * sizeof(int)); //allocate memory for arrays
		matrixPtrB[i] = (int*)malloc(userColumns * sizeof(int));
		matrixPtrC[i] = (int*)malloc(userColumns * sizeof(int));
    }
    
    printf("Enter Matrix A\n"); //populate matrix A
    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            scanf("%d", &matrixPtrA[i][j]);
        }
    }
    printf("Enter Matrix B\n"); //populate matrix B
    for (i=0; i<userRows; i++) {
        for (j=0; j<userColumns; j++) {
            scanf("%d", &matrixPtrB[i][j]);
        }
    }
    
    for (i=0; i<userRows; i++) { //Perform addition
        for (j=0; j<userColumns; j++) {
            matrixPtrC[i][j] = matrixPtrA[i][j] + matrixPtrB[i][j];
        }
    }
    
    printf("A + B =\n");
    
    for (i=0; i<userRows; i++) { //Print the C matrix
        for (j=0; j<userColumns; j++) {
            printf("%d ", matrixPtrC[i][j]);
        }
        printf("\n");
    }
    //Set them free!
    free(matrixPtrA); free(matrixPtrB); free(matrixPtrC);
    return;
}


