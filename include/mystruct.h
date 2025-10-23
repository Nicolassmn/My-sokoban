/*
** EPITECH PROJECT, 2023
** header
** File description:
** mystruct
*/

#pragma once

typedef struct coordinate_s {
    int player_x;
    int player_y;
    int x;
    int y;
    int old_x;
    int old_y;
} coordinate_t;

typedef struct game_s {
    char **map;
    int result;
    int objectif;
    int box;
    int test;
    int tmp_x;
    int tmp_y;
    coordinate_t co;
} game_t;
