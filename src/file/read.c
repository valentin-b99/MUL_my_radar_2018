/*
** EPITECH PROJECT, 2018
** read
** File description:
** read
*/

#include "../../include/my_radar.h"

int test_char(char c)
{
    if (c == ' ')
        return (1);
    if (c == '\n')
        return (1);
    if (c == 'A')
        return (1);
    if (c == 'T')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int count_word(char *str, int pos)
{
    int nbw = 0;

    for (int i = pos; str[i] && str[i] != '\n'; i++) {
        if (test_char(str[i]) &&
            (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == 0))
            nbw++;
    }
    return (nbw);
}

int test_valid_file(char *file)
{
    if (file[0] == 0) {
        my_putstr(ERR_EMPTY_FILE);
        return (0);
    }
    for (int i = 0; file[i]; i++) {
        if (!test_char(file[i])) {
            my_putstr(ERR_CHAR);
            return (0);
        }
        if (file[i] == 'A' && count_word(file, i) != 7) {
            my_putstr(ERR_FILE_A);
            return (0);
        }
        if (file[i] == 'T' && count_word(file, i) != 4) {
            my_putstr(ERR_FILE_T);
            return (0);
        }
    }
    return (1);
}

int read_file(char *path, char **buff)
{
    int len;
    int offset = 0;
    int file = open(path, O_RDONLY);
    struct stat st;

    if (file == -1) {
        my_putstr(ERR_FILE);
        return (84);
    }
    stat(path, &st);
    *buff = malloc(sizeof(char) * (st.st_size + 1));
    while ((len = read(file, (*buff) + offset, (st.st_size + 1) - offset)) > 0)
        offset = offset + len;
    (*buff)[offset] = '\0';
    close(file);
    return (0);
}