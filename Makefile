NAME=BrickGame


CC=gcc
CFLAGS=-std=c11 -Werror -Wall -Wextra -O2 -I.
LIBFLAGS=-lncurses -lsqlite3

HEADERS=brick_game/tetris/blocks.h brick_game/tetris/board.h \
	brick_game/tetris/callback.h brick_game/tetris/colors.h \
	brick_game/tetris/define.h brick_game/tetris/game_context.h \
	brick_game/tetris/input.h brick_game/tetris/levels.h \
	brick_game/tetris/piece.h brick_game/tetris/points.h \
	brick_game/tetris/save.h brick_game/tetris/sm.h brick_game/tetris/sm_enums.h \
	gui/cli/cli.h gui/cli/entry.h

SRC=gui/cli/cli.c gui/cli/entry.c brick_game/tetris/board.c \
	brick_game/tetris/blocks.c brick_game/tetris/game_context.c \
	brick_game/tetris/save.c brick_game/tetris/callback.c 
OBJ=$(SRC:.c=.o)


TEST_EXEC=test_$(NAME)
TEST_SRC=brick_game/tetris/blocks.c test/test.c test/test_blocks.c \
	brick_game/tetris/game_context.c test/test_game_context.c \
	brick_game/tetris/save.c test/test_db.c brick_game/tetris/board.c \
	test/test_board.c brick_game/tetris/callback.c gui/cli/cli.c \
	test/test_callback.c
TEST_HEADERS=test/test.h
TEST_FLAGS=-lcheck -lm -lsubunit -lsqlite3 -lncurses


all: clean brick_game


brick_game: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAGS)
	rm -rf $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: clear_db clean
	$(CC) $(CFLAGS) -g $(TEST_SRC) -o $(TEST_EXEC) $(TEST_FLAGS) 
	./$(TEST_EXEC)

gcov_report: clear_db clean 
	$(CC) $(CFLAGS) --coverage $(TEST_SRC) -o $(TEST_EXEC) $(TEST_FLAGS)
	./$(TEST_EXEC)
	lcov -t "$(TEST_EXEC)" -o $(TEST_EXEC)_gcov.info -c -d .
	genhtml -o report $(TEST_EXEC)_gcov.info
	open report/index.html

clang-format:
	cp ../materials/linters/.clang-format .
	clang-format -n $(SRC) $(HEADERS) $(TEST_SRC) $(TEST_HEADERS)
	rm .clang-format

install: uninstall
	make clean
	make
	mkdir ./build
	mv $(NAME) build

uninstall:
	rm -rf ./build

dvi: dvi/README.md
	open dvi/README.md

dist: all
	tar -cf $(NAME).tar $(NAME) dvi/README.md dvi/sm.png

clean:
	rm -rf report/
	rm -rf $(NAME) $(TEST_EXEC)
	rm -rf $(OBJ)
	rm -rf *.info *.gcda *.gcno
	rm -rf $(NAME).tar
	rm -rf ./build


clear_db:
	rm -rf brick_game_tetris_scores.db

full_clean: clean clear_db
