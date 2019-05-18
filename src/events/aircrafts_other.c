/*
** EPITECH PROJECT, 2019
** aircrafts_other
** File description:
** aircrafts_other
*/

#include "../../include/my_radar.h"

int test_aircraft_is_control(all_t *all, sfVector2f pos_aircraft)
{
    tower_t *tower = all->l_towers.first;

    while (tower) {
        if (pos_aircraft.x >= tower->coords.x - (WIN_WIDTH * tower->radius /
            100 / 2) &&
            pos_aircraft.x <= tower->coords.x + (WIN_WIDTH * tower->radius /
            100 / 2) &&
            pos_aircraft.y >= tower->coords.y - (WIN_WIDTH * tower->radius /
            100 / 2) &&
            pos_aircraft.y <= tower->coords.y + (WIN_WIDTH * tower->radius /
            100 / 2))
            return (1);
        tower = tower->next;
    }
    return (0);
}

int test_aircraft_land_on(aircraft_t *aircraft)
{
    if (aircraft->move_vect.x < 0) {
        if (aircraft->actual_pos.x > aircraft->arr_co.x)
            return (0);
    } else {
        if (aircraft->actual_pos.x < aircraft->arr_co.x)
            return (0);
    }
    if (aircraft->move_vect.y < 0) {
        if (aircraft->actual_pos.y > aircraft->arr_co.y)
            return (0);
    } else {
        if (aircraft->actual_pos.y < aircraft->arr_co.y)
            return (0);
    }
    return (1);
}

int check_all_aircraft(all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;

    while (aircraft) {
        if (!aircraft->end)
            return (0);
        aircraft = aircraft->next;
    }
    return (1);
}