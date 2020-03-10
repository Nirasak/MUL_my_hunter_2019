/*
** EPITECH PROJECT, 2019
** loop_menu.c
** File description:
** loop menu
*/

#include "my.h"

void new_enm(game_t *game, int i)
{
    init_new_enm(game, i);
    if (game->life == 1) {
        game->enm.r_enm[i].top = 65;
        game->enm.r_enm[i].left = 4;
        sfSprite_setTextureRect(game->enm.s_enm[i], game->enm.r_enm[i]);
    }
}

void clock_enm_in_menu(game_t *game)
{
    for (int i = 0; i <= MAX(game->enm.enm_dead / 7); i++) {
        game->enm.time_enm[i] = sfClock_getElapsedTime(game->enm.c_enm[i]);
        game->enm.sec_enm[i] = game->enm.time_enm[i].microseconds / 1000000.0f;
        game->enm.time_move[i] = sfClock_getElapsedTime(game->enm.c_move[i]);
        game->enm.sec_move[i] =
            game->enm.time_move[i].microseconds / 1000000.0f;
        anim_enm(game, i);
        move_enm(game, i);
        if ((game->enm.p_enm[i].x < -100 && game->enm.mv_enm[i].x < 0)
            || (game->enm.p_enm[i].x > 1930 && game->enm.mv_enm[i].x > 0)) {
            sfClock_restart(game->back.c_back);
            new_enm(game, i);
        }
        sfRenderWindow_drawSprite(game->wdw, game->enm.s_enm[i], NULL);
    }
}

void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->menu.s_menu, NULL);
    clock_enm_in_menu(game);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->wdw, game->menu.s_butt[i], NULL);
}

void loop_menu(game_t *game)
{
    sfEvent event;

    while (game->status == MENU && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_menu(game, event);
        display_menu(game);
        sfRenderWindow_display(game->wdw);
    }
}
