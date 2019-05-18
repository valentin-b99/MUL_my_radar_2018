/*
** EPITECH PROJECT, 2019
** towers
** File description:
** towers
*/

#include "../../include/my_radar.h"

void add_tower_chain(towers_list_t *list, sfVector2f coords, int radius)
{
    tower_t *tower = malloc(sizeof(*tower));

    tower->coords = coords;
    tower->radius = radius;
    tower->next = list->first;
    list->nb += 1;
    list->first = tower;
}

void add_tower(all_t *all, char *str, int *i)
{
    sfVector2f coords;

    *i += 2;
    coords.x = my_getnbr(str + *i);
    while (str[*i] >= '0' && str[*i] <= '9')
        *i += 1;
    coords.y = my_getnbr(str + *i);
    *i += 1;
    while (str[*i] >= '0' && str[*i] <= '9')
        *i += 1;
    add_tower_chain(&all->l_towers, coords, my_getnbr(str + *i));
}