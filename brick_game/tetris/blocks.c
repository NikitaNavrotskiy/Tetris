#include <brick_game/tetris/blocks.h>

static void init_block_stick(Blocks *blocks) {
  blocks->set[BLOCK_STICK].y[0] = 0 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_STICK].y[1] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_STICK].y[2] = 1 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_STICK].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_STICK].x[0] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_STICK].x[1] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_STICK].x[2] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_STICK].x[3] = 0 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_STICK].color = COLOR_BLOCK_STICK;
}

static void init_block_l_shape(Blocks *blocks) {
  blocks->set[BLOCK_L_SHAPE].y[0] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_L_SHAPE].y[1] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_L_SHAPE].y[2] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_L_SHAPE].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_L_SHAPE].x[0] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_L_SHAPE].x[1] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_L_SHAPE].x[2] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_L_SHAPE].x[3] = 2 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_L_SHAPE].color = COLOR_BLOCK_L_SHAPE;
}

static void init_block_rev_l_shape(Blocks *blocks) {
  blocks->set[BLOCK_REV_L_SHAPE].y[0] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_L_SHAPE].y[1] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_L_SHAPE].y[2] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_L_SHAPE].y[3] = 2 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_REV_L_SHAPE].x[0] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_L_SHAPE].x[1] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_L_SHAPE].x[2] = 2 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_L_SHAPE].x[3] = 2 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_REV_L_SHAPE].color = COLOR_BLOCK_REV_L_SHAPE;
}

static void init_block_square(Blocks *blocks) {
  blocks->set[BLOCK_SQUARE].y[0] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_SQUARE].y[1] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_SQUARE].y[2] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_SQUARE].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_SQUARE].x[0] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_SQUARE].x[1] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_SQUARE].x[2] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_SQUARE].x[3] = 1 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_SQUARE].color = COLOR_BLOCK_SQUARE;
}

static void init_block_z_shape(Blocks *blocks) {
  blocks->set[BLOCK_Z_SHAPE].y[0] = 1 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_Z_SHAPE].y[1] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_Z_SHAPE].y[2] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_Z_SHAPE].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_Z_SHAPE].x[0] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_Z_SHAPE].x[1] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_Z_SHAPE].x[2] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_Z_SHAPE].x[3] = 0 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_Z_SHAPE].color = COLOR_BLOCK_Z_SHAPE;
}

static void init_block_rev_z_shape(Blocks *blocks) {
  blocks->set[BLOCK_REV_Z_SHAPE].y[0] = 1 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_Z_SHAPE].y[1] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_Z_SHAPE].y[2] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_REV_Z_SHAPE].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_REV_Z_SHAPE].x[0] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_Z_SHAPE].x[1] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_Z_SHAPE].x[2] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_REV_Z_SHAPE].x[3] = 1 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_REV_Z_SHAPE].color = COLOR_BLOCK_REV_Z_SHAPE;
}

static void init_block_t_shape(Blocks *blocks) {
  blocks->set[BLOCK_T_SHAPE].y[0] = 2 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_T_SHAPE].y[1] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_T_SHAPE].y[2] = 3 - BOARD_BOARDER_Y_MIN;
  blocks->set[BLOCK_T_SHAPE].y[3] = 3 - BOARD_BOARDER_Y_MIN;

  blocks->set[BLOCK_T_SHAPE].x[0] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_T_SHAPE].x[1] = 0 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_T_SHAPE].x[2] = 1 + BLOCK_STARTING_OFFSET;
  blocks->set[BLOCK_T_SHAPE].x[3] = 2 + BLOCK_STARTING_OFFSET;

  blocks->set[BLOCK_T_SHAPE].color = COLOR_BLOCK_T_SHAPE;
}

void init_blocks(Blocks *blocks) {
  init_block_stick(blocks);
  init_block_l_shape(blocks);
  init_block_rev_l_shape(blocks);
  init_block_square(blocks);
  init_block_z_shape(blocks);
  init_block_rev_z_shape(blocks);
  init_block_t_shape(blocks);
}

static bool block_can_go_left(Board *board, block_t *block) {
  bool res = true;

  for (int i = 0; i < 4 && res; i++) {
    if (block->x[i] == 0) res = false;
    if (block->y[i] >= 0 && block->x[i] > 0 &&
        board->matrix[block->x[i] - 1][block->y[i]] != COLOR_EMPTY)
      res = false;
  }

  return res;
}

void block_go_left(Board *board, block_t *block, time_t cur_time) {
  if (block_can_go_left(board, block)) {
    for (int i = 0; i < 4; i++) block->x[i]--;
  }

  time_t new_cur_time = time(NULL);

  if (new_cur_time - cur_time >= 1) block_go_down(block);
}

