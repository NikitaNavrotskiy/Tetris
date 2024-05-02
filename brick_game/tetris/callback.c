#include <brick_game/tetris/callback.h>

static const sm_callback sm_vector[7][9] = {
    {CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn,
     CallbackPause, CallbackExit, CallbackGameOver, CallbackAutoDown},
    {CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn,
     CallbackPause, CallbackExit, CallbackGameOver, CallbackAutoDown},
    {CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn, CallbackSpawn,
     CallbackPause, CallbackExit, CallbackGameOver, CallbackAutoDown},
    {NULL, CallbackUp, CallbackDown, CallbackLeft, CallbackRight, CallbackPause,
     CallbackExit, CallbackAutoDown, CallbackAutoDown},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {CallbackPause, CallbackPause, CallbackPause, CallbackPause, CallbackPause,
     CallbackPause, CallbackExit, CallbackResume, CallbackPause},
    {CallbackGameOver, CallbackGameOver, CallbackGameOver, CallbackGameOver,
     CallbackGameOver, CallbackGameOver, CallbackExit, CallbackNewGame,
     CallbackGameOver}};

Signal InputToSignal(int input) {
  Signal sig = SignalNone;
  switch (input) {
    case KEY_RIGHT:
      sig = SignalRight;
      break;
    case KEY_LEFT:
      sig = SignalLeft;
      break;
    case KEY_DOWN:
    case ERR:
      sig = SignalDown;
      break;
    case KEY_UP:
      sig = SignalUp;
      break;
    case KEY_PAUSE:
      sig = SignalPause;
      break;
    case KEY_EXIT_:
      sig = SignalExit;
      break;
    case KEY_ENTER_:
      sig = SignalEnter;
      break;
    default:
      break;
  }

  return sig;
}

void CallbackPause(GameContext *gc) {
  *gc->state = statePause;
  print_pause();
}

void CallbackExit(GameContext *gc) {
  scoredb_save_score(gc->records[gc->cur_record_index]);
  *gc->state = stateExit;
}

void CallbackSpawn(GameContext *gc) {
  if (block_to_board(gc->b, &gc->cur_blocks->set[*gc->cur_piece]))
    *gc->state = stateGameOver;
  else
    *gc->state = stateMoving;

  gc->records[gc->cur_record_index] += points[board_count_full_lines(gc->b)];
  gc->cur_level = gc->records[gc->cur_record_index] / 600 + 1;

  if (gc->cur_level > 10) *gc->state = stateGameOver;

  timeout(timeouts_by_levels[gc->cur_level]);
  board_remove_full_lines(gc->b);
  game_context_update_records(gc);

  *gc->cur_piece = *gc->next_piece;
  *gc->next_piece = RANDOM(BLOCKS_AMOUNT);
  gc->score_flag = false;
  init_blocks(gc->cur_blocks);
  init_blocks(gc->next_blocks);
}

void CallbackUp(GameContext *gc) {
  block_rotate(gc->b, &gc->cur_blocks->set[*gc->cur_piece], gc->last_autodown);
}

void CallbackDown(GameContext *gc) {
  block_go_down(&gc->cur_blocks->set[*gc->cur_piece]);
}

void CallbackLeft(GameContext *gc) {
  block_go_left(gc->b, &gc->cur_blocks->set[*gc->cur_piece], gc->last_autodown);
}

void CallbackRight(GameContext *gc) {
  block_go_right(gc->b, &gc->cur_blocks->set[*gc->cur_piece],
                 gc->last_autodown);
}

void CallbackGameOver(GameContext *gc) {
  if (!gc->score_flag) {
    int score = gc->records[gc->cur_record_index];
    scoredb_save_score(score);
    print_game_over(gc->records[gc->cur_record_index]);
    gc->score_flag = true;
  }
  gc->cur_level = 1;
  gc->cur_record_index = 3;
  gc->records[3] = 0;
}

void CallbackAutoDown(GameContext *gc) {
  time_t new_cur_time = time(NULL);

  if (new_cur_time - gc->last_autodown >= 1) {
    block_go_down(&gc->cur_blocks->set[*gc->cur_piece]);
    gc->last_autodown = time(NULL);
  }
}

void CallbackResume(GameContext *gc) {
  print_clear();
  *gc->state = stateMoving;
}

void CallbackNewGame(GameContext *gc) {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) gc->b->matrix[i][j] = COLOR_EMPTY;
  }
  *gc->state = stateSpawn;
}

void SmCallback(Signal sig, GameContext *gc) {
  sm_callback cb = sm_vector[*gc->state][sig];

  if (sig != SignalPause && *gc->state != stateGameOver) {
    if (cb) cb(gc);
    print_clear();
    print_game_all(gc);

    if (!block_can_go_down(gc->b, &gc->cur_blocks->set[*gc->cur_piece])) {
      *gc->state = stateSpawn;
      timeout(0);
    }
  } else if ((sig == SignalPause || *gc->state == stateGameOver) && cb)
    cb(gc);
}