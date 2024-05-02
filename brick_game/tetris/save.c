#include <brick_game/tetris/save.h>

int scoredb_init() {
  sqlite3 *db;
  char *err = NULL;
  int status;

  status = sqlite3_open(DB_NAME, &db);

  if (status == SQLITE_OK) {
    status = sqlite3_exec(db, CREATE_TABLE_QUERY, NULL, 0, &err);

    if (status != SQLITE_OK) sqlite3_free(err);
  }

  sqlite3_close(db);

  return status;
}

int scoredb_save_score(int score) {
  sqlite3 *db;
  int status;
  char *err = NULL;

  char query[100];
  snprintf(query, sizeof(query), INSERT_SCORE_QUERY, score);

  status = sqlite3_open(DB_NAME, &db);

  if (status == SQLITE_OK) {
    status = sqlite3_exec(db, query, NULL, 0, &err);

    if (status != SQLITE_OK) sqlite3_free(err);
  }

  sqlite3_close(db);
  return status;
}

int scoredb_get_top3(int records[3]) {
  sqlite3 *db;
  sqlite3_stmt *res;
  int status;

  status = sqlite3_open(DB_NAME, &db);

  if (status == SQLITE_OK) {
    status = sqlite3_prepare_v2(db, GET_TOP_SCORES_QUERY, -1, &res, 0);

    int i = 0;
    while (sqlite3_step(res) == SQLITE_ROW && i < 3) {
      records[i] = sqlite3_column_int(res, 0);
      i++;
    }
  }

  sqlite3_finalize(res);
  sqlite3_close(db);

  return status;
}
