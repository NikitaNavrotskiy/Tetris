#include <test/test.h>

START_TEST(blocks_test) {
  Blocks b = {0};
  int tmp[7][2][4] = {0};
  int colors[7] = {1, 202, 11, 212, 55, 40, 4};

  init_blocks(&b);

  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 4; i++) {
      ck_assert(b.set[j].x[i] != 0);
      ck_assert(b.set[j].y[i] != 0);
      tmp[j][0][i] = b.set[j].x[i];
      tmp[j][1][i] = b.set[j].y[i];
    }

    ck_assert(b.set[j].color == colors[j]);
  }

  Board board = {0};

  for (int i = 0; i < 7; i++) {
    ck_assert(block_can_go_down(&board, &b.set[i]));
    block_go_down(&b.set[i]);

    for (int j = 0; j < 4; j++) {
      ck_assert(tmp[i][0][j] == b.set[i].x[j]);
      ck_assert(tmp[i][1][j] == b.set[i].y[j] - 1);
      tmp[i][0][j] = b.set[i].x[j];
      tmp[i][1][j] = b.set[i].y[j];
    }
  }

  for (int i = 0; i < 7; i++) {
    block_go_right(&board, &b.set[i], time(NULL));

    for (int j = 0; j < 4; j++) {
      ck_assert(tmp[i][0][j] == b.set[i].x[j] - 1);
      ck_assert(tmp[i][1][j] == b.set[i].y[j]);
      tmp[i][0][j] = b.set[i].x[j];
      tmp[i][1][j] = b.set[i].y[j];
    }
  }

  for (int i = 0; i < 7; i++) {
    block_go_left(&board, &b.set[i], time(NULL));

    for (int j = 0; j < 4; j++) {
      ck_assert(tmp[i][0][j] == b.set[i].x[j] + 1);
      ck_assert(tmp[i][1][j] == b.set[i].y[j]);
      tmp[i][0][j] = b.set[i].x[j];
      tmp[i][1][j] = b.set[i].y[j];
    }

    block_rotate(&board, &b.set[i], time(NULL));
  }

  for (int i = 0; i < 7; i++) {
    block_go_down(&b.set[i]);
    block_go_down(&b.set[i]);
    ck_assert(!block_to_board(&board, &b.set[i]));
    board_init(&board);
  }
}

Suite *suite_blocks() {
  Suite *s;
  TCase *tc;

  s = suite_create("Blocks test");
  tc = tcase_create("Blocks test");

  tcase_add_test(tc, blocks_test);

  suite_add_tcase(s, tc);

  return s;
}