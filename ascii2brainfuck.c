#include <stdio.h>
#include <locale.h>
#include "shared.h"
#include "ascii2brainfuck.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [FILE | TEXT...]\n", argv[0]);
        return 0;
    }

    setlocale(LC_ALL, "C");

    char *input = parse_args(argc, argv);

    ascii_to_brainfuck(input);

    free(input);

    return 0;
}
