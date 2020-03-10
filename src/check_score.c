/*
** EPITECH PROJECT, 2019
** check_score.c
** File description:
** check score
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy(char const *src, char *dest)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *new_score(game_t *game)
{
    char *str = NULL;
    char *str_score = my_itoa(game->enm.score);
    int size = my_strlen(game->enm.pseudo) + my_strlen(str_score);
    int i = 0;

    str = malloc(sizeof(char) * (size + 3));
    if (str == NULL)
        return (NULL);
    my_strcpy(game->enm.pseudo, str);
    for (; str[i] != '\n' && str[i] != '\0'; i++);
    str[i] = '=';
    str[i + 1] = '\0';
    my_strcat(str, str_score);
    for (; str[i] != '\n' && str[i] != '\0'; i++);
    str[i] = '\n';
    str[i + 1] = '\0';
    free(str_score);
    return (str);
}

void set_ldb_in_text(game_t *game)
{
    for (int i = 0; i < 10; i++) {
        sfText_setString(
            game->ldb.txt_ldb[i + 10], get_score(game->ldb.value_ldb[i]));
        get_name(game->ldb.value_ldb[i], game->ldb.txt_ldb[i]);
    }
}

void check_score(game_t *game)
{
    int i = 0;

    for (; i < 10; i++)
        if (game->enm.score > my_atoi(get_score(game->ldb.value_ldb[i]))) {
            break;
        }
    if (i == 10)
        return;
    for (int j = 9; j > i; j--) {
        free(game->ldb.value_ldb[j]);
        game->ldb.value_ldb[j] = my_strdup(game->ldb.value_ldb[j - 1]);
    }
    free(game->ldb.value_ldb[i]);
    game->ldb.value_ldb[i] = new_score(game);
    put_in_file("src/.leaderboard", game->ldb.value_ldb);
    set_ldb_in_text(game);
}
