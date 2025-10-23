/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** algo_win_or_losse
*/

#include "mystruct.h"
#include "my.h"

static void blocked(int *block, game_t *games, int i, int j)
{
    if (MAP[i][j + 1] == '#' || MAP[i][j + 1] == 'X')
        *block += 1;
    else if (MAP[i][j - 1] == '#' || MAP[i][j - 1] == 'X')
        *block += 1;
}

static void check_looser(game_t *games, int *block, int i, int j)
{
    if (MAP[i][j] == 'X') {
        if (MAP[i + 1][j] == '#' || MAP[i + 1][j] == 'X') {
            blocked(block, games, i, j);
            return;
        }
        if (MAP[i - 1][j] == '#' || MAP[i - 1][j] == 'X')
            blocked(block, games, i, j);
    }
}

void algo_loose(game_t *games)
{
    int block = 0;

    for (int i = 0; MAP[i]; i++) {
        for (int j = 0; MAP[i][j]; j++)
            check_looser(games, &block, i, j);
    }
    if (games->box == block) {
        endwin();
        write(1, "LOOSER\n", 6);
        exit(0);
    }
}

void win_or_loose(game_t *games)
{
    if (games->objectif == 0) {
        endwin();
        write(1, "WIN\n", 4);
        exit(0);
    }
    algo_loose(games);
}
