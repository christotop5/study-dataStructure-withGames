#ifndef FUNCTION_FONAYEN
#define FUNCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define General_length 480
#define General_wight  760
#define x_position 50
#define y_position 50
#define cell_size (General_length/28)
#define stone_radius (General_length/65)
#define cell_center (cell_size/2)
#define big_Ellipse_X_radius (cell_size*3)
#define big_Ellipse_Y_radius (cell_size*10)
#define small_Ellipse_X_radius (cell_size*2)
#define small_Ellipse_Y_radius (cell_size*3)

    typedef struct seed{
        int state;
        int position;
        int player;
    }seed;
    typedef seed seed_type;

     typedef struct house{
        int seedNumber;
        int colour;
        seed_type seed1;
        seed_type seed2;
        seed_type seed3;
        seed_type seed4;
    }house;
    typedef house* house_type;


        
    typedef struct Case {
        int number_stones;  // Holds the number of stones in this pit (case)
        int player;         // Identifies the owner (0 for player A, 1 for player B)
    } Case;
    typedef Case case_type;

    typedef struct Player {
        int number_captured_stones;   // Keeps track of stones captured by this player
        int colour;                   // Color associated with the player (for graphical rendering)
        case_type cas[7];             // Array of pits belonging to this player (7 pits in total)
        case_type deposit;            // Extra case as the deposit pit to store captured stones
    } Player;

    typedef Player* player_type;

    void draw_board(SDL_Renderer *);
    void drawLargeCircle(SDL_Renderer *render, int x, int y, int radius);
    void draw_stone(SDL_Renderer *render, int x, int y, int radius);
    void* check_malloc(size_t size) ;
    void Init_PathFO(SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *);
    void Init_PlayerFO(player_type*,player_type*);
    void render_stoneFO(SDL_Renderer *render, case_type cas, SDL_Point *pathFO);
    void render_all_stonesFO(SDL_Renderer *render ,player_type*,player_type*,SDL_Point* Table_Points[16]);
    void renderPlayerFO(SDL_Renderer *renderFO, TTF_Font *fontFO , int identifier );
    void drawPlayerFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO,int identifier );
    void move_stones(player_type current_player, player_type opponent_player, int start_pit);
    int has_worn(player_type,player_type);
    void display_Winner(SDL_Renderer *renderFO, TTF_Font *fontFO , int identifier  );
 
#endif

