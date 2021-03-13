//
// Created by CABANTOUS corto on 25/02/2021.
//




/*!
 * \file prof.c
 * \brief Teacher Source File
 * \authors corto
 * \version 1
 * \date 02/03/2021
 *
 * Teacher function implementation.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "prof.h"
#include "map.h"
#include "GAME.h"
#include "DS.h"
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

/*!
 * \fn int init_prof(Prof * prof, int x, int y, int length, int width, int speed, char * path)
 * \brief This function initialize the Teacher : position of the Teacher's top left corner (x,y), size (length, width), speed and also the path to the Teacher's image.
 *
 * \param [in] Teacher a pointer on the character
 * \param [in] x the Teacher's abscissa
 * \param [in] y the Teacher's ordinate
 * \param [in] length the Teacher's length
 * \param [in] width the Teacher's width
 * \param [in] path the path to the Teacher's image
 * \return 1 if the initialization went right.
 */

void init_prof(Prof * prof, int x, int y, int length, int width, int speed, char * path){
    prof->x_prof=x;
    prof->y_prof=y;
    prof->long_prof=length;
    prof->larg_prof=width;
    prof->speed_prof=speed;
    prof->image_prof = malloc(strlen(path));
    strcpy(prof->image_prof, path);
}



int  profmove(Prof *prof, int predirection,SDL_Rect * prof_rect, MAP * map, DS *exam){

	switch (predirection)
            {
                case 0:
					prof->y_prof -= prof->speed_prof;
                    break;
                case 1:
                    prof->y_prof += prof->speed_prof;
                    break;
                case 2:
                    prof->x_prof -= prof->speed_prof;
                    break;
				case 3:
                    prof->x_prof += prof->speed_prof;
                    break;
            }
	calculpointsprof(prof);
	// prof collision detection
    int collision = testpositionprof(prof,map,exam); // return 0 if nothing, 1 if wall or bounds
        // set the positions following collision variable
        switch (collision)
        {
            case 0:
                prof_rect->x = (int) prof->x_prof;
                prof_rect->y = (int) prof->y_prof;
                break;
            case 1:
                prof->y_prof = prof_rect->y;
                prof->x_prof = prof_rect->x;
				fflush(stdin);
                predirection = rand()%4;
                break;
        }
	
	
	
	return predirection;
}


void calculpointsprof(Prof * prof){
	//calculate 3 others points of rectangle
	prof->x_hr = prof->x_prof + prof->larg_prof ;
	prof->y_hr = prof->y_prof;
	prof->x_ll = prof->x_prof;
	prof->y_ll = prof->y_prof + prof->long_prof;
	prof->x_lr = prof->x_prof + prof->larg_prof;
	prof->y_lr = prof->y_prof + prof->long_prof;
	
}

int testpositionprof(Prof * prof,MAP * map, DS *exam){
	int testbound = testboundsprof(prof); //0 if nothing,  1 if bounds
	int testwall = testmapcolprof(prof,map,exam); //0 if nothing, 1 if wall
	if(testbound==1){
        return 1;
	}
	else if(testwall == 1){
        return 1;
	}
	return 0;
}

int testboundsprof(Prof * prof){
    if((prof->x_prof <= 0) || (prof->y_prof <= 0) || (prof->x_prof >= WINDOW_WIDTH - prof->larg_prof) || (prof->y_prof >= WINDOW_HEIGHT - prof->long_prof-20)) {
        return 1;
    }
    return 0;
}

int testmapcolprof(Prof * prof,  MAP * map, DS * exam){
	int testhl = testpointwithmap(prof->x_prof,prof->y_prof,map,exam);
	int testhr = testpointwithmap(prof->x_hr,prof->y_hr,map,exam) ;
	int testll = testpointwithmap(prof->x_ll,prof->y_ll,map,exam) ;
	int testlr = testpointwithmap(prof->x_lr,prof->y_lr,map,exam) ;
	if(testhl==1 || testhr==1 || testll==1 || testlr==1){
		return 1;
	}
	else return 0;
}




