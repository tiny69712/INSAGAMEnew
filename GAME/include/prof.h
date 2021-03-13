//
// Created by CABANTOUS corto on 18/02/2021.
//



/*!
 * \file prof.h
 * \brief Teacher Header File
 * \authors  Corto
 * \version 1
 * \date 25/02/2021
 *
 * Teacher structure and functions definiton.
 *
 */

#ifndef GAME_INSA_PROJECT_PROF_H
#define GAME_INSA_PROJECT_PROF_H

#include "map.h"
#include "DS.h"
/*!
 * \struct Prof
 * \brief Teacher structure
 */

typedef struct {
    int x_prof; /**< Position : abscissa */
    int y_prof; /**< Position : ordinate */
    int long_prof; /**< Size : length */
    int larg_prof; /**< Size : width */
    int speed_prof; /**< Teacher speed */
    char * image_prof; /**< Source image of the character. */
	int x_hr; 	/**< Position : x hight-right point */
	int y_hr; 	/**< Position : y hight-right point */
	int x_ll; 	/**< Position : x low-left point */
	int y_ll; 	/**< Position : y low-left point */
	int x_lr; 	/**< Position : x low-right point */
	int y_lr;	/**< Position : y low-right point */
} Prof;

void init_prof(Prof * prof, int x, int y, int length, int width, int speed, char * path);
int profmove(Prof * prof, int predirection,SDL_Rect * prof_rect, MAP * map, DS *exam);
void calculpointsprof(Prof * prof);
int testpositionprof(Prof * prof,MAP * map, DS *exam);
int testboundsprof(Prof * prof);
int testmapcolprof(Prof * prof,  MAP * map, DS *exam);
#endif /*GAME_INSA_PROJECT_Prof_H*/



