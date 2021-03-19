#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "brainfuck.h"
#include "shared.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [FILE | TEXT...]\n", argv[0]);
        return 0;
    }

    BRAINFUCK *handle = brainfuck_init();
    char *input = parse_args(argc, argv);

    if (input == NULL)
    {
        fputs("Something went wrong while parsing the input", stderr);
        return 1;
    }

    brainfuck_loads(handle, input);

    if (brainfuck_validate(handle) != 0)
    {
        fputs("Invalid brainfuck.", stderr);
        return 1;
    }

    brainfuck_evaluate(handle);

    return 0;
}
