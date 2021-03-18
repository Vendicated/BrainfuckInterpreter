#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "brainfuck.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [FILE | TEXT...]\n", argv[0]);
        return 0;
    }

    BRAINFUCK *handle;
    FILE *fp;

    handle = brainfuck_init();

    fp = fopen(argv[1], "r");
    if (fp)
    {
        brainfuck_loadf(handle, fp);
        fclose(fp);
    }
    else
    {
        char *input = (char *)malloc(sizeof(char *) * (argc - 1) + 1);
        for (int i = 1; i < argc; i++)
        {
            strcat(input, argv[i]);
        }

        brainfuck_loads(handle, input);
    }

    if (brainfuck_validate(handle) != 0)
    {
        puts("Invalid brainfuck.");
        return 1;
    }

    brainfuck_evaluate(handle);

    return 0;
}
