#Makefile for epsilon

cc=g++

all: epsilon_test epsilon

.PHONY: test
test: epsilon_test
	./epsilon_test

epsilon_test: main_gtest.cpp epsilon.h
	${cc} -o $@ $< -lgtest -lpthread

.PHONY: run
run: epsilon
	./epsilon

epsilon: main.cpp epsilon.h
	${cc} -o $@ $<

clean:
	rm -f epsilon_test epsilon

