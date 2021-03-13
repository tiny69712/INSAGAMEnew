/*
// Created by Tiny on 3/3/2021.
*/
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GAME.h"
#include "prof.h"
#include "personnage.h"
#include "map.h"
#include "DS.h"

#define WINDOW_WIDTH (700)
#define WINDOW_HEIGHT (700)




//Collisions Functions

int testposition(Personnage * pers, Prof * prof, DS * exam, MAP * map){
    //test variables
    int testbounds = testboundscol(pers); ;
    int testprof = testprofcol(pers,prof);

    //test bounds collision

    if(testbounds) return 4;

	//test prof collision

    if(testprof) return 3;

    //return the map test position

    return testmapcol(pers,map,exam); // = 0 if nothing , 1 if wall, 2 if exam

}

int testboundscol(Personnage * pers){
    if((pers->x_pers <= 0) || (pers->y_pers <= 0) || (pers->x_pers >= WINDOW_WIDTH - pers->larg_pers) || (pers->y_pers >= WINDOW_HEIGHT - pers->long_pers)) {
        return 1;
    }
    return 0;
}

int testprofcol(Personnage * pers, Prof * prof){

	int testhl;
	int testhr;
	int testll;
	int testlr;


	testhl=testpointwithprof(pers->x_pers, pers->y_pers,prof);
	testhr=testpointwithprof(pers->x_hr, pers->y_hr,prof) ;
	testll=testpointwithprof(pers->x_ll, pers->y_ll,prof);
	testlr=testpointwithprof(pers->x_lr, pers->y_lr,prof) ;

	if(testhl){
		return 1;
	}
	else if (testhr){
		return 1;
	}
	else if (testll){
		return 1;
	}
	else if (testlr){
		return 1;
	}
    return 0;
}


int testpointwithprof(int x, int y, Prof *prof){
	if (( x > prof->x_prof) && (x<prof->x_prof+prof->larg_prof)) {
        if (( y > prof->y_prof) && (y < prof->y_prof + prof->long_prof)) {
            return 1;
        }
    }
	return 0;
}



int testmapcol(Personnage * pers,  MAP * map, DS * exam ){
	int testhl = testpointwithmap(pers->x_pers,pers->y_pers,map,exam);
	int testhr = testpointwithmap(pers->x_hr,pers->y_hr,map,exam) ;
	int testll = testpointwithmap(pers->x_ll,pers->y_ll,map,exam) ;
	int testlr = testpointwithmap(pers->x_lr,pers->y_lr,map,exam) ;
	
	if(testhl==2 || testhr==2 || testll==2 || testlr==2) {
		return 2;
	}
	else if(testhl==1 || testhr==1 || testll==1 || testlr==1){
		return 1;
	}
	else return 0;
}



int testpointwithmap(int x, int y, MAP *map, DS * exam){
	if (map->functional[y][x] == 2){         //if zone exams
        //test exam collision
        if ((x > exam->x_DS) && (x < exam->x_DS+exam->larg_DS)) {
                if(((y > exam->y_DS) && (y < exam->y_DS+exam->long_DS))){
            return 2;
				}
        }
    }
    else if (map->functional[y][x] == 1){         //if zone wall
        return 1;
    }
	return 0;
}