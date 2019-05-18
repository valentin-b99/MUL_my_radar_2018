/*
** EPITECH PROJECT, 2019
** aircrafts
** File description:
** aircrafts
*/

#include "../../include/my_radar.h"

void set_vector(all_t *all, aircraft_t *aircraft)
{
    aircraft->move_vect.x = (aircraft->arr_co.x - aircraft->dep_co.x) /
    sqrt(pow(aircraft->arr_co.x - aircraft->dep_co.x, 2) +
    pow(aircraft->arr_co.y - aircraft->dep_co.y, 2)) / MAX_FPS *
    aircraft->speed;
    aircraft->move_vect.y = (aircraft->arr_co.y - aircraft->dep_co.y) /
    sqrt(pow(aircraft->arr_co.x - aircraft->dep_co.x, 2) +
    pow(aircraft->arr_co.y - aircraft->dep_co.y, 2)) / MAX_FPS *
    aircraft->speed;
}

void add_aircraft_chain(all_t *all, aircrafts_list_t *list, aircraft_t *info)
{
    aircraft_t *aircraft = malloc(sizeof(*aircraft));

    aircraft->dep_co = info->dep_co;
    aircraft->arr_co = info->arr_co;
    aircraft->actual_pos = aircraft->dep_co;
    aircraft->speed = info->speed;
    set_vector(all, aircraft);
    aircraft->time_dep = info->time_dep;
    aircraft->display = 0;
    aircraft->sprite = create_sprite(SP_AIRC_PATH, aircraft->dep_co);
    aircraft->hitbox = create_aircraft_hitbox(aircraft->dep_co);
    aircraft->end = 0;
    aircraft->next = list->first;
    list->nb += 1;
    list->first = aircraft;
}

void while_i(char *str, int *i)
{
    while (str[*i] >= '0' && str[*i] <= '9')
        *i += 1;
}

void add_aircraft(all_t *all, char *str, int *i)
{
    aircraft_t *info = malloc(sizeof(aircraft_t));

    *i += 2;
    info->dep_co.x = my_getnbr(str + *i);
    while_i(str, i);
    info->dep_co.y = my_getnbr(str + *i);
    *i += 1;
    while_i(str, i);
    info->arr_co.x = my_getnbr(str + *i);
    *i += 1;
    while_i(str, i);
    info->arr_co.y = my_getnbr(str + *i);
    *i += 1;
    while_i(str, i);
    info->speed = my_getnbr(str + *i);
    *i += 1;
    while_i(str, i);
    info->time_dep = my_getnbr(str + *i);
    add_aircraft_chain(all, &all->l_aircrafts, info);
    free(info);
}
