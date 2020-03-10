/*
** EPITECH PROJECT, 2019
** set_ldb.c
** File description:
** set ldb
*/

#include <stdlib.h>
#include "my.h"

void set_ldb(ldb_t *ldb)
{
    ldb->t_ldb = sfTexture_createFromFile("assets/ldb.png", NULL);
    ldb->s_ldb = sfSprite_create();
    ldb->r_ldb.top = 0;
    ldb->r_ldb.left = 0;
    ldb->r_ldb.width = 1300;
    ldb->r_ldb.height = 700;
    ldb->p_ldb.x = 300;
    ldb->p_ldb.y = 150;
    sfSprite_setTexture(ldb->s_ldb, ldb->t_ldb, sfTrue);
    sfSprite_setTextureRect(ldb->s_ldb, ldb->r_ldb);
    sfSprite_setPosition(ldb->s_ldb, ldb->p_ldb);
}

void get_name(char *str, sfText *txt)
{
    char *dest = my_strdup(str);
    int i = 0;

    if (dest == NULL) {
        sfText_setString(txt, "ERROR MALLOC");
        return;
    }
    for (; dest[i] != '=' && dest[i] != '\0'; i++);
    dest[i] = '\0';
    sfText_setString(txt, dest);
    free(dest);
}

char *get_score(char *str)
{
    int i = 0;

    for (; str[i] != '=' && str[i] != '\0'; i++);
    return (&str[i + 1]);
}

void set_font_ldb(ldb_t *ldb, int size)
{
    ldb->p_value_ldb.y = 150;
    ldb->font_ldb = sfFont_createFromFile("font/sans_serif.ttf");
    for (int i = 0; i < size; i++) {
        ldb->txt_ldb[i + 10] = sfText_create();
        sfText_setFont(ldb->txt_ldb[i + 10], ldb->font_ldb);
        sfText_setColor(ldb->txt_ldb[i + 10], sfWhite);
        sfText_setString(ldb->txt_ldb[i + 10], get_score(ldb->value_ldb[i]));
        sfText_setCharacterSize(ldb->txt_ldb[i + 10], 50);
        ldb->p_value_ldb.x = 1400;
        sfText_setPosition(ldb->txt_ldb[i + 10], ldb->p_value_ldb);
        ldb->p_value_ldb.x = 500;
        ldb->txt_ldb[i] = sfText_create();
        sfText_setFont(ldb->txt_ldb[i], ldb->font_ldb);
        sfText_setColor(ldb->txt_ldb[i], sfWhite);
        get_name(ldb->value_ldb[i], ldb->txt_ldb[i]);
        sfText_setCharacterSize(ldb->txt_ldb[i], 50);
        sfText_setPosition(ldb->txt_ldb[i], ldb->p_value_ldb);
        ldb->p_value_ldb.y += 71;
    }
}

bool create_ldb(ldb_t *ldb)
{
    int size = 0;

    set_ldb(ldb);
    ldb->value_ldb = get_from_file("src/.leaderboard");
    if (ldb->value_ldb == NULL)
        return (false);
    for (; ldb->value_ldb[size] != NULL; size++);
    ldb->txt_ldb = malloc(sizeof(sfText *) * (size * 2));
    if (ldb->txt_ldb == NULL)
        return (false);
    set_font_ldb(ldb, size);
    return (true);
}
