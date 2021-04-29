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

#ifndef _BRAINFUCK_H_
#define _BRAINFUCK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct BRAINFUCK
{
    char *ptr;
    const char *cursor;
} BRAINFUCK;

BRAINFUCK *brainfuck_init();

void brainfuck_loads(BRAINFUCK *handle, char *content);
int brainfuck_loadf(BRAINFUCK *handle, FILE *fp);

int brainfuck_validate(BRAINFUCK *handle);
void brainfuck_evaluate(BRAINFUCK *handle);

void _brainfuck_go_to_closing_bracket(BRAINFUCK *handle);
void _brainfuck_go_to_opening_bracket(BRAINFUCK *handle);

#endif
