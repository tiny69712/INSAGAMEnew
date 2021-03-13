/*
// Created by Lucile on 18/02/2021.
*/

/*!
 * \file personnage.h
 * \brief Character Header File
 * \authors Lucile
 * \version 1
 * \date 25/02/2021
 *
 * Character structure and functions definiton.
 *
 */

#ifndef GAME_INSA_PROJECT_PERSONNAGE_H
#define GAME_INSA_PROJECT_PERSONNAGE_H

/*!
 * \struct Personnage
 * \brief Character structure
 */

typedef struct {
    int x_pers; /**< Position : x hight-left point */
    int y_pers; /**< Position : y hight-left point */
    int long_pers; /**< Size : length */
    int larg_pers; /**< Size : width */
	int x_hr; 	/**< Position : x hight-right point */
	int y_hr; 	/**< Position : y hight-right point */
	int x_ll; 	/**< Position : x low-left point */
	int y_ll; 	/**< Position : y low-left point */
	int x_lr; 	/**< Position : x low-right point */
	int y_lr;	/**< Position : y low-right point */
    int speed_pers; /**< Charater speed */
    char * image_pers; /**< Source image of the character. */
}Personnage;

void init_pers(Personnage * character, int x, int y, int length, int width, int speed, char * path);
void calculpointspers(Personnage * character);


#endif /*GAME_INSA_PROJECT_PERSONNAGE_H*/
