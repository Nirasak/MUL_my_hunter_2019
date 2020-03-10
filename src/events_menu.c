/*
** EPITECH PROJECT, 2019
** events_menu.c
** File description:
** events menu
*/

#include "my.h"

void press_button(game_t *game, sfEvent event, int i)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (i == 0)
            game->status = GAME;
        if (i == 1)
            game->status = OPTIONS;
        if (i == 2)
            game->status = LDB;
        if (i == 3)
            sfRenderWindow_close(game->wdw);
        game->menu.r_butt[i].top = 0;
    } else if (
        event.type == sfEvtMouseButtonPressed
        || game->menu.r_butt[i].top == 180)
        game->menu.r_butt[i].top = 180;
    else
        game->menu.r_butt[i].top = 90;
    sfSprite_setTextureRect(game->menu.s_butt[i], game->menu.r_butt[i]);
}

void my_events_menu2(game_t *game, sfEvent event, sfVector2i p_mouse)
{
    for (int i = 0; i <= MAX(game->enm.enm_dead / 7); i++) {
        if (event.type == sfEvtMouseButtonPressed
            && p_mouse.x >= game->enm.p_enm[i].x + 10
            && p_mouse.x <= game->enm.p_enm[i].x + game->enm.r_enm[i].width - 10
            && p_mouse.y >= game->enm.p_enm[i].y
            && p_mouse.y <= game->enm.p_enm[i].y
            + game->enm.r_enm[i].height - 10) {
            init_new_enm(game, i);
            game->enm.enm_dead++;
        }
    }
}

void my_events_menu(game_t *game, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    for (int i = 0; i < 4; i++) {
        if (p_mouse.x >= game->menu.p_butt[i].x
            && p_mouse.x <= game->menu.p_butt[i].x + game->menu.r_butt[i].width
            && p_mouse.y >= game->menu.p_butt[i].y
            && p_mouse.y <= game->menu.p_butt[i].y
            + game->menu.r_butt[i].height) {
            press_button(game, event, i);
        }
        else {
            game->menu.r_butt[i].top = 0;
            sfSprite_setTextureRect(game->menu.s_butt[i], game->menu.r_butt[i]);
        }
    }
    my_events_menu2(game, event, p_mouse);
}
