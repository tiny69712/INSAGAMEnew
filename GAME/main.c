#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "map.h"
#include "personnage.h"
#include "prof.h"
#include "DS.h"
#include "GAME.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define SPEEDMAN 3
#define SPEEDPROF 5
int main(int argc, char* args[])
{
    //Init SDL soft with timer

    if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("Cannot init SDL GAME, Error : %s\n", SDL_GetError());
        return 1;
    }


    SDL_Window * win = SDL_CreateWindow("INSAGAMEPROqu",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH+2,WINDOW_HEIGHT+2,0);

    if (!win)
    {
        printf("Cannot create new window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // create a new renderer for graphic sofware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
    {
        printf("Cannot create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }



    //Create Map and give it the functional matrix

    MAP mapgame;

    initmap(&mapgame,"ressource/colored.bmp","ressource/mapvis.bmp");
    mapgame.functional = maptomatrix(&mapgame);


    //Create a texture for map
    SDL_Texture * texturemap = IMG_LoadTexture(rend, mapgame.visual_path);

    if (!texturemap)
    {
        printf("error creating texture for map: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }




    //create Personnage and query his texture

    Personnage person;

    init_pers(&person,3,480,27,23,SPEEDMAN,"ressource/man.png");

    // load the image data into the graphics hardware's memory
    SDL_Texture* textureperson = IMG_LoadTexture(rend, person.image_pers);

    if (!textureperson)
    {
        printf("Cannot create texture for persson: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // struct to hold the position and size of the sprite
    SDL_Rect pers_rect;

    // get and scale the dimensions of texture
    SDL_QueryTexture(textureperson, NULL, NULL, &pers_rect.w, &pers_rect.h);
    pers_rect.w =  person.larg_pers;
    pers_rect.h =  person.long_pers;







    //create Prof and query his texture


    Prof profe;

    init_prof(&profe,350,380,41,25,SPEEDPROF,"ressource/prof.png");

    // load the image data into the graphics hardware's memory

    SDL_Texture* textureprof = IMG_LoadTexture(rend, profe.image_prof);


    if (!textureprof)
    {
        printf("Cannot create texture for prof: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // struct to hold the position and size of prof
    SDL_Rect profrect;

    // get and scale the dimensions of texture
    SDL_QueryTexture(textureprof, NULL, NULL, &profrect.w, &profrect.h);
    profrect.w = profe.larg_prof;
    profrect.h = profe.long_prof;
    profrect.x = profe.x_prof;
    profrect.y = profe.y_prof;






    //Create DS and its texture
    DS exam;

    fflush(stdin);
    int r = 2 + rand() % 29;       //random [2,10] because bug door 1 impossible => for complete 11->30

    init_DS(&exam,r,"ressource/DS.png");


    // load the image data into the graphics hardware's memory
    SDL_Texture* textureDS = IMG_LoadTexture(rend, exam.image_DS);


    if (!textureDS)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect examenrect;

    SDL_QueryTexture(textureDS, NULL, NULL, &examenrect.w, &examenrect.h);
    examenrect.w /= 30;
    examenrect.h /= 35;
    examenrect.x=exam.x_DS;
    examenrect.y=exam.y_DS;




    //varia for inputs storage
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;


    //collision variable
    int collision;

    //resultat variable
    int result = 0;

    // set to 1 when window close button is pressed
    int close_request = 0;

    int first=1;
    // game loop
    while (!close_request)
    {
        // process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    close_request = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_UP:
                            up = 1;
                            break;
                        case SDL_SCANCODE_LEFT:
                            left = 1;
                            break;
                        case SDL_SCANCODE_DOWN:
                            down = 1;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            right = 1;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_UP:
                            up = 0;
                            break;
                        case SDL_SCANCODE_LEFT:
                            left = 0;
                            break;
                        case SDL_SCANCODE_DOWN:
                            down = 0;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            right = 0;
                            break;
                    }
                    break;
            }
        }

        int directionprof;

        if(first==1){
            fflush(stdin);
            directionprof = rand()%4;
            first=0;
        }
        else directionprof = profmove(&profe, directionprof, &profrect, &mapgame, &exam);

        // determine position following inputs

        if (up && !down && !right && !left) person.y_pers -= SPEEDMAN;
        if (!up && down && !right && !left) person.y_pers += SPEEDMAN;
        if (!up && !down && !right && left) person.x_pers -= SPEEDMAN ;
        if (!up && !down && right && !left) person.x_pers += SPEEDMAN;

        //re-calcul 4 points of person
        calculpointspers(&person);

        // collision detection
        collision = testposition(&person,&profe,&exam ,&mapgame); // return 0 if nothing, 1 if wall, 2 if exam, 3 if prof, 4 if bounds

        // set the positions following collision variable
        switch (collision)
        {
            case 0:
                pers_rect.x = (int) person.x_pers;
                pers_rect.y = (int) person.y_pers;
                break;
            case 1:
                person.y_pers = pers_rect.y;
                person.x_pers = pers_rect.x;
                break;
            case 2:
                close_request = 1;
                result = 1;
                break;

            case 3:
                close_request = 1;
                result = 0;
                break;

            case 4:
                if (person.x_pers <= 0) person.x_pers = 2;
                if (person.y_pers <= 0) person.y_pers = 2;
                if (person.x_pers >= WINDOW_WIDTH - pers_rect.w) person.x_pers = WINDOW_WIDTH - pers_rect.w-2;
                if (person.y_pers >= WINDOW_HEIGHT - pers_rect.h) person.y_pers = WINDOW_HEIGHT - pers_rect.h-2;
                pers_rect.x = (int) person.x_pers;
                pers_rect.y = (int) person.y_pers;
                break;
        }

        // clear the window
        SDL_RenderClear(rend);

        // draw the image to the window
        SDL_RenderCopy(rend, texturemap, NULL, NULL);
        SDL_RenderCopy(rend, textureperson, NULL, &pers_rect);
        SDL_RenderCopy(rend, textureprof, NULL, &profrect);
        SDL_RenderCopy(rend, textureDS, NULL, &examenrect);
        SDL_RenderPresent(rend);


        // wait 17ms of a second
        SDL_Delay(17);
    }


    SDL_DestroyTexture(texturemap);
    SDL_DestroyTexture(textureperson);
    SDL_DestroyTexture(textureprof);
    SDL_DestroyTexture(textureDS);

    //texture for endgame
    SDL_Texture* texendgame;

    if(result==1){
        texendgame = IMG_LoadTexture(rend,"ressource/win.png");
    }
    else texendgame = IMG_LoadTexture(rend,"ressource/lose.png");

    if (!texendgame)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_RenderCopy(rend, texendgame, NULL, NULL);
    SDL_RenderPresent(rend);
    SDL_Delay(2000);


    // clean up resources before exiting
    SDL_DestroyTexture(texendgame);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();


}
