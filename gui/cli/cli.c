#include <gui/cli/cli.h>

static void print_current_block(const block_t *block) {
  for (int y = 0; y < BOARD_Y_MIN - 1; y++) {
    for (int x = BOARD_X_MIN; x <= BOARD_X_MAX; x++) mvaddch(y, x, ' ');
  }

  for (int i = 0; i < 4; i++) {
    unsigned char color = block->color;
    init_pair(color, color, color);
    attron(COLOR_PAIR(color));
    mvaddch(block->y[i] + BOARD_Y_MIN, block->x[i] + BOARD_X_MIN, ' ');
    attroff(COLOR_PAIR(color));
  }
}

static void print_next_block(const block_t *block) {
  for (int x = NEXT_BOARDER_X_MIN + 1; x <= NEXT_BOARDER_X_MAX - 1; x++) {
    for (int y = NEXT_BOARDER_Y_MIN + 1; y <= NEXT_BOARDER_Y_MAX - 1; y++)
      mvaddch(y, x, ' ');
  }

  for (int i = 0; i < 4; i++) {
    unsigned char color = block->color;
    init_pair(color, color, color);
    attron(COLOR_PAIR(color));
    mvaddch(block->y[i] + NEXT_BOARDER_Y_MAX + 1,
            block->x[i] + NEXT_BOARDER_X_MIN + 2 - BLOCK_STARTING_OFFSET, ' ');
    attroff(COLOR_PAIR(color));
  }
}

static void print_board(const Board *board) {
  for (int x = BOARD_X_MIN, i = 0; x <= BOARD_X_MAX; x++, i++) {
    for (int y = BOARD_Y_MIN, j = 0; y <= BOARD_Y_MAX; y++, j++) {
      unsigned char color = board->matrix[i][j];
      init_pair(color, color, color);
      attron(COLOR_PAIR(color));
      mvaddch(y, x, ' ');
      attroff(COLOR_PAIR(color));
    }
  }
}

static void print_boarder(int y_min, int x_min, int y_max, int x_max) {
  for (int x = x_min; x <= x_max; x++) {
    mvaddch(y_min, x, ACS_HLINE);
    mvaddch(y_max, x, ACS_HLINE);
  }

  for (int y = y_min; y <= y_max; y++) {
    mvaddch(y, x_min, ACS_VLINE);
    mvaddch(y, x_max, ACS_VLINE);
  }

  mvaddch(y_min, x_min, ACS_ULCORNER);
  mvaddch(y_max, x_min, ACS_LLCORNER);
  mvaddch(y_min, x_max, ACS_URCORNER);
  mvaddch(y_max, x_max, ACS_LRCORNER);
}

static void print_records(const GameContext *gc) {
  mvprintw(14, 19, "Best 3");
  print_boarder(15, 18, 19, 25);
  mvprintw(16, 19, " %4d", gc->records[0]);
  mvprintw(17, 19, " %4d", gc->records[1]);
  mvprintw(18, 19, " %4d", gc->records[2]);
}

static void print_score(const GameContext *gc) {
  mvprintw(10, 19, "Score");
  print_boarder(11, 18, 13, 25);
  mvprintw(12, 19, " %4d", gc->records[gc->cur_record_index]);
}

static void print_level(const GameContext *gc) {
  mvprintw(6, 19, "Level");
  print_boarder(7, 18, 9, 25);
  mvprintw(8, 19, " %4d", gc->cur_level);
}

void print_clear() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) mvaddch(j, i, ' ');
  }
}

void print_game_all(const GameContext *gc) {
  print_board(gc->b);
  print_boarder(BOARD_BOARDER_Y_MIN, BOARD_BOARDER_X_MIN, BOARD_BOARDER_Y_MAX,
                BOARD_BOARDER_X_MAX);
  print_boarder(NEXT_BOARDER_Y_MIN, NEXT_BOARDER_X_MIN, NEXT_BOARDER_Y_MAX,
                NEXT_BOARDER_X_MAX);
  print_current_block(&gc->cur_blocks->set[*gc->cur_piece]);
  print_next_block(&gc->next_blocks->set[*gc->next_piece]);
  print_records(gc);
  print_score(gc);
  print_level(gc);

  mvprintw(NEXT_BOARDER_Y_MIN - 1, NEXT_BOARDER_X_MIN + 2, "Next");
  refresh();
}

void print_pause() {
  print_clear();
  mvprintw(14, 14, "PAUSE. [Enter] to continue");
}

void print_game_over(int score) {
  print_clear();
  mvprintw(13, 15, "Game over");
  mvprintw(14, 14, "Your score: %d", score);
  mvprintw(15, 7, "[Enter] to play again or [E]xit");
}