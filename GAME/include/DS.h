/*
// Created by Lucile on 18/02/2021.
*/

/*!
 * \file DS.h
 * \brief DS Header File
 * \authors Lucile
 * \version 1
 * \date 25/02/2021
 *
 * DS structure definiton.
 *
 */

#ifndef INSAGAME_DS_H
#define INSAGAME_DS_H

/*!
 * \struct DS
 * \brief DS structure
 */

typedef struct {
    int door; /**< Integer representing the door number i.e. the DS location. */
    char * image_DS; /**< Source image of the DS. */
    int x_DS; /**< Position : abscissa */
    int y_DS; /**< Position : ordinate */
    int long_DS; /**< Size : length */
    int larg_DS; /**< Size : width */
} DS;

void init_DS(DS * exam, int door_DS, char * path);

#endif /*INSAGAME_DS_H*/
