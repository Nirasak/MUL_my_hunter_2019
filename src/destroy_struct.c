/*
** EPITECH PROJECT, 2019
** destroy_game.c
** File description:
** destroy game
*/

#include <stdlib.h>
#include "my.h"

void free_struct(game_t *game)
{
    free(game->enm.s_enm);
    free(game->enm.p_enm);
    free(game->enm.r_enm);
    free(game->enm.c_enm);
    free(game->enm.time_enm);
    free(game->enm.sec_enm);
    free(game->enm.c_move);
    free(game->enm.time_move);
    free(game->enm.sec_move);
    free(game->enm.mv_enm);
    free(game->back.cond_back2);
    free(game->menu.s_butt);
    free(game->menu.r_butt);
    free(game->menu.p_butt);
    free(game->enm.pseudo);
    for (int i = 0; game->ldb.value_ldb[i] != NULL; i++)
        free(game->ldb.value_ldb[i]);
    free(game->ldb.value_ldb);
    free(game->ldb.txt_ldb);
}

void destroy_struct2(game_t *game)
{
    sfTexture_destroy(game->ldb.t_ldb);
    sfSprite_destroy(game->ldb.s_ldb);
    sfFont_destroy(game->ldb.font_ldb);
    for (int i = 0; i < 20; i++)
        sfText_destroy(game->ldb.txt_ldb[i]);
    sfTexture_destroy(game->opt.t_opt);
    sfTexture_destroy(game->opt.t_vol);
    sfSprite_destroy(game->opt.s_opt);
    sfSprite_destroy(game->opt.s_vol);
    sfSprite_destroy(game->opt.s_change_vol);
    sfSprite_destroy(game->opt.s_return);
    sfTexture_destroy(game->back.t_end);
    sfSprite_destroy(game->back.s_end);
    sfFont_destroy(game->enm.font);
    sfText_destroy(game->enm.txt_score);
}

void destroy_struct(game_t *game)
{
    sfMusic_destroy(game->music);
    sfTexture_destroy(game->enm.t_enm);
    for (int i = 0; i < 20; i++) {
        sfSprite_destroy(game->enm.s_enm[i]);
        sfClock_destroy(game->enm.c_enm[i]);
        sfClock_destroy(game->enm.c_move[i]);
    }
    sfTexture_destroy(game->back.t_back);
    sfTexture_destroy(game->back.t_back2);
    sfTexture_destroy(game->back.t_back3);
    sfSprite_destroy(game->back.s_back);
    sfClock_destroy(game->back.c_back);
    sfTexture_destroy(game->menu.t_menu);
    sfTexture_destroy(game->menu.t_butt);
    sfSprite_destroy(game->menu.s_menu);
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(game->menu.s_butt[i]);
    destroy_struct2(game);
    free_struct(game);
}
