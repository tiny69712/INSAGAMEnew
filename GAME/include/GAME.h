/*
// Created by Tiny on 3/3/2021.
*/

#ifndef INSAGAME_GAME_H
#define INSAGAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GAME.h"
#include "prof.h"
#include "personnage.h"
#include "map.h"
#include "DS.h"


//GAME Functions

void createtexture(SDL_Window * win, SDL_Renderer* rend, SDL_Texture * texture, char * path);


//Collisions Functions

int testposition(Personnage * pers, Prof * prof, DS * exam, MAP * map); // return 0 if nothing, 1 if wall, 2 if exam, 3 if prof, 4 if bounds
int testboundscol(Personnage * pers);
int testprofcol(Personnage * pers, Prof * prof);
int testmapcol(Personnage * pers,  MAP * map, DS * exam);
int testpointwithprof(int x, int y, Prof *prof);
int testpointwithmap(int x, int y, MAP *map, DS * exam);




#endif /*INSAGAME_GAME_H*/
