#include <stdio.h>
#include "move.h"

int getMove(char** board) {
	//Get a valid, sensible move from the player.
	int columns = board[0][1];
	int argsRead = 0;
	int userColumn = -1; //Ensures while loop is always entered
	
	while(!isValidMove(board, userColumn, argsRead)) {
		printf("Enter a column between 0 and %d to play in: ", columns-1);
		argsRead = scanf("%d", &userColumn);
		clearInput();
	}
	return userColumn;
}

int isValidMove(char** board, int userColumn, int argsRead) {
	int columns = board[0][1];
	//Determines whether move is out of bounds, or in a full column
	if (argsRead != 1 || userColumn < 0 || userColumn >= columns) {
		//Invalid input
		return 0;
	} else if (board[1][userColumn] != '*') {
		//Column is full
		return 0;
	}
	return 1;
}

void clearInput() {
	//removes all input that has not yet been read, until reaching a new line
	char c = getchar(); 
	while(c != '\n' && c != EOF){
		c = getchar();
	}
}
