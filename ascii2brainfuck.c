#include <stdio.h>
#include "shared.h"
#include "ascii2brainfuck.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [FILE | TEXT...]\n", argv[0]);
        return 0;
    }

    char *input = parse_args(argc, argv);

    ascii_to_brainfuck(input);

    return 0;
}
