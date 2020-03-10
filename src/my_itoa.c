/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** itoa
*/

#include <stdlib.h>
#include "my.h"

char *my_itoa(int nb)
{
    char *str = NULL;
    int stock = nb;
    int size = 0;

    if (stock <= 0)
        size++;
    for (; stock != 0; size++)
        stock = stock / 10;
    if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    str[size] = '\0';
    if (nb < 0)
        str[0] = '-';
    for (; (size > 0 && nb >= 0) || (size > 1 && nb < 0); size--) {
        str[size - 1] = ABS(nb % 10) + 48;
        nb = nb / 10;
    }
    return (str);
}
