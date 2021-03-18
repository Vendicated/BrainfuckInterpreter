COMPILER=gcc
BFOUT=out/brainfuck
BFFLAGS=-Wall
A2BFOUT=out/ascii2brainfuck
A2BFFLAGS=-Wall -lm

all: build

build:
	${COMPILER} ${FLAGS} brainfuck.c -o ${BFOUT}
	${COMPILER} ${A2BFFLAGS} ascii2brainfuck.c -o ${A2BFOUT}

clean:
	rm -rf out/*

test: build
	out/brainfuck test.bf

testa2bf: build
	out/brainfuck Makefile

debug:
	${COMPILER} ${FLAGS} -g brainfuck.c -o ${BFOUT}
	gdb ${BFOUT}

debuga2bf:
	${COMPILER} ${A2BFFLAGS} -g ascii2brainfuck.c -o ${A2BFOUT}
	gdb ${A2BFOUT}
