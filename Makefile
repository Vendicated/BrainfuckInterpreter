COMPILER=gcc
FLAGS="-Wall"
OUTFILE="out/brainfuck"

all: build

build:
	${COMPILER} ${FLAGS} brainfuck.c -o ${OUTFILE}

clean:
	rm -rf out/*

test: build
	out/brainfuck test.bf
