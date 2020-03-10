/*
** EPITECH PROJECT, 2019
** events_opt.c
** File description:
** events options
*/

#include "my.h"

void my_events_opt4(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        game->opt.r_return.top = 0;
        game->status = MENU;
    } else if (
        event.type == sfEvtMouseButtonPressed
        || game->opt.r_return.top == 180)
        game->opt.r_return.top = 180;
    else
        game->opt.r_return.top = 90;
}

void my_events_opt3(game_t *game, sfEvent event, sfVector2i p_mouse)
{
    if (p_mouse.x >= game->opt.p_return.x
        && p_mouse.x <= game->opt.p_return.x + game->opt.r_return.width
        && p_mouse.y >= game->opt.p_return.y
        && p_mouse.y <= game->opt.p_return.y + game->opt.r_return.height)
        my_events_opt4(game, event);
    else
        game->opt.r_return.top = 0;
    sfSprite_setTextureRect(game->opt.s_return, game->opt.r_return);
}

void my_events_opt2(game_t *game, sfVector2i p_mouse)
{
    if (game->opt.status_vol == 1) {
        game->opt.r_change_vol.width = p_mouse.x - 510;
        if (p_mouse.x - 510 < 0)
            game->opt.r_change_vol.width = 0;
        if (p_mouse.x - 510 > 1510)
            game->opt.r_change_vol.width = 1000;
        sfSprite_setTextureRect(game->opt.s_change_vol, game->opt.r_change_vol);
        sfMusic_setVolume(game->music, game->opt.r_change_vol.width / 10);
        if (game->opt.r_change_vol.width <= 1000)
            game->opt.r_vol.top = 0;
        if (game->opt.r_change_vol.width <= 666)
            game->opt.r_vol.top = 100;
        if (game->opt.r_change_vol.width <= 333)
            game->opt.r_vol.top = 200;
        if (game->opt.r_change_vol.width == 0)
            game->opt.r_vol.top = 300;
        sfSprite_setTextureRect(game->opt.s_vol, game->opt.r_vol);
    }
}

void my_events_opt(game_t *game, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    if (event.type == sfEvtMouseButtonPressed
        && p_mouse.x >= game->opt.p_change_vol.x
        && p_mouse.x <= game->opt.p_change_vol.x + 1000
        && p_mouse.y >= game->opt.p_change_vol.y
        && p_mouse.y <= game->opt.p_change_vol.y
        + game->opt.r_change_vol.height) {
        game->opt.status_vol = 1;
    }
    if (event.type == sfEvtMouseButtonReleased)
        game->opt.status_vol = 0;
    my_events_opt2(game, p_mouse);
    my_events_opt3(game, event, p_mouse);
}
