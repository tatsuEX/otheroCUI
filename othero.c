#include "board.h"

extern const int N;
extern const int BOARD_SIZE; // N * N = 64

int main(int argc, char ** argv) {
	init();
	display();
	quit();
}