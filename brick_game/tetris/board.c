#include <brick_game/tetris/board.h>

void board_init(Board *b) {
  for (int i = 0; i < BOARD_WIDTH; i++)
    for (int j = 0; j < BOARD_HEIGHT; j++) b->matrix[i][j] = COLOR_EMPTY;
}

static bool board_is_full_line(const Board *b, int n) {
  bool res = true;

  for (int i = 0; i < BOARD_WIDTH; i++) {
    if (b->matrix[i][n] == COLOR_EMPTY) res = false;
  }

  return res;
}

int board_count_full_lines(const Board *b) {
  int count = 0;

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    if (board_is_full_line(b, i)) count++;
  }

  return count;
}

static void board_remove_n_line(Board *b, int n) {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = n; j > 0; j--) b->matrix[i][j] = b->matrix[i][j - 1];
  }

  for (int i = 0; i < BOARD_WIDTH; i++) b->matrix[i][0] = COLOR_EMPTY;
}

void board_remove_full_lines(Board *b) {
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    if (board_is_full_line(b, i)) board_remove_n_line(b, i);
  }
}