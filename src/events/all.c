/*
** EPITECH PROJECT, 2018
** all
** File description:
** all
*/

#include "../../include/my_radar.h"

void analyse_events(all_t *all)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->window);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(all->window);
        if (event.key.code == sfKeyL && all->display_hitbox &&
            event.type == sfEvtKeyPressed)
            all->display_hitbox = 0;
        else if (event.key.code == sfKeyL && !all->display_hitbox &&
            event.type == sfEvtKeyPressed)
            all->display_hitbox = 1;
        if (event.key.code == sfKeyS && all->display_sprites &&
            event.type == sfEvtKeyPressed)
            all->display_sprites = 0;
        else if (event.key.code == sfKeyS && !all->display_sprites &&
            event.type == sfEvtKeyPressed)
            all->display_sprites = 1;
    }
}