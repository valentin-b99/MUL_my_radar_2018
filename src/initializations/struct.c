/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#include "../../include/my_radar.h"

void create_lists(all_t *all, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'T')
            add_tower(all, str, &i);
        if (str[i] == 'A')
            add_aircraft(all, str, &i);
    }
}

void create_main_structure(all_t *all, char *file)
{
    create_windows(&all->window);
    init_towers_list(&all->l_towers);
    init_aircrafts_list(&all->l_aircrafts);
    create_sprites(all);
    create_lists(all, file);
    all->g_clock = sfClock_create();
    all->display_hitbox = 1;
    all->display_sprites = 1;
}