/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

int main(int ac, char **av, char **env)
{
    game_t game;

    if (env[0] == NULL)
        return (84);
    if (ac == 1)
        my_hunter(&game);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_descr(av[0]));
    return (84);
}
