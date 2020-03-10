/*
** EPITECH PROJECT, 2019
** anim_enm.c
** File description:
** anim enm
*/

#include <stdlib.h>
#include "my.h"

void init_new_enm(game_t *game, int i)
{
    game->enm.p_enm[i].x = rand() % 2 + 0;
    game->enm.p_enm[i].y = rand() % 994 + 0;
    if (game->enm.p_enm[i].x == 0) {
        game->enm.p_enm[i].x = -100 - (game->enm.enm_dead / 10) * 100;
        game->enm.mv_enm[i].x = 5;
    } else {
        game->enm.p_enm[i].x = 1930 + (game->enm.enm_dead / 10) * 100;
        game->enm.mv_enm[i].x = -5;
    }
    game->enm.mv_enm[i].y = rand() % 10 + -5;
    sfSprite_setPosition(game->enm.s_enm[i], game->enm.p_enm[i]);
}

void anim_enm(game_t *game, int i)
{
    if (game->enm.sec_enm[i] > 0.1) {
        game->enm.r_enm[i].left += 106;
        if (game->enm.r_enm[i].left > 400)
            game->enm.r_enm[i].left = 4;
        sfClock_restart(game->enm.c_enm[i]);
        sfSprite_setTextureRect(game->enm.s_enm[i], game->enm.r_enm[i]);
    }
}

void move_enm(game_t *game, int i)
{
    if (game->enm.sec_move[i] > 0.1) {
        if ((game->enm.p_enm[i].y <= 67 && game->enm.mv_enm[i].y < 0)
            || (game->enm.p_enm[i].y >= 990 && game->enm.mv_enm[i].y > 0))
            game->enm.mv_enm[i].y = -game->enm.mv_enm[i].y;
        game->enm.p_enm[i].x += game->enm.mv_enm[i].x;
        game->enm.p_enm[i].y += game->enm.mv_enm[i].y;
        sfSprite_setPosition(game->enm.s_enm[i], game->enm.p_enm[i]);
    }
}

void loose_life(game_t *game)
{
    game->life -= 1;
    sfClock_restart(game->back.c_back);
    if (game->life == 2) {
        game->back.i_back = 0;
        game->back.r_back.top = 0;
        sfSprite_setTexture(game->back.s_back, game->back.t_back2, sfTrue);
    }
    if (game->life == 1) {
        game->back.r_back.top = 0;
        game->back.r_back.left = 0;
        sfSprite_setTexture(game->back.s_back, game->back.t_back3, sfTrue);
    }
    for (int i = 0; i < 20; i++) {
        init_new_enm(game, i);
        if (game->life == 1) {
            game->enm.r_enm[i].top = 65;
            game->enm.r_enm[i].left = 4;
            sfSprite_setTextureRect(game->enm.s_enm[i], game->enm.r_enm[i]);
        }
    }
}

void clock_enm(game_t *game)
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
            || (game->enm.p_enm[i].x > 1930 && game->enm.mv_enm[i].x > 0))
            loose_life(game);
        sfRenderWindow_drawSprite(game->wdw, game->enm.s_enm[i], NULL);
    }
}
