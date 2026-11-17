#ifndef FONCTION_FONAYEN
#define FONCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>

#define DELAY 100000  // Delay in microseconds
#define long_DELAY 5000000 // Delay in microseconds
#define board_X_size 60
#define board_Y_size 30

    typedef struct Node{
        char symbol;
        int x;
        int y;
        struct Node *next;
        struct Node *prev;
    }Node;
    typedef struct Node* snake_type;

    typedef struct food{
        int x;
        int y;
    }food;
    

    void* check_mallocFO(size_t size);
    void Init_snakeFO(snake_type *);
    void Init_boardFO(char boardFO[board_Y_size][board_X_size]);
    void clear_boardFO(char boardFO[board_Y_size][board_X_size]);
    void Print_boardFO(char boardFO[board_Y_size][board_X_size],snake_type,food);
    void move_rightFO(snake_type*);
    void move_leftFO(snake_type*);
    void move_upFO(snake_type*);
    void move_downFO(snake_type*);
    food put_foodFO();
    snake_type creat_nodeFO(int x,int y);
    snake_type add_nodeFO(snake_type ,int x,int y);
    int bit_tailFO(snake_type);
    int same_lineFO(snake_type snake);
    void lossFO(int);
    void followFO(snake_type *snake);

    
#endif
