#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_DEFINE_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_DEFINE_H

#include <stdlib.h>

#define WIN_INIT(time)     \
  {                        \
    initscr();             \
    start_color();         \
    noecho();              \
    keypad(stdscr, true);  \
    nodelay(stdscr, true); \
    timeout(time);         \
    curs_set(false);       \
  }

#define WIN_FINI endwin()

#define RANDOM(mod) rand() % mod

#endif