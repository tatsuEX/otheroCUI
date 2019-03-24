#ifndef __BOARD_H
#define __BOARD_H

// variables
typedef enum state {
	WHITE = -1,
	BLANK,
	BLACK,
	PUTTABLE
} State;

static const int N = 8;
static const int BOARD_SIZE = 8 << 3; // N * N = 64

static State * board;

// functions
void init();
int getPos(const int x, const int y);
void setState(const int x, const int y, const State state);
State getState(const int x, const int y);
void putState(const int x, const int y);
int count(const int dif, const State state);
void display();
void quit();

#endif
