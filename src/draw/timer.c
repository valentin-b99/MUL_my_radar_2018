/*
** EPITECH PROJECT, 2019
** timer
** File description:
** timer
*/

#include "../../include/my_radar.h"

float calc_elapsed_sec(sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    return (time.microseconds / 1000000.0);
}

char *calc_elapsed_time_for_display(sfClock *clock)
{
    float el_time = calc_elapsed_sec(clock);
    int min = 0;
    int sec = 0;
    char *result = malloc(sizeof(char) * 5);

    while (el_time - 60 * min > 60)
        min += 1;
    sec = el_time - 60 * min;
    if (min < 10)
        result = "0";
    else
        result = "";
    result = my_strcat(result, int_to_char(min));
    result = my_strcat(result, " : ");
    if (sec < 10)
        result = my_strcat(result, "0");
    result = my_strcat(result, int_to_char(sec));
    return (result);
}

void draw_timer(all_t *all)
{
    sfText_setString(all->sprites.timer,
    calc_elapsed_time_for_display(all->g_clock));
    sfRenderWindow_drawText(all->window, all->sprites.timer, NULL);
}