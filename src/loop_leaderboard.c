/*
** EPITECH PROJECT, 2019
** loop_leaderboard.c
** File description:
** loop leaderboard
*/

#include "my.h"

void my_events_ldb(game_t *game, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    my_events_opt3(game, event, p_mouse);
}

void display_ldb(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_opt, NULL);
    sfRenderWindow_drawSprite(game->wdw, game->ldb.s_ldb, NULL);
    for (int i = 0; i < 20; i++)
        sfRenderWindow_drawText(game->wdw, game->ldb.txt_ldb[i], NULL);
    sfRenderWindow_drawSprite(game->wdw, game->opt.s_return, NULL);
}

void loop_ldb(game_t *game)
{
    sfEvent event;

    while (game->status == LDB && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_ldb(game, event);
        display_ldb(game);
        sfRenderWindow_display(game->wdw);
    }
}
