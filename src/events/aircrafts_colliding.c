/*
** EPITECH PROJECT, 2019
** aircrafts_colliding
** File description:
** aircrafts_colliding
*/

#include "../../include/my_radar.h"

int test_colliding_aircraft(sfVector2f aircraft1_pos, sfVector2f aircraft2_pos)
{
    if (aircraft1_pos.x >= aircraft2_pos.x &&
        aircraft1_pos.x <= aircraft2_pos.x + 20) {
            if (aircraft1_pos.y >= aircraft2_pos.y &&
                aircraft1_pos.y <= aircraft2_pos.y + 20)
                return (1);
            if (aircraft1_pos.y + 20 >= aircraft2_pos.y &&
                aircraft1_pos.y + 20 <= aircraft2_pos.y + 20)
                return (1);
    } else if (aircraft1_pos.x + 20 >= aircraft2_pos.x &&
        aircraft1_pos.x + 20 <= aircraft2_pos.x + 20) {
            if (aircraft1_pos.y >= aircraft2_pos.y &&
                aircraft1_pos.y <= aircraft2_pos.y + 20)
                return (1);
            if (aircraft1_pos.y + 20 >= aircraft2_pos.y &&
                aircraft1_pos.y + 20 <= aircraft2_pos.y + 20)
                return (1);
    }
    return (0);
}

int test_colliding_aircrafts(sfVector2f aircraft_pos, int i, all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;
    int j = 0;

    while (aircraft) {
        if (i != j && aircraft->display) {
            if (test_colliding_aircraft(aircraft->actual_pos, aircraft_pos)) {
                aircraft->display = 0;
                aircraft->end = 1;
                return (1);
            }
        }
        aircraft = aircraft->next;
        j++;
    }
    return (0);
}

void colliding_aircrafts(all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;
    int i = 0;

    while (aircraft) {
        if (!test_aircraft_is_control(all, aircraft->actual_pos) &&
            test_colliding_aircrafts(aircraft->actual_pos, i, all)) {
            aircraft->display = 0;
            aircraft->end = 1;
        }
        aircraft = aircraft->next;
        i++;
    }
}