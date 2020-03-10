/*
** EPITECH PROJECT, 2019
** anim_back.c
** File description:
** anim back
*/

#include "my.h"

void back1(game_t *game)
{
    game->back.time_back = sfClock_getElapsedTime(game->back.c_back);
    game->back.sec_back = game->back.time_back.microseconds / 1000000.0f;
    if (game->back.sec_back > 0.1) {
        game->back.r_back.left += 1920;
        if (game->back.r_back.left >= 9600) {
            game->back.r_back.left = 0;
            game->back.r_back.top += 1053;
        }
        sfClock_restart(game->back.c_back);
        sfSprite_setTextureRect(game->back.s_back, game->back.r_back);
    }
}

void back2(game_t *game)
{
    game->back.time_back = sfClock_getElapsedTime(game->back.c_back);
    game->back.sec_back = game->back.time_back.microseconds / 1000000.0f;
    if (game->back.sec_back > game->back.cond_back2[game->back.i_back]) {
        game->back.r_back.left += 1920;
        if (game->back.r_back.left >= 9600) {
            game->back.r_back.left = 0;
            game->back.r_back.top += 1053;
        }
        sfClock_restart(game->back.c_back);
        sfSprite_setTextureRect(game->back.s_back, game->back.r_back);
        game->back.i_back++;
    }
}

void back3(game_t *game)
{
    game->back.time_back = sfClock_getElapsedTime(game->back.c_back);
    game->back.sec_back = game->back.time_back.microseconds / 1000000.0f;
    if (game->back.sec_back > 0.1) {
        game->back.r_back.left += 1920;
        if (game->back.r_back.left >= 9600) {
            game->back.r_back.left = 0;
            game->back.r_back.top += 1054;
        }
        sfClock_restart(game->back.c_back);
        sfSprite_setTextureRect(game->back.s_back, game->back.r_back);
        game->back.i_back++;
    }
}

bool clock_back(game_t *game)
{
    if (game->life == 3 && game->back.r_back.top < 3159) {
        back1(game);
        return (false);
    }
    if (game->life == 2 && game->back.i_back < 34) {
        back2(game);
        game->enm.enm_dead = 0;
        return (false);
    }
    if ((game->life == 1 && game->back.i_back < 35)
        || (game->life == 0 && game->back.i_back < 83)) {
        back3(game);
        game->enm.enm_dead = 0;
        return (false);
    }
    return (true);
}
