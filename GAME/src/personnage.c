/*
// Created by Lucile on 25/02/2021.
*/

/*!
 * \file personnage.c
 * \brief Character Source File
 * \authors Lucile
 * \version 1
 * \date 02/03/2021
 *
 * Character function implementation.
 *
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "personnage.h"

/*!
 * \fn int init_pers(Personnage * character, int x, int y, int length, int width, int speed, char * path)
 * \brief This function initialize the character : position of the character's top left corner (x,y), size (length, width), speed and also the path to the character's image.
 *
 * \param [in] character a pointer on the character
 * \param [in] x the character's abscissa
 * \param [in] y the character's ordinate
 * \param [in] length the character's length
 * \param [in] width the character's width
 * \param [in] path the path to the character's image
 * \return 1 if the initialization went right.
 */

void init_pers(Personnage * character, int x, int y, int length, int width, int speed, char * path){
    character->x_pers=x;
    character->y_pers=y;
    character->long_pers=length;
    character->larg_pers=width;
    character->speed_pers=speed;
    character->image_pers = malloc(strlen(path));
    strcpy(character->image_pers, path);
}

void calculpointspers(Personnage * character){
	//calculate 3 others points of rectangle
	character->x_hr = character->x_pers + character->larg_pers ;
	character->y_hr = character->y_pers;
	character->x_ll = character->x_pers;
	character->y_ll = character->y_pers + character->long_pers;
	character->x_lr = character->x_pers + character->larg_pers;
	character->y_lr = character->y_pers + character->long_pers;
}