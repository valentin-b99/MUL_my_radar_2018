/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/my_functions.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * my_strlen(dest));
    
    tmp = my_strcpy(tmp, dest);
    dest = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1));
    for (int i = 0; tmp[i] != '\0'; i++)
        dest[i] = tmp[i];
    for (int i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + my_strlen(src)] = '\0';
    return (dest);
}
