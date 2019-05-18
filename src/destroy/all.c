/*
** EPITECH PROJECT, 2018
** all
** File description:
** all
*/

#include "../../include/my_radar.h"

void destroy_all_aircrafts(all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;

    while (aircraft) {
        sfSprite_destroy(aircraft->sprite);
        sfRectangleShape_destroy(aircraft->hitbox);
        aircraft = aircraft->next;
    }
}

void destroy_all(all_t *all)
{
    sfSprite_destroy(all->sprites.background);
    sfSprite_destroy(all->sprites.tower);
    sfCircleShape_destroy(all->sprites.tower_radius);
    destroy_all_aircrafts(all);
    sfRenderWindow_destroy(all->window);
}