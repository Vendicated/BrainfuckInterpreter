PREFIX ?= /usr/local

COMPILER=gcc
BFOUT=bin/brainfuck
BFFLAGS=-Wall
A2BFOUT=bin/ascii2brainfuck
A2BFFLAGS=-Wall -lm

all: build

.PHONY: install
install: build install-bf install-a2bf

build:
	mkdir -p bin
	${COMPILER} ${BFFLAGS} -s brainfuck.c -o ${BFOUT}
	${COMPILER} ${A2BFFLAGS} -s ascii2brainfuck.c -o ${A2BFOUT}

clean:
	rm -rf out/*

test: test-bf test-a2bf

test-bf: build
	${BFOUT} test.bf > /dev/null

test-a2bf: build
	${A2BFOUT} Makefile > /dev/null

debug: debug-bf debug-a2bf

debug-bf:
	${COMPILER} ${BFFLAGS} -fsanitize=address -g brainfuck.c -o ${BFOUT}

debug-a2bf:
	${COMPILER} ${A2BFFLAGS} -fsanitize=address -g ascii2brainfuck.c -o ${A2BFOUT}

install-bf: bin/brainfuck
	mkdir -p $(PREFIX)/$(dir $<)
	install -m 0755 $< $(PREFIX)/$<

install-a2bf: bin/ascii2brainfuck
	mkdir -p $(PREFIX)/$(dir $<)
	install -m 0755 $< $(PREFIX)/$<
