/*
// Created by Tiny on 2/16/2021.
*/

/*!
 * \file map.h
 * \brief Map Header File
 * \authors Tin
 * \version 1
 * \date 16/02/2021
 *
 * Map structure and functions definiton.
 *
 */

#ifndef INSAGAME_MAP_H
#define INSAGAME_MAP_H

/*!
 * \struct MAP
 * \brief Map structure
 */

typedef struct {
	char *functional_path; /**< Path of image functional bmp of map */
	char *visual_path; /**< Path of image visual bmp of map */
	int width; /**< Map's width */
	int height; /**< Map's height */
	int **functional; /**< 2D functional matrix */
} MAP;



void initmap(MAP *map, char *func_path, char *vis_path);
int **maptomatrix(MAP *map);




#endif /*INSAGAME_MAP_H*/
