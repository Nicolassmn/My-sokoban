/*
** EPITECH PROJECT, 2023
** header
** File description:
** my_popup
*/

#include "mystruct.h"
#include "my.h"

static void search_player(game_t *games, int i)
{
    for (int j = 0; MAP[i][j]; j++) {
        if (MAP[i][j] == 'P') {
            CO.player_x = j;
            CO.player_y = i;
        }
        if (MAP[i][j] == 'X')
            games->box++;
        if (MAP[i][j] == 'O')
            games->objectif++;
    }
}

static void init_error(game_t *games)
{
    if (CO.player_y == -1 && CO.player_x == -1) {
    endwin();
    write(1, "Player invalid\n", 15);
    exit(84);
    }
    if (games->box < games->objectif || games->objectif == 0) {
    endwin();
    write(1, "Map invalid\n", 12);
    exit(84);
    }
}

static void load_map(FILE *map, game_t *games)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, map);
    int i = 0;

    while (read != -1) {
        MAP[i] = my_strdup(line);
        CO.y = i;
        i++;
        read = getline(&line, &len, map);
    }
    CO.y++;
    for (int i = 0; MAP[i]; i++)
        search_player(games, i);
    MAP[CO.y] = NULL;
    init_error(games);
}

static void action_keyboard(game_t *games, FILE *map)
{
    int ch = getch();

    switch (ch) {
        case 27:
        case 'a':
            endwin();
            exit(0);
        case 32:
            rewind(map);
            load_map(map, games);
            break;
        default:
            move_player(games, ch);
    }
}

void game(FILE *map, game_t *games)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    load_map(map, games);
    while (1) {
        clear();
        refresh();
        for (int i = 0; MAP[i]; i++)
            mvprintw(LINES / 2 + i, COLS / 2, MAP[i]);
        refresh();
        action_keyboard(games, map);
        win_or_loose(games);
    }
    endwin();
}

void init(game_t *games, struct stat *info_map)
{
    games->map = malloc(sizeof(char *) * info_map->st_size + 1);
    games->box = 0;
    games->result = 0;
    games->test = 0;
    games->objectif = 0;
    CO.player_x = -1;
    CO.player_y = -1;
    CO.x = 0;
    CO.y = 0;
    CO.old_x = 0;
    CO.old_y = 0;
}

int main(int argc, char **argv)
{
    FILE *map = fopen(argv[1], "r");
    game_t games;
    struct stat info_map;

    if (argc != 2 && stat(argv[1], &info_map) != -1)
        return 84;
    else if (my_strcmp(argv[1], "-h") == 0)
        return (description("description.txt"));
    if (!map) {
        perror("fopen");
        return 84;
    }
    init(&games, &info_map);
    game(map, &games);
    for (int i = 0; games.map[i]; i++)
        free(games.map[i]);
    free(games.map);
    fclose(map);
    return 0;
}
