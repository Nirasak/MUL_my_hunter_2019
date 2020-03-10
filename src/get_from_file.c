/*
** EPITECH PROJECT, 2019
** get_from_file.c
** File description:
** get from file
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    return (my_strcpy(src, dest));
}

char **extract_from_file(char *file, int len)
{
    char **tab = malloc(sizeof(char *) * (len + 1));
    FILE *fd = fopen(file, "r");
    char *buff = NULL;
    size_t size = 0;
    int i = 0;

    if (tab == NULL || fd == NULL)
        return (NULL);
    for (; getline(&buff, &size, fd) > 0; i++)
        tab[i] = my_strdup(buff);
    tab[i] = NULL;
    free(buff);
    fclose(fd);
    return (tab);
}

int nb_lines_file(char *file)
{
    FILE *fd = fopen(file, "r");
    char *buff = NULL;
    size_t size = 0;
    int len = 0;

    if (fd == NULL)
        return (-1);
    for (; getline(&buff, &size, fd) > 0; len++);
    free(buff);
    fclose(fd);
    return (len);
}

char **get_from_file(char *file)
{
    int size = nb_lines_file(file);

    if (size < 0)
        return (NULL);
    return (extract_from_file(file, size));
}
