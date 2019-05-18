/*
** EPITECH PROJECT, 2018
** sprites
** File description:
** sprites
*/

#include "../../include/my_radar.h"

sfSprite *create_sprite(char *path, sfVector2f position)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}

sfRectangleShape *create_aircraft_hitbox(sfVector2f position)
{
    sfVector2f size = {20, 20};
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    return (rect);
}

sfText *create_text(char *text, int size, sfVector2f position)
{
    sfText *e_text = sfText_create();

    sfText_setString(e_text, text);
    sfText_setFont(e_text, sfFont_createFromFile("./font/GROBOLD.ttf"));
    sfText_setCharacterSize(e_text, size);
    sfText_setPosition(e_text, position);
    return (e_text);
}

void create_sprites(all_t *all)
{
    sfVector2f pos = {0, 0};
    
    all->sprites.background = create_sprite(SP_BG_PATH, pos);
    all->sprites.tower = create_sprite(SP_TOWER_PATH, pos);
    all->sprites.tower_radius = sfCircleShape_create();
    sfCircleShape_setRadius(all->sprites.tower_radius, 0);
    sfCircleShape_setFillColor(all->sprites.tower_radius, sfTransparent);
    sfCircleShape_setOutlineColor(all->sprites.tower_radius, sfBlue);
    sfCircleShape_setOutlineThickness(all->sprites.tower_radius, 2.5);
    pos.x = 1820;
    all->sprites.timer = create_text("", 25, pos);
    sfText_setOutlineThickness(all->sprites.timer, 2);
}