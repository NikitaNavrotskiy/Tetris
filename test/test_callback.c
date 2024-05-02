#include <test/test.h>

START_TEST(callback_test) {
  int input[] = {KEY_UP,     KEY_DOWN,  KEY_LEFT, KEY_RIGHT,
                 KEY_ENTER_, KEY_EXIT_, KEY_PAUSE};

  GameContext gc = {0};
  Board board = {0};
  Blocks blocks_cur = {0};
  Blocks blocks_next = {0};
  int cur = 4;
  int next = 3;
  State s = stateStart;
  board_init(&board);

  game_context_init(&gc, &board, &blocks_cur, &blocks_next, &cur, &next, &s);

  for (int i = 0; i < 7; i++) {
    Signal sig = InputToSignal(input[i]);
    SmCallback(sig, &gc);
  }
  *gc.state = stateStart;
  CallbackUp(&gc);
  ck_assert_int_eq(*gc.state, stateStart);
  CallbackPause(&gc);
  ck_assert(*gc.state == statePause);
  CallbackResume(&gc);
  ck_assert(*gc.state == stateMoving);
  CallbackNewGame(&gc);
  ck_assert(*gc.state == stateSpawn);
  CallbackAutoDown(&gc);
  ck_assert(gc.last_autodown == time(NULL));
}

Suite *suite_callback() {
  Suite *s;
  TCase *tc;

  s = suite_create("Callback test");
  tc = tcase_create("Callback test");

  tcase_add_test(tc, callback_test);

  suite_add_tcase(s, tc);

  return s;
}