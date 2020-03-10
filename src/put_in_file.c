/*
** EPITECH PROJECT, 2019
** put_in_file.c
** File description:
** put in file
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void put_in_file(char *file, char **tab)
{
    int fd = open(file, O_WRONLY | O_TRUNC);

    for (int i = 0; tab[i] != NULL; i++)
        write(fd, tab[i], my_strlen(tab[i]));
    close(fd);
}
