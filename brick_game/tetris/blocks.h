#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_BLOCKS_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_BLOCKS_H

#include <brick_game/tetris/board.h>
#include <brick_game/tetris/colors.h>
#include <stdint.h>
#include <time.h>

#define BLOCKS_AMOUNT 7

#define BLOCK_STICK 0
#define BLOCK_L_SHAPE 1
#define BLOCK_REV_L_SHAPE 2
#define BLOCK_SQUARE 3
#define BLOCK_Z_SHAPE 4
#define BLOCK_REV_Z_SHAPE 5
#define BLOCK_T_SHAPE 6

#define BLOCK_STARTING_OFFSET 4

typedef struct block {
  int8_t y[4];
  int8_t x[4];
  uint8_t color;
} block_t;

typedef struct Blocks {
  block_t set[7];
} Blocks;

void init_blocks(Blocks *blocks);

bool block_can_go_down(Board *board, block_t *block);

bool block_to_board(Board *board, block_t *block);

void block_go_down(block_t *block);

void block_go_left(Board *board, block_t *block, time_t cur_time);

void block_go_right(Board *board, block_t *block, time_t cur_time);

void block_rotate(Board *board, block_t *block, time_t cur_time);

#endif