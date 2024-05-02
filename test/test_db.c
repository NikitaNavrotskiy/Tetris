#include <test/test.h>

START_TEST(db_test) {
  scoredb_init();
  for (int i = 0; i < 100; i++) scoredb_save_score(i);

  int records[3] = {0};

  scoredb_get_top3(records);

  ck_assert(records[0] == 99);
  ck_assert(records[1] == 98);
  ck_assert(records[2] == 97);
}

Suite *suite_db() {
  Suite *s;
  TCase *tc;

  s = suite_create("Database test");
  tc = tcase_create("Database test");

  tcase_add_test(tc, db_test);

  suite_add_tcase(s, tc);

  return s;
}