/*
** EPITECH PROJECT, 2019
** aircrafts
** File description:
** aircrafts
*/

#include "../../include/my_radar.h"

void draw_sprites_hbox(all_t *all, aircraft_t *aircraft)
{
    if (all->display_hitbox)
        sfRenderWindow_drawRectangleShape(all->window, aircraft->hitbox, NULL);
    if (all->display_sprites)
        sfRenderWindow_drawSprite(all->window, aircraft->sprite, NULL);
}

void draw_aircrafts(all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;

    while (aircraft) {
        if (calc_elapsed_sec(all->g_clock) >= aircraft->time_dep)
            aircraft->display = 1;
        if (test_aircraft_land_on(aircraft)) {
            aircraft->display = 0;
            aircraft->end = 1;
        }
        colliding_aircrafts(all);
        if (aircraft->display) {
            draw_sprites_hbox(all, aircraft);
            sfSprite_move(aircraft->sprite, aircraft->move_vect);
            sfRectangleShape_move(aircraft->hitbox, aircraft->move_vect);
        }
        aircraft = aircraft->next;
    }
}