#include <stdio.h>
#include <stdlib.h>
#include "board.h"

extern const int N;
extern const int BOARD_SIZE; // N * N = 64

void init() {
	int i;
	board = (State *) malloc(sizeof(State) * BOARD_SIZE);
	for (i = 0; i < BOARD_SIZE; i++) {
		board[i] = BLANK;
	}
	setState(4, 4, WHITE);
	setState(5, 5, WHITE);
	setState(5, 4, BLACK);
	setState(4, 5, BLACK);
	count(2, WHITE);
	count(2, BLACK);
}

int getPos(const int x, const int y) {
	return (y - 1) * N + (x - 1);
}

void setState(const int x, const int y, const State state) {
	board[getPos(x, y)] = state;
}

State getState(const int x, const int y) {
	return board[getPos(x, y)];
}

void putState(const int x, const int y) {
	switch (getState(x, y)) {
		case WHITE:
			printf("��");
			break;
		case BLANK:
			printf("�@");
			break;
		case BLACK:
			printf("��");
			break;
		case PUTTABLE:
			printf("�E");
			break;
		default:
			break;
	}
}

int count(const int dif, const State state) {
	static int cntBlk = 0, cntWht = 0;
	if (state == BLACK) {
		cntBlk += dif;
		return cntBlk;
	} else if (state == WHITE) {
		cntWht += dif;
		return cntWht;
	}
	return 0;
}

void display() {
	int i, j;
	printf(" ��%2d          %2d         [��%2d]\n", count(0, WHITE), 60, count(0, BLACK));
	puts("+---+---+---+---+---+---+---+---+");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("| ");
			putState(i, j);
		}
		printf("|\n");
		if (i == 2 || i == 6) {
			puts("+---+-- * --+---+---+-- * --+---+");
		} else {
			puts("+---+---+---+---+---+---+---+---+");
		}
	}
}

void quit() {
	free(board);
}
