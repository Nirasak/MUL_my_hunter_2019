/*
** EPITECH PROJECT, 2019
** set_enm.c
** File description:
** set enm
*/

#include <stdlib.h>
#include "my.h"

void set_move_enm(enm_t *enm)
{
    for (int i = 0; i < 20; i++) {
        enm->p_enm[i].x = rand() % 2 + 0;;
        enm->p_enm[i].y = rand() % 994 + 0;
        if (enm->p_enm[i].x == 0) {
            enm->p_enm[i].x = -100;
            enm->mv_enm[i].x = 5;
        } else {
            enm->p_enm[i].x = 1930;
            enm->mv_enm[i].x = -5;
        }
        enm->mv_enm[i].y = rand() % 10 - 5;
        sfSprite_setPosition(enm->s_enm[i], enm->p_enm[i]);
    }
}

void set_enm(enm_t *enm)
{
    enm->t_enm = sfTexture_createFromFile("assets/enm.png", NULL);
    for (int i = 0; i < 20; i++) {
        enm->s_enm[i] = sfSprite_create();
        sfSprite_setTexture(enm->s_enm[i], enm->t_enm, sfTrue);
        enm->r_enm[i].top = 4;
        enm->r_enm[i].left = 4;
        enm->r_enm[i].width = 100;
        enm->r_enm[i].height = 55;
        sfSprite_setTextureRect(enm->s_enm[i], enm->r_enm[i]);
        enm->c_enm[i] = sfClock_create();
        enm->sec_enm[i] = 0;
        enm->c_move[i] = sfClock_create();
        enm->sec_move[i] = 0;
    }
    enm->enm_dead = 0;
}

bool malloc_enm(enm_t *enm)
{
    enm->s_enm = malloc(sizeof(sfSprite *) * 20);
    enm->p_enm = malloc(sizeof(sfVector2f) * 20);
    enm->r_enm = malloc(sizeof(sfIntRect) * 20);
    enm->c_enm = malloc(sizeof(sfClock *) * 20);
    enm->time_enm = malloc(sizeof(sfTime) * 20);
    enm->sec_enm = malloc(sizeof(float) * 20);
    enm->c_move = malloc(sizeof(sfClock *) * 20);
    enm->time_move = malloc(sizeof(sfTime) * 20);
    enm->sec_move = malloc(sizeof(float) * 20);
    enm->mv_enm = malloc(sizeof(sfVector2f) * 20);
    if (enm->s_enm == NULL || enm->p_enm == NULL || enm->r_enm == NULL
        || enm->c_enm == NULL || enm->time_enm == NULL || enm->sec_enm == NULL
        || enm->c_move == NULL || enm->time_move == NULL
        || enm->sec_move == NULL || enm->mv_enm == NULL)
        return (false);
    return (true);
}

bool create_enm(enm_t *enm)
{
    enm->score = 0;
    if (malloc_enm(enm) == false)
        return (false);
    set_enm(enm);
    set_move_enm(enm);
    enm->font = sfFont_createFromFile("font/sans_serif.ttf");
    enm->txt_score = sfText_create();
    sfText_setFont(enm->txt_score, enm->font);
    sfText_setColor(enm->txt_score, sfWhite);
    sfText_setCharacterSize(enm->txt_score, 62);
    enm->p_score.x = 1600;
    enm->p_score.y = 904;
    sfText_setPosition(enm->txt_score, enm->p_score);
    return (enm);
}
