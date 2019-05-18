/*
** EPITECH PROJECT, 2019
** struct_chain
** File description:
** struct_chain
*/

#include "../../include/my_radar.h"

void init_towers_list(towers_list_t *list)
{
    list->nb = 0;
    list->first = NULL;
}

void init_aircrafts_list(aircrafts_list_t *list)
{
    list->nb = 0;
    list->first = NULL;
}