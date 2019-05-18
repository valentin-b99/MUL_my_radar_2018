/*
** EPITECH PROJECT, 2019
** towers
** File description:
** towers
*/

#include "../../include/my_radar.h"

void draw_towers(all_t *all)
{
    tower_t *tower = all->l_towers.first;
    sfVector2f pos;

    while (tower) {
        if (all->display_sprites) {
            pos.x = tower->coords.x - SP_TOWER_W / 2;
            pos.y = tower->coords.y - SP_TOWER_H / 2;
            sfSprite_setPosition(all->sprites.tower, pos);
            sfRenderWindow_drawSprite(all->window, all->sprites.tower, NULL);
        }
        if (all->display_hitbox) {
            sfCircleShape_setRadius(all->sprites.tower_radius,
            WIN_WIDTH * tower->radius / 100 / 2);
            pos.x = tower->coords.x - WIN_WIDTH * tower->radius / 100 / 2;
            pos.y = tower->coords.y - WIN_WIDTH * tower->radius / 100 / 2;
            sfCircleShape_setPosition(all->sprites.tower_radius, pos);
            sfRenderWindow_drawCircleShape(all->window,
            all->sprites.tower_radius, NULL);
        }
        tower = tower->next;
    }
}