static bool block_can_go_right(Board *board, block_t *block) {
  bool res = true;

  for (int i = 0; i < 4 && res; i++) {
    if (block->x[i] == BOARD_WIDTH - 1) res = false;
    if (block->y[i] >= 0 && block->x[i] < 9 &&
        board->matrix[block->x[i] + 1][block->y[i]] != COLOR_EMPTY)
      res = false;
  }

  return res;
}

void block_go_right(Board *board, block_t *block, time_t cur_time) {
  if (block_can_go_right(board, block)) {
    for (int i = 0; i < 4; i++) block->x[i]++;
  }

  time_t new_cur_time = time(NULL);

  if (new_cur_time - cur_time >= 1) block_go_down(block);
}

void block_go_down(block_t *block) {
  for (int i = 0; i < 4; i++) block->y[i]++;
}

bool block_can_go_down(Board *board, block_t *block) {
  bool res = true;

  for (int i = 0; i < 4 && res; i++) {
    if (block->y[i] == BOARD_Y_MAX - BOARD_Y_MIN - 1) res = false;
    if (block->y[i] >= 0) {
      if (board->matrix[block->x[i]][block->y[i]] != COLOR_EMPTY) res = false;
    }
  }

  if (!res) {
    for (int i = 0; i < 4; i++) block->y[i]--;
  }

  return res;
}

static bool block_is_fit_after_rotate(Board *board, int new_x[4],
                                      int new_y[4]) {
  bool res = true;

  for (int i = 0; i < 4; i++) {
    if (new_x[i] >= 0 && new_x[i] < BOARD_WIDTH && new_y[i] >= 0 &&
        new_y[i] < BOARD_HEIGHT &&
        board->matrix[new_x[i]][new_y[i]] != COLOR_EMPTY)
      res = false;
  }

  return res;
}

static bool block_is_push_bug_case(block_t *block, int y[4]) {
  bool res = false;

  int flags[4] = {0};

  if (block->color == COLOR_BLOCK_REV_Z_SHAPE ||
      block->color == COLOR_BLOCK_Z_SHAPE ||
      block->color == COLOR_BLOCK_STICK ||
      block->color == COLOR_BLOCK_T_SHAPE) {
    for (int i = 0; i < 4; i++) flags[y[i] % 3]++;

    res = flags[0] && flags[1] && flags[2];
  }

  return res;
}

static bool block_is_left_bug_case(int y[4]) {
  bool need_to_fix = false;

  int flags[4] = {0};

  for (int i = 0; i < 4; i++) {
    if (y[i] - BOARD_Y_MIN < 0) need_to_fix = true;
    flags[y[i] % 3]++;
  }
  return flags[0] && flags[1] && flags[2] && need_to_fix;
}

void block_rotate(Board *board, block_t *block, time_t cur_time) {
  int need_right = 0;
  int need_left = 0;
  int x_cen = (block->x[0] + block->x[1] + block->x[2] + block->x[3]) / 4;
  int y_cen = (block->y[0] + block->y[1] + block->y[2] + block->y[3]) / 4;
  int new_x[4] = {0};
  int new_y[4] = {0};

  for (int i = 0; i < 4; i++) {
    new_x[i] = (block->y[i] - y_cen) + x_cen;
    new_y[i] = -(block->x[i] - x_cen) + y_cen + 1;
  }

  for (int i = 0; i < 4; i++) {
    if (new_x[i] < 0 && need_right < -new_x[i]) need_right = -new_x[i];
    if ((new_x[i] > BOARD_WIDTH - 1 && need_left > new_x[i] - BOARD_WIDTH - 2))
      need_left = new_x[i] - BOARD_WIDTH - 2;
  }

  if ((!need_left || !need_right) &&
      block_is_fit_after_rotate(board, new_x, new_y)) {
    for (int i = 0; i < 4; i++) {
      if (need_left) new_x[i] += need_left;
      if (need_right) new_x[i] += need_right;
    }
    for (int i = 0; i < 4; i++) {
      block->x[i] = new_x[i];
      block->y[i] = new_y[i];
    }
  }
  if (block_is_push_bug_case(block, new_y)) {
    for (int i = 0; i < 4; i++) block->y[i]--;
  }
  if (block_is_left_bug_case(new_x)) {
    for (int i = 0; i < 4; i++) block->x[i]++;
  }

  time_t new_cur_time = time(NULL);

  if (new_cur_time - cur_time >= 1) block_go_down(block);
}

bool block_to_board(Board *board, block_t *block) {
  bool is_finish = false;

  for (int i = 0; i < 4; i++) {
    if (block->y[i] == -1) is_finish = true;
  }

  bool is_print = true;

  for (int i = 0; i < 4; i++) {
    if (block->y[i] < 0) is_print = false;
  }

  if (is_print) {
    board->matrix[block->x[0]][block->y[0]] = block->color;
    board->matrix[block->x[1]][block->y[1]] = block->color;
    board->matrix[block->x[2]][block->y[2]] = block->color;
    board->matrix[block->x[3]][block->y[3]] = block->color;
  }

  return is_finish;
}