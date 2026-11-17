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

#define DELAY 100000  // Delay in microseconds
#define long_DELAY 5000000 // Delay in microseconds
#define board_X_size 44
#define board_Y_size 29

    typedef struct Node{
        char symbol;
        int x;
        int y;
        struct Node *next;
        struct Node *prev;
    }Node;
    typedef struct Node *snake_type;

    typedef struct food{
        int x;
        int y;
    }food;

    void* check_malloc(size_t size);
    void Init_snake(snake_type *);
    void Init_board(char boardFO[board_Y_size][board_X_size]);
    void clear_board(char boardFO[board_Y_size][board_X_size]);
    void Print_board(char boardFO[board_Y_size][board_X_size],snake_type,food);
    void move_right(snake_type*);
    void move_left(snake_type*);
    void move_up(snake_type*);
    void move_down(snake_type*);
    food put_food();
    snake_type creat_node(int x,int y);
    snake_type add_node(snake_type ,int x,int y);
    int bit_tail(snake_type);
    int same_line(snake_type snake);
    void follow(snake_type *snake);



    void draw_board(SDL_Renderer *);
    void draw_node(SDL_Renderer *render, int x, int y, int radius);
    void render_snakeFO(SDL_Renderer *render, snake_type snake);

    void Init_PathFO(SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *,SDL_Point *);
    void draw_food(SDL_Renderer *render, int x, int y, int radius);
    void render_foodFO(SDL_Renderer *render, food fo);

    void renderLossFO(SDL_Renderer *renderFO, TTF_Font *fontFO ,int );
    void drawLossFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO);
    void render_scoreFO(SDL_Renderer *renderFO, TTF_Font *fontFO, int actual_score);
    void draw_scoreFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO );

#endif

