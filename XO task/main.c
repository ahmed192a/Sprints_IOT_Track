#include "XO_APIs.h"

char board[3][3] = { 0 };
char player = 1;

int main() {
	int r = 0, c= 0;
	int choice = 1;
	int end = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	while (choice == 1) {

		clearboard();
		end = 0;
		player = 1;
		while (end == 0)
		{
			switch (player) {
			case 1:
				printf("First Player choose row and column : ");
				break;
			case 0:
				printf("Second Player choose row and column : ");

				break;
			}
			scanf("%d %d", &r, &c);
			// Error handling
			if ((r <= 0 || r > 3) || (c <= 0 || c > 3)) {
				printf("ERROR: OUT OF RANGE\n\n");
				continue;
			}
			else if (board[r - 1][c - 1] != ' ') {
				printf("ERROR: WRONG POSITION\n\n");
				continue;
			}
			else {
				switch (player) {
				case 1:
					board[r - 1][c - 1] = 'X';
					player = 0;
					break;
				case 0:
					board[r - 1][c - 1] = 'O';
					player = 1;
					break;
				}
			}
			displayboard();
			end = endboard();
		}
		printf("\tGAME OVER\n");
		if (end == -1) {
			printf("\t NO WINNER \n");
		}
		else {
			printf("\t PLAYER %d WON \n", end);
		}
		printf("Play Again?  1: Continue  2: Exit  -> ");
		scanf("%d",&choice);
	}
	return 0;

}

