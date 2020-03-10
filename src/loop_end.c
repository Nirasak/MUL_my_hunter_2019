/*
** EPITECH PROJECT, 2019
** loop_end.c
** File description:
** loop end
*/

#include <stdlib.h>
#include "my.h"

void my_events_end(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->wdw);
    if (event.type == sfEvtKeyReleased
        || event.type == sfEvtMouseButtonReleased) {
        game->back.r_end.left = 0;
        sfSprite_setTextureRect(game->back.s_end, game->back.r_end);
        game->status = MENU;
    }
}

void anim_back(game_t *game)
{
    game->back.time_back = sfClock_getElapsedTime(game->back.c_back);
    game->back.sec_back = game->back.time_back.microseconds / 1000000.0f;
    if (game->back.sec_back > 0.5 && game->back.r_end.left < 7680) {
        game->back.r_end.left += 1920;
        sfClock_restart(game->back.c_back);
        sfSprite_setTextureRect(game->back.s_end, game->back.r_end);
    }
}

void display_end(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->back.s_end, NULL);
    if (game->back.r_end.left >= 7680)
        sfRenderWindow_drawText(game->wdw, game->enm.txt_score, NULL);
}

void loop_end(game_t *game)
{
    sfEvent event;
    char *temp_score = my_itoa(game->enm.score);

    sfClock_restart(game->back.c_back);
    sfText_setString(game->enm.txt_score, temp_score);
    free(temp_score);
    while (game->status == END && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_end(game, event);
        anim_back(game);
        display_end(game);
        sfRenderWindow_display(game->wdw);
    }
}
