#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_CALLBACK_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_CALLBACK_H

#include <brick_game/tetris/define.h>
#include <brick_game/tetris/game_context.h>
#include <brick_game/tetris/input.h>
#include <brick_game/tetris/levels.h>
#include <brick_game/tetris/points.h>
#include <brick_game/tetris/save.h>
#include <brick_game/tetris/sm.h>
#include <gui/cli/cli.h>

Signal InputToSignal(int input);

void SmCallback(Signal sig, GameContext *gc);

void CallbackPause(GameContext *gc);

void CallbackExit(GameContext *gc);

void CallbackSpawn(GameContext *gc);

void CallbackUp(GameContext *gc);

void CallbackDown(GameContext *gc);

void CallbackLeft(GameContext *gc);

void CallbackRight(GameContext *gc);

void CallbackGameOver(GameContext *gc);

void CallbackResume(GameContext *gc);

void CallbackAutoDown(GameContext *gc);

void CallbackNewGame(GameContext *gc);

#endif