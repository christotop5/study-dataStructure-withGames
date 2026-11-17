#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {
    char boardFO[board_Y_size][board_X_size];
    snake_type snakeFO = (snake_type)check_mallocFO(sizeof(Node));
    

    initscr();               // Start ncurses mode
    keypad(stdscr, TRUE);    // Enable keyboard input
    nodelay(stdscr, TRUE);   // Make getch() non-blocking
    noecho();                // Don't display input
    curs_set(FALSE);         // Hide the cursor

    srand(time(NULL));
    int quitFO = 0;
    int directionFO = KEY_RIGHT;  // Initial directionFO

    food fo = put_foodFO();
    
    Init_snakeFO(&snakeFO);
    Init_boardFO(boardFO);

    Print_boardFO(boardFO,snakeFO,fo);
    

    


    while (!quitFO){

        // Handle input
        int ch = getch();
        if (ch != ERR) {     // If a key was pressed
            if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch ==   KEY_RIGHT ) {
                directionFO = ch;  // Update directionFO
            }
        }

        // Move snake based on directionFO
        switch (directionFO) {
            case KEY_UP:
                followFO(&snakeFO);
                move_upFO(&snakeFO);
                
                if( snakeFO->x == fo.x && snakeFO->y == fo.y){
                    snakeFO = realloc(snakeFO,sizeof(snakeFO)+sizeof(Node));
                    snakeFO = add_nodeFO(snakeFO,snakeFO->x,snakeFO->y);
                    move_upFO(&snakeFO);
                    
                    fo = put_foodFO();
                }
                break;
            case KEY_DOWN:
                followFO(&snakeFO);
                move_downFO(&snakeFO);
                if( snakeFO->x == fo.x && snakeFO->y == fo.y){
                    snakeFO = realloc(snakeFO,sizeof(snakeFO)+sizeof(Node));
                    snakeFO = add_nodeFO(snakeFO,snakeFO->x,snakeFO->y);
                    move_downFO(&snakeFO);
                    
                    fo = put_foodFO();
                }
                break;
            case KEY_LEFT:
                followFO(&snakeFO);
                move_leftFO(&snakeFO);
                
                if( snakeFO->x == fo.x && snakeFO->y == fo.y){
                    snakeFO = realloc(snakeFO,sizeof(snakeFO)+sizeof(Node));
                    snakeFO = add_nodeFO(snakeFO,snakeFO->x,snakeFO->y);
                    move_leftFO(&snakeFO);
                    
                    fo = put_foodFO();
                }
                break;
            case KEY_RIGHT:
                followFO(&snakeFO);
                move_rightFO(&snakeFO);
                
                if( snakeFO->x == fo.x && snakeFO->y == fo.y){
                    snakeFO = realloc(snakeFO,sizeof(snakeFO)+sizeof(Node));
                    snakeFO = add_nodeFO(snakeFO,snakeFO->x,snakeFO->y);
                    move_rightFO(&snakeFO);
                    
                    fo = put_foodFO();
                }
                break;
        }

        refresh();           // Refresh the screen to show changes
        usleep(DELAY);

        clear_boardFO(boardFO);
        Print_boardFO(boardFO, snakeFO,fo);
        

        // Check for collision with board edges
        if (snakeFO->x == board_X_size-1 || snakeFO->y == board_Y_size-1 || snakeFO->y == 0 || snakeFO->x == 0 ||( bit_tailFO(snakeFO) && !same_lineFO(snakeFO))) {
            int score = 0;
            while (snakeFO->next !=NULL){
                score++;
                snakeFO = snakeFO->next;
            }
            endwin(); 
            lossFO(score);
            quitFO = 1;
        }

    }
    
    endwin();  // End ncurses mode
    free(snakeFO);
    return 0;
 }



