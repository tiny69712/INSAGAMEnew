/*
// Created by Tiny on 2/16/2021.
*/

/*!
 * \file map.c
 * \brief Map Source File
 * \authors Tin
 * \version 1
 * \date 16/02/2021
 *
 * Map function implementation.
 *
 */

#include "map.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \fn int initmap(MAP *map,char *path)
 * \brief This function initialize the map : allocate the map's name and call the maptomatrix
 *
 * \param [in] map the map pointer
 * \param [in] path the map image path
 * \return 0 if the initialization went right.
 */

void initmap(MAP *map,char *func_path, char *vis_path){
    int lenpathfunc = strlen(func_path); //get the path lenght
	int lenpathvis = strlen(vis_path); //get the path lenght
	
    map->functional_path = (char *)malloc((lenpathfunc)*sizeof(char)); //allocate the path
    strcpy(map->functional_path,func_path); //copy the path given to map's path
	
	map->visual_path = (char *)malloc((lenpathvis)*sizeof(char)); //allocate the path
    strcpy(map->visual_path,vis_path); //copy the path given to map's path
	
    map->functional = maptomatrix(map); //fill the map's functional matrix
}

/*!
 * \fn int **maptomatrix(MAP *map)
 * \brief This function gets the matrix's length and width and creates a functional matrix from the bmp matrix.
 *
 * \param [in] map the map pointer
 * \return NULL if there is an error when opening the map, fonc otherwise.
 */

int **maptomatrix(MAP *map){
	
	char identity[2] ;
	unsigned char color[3];	
	uint32_t  file_size;          
	char application_id[4] ;       
	uint32_t raster_address; 
	uint32_t size_DIBHeader;      
	uint32_t image_width;         
	uint32_t image_height;        
	uint16_t nbColorPlanes;       
	uint16_t nbBitPerPixel;       
	uint32_t typeCompression;     
	uint32_t size_raw_image;      
	int32_t hResolution;          
	int32_t vResolution;          
	uint32_t nbUsedColours;      
	uint32_t nbImportantColours;
	int linematrix;
	int colummatrix;
	int rmalloc,cmalloc;
	int **fonc ;
	
	
	int i;
	
	FILE *bin;
	if(!(bin=fopen(map->functional_path,"rb"))){
		puts("Error to open the map !");
		return NULL;
	}

	FILE *outout;
    if(!(outout=fopen("map.log","w"))){
        puts("Error to open the map !");
        return NULL;
    }

	//Read Every Information of Map
	fread(identity,sizeof(identity),1,bin);
	fread(&file_size,sizeof(file_size),1,bin);
	fread(application_id,sizeof(application_id),1,bin);
	fread(&raster_address,sizeof(raster_address),1,bin);
	fread(&size_DIBHeader,sizeof(size_DIBHeader),1,bin);
	fread(&image_width,sizeof(image_width),1,bin);
	fread(&image_height,sizeof(image_height),1,bin);
	fread(&nbColorPlanes,sizeof(nbColorPlanes),1,bin);
	fread(&nbBitPerPixel,sizeof(nbBitPerPixel),1,bin);
	fread(&typeCompression,sizeof(typeCompression),1,bin);
	fread(&size_raw_image,sizeof(size_raw_image),1,bin);
	fread(&hResolution,sizeof(hResolution),1,bin);
	fread(&vResolution,sizeof(vResolution),1,bin);
	fread(&nbUsedColours,sizeof(nbUsedColours),1,bin);
	fread(&nbImportantColours,sizeof(nbImportantColours),1,bin);    
	
	
	//allocating a 2D matrix
	cmalloc = image_width;
	rmalloc = image_height;
	fonc = (int **)malloc(rmalloc * sizeof(int *));
	for(i=0;i<rmalloc;i++)
    {
	    fonc[i] = (int *)malloc(cmalloc*sizeof(int));
    }
	
	
	
	//get map height and width
	map->height = image_height;
	map->width = image_width;
	
	
	//fill the functional matrix
	linematrix = image_height -1;
	colummatrix = 0;
	for(i = 0 ; i < image_height*image_width ; i++){
			fread(color,sizeof(color),1,bin);
			if(color[2] == 255 && color[1] == 0 && color[0] == 0) 
			{
				fonc[linematrix][colummatrix] = 2;        //Exam
			}
			else if (color[2] == 0 && color[1] == 255 && color[0] == 0) 
			{
				fonc[linematrix][colummatrix] = 1;            //wall
			}
			else {
			fonc[linematrix][colummatrix] = 0;          //road
			}
			if(colummatrix<image_width-1) colummatrix ++;
			else {
				colummatrix = 0;
				linematrix --;
			}
	}



    for(linematrix = 0; linematrix <image_height; linematrix ++)
    {
        for(colummatrix=0; colummatrix<image_height;colummatrix++){
            fprintf(outout,"%d",fonc[linematrix][colummatrix]);
        }
        fprintf(outout,"\n");
    }


	fclose(bin);
	fclose(outout);
	return fonc;
	
}