#include "fonction_Fonayen.h"

void draw_board(SDL_Renderer *render){  

    for(int i=0;i<=General_wight;i+=(cell_size)){
        for(int j=0;j<=General_length;j+=cell_size){
            SDL_Rect smalls = {
                .x = x_position+(i),
                .y = y_position+(j),
                .h = cell_size,
                .w = cell_size,
            };
            
            SDL_SetRenderDrawColor(render,150,105,145,250);
            SDL_RenderFillRect(render,&smalls);   
        }
    }
}

void draw_node(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render,x_position + (x*cell_size)+ cell_center,x_position + (y*cell_size)+ cell_center, radius, 0, 0, 0, 220);
}

void draw_food(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render,x_position + (x*cell_size)+ cell_center,x_position + (y*cell_size)+ cell_center, radius, 108, 50, 35, 220);
}

void* check_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void render_snakeFO(SDL_Renderer *render, snake_type snake){
    snake_type temp = snake;
    while (temp != NULL){
        draw_node(render,temp->x,temp->y,stone_radius);
        temp = temp->next;
    }   
}

void render_foodFO(SDL_Renderer *render, food fo){
    draw_food(render,fo.x,fo.y,stone_radius);      
}

void drawLossFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO ) {
    SDL_SetRenderDrawColor(renderFO, 250, 0, 0, 200);
    SDL_RenderFillRect(renderFO, &diceButtonFO);
}

void renderLossFO(SDL_Renderer *renderFO, TTF_Font *fontFO ,int score ) {
    SDL_Color whiteFO = {205, 205, 205};
    char ch[25] = "YOU LOSS SCORE :    ";

    char TextFO[3];
    sprintf(TextFO, "%d", score);

    ch[17] = TextFO[0];
    ch[18] = TextFO[1];
    ch[19] = TextFO[2];
    
    SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, ch, whiteFO);
    SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

    SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size};   // Adjust for position and size
    SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

    SDL_FreeSurface(surfaceFO);
    SDL_DestroyTexture(textureFO);
    return;
    
}


void render_scoreFO(SDL_Renderer *renderFO, TTF_Font *fontFO, int actual_score){
    SDL_Color white = {255,255,255};
    char score_panel[12] = "SCORE : ";
    char score[3];
    sprintf(score, "%d", actual_score);
    score_panel[8] = score[0];
    score_panel[9] = score[1];
    score_panel[10] = score[2];

    SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, score_panel, white);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

    SDL_Rect score_rect = {300, 5, 100, 20};
    SDL_RenderCopy(renderFO, texture, NULL, &score_rect);

    SDL_FreeSurface(surfaceFO);
    SDL_DestroyTexture(texture);
    return;
}

void draw_scoreFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO ) {
    SDL_SetRenderDrawColor(renderFO, 20, 40, 80, 200);
    SDL_RenderFillRect(renderFO, &diceButtonFO);
}

void Init_snake(snake_type *snake){
    (*snake)->symbol = 'O';
    (*snake)->x = board_X_size/2;
    (*snake)->y = board_Y_size/2;
    (*snake)->next = NULL;
    (*snake)->prev = NULL;

}

snake_type creat_node(int x,int y){
    snake_type snake = (snake_type)check_malloc(sizeof(Node));

    snake->next = NULL;
    snake->prev = NULL;
    snake->symbol = 'O';
    snake->x = x;
    snake->y = y;

    return snake;
}

snake_type add_node(snake_type snake, int x, int y) {
    snake_type newNode = creat_node(x, y);  // Create the new node

    if (snake->next == NULL) {  // If there's only one node, just append
        snake->next = newNode;
        newNode->prev = snake;
    } else {
        // Insert newNode as the second node
        snake_type second = snake->next;  // The current second node

        snake->next = newNode;            // Set snake's next to newNode
        newNode->prev = snake;            // Link newNode back to snake

        newNode->next = second;           // Link newNode to the current second node
        second->prev = newNode;           // Link the current second node back to newNode
    }

    return snake;
}

food put_food(){
    int randX = (rand()% 44  );
    int randY = (rand()% 28 );
    food fo ;
    fo.x = randX;
    fo.y = randY;

    return fo;
}

void move_right(snake_type *snake){
    (*snake)->x++;
}

void follow(snake_type *snake){
    if((*snake) == NULL) return;
    snake_type temp = (*snake);

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp->prev != NULL){
        temp->y = temp->prev->y;
        temp->x = temp->prev->x;
        temp = temp->prev;
    }
}

void move_left(snake_type *snake){
    (*snake)->x--;
}

void move_up(snake_type *snake){
    (*snake)->y--;
}

void move_down(snake_type *snake){
    (*snake)->y++;
}

int bit_tail(snake_type snake){
    if(snake->next == NULL)return 0;
    int x = snake->x;
    int y = snake->y;

    snake_type temp = snake;
    temp = temp->next;
    temp = temp->next;

    while(temp != NULL){
        if(temp->x == x && temp->y == y) return 1;
        temp = temp->next;
    }
    return 0;
}

int same_line(snake_type snake){
    if(snake->next == NULL)return 0;
    int x = snake->x;
    int y = snake->y;

    snake_type temp = snake;

    while(temp != NULL){
        if(temp->x != x && temp->y != y) return 0;
        temp = temp->next;
    }
    return 1;
}











