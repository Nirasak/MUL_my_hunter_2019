/*
** EPITECH PROJECT, 2019
** loop_game.c
** File description:
** loop game
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"

void my_events_game(game_t *game, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(game->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    for (int i = 0; i <= MAX(game->enm.enm_dead / 7); i++) {
        if (event.type == sfEvtMouseButtonPressed
            && p_mouse.x >= game->enm.p_enm[i].x + 10
            && p_mouse.x <= game->enm.p_enm[i].x + game->enm.r_enm[i].width - 10
            && p_mouse.y >= game->enm.p_enm[i].y
            && p_mouse.y <= game->enm.p_enm[i].y
            + game->enm.r_enm[i].height - 10) {
            init_new_enm(game, i);
            game->enm.enm_dead++;
            game->enm.score++;
        }
    }
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->back.s_back, NULL);
}

void init_game(game_t *game)
{
    game->life = 3;
    game->enm.score = 0;
    game->enm.enm_dead = 0;
    for (int i = 0; i < 20; i++) {
        game->enm.r_enm[i].top = 4;
        game->enm.r_enm[i].left = 4;
        sfSprite_setTextureRect(game->enm.s_enm[i], game->enm.r_enm[i]);
        init_new_enm(game, i);
    }
    game->back.r_back.top = 0;
    game->back.r_back.left = 0;
    sfSprite_setTexture(game->back.s_back, game->back.t_back, sfTrue);
    sfSprite_setTextureRect(game->back.s_back, game->back.r_back);
}

void loop_game(game_t *game)
{
    sfEvent event;

    init_game(game);
    while (game->status == GAME && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_game(game, event);
        if (game->life <= 0 && game->back.i_back >= 83)
            game->status = END;
        display_game(game);
        if (clock_back(game) == true)
            clock_enm(game);
        sfRenderWindow_display(game->wdw);
    }
    check_score(game);
}
