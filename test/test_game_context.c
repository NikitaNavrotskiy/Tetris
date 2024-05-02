#include <test/test.h>

START_TEST(game_context_test) {
  GameContext gc = {0};
  Board b = {0};
  Blocks b1 = {0}, b2 = {0};
  int cur = 1, next = 5;
  State st = 3;

  game_context_init(&gc, &b, &b1, &b2, &cur, &next, &st);

  ck_assert(gc.state == &st);
  ck_assert(gc.next_piece == &next);
  ck_assert(gc.cur_piece == &cur);
  ck_assert(gc.b == &b);
  ck_assert(gc.cur_blocks == &b1);
  ck_assert(gc.next_blocks == &b2);

  gc.records[0] = 500;
  gc.records[1] = 400;
  gc.records[2] = 300;
  gc.records[3] = 600;

  game_context_update_records(&gc);

  ck_assert(gc.records[0] == 600);
  ck_assert(gc.records[1] == 500);
  ck_assert(gc.records[2] == 400);
  ck_assert(gc.records[3] == 300);
}

Suite *suite_game_context() {
  Suite *s;
  TCase *tc;

  s = suite_create("Game context test");
  tc = tcase_create("Game context test");

  tcase_add_test(tc, game_context_test);

  suite_add_tcase(s, tc);

  return s;
}