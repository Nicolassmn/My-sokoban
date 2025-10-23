/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <math.h>
#include "mystruct.h"

#define UP direction == KEY_UP
#define DOWN direction == KEY_DOWN
#define RIGHT direction == KEY_RIGHT
#define LEFT direction == KEY_LEFT
#define MAP games->map
#define CO games->co

void move_player(game_t *games, int direction);
void win_or_loose(game_t *games);
int description(char *filename);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
