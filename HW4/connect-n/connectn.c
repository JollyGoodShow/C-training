#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void setUpBoard(char***, int, int, int);
void freeBoard(char**);


int main(int argc, char* argv[]) {
	int userRows, userColumns, userConnectNum;
	char** board;
	
	if ((argc-1) == 3) { //Correct number of command line arguments
		sscanf(argv[1], "%d", &userRows);
		sscanf(argv[2], "%d", &userColumns); //store parameters
		sscanf(argv[3], "%d", &userConnectNum);
		
		setUpBoard(&board, userRows, userColumns, userConnectNum);
		playGame(board);
		freeBoard(board);
	}
	else if (argc<4) { //Incorrect number of command line arguments
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		void exit (int status);
	} else {
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		void exit (int status);
	}
	
	return 0;
}


void setUpBoard(char*** board, int BOARD_ROWS, int BOARD_COLUMNS, int CONNECT_NUM) {
	int i, j;
	/*
	    Create the board to be used to for the rest of the game. Mallocs
	    a 2D array, with an extra row to store the BOARD_ROWS, BOARD_COLUMNS,
	    and CONNECT_NUM for later use.
	*/
	*board = (char**)malloc( (BOARD_ROWS+1) * sizeof(char *));
	for (i=1; i<BOARD_ROWS+1; i++) {
		(*board)[i] = (char*)malloc(BOARD_COLUMNS * sizeof(char));
		for (j=0; j<BOARD_COLUMNS; j++) {
			(*board)[i][j] = '*';
		}
	}
	(*board)[0] = (char*)malloc(3*sizeof(char)); //Store the board size and win info in a hidden first row
	(*board)[0][0] = BOARD_ROWS;
	(*board)[0][1] = BOARD_COLUMNS;
	(*board)[0][2] = CONNECT_NUM;
	return;
}

void freeBoard(char** board) {
	//Free the memory used by board
	int i;
	int rows = board[0][0];
	for (i=0; i<=rows; i++) {
		free(board[i]);
	}
	free(*board);
	*board = NULL;
	return;
}
