#include "win.h"

int won(char** board) {
	return verticalWin(board) || horozontalWin(board) || diagonalWin(board);
}

int verticalWin(char** board) {
	//Determine whether any vertical wins have taken place.
	//Returns 1 if there is a vertical winner, 0 otherwise.
	
	//Pull info from board
	int i, j, k;
	int rows = board[0][0];
	int columns = board[0][1];
	int connectNum = board[0][2];
	int in_a_row;
	char firstChar;
	//First checks whether a vertical win can even happen.
	if (connectNum>rows) {
		return 0;
	}
	
	//Check each column in chunks of size connectNum.
	for (i=0; i<columns; i++) { //For each column
		for (j=0; j<(rows-connectNum+1); j++) { //For each chunk of size connectNum
			in_a_row = 1;
			firstChar = board[j+1][i];
			for (k=1; k<connectNum; k++) { //For each character in the chunk
				if (board[j+k+1][i] == firstChar) {
					in_a_row++; //Add to in-a-row if current char is the same as firstChar
				}
			}
			if (in_a_row == connectNum && firstChar!= '*') { //After going through the chunk
				return 1; //if every character was the same and not *, there is a winner
			}
		}
	}
	return 0;
}

int horozontalWin(char** board) {
	
	//Determine whether any horozontal wins have taken place.
	//Returns 1 if there is a horozontal winner, 0 otherwise.
	
	//Pull info from board
	int i, j, k;
	int rows = board[0][0];
	int columns = board[0][1];
	int connectNum = board[0][2];
	int in_a_row;
	char firstChar;
	//First checks whether a horozontal win can even happen.
	if (connectNum>columns) { 
		return 0;
	}
	
	//Check each row in chunks of size connectNum.
	for (i=1; i<rows+1; i++) { //For each row
		for (j=0; j<(columns-connectNum+1); j++) { //For each chunk of size connectNum
			in_a_row = 1;
			firstChar = board[i][j];
			for (k=1; k<connectNum; k++) { //For each character in the chunk
				if (board[i][j+k] == firstChar) {
					in_a_row++; //Add to in-a-row if current char is the same as firstChar
				}
			}
			if (in_a_row == connectNum && firstChar!= '*') { //After going through the chunk
				return 1; //if every character was the same and not *, there is a winner
			}
		}
	}
	return 0;
}

int diagonalWin(char** board) {
	//Determine whether any diagonal wins have taken place.
	//Returns 1 if there is a diagonal winner, 0 otherwise.
	int start;
	int r, c; //Keep track of where we are, to not go out of bounds
	int rowMax = board[0][0]; 	//Pull info from board
	int colMax = board[0][1];
	int connectNum = board[0][2];
	int xCount, oCount; //Count to find wins
	//First checks whether a vertical win can even happen.
	if ((connectNum>rowMax) || (connectNum>colMax)){
		return 0;
	}
	
	//Check diagonals starting in the first column and running downhill
	for(start=1; start<(rowMax-(connectNum-2)); start++) {
		xCount=0, oCount=0;
		for (r=start, c = 0; r<=rowMax && c<colMax; r++, c++) {
			if (board[r][c] == 'X') {
				xCount++;
				oCount = 0;
				if (xCount == connectNum) {
					return 1;
				}
			}
			else if (board[r][c] == 'O') {
				oCount++;
				xCount = 0;
				if (oCount == connectNum) {
					return 1;
				}
			}
			else {
				xCount = 0, oCount = 0;
			}
		}
	}
	
	//Check diagonals starting in the first row and running downhill
	for (start=1; start<(colMax-(connectNum-1)); start++) {
		xCount = 0, oCount = 0;
		for (c=start, r=1; r<=rowMax && c<colMax; r++, c++) {
			if (board[r][c] == 'X') {
				xCount++, oCount = 0;
				if (xCount == connectNum) {
					return 1;
				}
			}
			else if (board[r][c] == 'O') {
				oCount++, xCount = 0;
				if (oCount == connectNum) {
					return 1;
				}
			}
			else {
				xCount = 0, oCount = 0;
			}
		}
	}
	//Check diagonals starting in the first column and running uphill
	for (start=rowMax; start>(rowMax-(connectNum-1)); start--) {
		xCount = 0, oCount = 0;
		for (r=start, c=0; r>=1 && c<colMax; r--, c++) {
			if (board[r][c] == 'X') {
				xCount++, oCount = 0;
				if (xCount == connectNum) {
					return 1;
				}
			}
			else if (board[r][c] == 'O') {
				oCount++, xCount = 0;
				if (oCount == connectNum) {
					return 1;
				}
			}
			else {
				xCount = 0, oCount = 0;
			}
		}
	}
	//Check diagonals starting in the last row and running uphill
	for (start=1; start<(colMax-(connectNum-2)); start++) {
		xCount=0, oCount=0;
		for (r=rowMax, c=start; r>=1 && c<colMax; r--, c++) {
			if (board[r][c] == 'X') {
				xCount++, oCount = 0;
				if (xCount == connectNum) {
					return 1;
				}
			}
			else if (board[r][c] == 'O') {
				oCount++, xCount = 0;
				if (oCount == connectNum) {
					return 1;
				}
			}
			else {
				xCount = 0, oCount = 0;
			}
		}
	}
	return 0;
}
