PREFIX ?= /usr/local

COMPILER=gcc
BFOUT=bin/brainfuck
BFFLAGS=-Wall
A2BFOUT=bin/ascii2brainfuck
A2BFFLAGS=-Wall -lm

.PHONY: install
install: build install-bf install-a2bf

all: build

build:
	mkdir -p bin
	${COMPILER} ${FLAGS} brainfuck.c -o ${BFOUT}
	${COMPILER} ${A2BFFLAGS} ascii2brainfuck.c -o ${A2BFOUT}

clean:
	rm -rf out/*

test: build
	out/brainfuck test.bf

test-a2bf: build
	out/brainfuck Makefile

debug:
	${COMPILER} ${FLAGS} -g brainfuck.c -o ${BFOUT}
	gdb ${BFOUT}

debug-a2bf:
	${COMPILER} ${A2BFFLAGS} -g ascii2brainfuck.c -o ${A2BFOUT}
	gdb ${A2BFOUT}

install-bf: bin/brainfuck
	mkdir -p $(PREFIX)/$(dir $<)
	install -m 0755 $< $(PREFIX)/$<

install-a2bf: bin/ascii2brainfuck
	mkdir -p $(PREFIX)/$(dir $<)
	install -m 0755 $< $(PREFIX)/$<
