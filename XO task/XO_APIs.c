#include "XO_APIs.h"
int checkwinner() {
	int r, c;
	int cxw[3] = { 0 }, cow[3] = { 0 }, rxw[3] = { 0 }, row[3] = { 0 };
	int xdw[2] = { 0 }, odw[2] = {0};

	for (r = 0; r < 3; r++) {
		if (board[r][r] == 'X') {
			xdw[0] += 1;
		}
		else if (board[r][r] == 'O') {
			odw[0] += 1;
		}
		if (board[r][2 - r] == 'X') {
			xdw[1] += 1;
		}
		else if (board[r][2 - r] == 'O') {
			odw[1] += 1;
		}
		for (c = 0; c < 3; c++) {
			if (board[r][c] == 'X') {
				cxw[c] += 1;
				rxw[r] += 1;
			}
			else if (board[r][c] == 'O') {
				cow[c] += 1;
				row[r] += 1;
			}
		}
	}
	for (r = 0; r < 3; r++) {
		if (rxw[r] == 3 || cxw[r] == 3) {
			return 1;
		}
		else if (row[r] == 3 || cow[r] == 3) {
			return 2;
		}
	}
	if (xdw[0] == 3 || xdw[1] == 3) {
		return 1;
	}
	else if (odw[0] == 3 || odw[1] == 3) {
		return 2;
	}


	return 0;
}

int endboard() {
	int r, c;
	for (r = 0; r < 3; r++) {
		for (c = 0; c < 3; c++) {
			if (board[r][c] == ' ') {
				return checkwinner();
			}
		}
	}
	return -1;
}

void displayboard() {
	int r;
	printf("\n");
	for (r = 0; r < 3; r++) {
		printf(" %c | %c | %c \n", board[r][0], board[r][1], board[r][2]);
		if (r != 2) {
			printf("------------\n");
		}
	}
	printf("\n\n");
}

void clearboard() {
	int r, c;
	for (r = 0; r < 3; r++) {
		for (c = 0; c < 3; c++) {
			board[r][c] = ' ';
		}
	}
}