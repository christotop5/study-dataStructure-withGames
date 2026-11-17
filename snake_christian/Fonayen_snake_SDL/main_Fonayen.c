#include "fonction_Fonayen.h"

int main(int argc, char* argv[]){

    snake_type snake = (snake_type)check_malloc(sizeof(Node));

    srand(time(NULL));

    food fo = put_food();
    
    Init_snake(&snake);

    
    SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size}; 

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* windowFO= SDL_CreateWindow("CHRISTOTOP5 snake",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderFO = SDL_CreateRenderer(windowFO, -1, SDL_RENDERER_ACCELERATED);
   
    TTF_Init();
    TTF_Font *fontFO = TTF_OpenFont("calibri.ttf", 200);

    int actual_score = 0;
    int counter = 0;
    SDL_Event eventFO;
    SDL_bool quit = SDL_FALSE;
    int track =4;
    SDL_Rect score_rect = {300, 5, 100, 20};
   


    SDL_SetRenderDrawColor(renderFO, 180,120, 110, 255);
    SDL_RenderClear(renderFO);
    SDL_SetRenderDrawColor(renderFO, 115, 115, 50, 20);
    draw_board(renderFO);
    draw_scoreFO(renderFO,score_rect );
    render_scoreFO(renderFO,fontFO,actual_score);
    render_foodFO(renderFO,fo);
    render_snakeFO(renderFO,snake);
    SDL_RenderPresent(renderFO);
    
    while (!quit) {
        // Event loop
        while (SDL_PollEvent(&eventFO)) {
            if (eventFO.type == SDL_QUIT) {
                quit = 1;
            } else if (eventFO.type == SDL_KEYDOWN) {
                switch (eventFO.key.keysym.sym) {
                        
                    case SDLK_UP:
                        track =1;
                        break;
                    case SDLK_DOWN:
                        track=2;
                        break;
                    case SDLK_LEFT:
                        track=3;
                        break;
                    case SDLK_RIGHT:
                        track=4;
                        break;
                }
            }
        }
        switch (track){
        case 1:
            follow(&snake);
            move_up(&snake);
            if( snake->x == fo.x && snake->y == fo.y){
                snake = realloc(snake,sizeof(snake)+sizeof(Node));
                snake = add_node(snake,snake->x,snake->y);
                actual_score++;
                move_up(&snake);
                
                fo = put_food();
            }
            break;
        case 2:
            follow(&snake);
            move_down(&snake);
            if( snake->x == fo.x && snake->y == fo.y){
                snake = realloc(snake,sizeof(snake)+sizeof(Node));
                snake = add_node(snake,snake->x,snake->y);
                actual_score++;
                move_down(&snake);
                
                fo = put_food();
            }
            break;
        case 3:
            follow(&snake);
            move_left(&snake);
            if( snake->x == fo.x && snake->y == fo.y){
                snake = realloc(snake,sizeof(snake)+sizeof(Node));
                snake = add_node(snake,snake->x,snake->y);
                actual_score++;

                move_left(&snake);
                
                fo = put_food();
            }
            break;
        case 4:
            follow(&snake);
            move_right(&snake);
            if( snake->x == fo.x && snake->y == fo.y){
                snake = realloc(snake,sizeof(snake)+sizeof(Node));
                snake = add_node(snake,snake->x,snake->y);
                actual_score++;
                move_right(&snake);
                
                fo = put_food();
            }
            break;
        }
        
        SDL_SetRenderDrawColor(renderFO, 180,120, 110, 255);
        SDL_RenderClear(renderFO);
        SDL_SetRenderDrawColor(renderFO, 115, 115, 50, 20);
        draw_board(renderFO);
        SDL_SetRenderDrawColor(renderFO, 0,255,100,255);
        draw_scoreFO(renderFO,score_rect );
        render_scoreFO(renderFO,fontFO,actual_score);
        render_foodFO(renderFO,fo);
        render_snakeFO(renderFO,snake);
        SDL_RenderPresent(renderFO);

        SDL_Delay(150);

        // Check for collision with board edges
        if (snake->x == board_X_size || snake->y == board_Y_size || snake->y == 0 || snake->x == 0 ||( bit_tail(snake) && !same_line(snake))) {
            int score = 0;
            while (snake->next !=NULL){
                score++;
                snake = snake->next;
            }
            drawLossFO(renderFO,textRectFO);
            renderLossFO(renderFO,fontFO,score);
            SDL_RenderPresent(renderFO);
            SDL_Delay(10000);
            quit =1;
        }
    }

    free(snake);
    TTF_CloseFont(fontFO);
    SDL_DestroyRenderer(renderFO);
    SDL_DestroyWindow(windowFO);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

