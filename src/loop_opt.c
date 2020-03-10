/*
** EPITECH PROJECT, 2019
** loop_opt.c
** File description:
** loop opt
*/

#include "my.h"

void display_opt(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_opt, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_vol, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_change_vol, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_return, NULL);
}

void loop_opt(game_t *game)
{
    sfEvent event;

    while (game->status == OPTIONS && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_opt(game, event);
        display_opt(game);
        sfRenderWindow_display(game->wdw);
    }
}
