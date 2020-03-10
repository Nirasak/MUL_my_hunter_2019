/*
** EPITECH PROJECT, 2019
** init_struct.c
** File description:
** init struct
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void set_window(game_t *game)
{
    sfVideoMode vm = {1920, 1080, 32};

    game->wdw = sfRenderWindow_create(
        vm, "my_hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->wdw, 120);
    sfRenderWindow_setVerticalSyncEnabled(game->wdw, sfTrue);
    game->status = MENU;
    game->life = 3;
}

void create_music(game_t *game)
{
    game->music = sfMusic_createFromFile("./music/music.ogg");
    sfMusic_setVolume(game->music, 50);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
}

bool init_struct(game_t *game)
{
    char *buff = NULL;
    size_t len = 0;

    my_putstr("Please enter your name:\n");
    create_opt(&game->opt);
    if (create_ldb(&game->ldb) == false)
        return (false);
    if (create_menu(&game->menu) == false)
        return (false);
    if (create_enm(&game->enm) == false)
        return (false);
    if (create_back(&game->back) == false)
        return (false);
    create_music(game);
    while (getline(&buff, &len, stdin) == 0);
    game->enm.pseudo = my_strdup(buff);
    free(buff);
    set_window(game);
    return (true);
}
