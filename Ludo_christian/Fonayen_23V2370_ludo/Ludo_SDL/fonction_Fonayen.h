#ifndef FONCTION_FONAYEN
#define FONCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define General_size 630
#define x_position 100
#define y_position 100
#define cell_size (General_size/15)
#define seed_radus (General_size/40)
#define cell_center (General_size/27)

    typedef struct seed{
        int state;
        int position;
        int player;
    }seed;
    typedef seed seed_type;

    typedef struct house{
        int seedNumber;//Number of seeds at home
        int colour;   
        seed_type seed1;
        seed_type seed2;
        seed_type seed3;
        seed_type seed4;
    }house;
    typedef house* house_type;

    void drow_bord(SDL_Renderer *);
    void drawLargeCircle(SDL_Renderer *render, int x, int y, int radius);
    void drawMiniCircleRed(SDL_Renderer *render, int x, int y, int radius);
    void drawMiniCircleGreen(SDL_Renderer *render, int x, int y, int radius);
    void drawMiniCircleYellow(SDL_Renderer *render, int x, int y, int radius);
    void drawMiniCircleBLue(SDL_Renderer *render, int x, int y, int radius);
    void* check_malloc(size_t size);
    void Init_PathFO(SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *);
    void INit_HousesFO(house_type*,house_type*,house_type*,house_type*);
    int roll_dice();
    int statFO(house_type *houseFO, int diceValueFO );

    int has_worn(house_type);
  
    void drawDiceButtonFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO ,int);
    void renderDiceResultFO(SDL_Renderer *renderFO, int diceValueFO, TTF_Font *fontFO);

    void move_seedFO(seed_type*,int,house_type*,SDL_Point **,SDL_Point *);
    void remove_seedFO(seed_type*,house_type*,SDL_Point **,SDL_Point *);

    void render_all_seedsFO(SDL_Renderer *render, house_type house_YellowFO, house_type house_GreenFO,  house_type house_RedFO, house_type house_BlueFO,  SDL_Point *home_yellow, SDL_Point *home_green,  SDL_Point *home_red, SDL_Point *home_blue ,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *);
    void render_seedFO(SDL_Renderer *render, seed_type seed, SDL_Point *pathFO, SDL_Point homePathFO);

    void handleSeedMovementFO(SDL_Renderer*,house_type house, SDL_Point* path, int diceValueFO,SDL_Point*, TTF_Font *fontFO,SDL_Rect ,SDL_Rect ,SDL_Rect ,SDL_Rect ,SDL_Rect  ,int,house_type* ,SDL_Point **);

#endif
