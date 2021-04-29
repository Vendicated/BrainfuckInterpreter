PREFIX ?= /usr/local

CC=gcc
CFLAGS=-Wall -lm

.PHONY: bin/brainfuck bin/debug clean install
build: bin/brainfuck
debug: bin/debug

bin/brainfuck:
	mkdir -p bin
	${CC} ${CFLAGS} *.c -o bin/brainfuck

bin/debug:
	mkdir -p bin
	${CC} ${CFLAGS} -fsanitize=address -g *.c -o bin/debug

clean:
	rm -rf bin

install: bin/brainfuck
	mkdir -p $(PREFIX)/$(dir $<)
	install -m 0755 $< $(PREFIX)/$<
