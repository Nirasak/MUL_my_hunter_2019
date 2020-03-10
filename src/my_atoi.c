/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** atoi
*/

#include "my.h"

int my_atoi(char *av)
{
    int nbr = 0;
    int neg = 1;
    int a = 0;

    if (av[a] == '-') {
        neg = -1;
        a = a + 1;
    }
    for (; av[a] != '\0' && av[a] != '\n'; a = a + 1)
        nbr = nbr * 10 + av[a] - 48;
    return (nbr * neg);
}
