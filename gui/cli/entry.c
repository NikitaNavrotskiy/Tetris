#include "entry.h"

static void game() {
  srand(time(NULL));

  Board board = {0};
  Blocks blocks = {0};
  Blocks blocks_next = {0};
  GameContext gc = {0};
  State state = stateStart;
  int cur = 0;
  int next = RANDOM(BLOCKS_AMOUNT);
  Signal sig = SignalEmpty;

  board_init(&board);
  game_context_init(&gc, &board, &blocks, &blocks_next, &cur, &next, &state);
  scoredb_get_top3(gc.records);

  while (*gc.state != stateExit) {
    if (sig != SignalNone) gc.last_autodown = time(NULL);

    int ch = ERR;
    ch = getch();
    sig = InputToSignal(ch);

    if (*gc.state != statePause || sig != 2) SmCallback(sig, &gc);
  }
}

int main() {
  scoredb_init();

  WIN_INIT(500);
  game();
  WIN_FINI;

  return 0;
}
