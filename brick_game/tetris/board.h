#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_BOARD_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_BOARD_H

#include <brick_game/tetris/colors.h>
#include <brick_game/tetris/piece.h>

#define BOARD_BOARDER_Y_MIN 5
#define BOARD_BOARDER_X_MIN 4
#define BOARD_BOARDER_Y_MAX BOARD_BOARDER_Y_MIN + 21
#define BOARD_BOARDER_X_MAX BOARD_BOARDER_X_MIN + 11

#define BOARD_Y_MIN BOARD_BOARDER_Y_MIN + 1
#define BOARD_X_MIN BOARD_BOARDER_X_MIN + 1
#define BOARD_Y_MAX BOARD_BOARDER_Y_MAX - 1
#define BOARD_X_MAX BOARD_BOARDER_X_MAX - 1
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#define NEXT_BOARDER_Y_MIN NEXT_BOARDER_Y_MAX - 5
#define NEXT_BOARDER_X_MIN BOARD_BOARDER_X_MAX + 3
#define NEXT_BOARDER_Y_MAX BOARD_BOARDER_Y_MAX
#define NEXT_BOARDER_X_MAX NEXT_BOARDER_X_MIN + 7

typedef struct board {
  piece_t matrix[BOARD_WIDTH][BOARD_HEIGHT];
} Board;

void board_init(Board *b);

int board_count_full_lines(const Board *b);

void board_remove_full_lines(Board *b);

#endif