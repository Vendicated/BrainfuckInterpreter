# Ven's Brainfuck Interpreter

My Brainfuck implementation according to the spec described here <https://en.wikipedia.org/wiki/Brainfuck#Language_design>

## Installation

The simplest way is to just grab precompiled binaries from the [releases tab](https://github.com/Vendicated/BrainfuckInterpreter/releases/latest)

### From Source

1. `git clone https://github.com/Vendicated/Brainfuck-Interpreter`
2. `cd Brainfuck-Interpreter`
3. `sudo make install` to install to /usr/local/bin or `make install PREFIX=/custom/dir` to install to /custom/dir

## Interpreter

This interprets any given Brainfuck code

Usage:

```bash
brainfuck decode [FILE | TEXT...]
```

Example:

```bash
$ brainfuck decode samples/HelloWorld.bf
Hello World!
```

## Ascii to Brainfuck converter

This converts plain ascii text to Brainfuck

Usage:

```bash
brainfuck encode [FILE | TEXT...]
```

Example:

```bash
$ brainfuck encode Hello World!
>++++++++[<++++++++>-]<++++++++.>++....
```
