/*
** EPITECH PROJECT, 2019
** print_descr.c
** File description:
** print_descr
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int print_descr(char *exe)
{
    my_putstr("USAGE\n    ");
    my_putstr(exe);
    my_putstr("\nDESCRIPTION\n");
    my_putstr("    The goal of this game is to kill as many enemies as\n");
    my_putstr("    you can before being banned from Epitech after taking\n");
    my_putstr("    three -42. Enjoy the game.\n");
    return (0);
}
