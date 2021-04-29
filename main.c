/*
 * Brainfuck Interpreter
 * Copyright (C) 2021 Vendicated
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "main.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "ascii2brainfuck.h"
#include "brainfuck.h"

const char *LICENSE =
    "BrainfuckInterpreter 2.0 - "
    "Copyright (C) 2021 Vendicated\n"
    "This program comes with ABSOLUTELY NO WARRANTY\n"
    "This is free software, and you are welcome to redistribute it under the terms of the "
    "GNU General Public License 3 or later\n\n";

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "%s", LICENSE);
        fprintf(stderr, "Usage:\n  %s [encode|decode] [FILE | TEXT...]\n", argv[0]);
        return 0;
    }

    setlocale(LC_ALL, "C");

    char *mode = argv[1];

    if (strcmp(mode, "encode") == 0 || strcmp(mode, "e") == 0)
    {
        return to_brainfuck(argc, argv);
    }
    else if (strcmp(mode, "decode") == 0 || strcmp(mode, "d") == 0)
    {
        return eval(argc, argv);
    }
    else
    {
        fprintf(stderr, "Unknown operation %s\n", mode);
        return EXIT_FAILURE;
    }
}

int to_brainfuck(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "%s", LICENSE);
        fprintf(stderr, "Usage:\n  %s %s [FILE | TEXT...]\n", argv[0], argv[1]);
        return EXIT_SUCCESS;
    }

    char *input = parse_args(argc, argv);
    if (!input)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        return EXIT_FAILURE;
    }

    ascii_to_brainfuck(input);

    free(input);

    return EXIT_SUCCESS;
}

int eval(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "%s", LICENSE);
        fprintf(stderr, "Usage:\n  %s %s [FILE | TEXT...]\n", argv[0], argv[1]);
        return EXIT_SUCCESS;
    }

    char *input = parse_args(argc, argv);
    if (!input)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        return EXIT_FAILURE;
    }

    BRAINFUCK *handle = brainfuck_init();

    brainfuck_loads(handle, input);

    if (brainfuck_validate(handle) != 0)
    {
        fputs("Invalid brainfuck.", stderr);
        return EXIT_FAILURE;
    }

    brainfuck_evaluate(handle);

    free(input);

    return EXIT_SUCCESS;
}

char *read_file(FILE *fp)
{
    char *out;
    int cont_size, read_size;

    fseek(fp, 0, SEEK_END);
    cont_size = ftell(fp);
    rewind(fp);

    out = (char *)malloc(sizeof(char) * (cont_size + 1));
    if (!out)
        return NULL;

    read_size = fread(out, sizeof(char), cont_size, fp);

    out[read_size] = '\0';

    return out;
}

char *parse_args(int argc, char *argv[])
{
    char *out = NULL;
    FILE *fp;

    fp = fopen(argv[2], "r");
    if (fp)
    {
        out = read_file(fp);
        fclose(fp);
    }
    else
    {
        // Figure out required buffer size
        size_t size = 1;
        for (int i = 2; i < argc; i++)
        {
            size += strlen(argv[i]) + 1;
        }
        out = (char *)malloc(size);
        size = 0;

        for (int i = 2; i < argc; i++)
        {
            size += sprintf(out + size, "%s ", argv[i]);
        }

        // Remove last space
        out[--size] = '\0';
    }

    return out;
}
