/*
** EPITECH PROJECT, 2019
** set_menu.c
** File description:
** set menu
*/

#include <stdlib.h>
#include "my.h"

void set_buttons(menu_t *menu)
{
    menu->t_butt = sfTexture_createFromFile("assets/buttons_menu.png", NULL);
    menu->p_butt[0].y = 445;
    menu->p_butt[1].y = 541;
    menu->p_butt[2].y = 636;
    menu->p_butt[3].y = 731;
    for (int i = 0; i < 4; i++) {
        menu->s_butt[i] = sfSprite_create();
        menu->r_butt[i].top = 0;
        menu->r_butt[i].left = 0 + 520 * i;
        menu->r_butt[i].width = 520;
        menu->r_butt[i].height = 84;
        menu->p_butt[i].x = 692;
        sfSprite_setTexture(menu->s_butt[i], menu->t_butt, sfTrue);
        sfSprite_setTextureRect(menu->s_butt[i], menu->r_butt[i]);
        sfSprite_setPosition(menu->s_butt[i], menu->p_butt[i]);
    }
}

void set_menu(menu_t *menu)
{
    menu->t_menu = sfTexture_createFromFile("assets/menu.png", NULL);
    menu->s_menu = sfSprite_create();
    menu->r_menu.top = 120;
    menu->r_menu.left = 0;
    menu->r_menu.width = 1920;
    menu->r_menu.height = 1200;
    menu->p_menu.x = 0;
    menu->p_menu.y = 0;
    sfSprite_setTexture(menu->s_menu, menu->t_menu, sfTrue);
    sfSprite_setTextureRect(menu->s_menu, menu->r_menu);
    sfSprite_setPosition(menu->s_menu, menu->p_menu);
}

bool create_menu(menu_t *menu)
{
    menu->s_butt = malloc(sizeof(sfSprite *) * 4);
    menu->r_butt = malloc(sizeof(sfIntRect) * 4);
    menu->p_butt = malloc(sizeof(sfVector2f) * 4);
    if (menu->s_butt == NULL || menu->r_butt == NULL)
        return (false);
    set_menu(menu);
    set_buttons(menu);
    return (true);
}
