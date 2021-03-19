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
    char *out = NULL;
    FILE *fp;

    fp = fopen(argv[1], "r");
    if (fp)
    {
        out = read_file(fp);
        fclose(fp);
    }
    else
    {
        size_t size = 1;
        for (int i = 1; i < argc; i++)
        {
            size += strlen(argv[i]) + 1;
        }
        out = malloc(size);
        size = 0;

        for (int i = 1; i < argc; i++)
        {
            size += sprintf(out + size, "%s ", argv[i]);
        }

        // Remove last space
        out[--size] = '\0';
    }

    return out;
}

#endif
