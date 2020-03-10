/*
** EPITECH PROJECT, 2019
** set_back
** File description:
** set back
*/

#include <stdlib.h>
#include "my.h"

void init_sec_back2(back_t *back)
{
    back->cond_back2[0] = 0.1;
    back->cond_back2[1] = 0.5;
    for (int i = 2; i < 14; i++)
        back->cond_back2[i] = 0.02;
    back->cond_back2[14] = 0.4;
    back->cond_back2[15] = 0.8;
    for (int i = 16; i < 33; i++)
        back->cond_back2[i] = 0.02;
    back->cond_back2[33] = 0.8;
    back->i_back = 0;
}

void init_back(back_t *back)
{
    back->t_back = sfTexture_createFromFile("assets/back1.png", NULL);
    back->t_back2 = sfTexture_createFromFile("assets/back2.png", NULL);
    back->t_back3 = sfTexture_createFromFile("assets/back3.png", NULL);
    back->s_back = sfSprite_create();
    sfSprite_setTexture(back->s_back, back->t_back, sfTrue);
    back->p_back.x = 0;
    back->p_back.y = 0;
    sfSprite_setPosition(back->s_back, back->p_back);
    back->r_back.top = 0;
    back->r_back.left = 0;
    back->r_back.width = 1920;
    back->r_back.height = 1054;
    sfSprite_setTextureRect(back->s_back, back->r_back);
    back->c_back = sfClock_create();
    back->sec_back = 0;
    init_sec_back2(back);
}

void init_end(back_t *back)
{
    back->t_end = sfTexture_createFromFile("assets/end.png", NULL);
    back->p_end.x = 0;
    back->p_end.y = 0;
    back->r_end.top = 0;
    back->r_end.left = 0;
    back->r_end.width = 1920;
    back->r_end.height = 1080;
    back->s_end = sfSprite_create();
    sfSprite_setTexture(back->s_end, back->t_end, sfTrue);
    sfSprite_setPosition(back->s_end, back->p_end);
    sfSprite_setTextureRect(back->s_back, back->r_back);
}

bool create_back(back_t *back)
{
    back->cond_back2 = malloc(sizeof(float) * 35);
    if (back->cond_back2 == NULL)
        return (false);
    init_back(back);
    init_end(back);
    return (true);
}
