#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_SM_ENUMS_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_SM_ENUMS_H

typedef enum State {
  stateStart = 0,
  stateSpawn,
  stateAttaching,
  stateMoving,
  stateExit,
  statePause,
  stateGameOver
} State;

typedef enum Signal {
  SignalEmpty = 0,
  SignalUp,
  SignalDown,
  SignalLeft,
  SignalRight,
  SignalPause,
  SignalExit,
  SignalEnter,
  SignalNone
} Signal;

#endif