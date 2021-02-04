# Ven's Brainfuck Interpreter

My Brainfuck implementation according to the spec described here <https://en.wikipedia.org/wiki/Brainfuck#Language_design>

## Interpreter

This interprets any given Brainfuck code.

Usage: Compile, then run

```bash
./brainfuck.out < BrainfuckSamples/HelloWorld.bf
```

## Ascii to Brainfuck converter

A simple python script to convert any given Ascii Text into Brainfuck code

Usage:

```bash
python3 convert_to_brainfuck.py Hello World > myBrainfuckCode.bf

# Prettify brainfuck output
python3 convert_to_brainfuck.py Hello World --pretty > myBrainfuckCode.bf
```
