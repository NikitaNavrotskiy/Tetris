#ifndef _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_SAVE_H
#define _C_BRICK_GAME_V1_BRICK_GAME_TETRIS_SAVE_H

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#define DB_NAME "brick_game_tetris_scores.db"

#define CREATE_TABLE_QUERY \
  "create table if not exists \
brick_game_tetris_scores  (id integer primary key, score integer);"

#define INSERT_SCORE_QUERY \
  "insert into brick_game_tetris_scores \
(score) values(%d);"

#define GET_TOP_SCORES_QUERY \
  "select score from brick_game_tetris_scores \
order by score desc limit 3;"

int scoredb_init();
int scoredb_save_score(int score);
int scoredb_get_top3(int records[3]);

#endif