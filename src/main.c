/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my_radar.h"

void set_var_actual_pos_aircrafts(all_t *all)
{
    aircraft_t *aircraft = all->l_aircrafts.first;

    while (aircraft) {
        if (aircraft->display) {
            aircraft->actual_pos.x += aircraft->move_vect.x;
            aircraft->actual_pos.y += aircraft->move_vect.y;
        }
        aircraft = aircraft->next;
    }
}

void my_radar(all_t *all, char *file)
{
    create_main_structure(all, file);
    while (sfRenderWindow_isOpen(all->window)) {
        analyse_events(all);
        sfRenderWindow_drawSprite(all->window, all->sprites.background, NULL);
        draw_towers(all);
        draw_aircrafts(all);
        draw_timer(all);
        sfRenderWindow_display(all->window);
        if (check_all_aircraft(all))
            sfRenderWindow_close(all->window);
        set_var_actual_pos_aircrafts(all);
    }
    destroy_all(all);
}

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));
    char *file;

    if (ac < 2 || ac > 2) {
        my_putstr(ERR_ARG_1);
        my_putstr(int_to_char(ac - 1));
        my_putstr(ERR_ARG_2);
        return (84);
    }
    if (ac > 1 && !my_strcmp(av[1], CMD_HELP)) {
        my_putstr(MSG_HELP);
        return (0);
    }
    if (read_file(av[1], &file) == 84 || !test_valid_file(file))
        return (84);
    my_radar(all, file);
    free(all);
    return (0);
}