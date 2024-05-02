#ifndef _C_BRICK_GAME_V1_GUI_CLI_CLI_H
#define _C_BRICK_GAME_V1_GUI_CLI_CLI_H

#include <brick_game/tetris/blocks.h>
#include <brick_game/tetris/board.h>
#include <brick_game/tetris/game_context.h>
#include <ncurses.h>

void print_game_all(const GameContext *gc);

void print_pause();

void print_game_over(int score);

void print_clear();

#endif