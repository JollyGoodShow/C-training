#include <stdio.h>

#include "game.h"
#include "move.h"
#include "win.h"

void printBoard(char** board) {
	//Print the current board
	int i, j;
	int rows = board[0][0];
	int columns = board[0][1];
	
	for (i=0; i<rows; i++) {
		printf("%d ", rows - (i+1)); //Print row numbers
		for (j=0; j<columns; j++) {
			printf("%c ", board[i+1][j]); //+1 because first row holds size info
		}
		printf("\n");
	}
	printf(" ");
	for (i=0; i<columns; i++) { //Print column numbers
		printf(" %d", i);
	}
	printf("\n");
	return;
}

void playGame(char** board) {
	//Play the game of connect-n
	int turn, done = 0;
	const char PIECES[] = "XO";
	int rows = board[0][0];
	int columns = board[0][1];
	
	for (turn=0; turn<rows*columns && !done; turn++) { //Take turns until the board is full, or game is over
		takeTurn(board, PIECES[(turn)%2]);
		done = won(board); //Check after each turn if there was a win
	}
	
	if (turn == rows*columns) { //If there has been rows*columns turns, --> tie
		printBoard(board);
		printf("Tie game!\n");
	}
	else {
		printBoard(board);
		printf("Player %d Won!\n", ((turn+1)%2)+1);
	}
}

void takeTurn(char** board, char PIECES) {
	int userColumn = 0;
	//In a turn, we: display board, get user input, update the board
	printBoard(board);
	userColumn = getMove(board);
	updateBoard(board, userColumn, PIECES);
	
	return;
}

void updateBoard(char** board, int userColumn, char PIECES) {
	int i;
	int rows = board[0][0];
	//If this is the first play in this column, fill in the bottom
	if (board[rows][userColumn] == '*') {
		board[rows][userColumn] = PIECES; //Update board
	} 
	//Check where the last play was made in this column
	else {
		for (i=1; i<=rows; i++) {
			if (board[i][userColumn] != '*') {
				board[i-1][userColumn] = PIECES; //Update board
				i=rows+1;
			}
		}
	}
}
