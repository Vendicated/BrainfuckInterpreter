# Ven's Brainfuck Interpreter

My Brainfuck implementation according to the spec described here <https://en.wikipedia.org/wiki/Brainfuck#Language_design>

## Building

Simply run `make`. That's it. If you're on windows, welp :D

## Interpreter

This interprets any given Brainfuck code

Usage:

```bash
brainfuck [FILE | TEXT...]
```

Example:

```bash
$ brainfuck samples/HelloWorld.bf
Hello World!
```

## Ascii to Brainfuck converter

This converts plain ascii text to Brainfuck

Usage:

```bash
ascii2brainfuck [FILE | TEXT...]
```

Example:

```bash
$ ascii2brainfuck Hello World\!
>++++++++[<++++++++>-]<++++++++.>++....
```
