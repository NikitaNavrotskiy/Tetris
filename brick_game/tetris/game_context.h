#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_GAME_CONTEXT_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_GAME_CONTEXT_H

#include <brick_game/tetris/blocks.h>
#include <brick_game/tetris/board.h>
#include <brick_game/tetris/sm_enums.h>

typedef struct GameContext {
  Board *b;
  Blocks *cur_blocks;
  Blocks *next_blocks;
  int cur_level;
  int records[4];
  int *cur_piece;
  int *next_piece;
  int cur_record_index;
  time_t last_autodown;
  State *state;
  bool score_flag;
} GameContext;

void game_context_init(GameContext *gc, Board *b, Blocks *cur, Blocks *next,
                       int *cur_piece, int *next_piece, State *st);

void game_context_update_records(GameContext *gc);

#endif