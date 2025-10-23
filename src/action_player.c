/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** action_player
*/

#include "mystruct.h"
#include "my.h"

static int coo_letter(game_t *games, int x, int y)
{
    if (MAP[y][x] == 'O') {
        CO.old_x = x;
        CO.old_y = y;
        return 1;
    }
    return 0;
}

static void orientation_move(game_t *games, int x, int y)
{
    if (coo_letter(games, x, y) == 1) {
        games->tmp_x = CO.old_x;
        games->tmp_y = CO.old_y;
    }
    MAP[y][x] = 'X';
    if (MAP[games->tmp_y][games->tmp_x] == 'X') {
        games->objectif -= 1;
        games->tmp_x = 0;
        games->tmp_y = 0;
    }
}

static void move_box(game_t *games, int direction, int x, int y)
{
    int tmp_x = x;
    int tmp_y = y;

    y = UP ? y - 1 : y;
    y = DOWN ? y + 1 : y;
    x = RIGHT ? x + 1 : x;
    x = LEFT ? x - 1 : x;
    if (MAP[y][x] == ' ' || MAP[y][x] == 'O') {
        orientation_move(games, x, y);
        MAP[tmp_y][tmp_x] = 'P';
    } else {
        MAP[CO.player_y][CO.player_x] = 'P';
        return;
    }
    CO.player_x = tmp_x;
    CO.player_y = tmp_y;
}

static void condition_move(game_t *games, int x, int y, int direction)
{
    if (MAP[y][x] == '#')
        return;
    if (MAP[y][x] == 'X') {
        MAP[CO.player_y][CO.player_x] = ' ';
        move_box(games, direction, x, y);
    } else if (MAP[y][x] == 'O' || MAP[y][x] != '#') {
        MAP[CO.player_y][CO.player_x] = ' ';
        coo_letter(games, x, y);
        MAP[y][x] = 'P';
        CO.player_x = x;
        CO.player_y = y;
    }
    if (MAP[CO.old_y][CO.old_x] == ' ')
        MAP[CO.old_y][CO.old_x] = 'O';
}

void move_player(game_t *games, int direction)
{
    int x = CO.player_x;
    int y = CO.player_y;

    switch (direction) {
        case KEY_UP:
            y--;
            break;
        case KEY_DOWN:
            y++;
            break;
        case KEY_LEFT:
            x--;
            break;
        case KEY_RIGHT:
            x++;
            break;
        default:
            return;
    }
    condition_move(games, x, y, direction);
}
