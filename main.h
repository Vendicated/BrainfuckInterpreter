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

#ifndef _BRAINFUCK_MAIN_H_
#define _BRAINFUCK_MAIN_H_

#include <stdio.h>

int to_brainfuck(int argc, char *argv[]);
int eval(int argc, char *argv[]);

char *read_file(FILE *fp);
char *parse_args(int argc, char *argv[]);

#endif
