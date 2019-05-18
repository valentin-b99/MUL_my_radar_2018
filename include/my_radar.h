/*
** EPITECH PROJECT, 2018
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
#define MY_RADAR_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "my_functions.h"
#include "config.h"
#include "structures.h"

/**
*? Text colors
*/
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"


/**
*? src/create/sprites.c
*/
sfSprite *create_sprite(char *, sfVector2f);
sfRectangleShape *create_aircraft_hitbox(sfVector2f);
sfText *create_text(char *, int, sfVector2f);
void create_sprites(all_t *);

/**
*? src/create/window.c
*/
void create_windows(sfRenderWindow **);

/**
*? src/destroy/all.c
*/
void destroy_all_aircrafts(all_t *);
void destroy_all(all_t *);

/**
*? src/draw/aircrafts.c
*/
void draw_sprites_hbox(all_t *, aircraft_t *);
void draw_aircrafts(all_t *);

/**
*? src/draw/timer.c
*/
float calc_elapsed_sec(sfClock *);
char *calc_elapsed_time_for_display(sfClock *);
void draw_timer(all_t *);

/**
*? src/draw/towers.c
*/
void draw_towers(all_t *);

/**
*? src/events/aircrafts_colliding.c
*/
int test_colliding_aircraft(sfVector2f, sfVector2f);
int test_colliding_aircrafts(sfVector2f, int, all_t *);
void colliding_aircrafts(all_t *);

/**
*? src/events/aircrafts_other.c
*/
int test_aircraft_is_control(all_t *, sfVector2f);
int test_aircraft_land_on(aircraft_t *);
int check_all_aircraft(all_t *);

/**
*? src/events/all.c
*/
void analyse_events(all_t *);

/**
*? src/file/read.c
*/
int test_char(char);
int count_word(char *, int);
int test_valid_file(char *);
int read_file(char *, char **);

/**
*? src/initializations/aircrafts.c
*/
void set_vector(all_t *, aircraft_t *);
void add_aircraft_chain(all_t *, aircrafts_list_t *, aircraft_t *);
void while_i(char *, int *);
void add_aircraft(all_t *, char *, int *);

/**
*? src/initializations/struct_chain.c
*/
void init_towers_list(towers_list_t *);
void init_aircrafts_list(aircrafts_list_t *);

/**
*? src/initializations/struct.c
*/
void init_towers_list(towers_list_t *);
void init_aircrafts_list(aircrafts_list_t *);
void add_tower_chain(towers_list_t *, sfVector2f, int);
void create_main_structure(all_t *, char *);

/**
*? src/initializations/towers.c
*/
void add_tower_chain(towers_list_t *, sfVector2f, int);
void add_tower(all_t *, char *, int *);

/**
*? src/main.c
*/
void set_var_actual_pos_aircrafts(all_t *);
void my_radar(all_t *, char *);

#endif /* !MY_RADAR_H_ */
