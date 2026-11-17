#ifndef FONCTION_FONAYEN
#define FONCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



    typedef struct Point{
        int x;
        int y;
    } Point;
    typedef Point *point_type;

    typedef struct seed{
        int state;
        int position;
        int player;
        char caracter;
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

    void init_boardFO(char boardFO[32][32]);
    void* check_mallocFO(size_t size);
    void print_boardFO(char boardFO[32][32]);
    void init_pathFO(point_type ,point_type ,point_type ,point_type ,point_type ,point_type ,point_type ,point_type );
    int roll_diceFO();
    void INit_HousesFO(house_type *yellow,house_type *green,house_type *red,house_type *blue);
    void move_seedFO(char boardFO[32][32],seed_type *player_token, int dice_value,house_type *other,Point **Homes,Point *thisHome);

    void drawRedFO(char boardFO[32][32], int x, int y);
    void draweGreenFO(char boardFO[32][32], int x, int y);
    void drawYellowFO( char boardFO[32][32], int x, int y);
    void drawBLueFO( char boardFO[32][32], int x, int y);
   
   void render_seedFO( char boardFO[32][32], seed_type seed, Point *pathFO, Point homePathFO);
   void render_all_seedsFO(char boardFO[32][32] , house_type house_YellowFO, house_type house_GreenFO, house_type house_RedFO, house_type house_BlueFO, Point *home_yellow, Point *home_green,Point *home_red,Point *home_blue, Point *path_yellow,Point *path_green, Point *path_red,Point *path_blue);
   void render_seedFO(char boardFO[32][32], seed_type seed, Point *pathFO, Point homePathFO);
   int statFO(house_type *houseFO, int diceValueFO);
   int can_MoveFO(house_type *houseFO, int diceValueFO);
   void handleSeedMovementFO(char boardFO[32][32] ,house_type house,Point* path, int diceValueFO,Point*pathHom ,int player, house_type* others,Point **Homes);
   void remove_seedFO(seed_type *seed,house_type *other,Point **Homes,Point *thisHome);
   int has_worn(house_type houseFO);
   void renderDiceResultFO(char boardFO[32][32], int diceValueFO);
#endif
