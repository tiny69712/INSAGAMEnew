/*
// Created by Lucile on 02/03/2021.
*/

/*!
 * \file DS.c
 * \brief Exam Source File
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
#include "DS.h"

/*!
 * \fn int init_DS(DS * exam, int door_DS, char * path)
 * \brief This function initialize a DS : position (the door number) and the path to the DS's image.
 *
 * \param [in] exam a DS pointer
 * \param [in] door_DS a door number corresponding to the DS location
 * \param [in] path the DS image path
 * \return 1 if the initialization went right.
 */

void init_DS(DS * exam, int door_DS, char * path){
    exam->door=door_DS;
    exam->image_DS = malloc(strlen(path));
    strcpy(exam->image_DS, path);

    switch (exam->door)
    {
                case 2:
            exam->x_DS = 144;
            exam->y_DS= 48;
            exam->larg_DS= 21;
            exam->long_DS= 14;
            break;

        case 3:
            exam->x_DS = 369;
            exam->y_DS= 41;
            exam->larg_DS= 21;
            exam->long_DS= 10;
            break;

        case 4:
            exam->x_DS = 564;
            exam->y_DS= 38;
            exam->larg_DS= 23;
            exam->long_DS= 12;
            break;

        case 5:
            exam->x_DS = 43;
            exam->y_DS= 85;
            exam->larg_DS= 24;
            exam->long_DS= 14;
            break;

        case 6:
            exam->x_DS = 237;
            exam->y_DS= 98;
            exam->larg_DS= 11;
            exam->long_DS= 19;
            break;

        case 7:
            exam->x_DS = 460;
            exam->y_DS= 74;
            exam->larg_DS= 12;
            exam->long_DS= 17;
            break;

        case 8:
            exam->x_DS = 75;
            exam->y_DS= 172;
            exam->larg_DS= 19;
            exam->long_DS= 11;
            break;

        case 9:
            exam->x_DS = 316;
            exam->y_DS= 162;
            exam->larg_DS= 13;
            exam->long_DS= 18;
            break;

        case 10:
            exam->x_DS = 454;
            exam->y_DS= 149;
            exam->larg_DS= 20;
            exam->long_DS= 10;
            break;

        case 11:
            exam->x_DS = 191;
            exam->y_DS= 203;
            exam->larg_DS= 22;
            exam->long_DS= 11;
            break;

        case 12:
            exam->x_DS = 544;
            exam->y_DS= 201;
            exam->larg_DS= 14;
            exam->long_DS= 24;
            break;

        case 13:
            exam->x_DS = 632;
            exam->y_DS= 181;
            exam->larg_DS= 14;
            exam->long_DS= 23;
            break;

        case 14:
            exam->x_DS = 228;
            exam->y_DS= 263;
            exam->larg_DS= 14;
            exam->long_DS= 20;
            break;

        case 15:
            exam->x_DS = 314;
            exam->y_DS= 261;
            exam->larg_DS= 21;
            exam->long_DS= 14;
            break;

        case 16:
            exam->x_DS = 82;
            exam->y_DS= 356;
            exam->larg_DS= 16;
            exam->long_DS= 24;
            break;

        case 17:
            exam->x_DS = 493;
            exam->y_DS= 319;
            exam->larg_DS= 16;
            exam->long_DS= 21;
            break;

        case 18:
            exam->x_DS = 600;
            exam->y_DS= 308;
            exam->larg_DS= 13;
            exam->long_DS= 20;
            break;

        case 19:
            exam->x_DS = 194;
            exam->y_DS= 414;
            exam->larg_DS= 21;
            exam->long_DS= 13;
            break;

        case 20:
            exam->x_DS = 553;
            exam->y_DS= 392;
            exam->larg_DS= 12;
            exam->long_DS= 20;
            break;

        case 21:
            exam->x_DS = 654;
            exam->y_DS= 407;
            exam->larg_DS= 20;
            exam->long_DS= 12;
            break;

        case 22:
            exam->x_DS = 349;
            exam->y_DS= 434;
            exam->larg_DS= 22;
            exam->long_DS= 12;
            break;

        case 23:
            exam->x_DS = 269;
            exam->y_DS= 467;
            exam->larg_DS= 16;
            exam->long_DS= 20;
            break;

        case 24:
            exam->x_DS = 461;
            exam->y_DS= 507;
            exam->larg_DS= 24;
            exam->long_DS= 14;
            break;

        case 25:
            exam->x_DS = 637;
            exam->y_DS= 513;
            exam->larg_DS= 13;
            exam->long_DS= 24;
            break;
        case 26:
            exam->x_DS = 32;
            exam->y_DS= 556;
            exam->larg_DS= 26;
            exam->long_DS= 13;
            break;

        case 27:
            exam->x_DS = 192;
            exam->y_DS= 614;
            exam->larg_DS= 18;
            exam->long_DS= 24;
            break;
        case 28:
            exam->x_DS = 238;
            exam->y_DS= 653;
            exam->larg_DS= 14;
            exam->long_DS= 20;
            break;

        case 29:
            exam->x_DS = 501;
            exam->y_DS= 651;
            exam->larg_DS= 14;
            exam->long_DS= 21;
            break;

        case 30:
            exam->x_DS = 553;
            exam->y_DS= 662;
            exam->larg_DS= 17;
            exam->long_DS= 23;
            break;


    }

}