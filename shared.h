#ifndef _BRAINFUCK_SHARED_H_
#define _BRAINFUCK_SHARED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(FILE *fp)
{
    char *out;
    int cont_size, read_size;

    fseek(fp, 0, SEEK_END);
    cont_size = ftell(fp);
    rewind(fp);

    out = (char *)malloc(sizeof(char) * (cont_size + 1));

    read_size = fread(out, sizeof(char), cont_size, fp);

    if (read_size != cont_size)
    {
        // Something went wrong while reading file
        free(out);
        out = NULL;
    }

    return out;
}

char *parse_args(int argc, char *argv[])
{
    char *out;
    FILE *fp;

    fp = fopen(argv[1], "r");
    if (fp)
    {
        out = read_file(fp);
        fclose(fp);
    }
    else
    {
        int size = 0;
        out = (char *)malloc(size);

        for (int i = 1; i <= argc - 1; i++)
        {
            out = (char *)realloc(out, (size + strlen(argv[i])));
            strcat(out, argv[i]);
            strcat(out, " ");
        }
    }

    return out;
}

#endif
