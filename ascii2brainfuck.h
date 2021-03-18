#ifndef _ASCII_2_BRAINFUCK_H_
#define _ASCII_2_BRAINFUCK_H_

#include <stdio.h>
#include <math.h>

void print_char(char character, int times)
{
    for (int i = 0; i < times; i++)
    {
        putchar(character);
    }
}

void ascii_to_brainfuck(const char *text)
{
    char current = 0;
    while (*text)
    {
        char sign = *text >= current ? '+' : '-';
        char diff = abs(*text - current);

        if (diff == 0)
        {
            putchar('.');
        }
        else if (diff < 10)
        {
            print_char(sign, diff);
            putchar('.');
        }
        else
        {
            int closest_sqn = round(sqrt(diff));
            int rest = diff - (pow(closest_sqn, 2));

            putchar('>');
            print_char('+', closest_sqn);
            printf("[<");
            print_char(sign, closest_sqn);
            printf(">-]<");
            print_char(rest > 0 ? sign : sign == '-' ? '+'
                                                     : '-',
                       abs(rest));
            putchar('.');
        }

        current = *text;
        text++;
    }
}

#endif
