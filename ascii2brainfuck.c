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

#include "ascii2brainfuck.h"

#include <stdio.h>
#include <stdlib.h>
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
