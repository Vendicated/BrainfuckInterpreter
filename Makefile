COMPILER=gcc
FLAGS="-Wall"

all: build

build:
	${COMPILER} ${FLAGS} brainfuck.c -o out/brainfuck

clean:
	rm -rf out/*
