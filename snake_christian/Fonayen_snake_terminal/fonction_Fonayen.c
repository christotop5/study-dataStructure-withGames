#include "fonction_Fonayen.h"

void* check_mallocFO(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void Init_snakeFO(snake_type *snake){
    (*snake)->symbol = 'O';
    (*snake)->x = board_X_size/2;
    (*snake)->y = board_Y_size/2;
    (*snake)->next = NULL;
    (*snake)->prev = NULL;

}

snake_type creat_nodeFO(int x,int y){
    snake_type snake = (snake_type)check_mallocFO(sizeof(Node));

    snake->next = NULL;
    snake->prev = NULL;
    snake->symbol = 'O';
    snake->x = x;
    snake->y = y;

    return snake;
}

snake_type add_nodeFO(snake_type snake, int x, int y) {
    snake_type newNode = creat_nodeFO(x, y);  // Create the new node

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


void Init_boardFO(char boardFO[board_Y_size][board_X_size]) {
    for (int i = 0; i < board_Y_size; i++) {
        for (int j = 0; j < board_X_size; j++) { 
            if (j == 0 || i == 0 || j == board_X_size - 1 || i == board_Y_size - 1) {
                boardFO[i][j] = '*';  // Border
            } else {
                boardFO[i][j] = ' ';  // Inside space
            }
        }
    }

    // Corner markers if needed (optional)
    boardFO[0][0] = '#';
    boardFO[board_Y_size - 1][board_X_size - 1] = '#';
    boardFO[board_Y_size - 1][0] = '#';
    boardFO[0][board_X_size - 1] = '#';
}

void clear_boardFO(char boardFO[board_Y_size][board_X_size]){
    //reinitialize board
    for (int i = 0; i < board_Y_size; i++) {
        for (int j = 0; j < board_X_size; j++) { 
            if (j == 0 || i == 0 || j == board_X_size - 1 || i == board_Y_size - 1) {
                boardFO[i][j] = '*';  // Border
            } else {
                boardFO[i][j] = ' ';  // Inside space
            }
        }
    }

    // Corner markers if needed (optional)
    boardFO[0][0] = '#';
    boardFO[board_Y_size - 1][board_X_size - 1] = '#';
    boardFO[board_Y_size - 1][0] = '#';
    boardFO[0][board_X_size - 1] = '#';
}

food put_foodFO(){
    int randX = (rand()% 58  + 1 );
    int randY = (rand()% 28  + 1 );
    food fo ;
    fo.x = randX;
    fo.y = randY;

    return fo;
}

void Print_boardFO(char boardFO[board_Y_size][board_X_size],snake_type snake,food fo){
    
    //insert snake in board 
    snake_type temp = snake;
    boardFO[temp->y][temp->x] = 'H';
    temp = temp->next;
    while (temp != NULL){
        boardFO[temp->y][temp->x] = temp->symbol;
        temp = temp->next;
    }

    boardFO[fo.y][fo.x] = '@';
    for(int i=0; i<board_Y_size; i++){
        for(int j=0; j<board_X_size; j++){ 
            mvprintw(i, j, "%c", boardFO[i][j]); 
        }
        mvprintw(i, board_X_size, " ");
    } 
    refresh();
}

void move_rightFO(snake_type *snake){
    (*snake)->x++;
}

void followFO(snake_type *snake){
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

void move_leftFO(snake_type *snake){
    (*snake)->x--;
}

void move_upFO(snake_type *snake){
    (*snake)->y--;
}

void move_downFO(snake_type *snake){
    (*snake)->y++;
}

void lossFO(int score){
    refresh();           // Refresh the screen to show changes
        printf("\n\n\n\t\t*****************   YOUR lossFO     SCORE : %d *****************\n\n\n",score);
    usleep(long_DELAY);  
}

int bit_tailFO(snake_type snake){
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

int same_lineFO(snake_type snake){
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


