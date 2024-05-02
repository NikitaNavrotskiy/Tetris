#ifndef _C_BRICK_GAME_V1_TEST_TEST_H
#define _C_BRICK_GAME_V1_TEST_TEST_H

#include <brick_game/tetris/blocks.h>
#include <brick_game/tetris/board.h>
#include <brick_game/tetris/callback.h>
#include <brick_game/tetris/colors.h>
#include <brick_game/tetris/game_context.h>
#include <brick_game/tetris/save.h>
#include <brick_game/tetris/sm_enums.h>
#include <check.h>

Suite *suite_blocks();
Suite *suite_game_context();
Suite *suite_db();
Suite *suite_board();
Suite *suite_callback();

#endif