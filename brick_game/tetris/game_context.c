#include <brick_game/tetris/game_context.h>

void game_context_init(GameContext *gc, Board *b, Blocks *cur, Blocks *next,
                       int *cur_piece, int *next_piece, State *st) {
  gc->b = b;
  gc->cur_blocks = cur;
  gc->next_blocks = next;
  gc->cur_level = 1;
  gc->cur_piece = cur_piece;
  gc->next_piece = next_piece;
  gc->cur_record_index = 3;
  gc->last_autodown = time(NULL);
  gc->state = st;
  gc->score_flag = false;

  for (int i = 0; i < 4; i++) gc->records[i] = 0;
}

void game_context_update_records(GameContext *gc) {
  for (int i = gc->cur_record_index; i >= 1; i--) {
    if (gc->records[i] >= gc->records[i - 1]) {
      int tmp = gc->records[i];
      gc->records[i] = gc->records[i - 1];
      gc->records[i - 1] = tmp;

      gc->cur_record_index = i - 1;
    }
  }
}