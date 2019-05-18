/*
** EPITECH PROJECT, 2018
** config
** File description:
** config
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#include "my_radar.h"

/**
*? Commands
*/
#define CMD_HELP "-h" /* help */

/**
*? Terminal Texts
*/
#define ERR_ARG_1 BOLD RED "Bad arguments: "
#define ERR_ARG_2 " given but 1 is required\n" RESET "Retry with -h\n"
#define ERR_CHAR BOLD RED "Error: This file contain not autorized characters.\
\n" RESET
#define ERR_FILE BOLD RED "Error: No such file.\n" RESET
#define ERR_EMPTY_FILE BOLD RED "Error: This file is empty.\n" RESET
#define ERR_FILE_A BOLD RED "Error: This file is not in the right format.\n"\
RESET "The lines with A must contain 6 number after this.\n"
#define ERR_FILE_T BOLD RED "Error: This file is not in the right format.\n"\
RESET "The lines with T must contain 3 number after this.\n"
#define MSG_HELP "Air traffic simulation panel.\n\n" UNDERLINE "USAGE" \
RESET "\n\t./my_radar [OPTIONS] path_to_script\n\tpath_to_script The path to \
the script file.\n\n" UNDERLINE "OPTIONS" RESET "\n\t-h print the usage and \
quit.\n\n" UNDERLINE "USER INTERACTIONS" RESET "\n\t'L' key enable/disable \
hitboxes and areas.\n\t'S' key enable/disable sprites.\n"

/**
*? Images Folders Paths
*/
#define FLD_IMG_PTH "./img" /* Path for the main folder */

/**
*? Window
*/
#define WIN_WIDTH 1920 /* Window width */
#define WIN_HEIGHT 1080 /* Window height */
#define MAX_FPS 60 /* Window Framerate Limit */
#define WIN_TITLE "My Radar" /* Window title */

/**
*? Sprites Paths
*/
#define SP_BG_PATH FLD_IMG_PTH "/map.png"
#define SP_AIRC_PATH FLD_IMG_PTH "/aircraft.png"
#define SP_TOWER_PATH FLD_IMG_PTH "/tower.png"

/**
*? Sprites size
*/
#define SP_TOWER_W 29
#define SP_TOWER_H 50

#endif /* !CONFIG_H_ */