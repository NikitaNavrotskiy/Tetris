#include <test/test.h>

START_TEST(board_test) {
  Board b;

  board_init(&b);

  ck_assert(board_count_full_lines(&b) == 0);

  for (int i = 0; i < 10; i++) {
    b.matrix[i][19] = COLOR_BLUE;
    b.matrix[i][18] = COLOR_BLUE;
  }

  ck_assert(board_count_full_lines(&b) == 2);

  board_remove_full_lines(&b);
  ck_assert(board_count_full_lines(&b) == 0);
}

Suite *suite_board() {
  Suite *s;
  TCase *tc;

  s = suite_create("Board test");
  tc = tcase_create("Board test");

  tcase_add_test(tc, board_test);

  suite_add_tcase(s, tc);

  return s;
}