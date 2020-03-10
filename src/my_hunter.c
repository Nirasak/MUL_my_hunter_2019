/*
** EPITECH PROJECT, 2019
** my_hunter.c
** File description:
** hunter
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"

int my_hunter(game_t *game)
{
    srand(time(NULL));
    if (init_struct(game) == false)
        return (84);
    while (sfRenderWindow_isOpen(game->wdw)) {
        if (game->status == MENU)
            loop_menu(game);
        if (game->status == GAME)
            loop_game(game);
        if (game->status == OPTIONS)
            loop_opt(game);
        if (game->status == LDB)
            loop_ldb(game);
        if (game->status == END)
            loop_end(game);
    }
    destroy_struct(game);
    sfRenderWindow_destroy(game->wdw);
    return (0);
}
