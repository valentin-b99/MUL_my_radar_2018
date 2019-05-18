/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include "../../include/my_radar.h"

void create_windows(sfRenderWindow **window)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};

    *window = sfRenderWindow_create(mode, WIN_TITLE,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(*window, MAX_FPS);
}