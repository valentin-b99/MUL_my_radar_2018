/*
** EPITECH PROJECT, 2018
** structures
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef struct tower_s
{
    sfVector2f coords;
    int radius;
    struct tower_s *next;
} tower_t;

typedef struct aircraft_s
{
    sfVector2f dep_co;
    sfVector2f arr_co;
    int speed;
    sfVector2f move_vect;
    int time_dep;
    int display;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    int end;
    sfVector2f actual_pos;
    struct aircraft_s *next;
} aircraft_t;

typedef struct towers_list_s
{
    int nb;
    struct tower_s *first;
} towers_list_t;

typedef struct aircrafts_list_s
{
    int nb;
    struct aircraft_s *first;
} aircrafts_list_t;

typedef struct sprites_s
{
    sfSprite *background;
    sfSprite *tower;
    sfCircleShape *tower_radius;
    sfText *timer;
} sprites_t;

typedef struct all_s
{
    sfRenderWindow *window;
    sprites_t sprites;
    sfClock *g_clock;
    int display_hitbox;
    int display_sprites;
    aircrafts_list_t l_aircrafts;
    towers_list_t l_towers;
} all_t;

#endif /* !STRUCTURES_H_ */