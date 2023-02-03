# Makefile for game_of_life

CC=g++
CFLAGS?=
DEPS=Board.cpp Cell.cpp
SOURCES=main.cpp ${DEPS}
TEST_SOURCES=main_gtest.cpp ${DEPS}
HEADERS=Board.h Cell.h

all: gol gol_test

PHONY: run
run: gol
	./gol

gol: ${SOURCES} ${HEADERS}
	${CC} ${CFLAGS} -o $@ ${MAIN} ${SOURCES}

PHONY: test
test: gol_test
	./gol_test

gol_test: ${TEST_SOURCES} ${HEADERS}
	${CC} ${CFLAGS} -o $@ ${TEST_SOURCES}

clean:
	rm -f gol gol_test


