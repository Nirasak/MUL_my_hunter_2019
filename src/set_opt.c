/*
** EPITECH PROJECT, 2019
** set_opt.c
** File description:
** set opt
*/

#include "my.h"

void set_back_opt(opt_t *opt)
{
    opt->s_opt = sfSprite_create();
    opt->r_opt.top = 0;
    opt->r_opt.left = 0;
    opt->r_opt.width = 1920;
    opt->r_opt.height = 1080;
    opt->p_opt.x = 0;
    opt->p_opt.y = 0;
    sfSprite_setTexture(opt->s_opt, opt->t_opt, sfTrue);
    sfSprite_setTextureRect(opt->s_opt, opt->r_opt);
    sfSprite_setPosition(opt->s_opt, opt->p_opt);
}

void set_vol(opt_t *opt)
{
    opt->s_vol = sfSprite_create();
    opt->s_change_vol = sfSprite_create();
    opt->r_vol.top = 100;
    opt->r_vol.left = 0;
    opt->r_vol.width = 1200;
    opt->r_vol.height = 60;
    opt->p_vol.x = 310;
    opt->p_vol.y = 180;
    sfSprite_setTexture(opt->s_vol, opt->t_vol, sfTrue);
    sfSprite_setTextureRect(opt->s_vol, opt->r_vol);
    sfSprite_setPosition(opt->s_vol, opt->p_vol);
    opt->r_change_vol.top = 500;
    opt->r_change_vol.left = 0;
    opt->r_change_vol.width = 500;
    opt->r_change_vol.height = 18;
    opt->p_change_vol.x = 510;
    opt->p_change_vol.y = 201;
    sfSprite_setTexture(opt->s_change_vol, opt->t_vol, sfTrue);
    sfSprite_setTextureRect(opt->s_change_vol, opt->r_change_vol);
    sfSprite_setPosition(opt->s_change_vol, opt->p_change_vol);
}

void set_return(opt_t *opt)
{
    opt->s_return = sfSprite_create();
    opt->r_return.top = 0;
    opt->r_return.left = 1300;
    opt->r_return.width = 520;
    opt->r_return.height = 84;
    opt->p_return.x = 80;
    opt->p_return.y = 900;
    sfSprite_setTexture(opt->s_return, opt->t_vol, sfTrue);
    sfSprite_setTextureRect(opt->s_return, opt->r_return);
    sfSprite_setPosition(opt->s_return, opt->p_return);
}

void create_opt(opt_t *opt)
{
    opt->t_opt = sfTexture_createFromFile("assets/opt.png", NULL);
    opt->t_vol = sfTexture_createFromFile("assets/sound.png", NULL);
    opt->status_vol = 0;
    set_back_opt(opt);
    set_vol(opt);
    set_return(opt);
}
