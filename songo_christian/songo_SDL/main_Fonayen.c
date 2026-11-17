#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {

    SDL_Point *path_red0FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red1FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red2FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red3FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red4FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red5FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_red6FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_Deposit_redFO = (SDL_Point*)check_malloc(70 * sizeof(SDL_Point));
    SDL_Point *path_blue0FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue1FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue2FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue3FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue4FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue5FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_blue6FO = (SDL_Point*)check_malloc(16 * sizeof(SDL_Point));
    SDL_Point *path_Deposit_blueFO = (SDL_Point*)check_malloc(70 * sizeof(SDL_Point));
    Init_PathFO( path_blue0FO,path_blue1FO,path_blue2FO,path_blue3FO,path_blue4FO,path_blue5FO,path_blue6FO,path_Deposit_blueFO,path_red0FO,path_red1FO,path_red2FO,path_red3FO,path_red4FO,path_red5FO,path_red6FO,path_Deposit_redFO);
    
    SDL_Point* Table_Points[16] = { path_blue0FO,path_blue1FO,path_blue2FO,path_blue3FO,path_blue4FO,path_blue5FO,path_blue6FO,path_Deposit_blueFO,path_red0FO,path_red1FO,path_red2FO,path_red3FO,path_red4FO,path_red5FO,path_red6FO,path_Deposit_redFO};

    player_type player_blueFO = (player_type)check_malloc(sizeof(Player));
    player_type player_redFO = (player_type)check_malloc(sizeof(Player));

    Init_PlayerFO(&player_blueFO,&player_redFO);

    SDL_Rect rect_blueFO[7]= { 
        {x_position+(cell_size*5) , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*10)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*15)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*20)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*25)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*30)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*35)  , y_position+(cell_size*2) ,cell_size*4, cell_size*6}
    };
    
    SDL_Rect rect_redFO[7] = { 
        {x_position+(cell_size*5) , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*10)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*15)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*20)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*25)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*30)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6},
        {x_position+(cell_size*35)  , y_position+(cell_size*21) ,cell_size*4, cell_size*6}
    };
    SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size}; 

    int NumberOfPlayersFO = 2;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* windowFO= SDL_CreateWindow("CHRISTOTOP5 songo",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderFO = SDL_CreateRenderer(windowFO, -1, SDL_RENDERER_ACCELERATED);
   
    SDL_Texture* texture = IMG_LoadTexture(renderFO, "image.png");
    if (texture == NULL) {
        printf("Failed to load texture: %s\n", IMG_GetError());
    }

    TTF_Init();
    TTF_Font *fontFO = TTF_OpenFont("calibri.ttf", 200);


    int counter = 0;
    SDL_Event eventFO;
    SDL_bool quit = SDL_FALSE;
    int currentPlayerFO = 0;
    int worn=0;


    SDL_SetRenderDrawColor(renderFO, 180,120, 110, 255);
    SDL_RenderClear(renderFO);
    SDL_SetRenderDrawColor(renderFO, 115, 115, 50, 20);
    draw_board(renderFO);
    render_all_stonesFO(renderFO,&player_blueFO,&player_redFO,Table_Points);
    SDL_RenderPresent(renderFO);
    
    while (!quit) {
        // Wait for an eventFO
        SDL_WaitEvent(&eventFO);

        // Handle the eventFO
        switch (eventFO.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;

            case SDL_MOUSEBUTTONDOWN:{
                printf("Mouse button clicked\n");
                int mouseXFO = eventFO.button.x;
                int mouseYFO = eventFO.button.y;

                    switch (currentPlayerFO) {
                        case 0: printf("// blue's turn");{
                            if (mouseXFO >= rect_blueFO[0].x && mouseXFO <= rect_blueFO[0].x + rect_blueFO[0].w &&  mouseYFO >= rect_blueFO[0].y && mouseYFO <= rect_blueFO[0].y + rect_blueFO[0].h && player_blueFO->cas[0].number_stones != 0) {
                                move_stones(player_blueFO,player_redFO,0);
                                
                                printf("1");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[1].x && mouseXFO <= rect_blueFO[1].x + rect_blueFO[1].w &&  mouseYFO >= rect_blueFO[1].y && mouseYFO <= rect_blueFO[1].y + rect_blueFO[1].h && player_blueFO->cas[1].number_stones != 0){
                                move_stones(player_blueFO,player_redFO,1);

                                printf("2");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[2].x && mouseXFO <= rect_blueFO[2].x + rect_blueFO[2].w &&  mouseYFO >= rect_blueFO[2].y && mouseYFO <= rect_blueFO[2].y + rect_blueFO[2].h && player_blueFO->cas[2].number_stones != 0){
                                move_stones(player_blueFO,player_redFO,2);

                                printf("3");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[3].x && mouseXFO <= rect_blueFO[3].x + rect_blueFO[3].w &&  mouseYFO >= rect_blueFO[3].y && mouseYFO <= rect_blueFO[3].y + rect_blueFO[3].h && player_blueFO->cas[3].number_stones != 0) {
                                move_stones(player_blueFO,player_redFO,3);

                                printf("4");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[4].x && mouseXFO <= rect_blueFO[4].x + rect_blueFO[4].w &&  mouseYFO >= rect_blueFO[4].y && mouseYFO <= rect_blueFO[4].y + rect_blueFO[4].h && player_blueFO->cas[4].number_stones != 0) {
                                move_stones(player_blueFO,player_redFO,4);

                                printf("5");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[5].x && mouseXFO <= rect_blueFO[5].x + rect_blueFO[5].w &&  mouseYFO >= rect_blueFO[5].y && mouseYFO <= rect_blueFO[5].y + rect_blueFO[5].h && player_blueFO->cas[5].number_stones != 0){
                                move_stones(player_blueFO,player_redFO,5);

                                printf("6");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_blueFO[6].x && mouseXFO <= rect_blueFO[6].x + rect_blueFO[6].w &&  mouseYFO >= rect_blueFO[6].y && mouseYFO <= rect_blueFO[6].y + rect_blueFO[6].h && player_blueFO->cas[6].number_stones != 0) {
                                move_stones(player_blueFO,player_redFO,6);

                                printf("7");
                                counter++;
                                currentPlayerFO = (counter%2);  
                            }
                                
                            break;

                        }case 1:  printf("// red's turn");{
                            if (mouseXFO >= rect_redFO[0].x && mouseXFO <= rect_redFO[0].x + rect_redFO[0].w &&  mouseYFO >= rect_redFO[0].y && mouseYFO <= rect_redFO[0].y + rect_redFO[0].h && player_redFO->cas[6].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,6);
                                
                                player_redFO->cas[6].number_stones = 0;
                                printf("7");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[1].x && mouseXFO <= rect_redFO[1].x + rect_redFO[1].w &&  mouseYFO >= rect_redFO[1].y && mouseYFO <= rect_redFO[1].y + rect_redFO[1].h && player_redFO->cas[5].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,5);
                                
                                player_redFO->cas[5].number_stones = 0;
                                printf("6");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[2].x && mouseXFO <= rect_redFO[2].x + rect_redFO[2].w &&  mouseYFO >= rect_redFO[2].y && mouseYFO <= rect_redFO[2].y + rect_redFO[2].h && player_redFO->cas[4].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,4);
                                
                    
                                printf("5");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[3].x && mouseXFO <= rect_redFO[3].x +rect_redFO[3] .w &&  mouseYFO >= rect_redFO[3].y && mouseYFO <= rect_redFO[3].y + rect_redFO[3].h && player_redFO->cas[3].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,3);
                                
                             
                                printf("4");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[4].x && mouseXFO <= rect_redFO[4].x + rect_redFO[4].w &&  mouseYFO >= rect_redFO[4].y && mouseYFO <= rect_redFO[4].y + rect_redFO[4].h && player_redFO->cas[2].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,2);

                                printf("3");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[5].x && mouseXFO <= rect_redFO[5].x + rect_redFO[5].w &&  mouseYFO >= rect_redFO[5].y && mouseYFO <= rect_redFO[5].y + rect_redFO[5].h && player_redFO->cas[1].number_stones != 0)  {
                                move_stones(player_redFO,player_blueFO,1);
                                
                                printf("2");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }else if(mouseXFO >= rect_redFO[6].x && mouseXFO <= rect_redFO[6].x + rect_redFO[6].w &&  mouseYFO >= rect_redFO[6].y && mouseYFO <= rect_redFO[6].y + rect_redFO[6].h && player_redFO->cas[0].number_stones != 0) {
                                move_stones(player_redFO,player_blueFO,0);
                                
                                printf("1");
                                counter++;
                                currentPlayerFO = (counter%2); 
                            }
                            break;
                        }
                    }
                if(has_worn(player_blueFO,player_redFO)) worn = has_worn(player_blueFO,player_redFO);
            }
            break;
        }
        
        SDL_SetRenderDrawColor(renderFO, 180,120, 110, 255);
        SDL_RenderClear(renderFO);
        SDL_SetRenderDrawColor(renderFO, 115, 115, 50, 20);
        draw_board(renderFO);
        render_all_stonesFO(renderFO,&player_blueFO,&player_redFO,Table_Points);
        
        if(!worn){
            drawPlayerFO(renderFO,textRectFO,currentPlayerFO);
            renderPlayerFO(renderFO,fontFO,currentPlayerFO);
            SDL_RenderPresent(renderFO);
        }else {
            drawPlayerFO(renderFO,textRectFO,worn);
            display_Winner(renderFO,fontFO,worn); 
            SDL_RenderPresent(renderFO);
            sleep(10); break;
        }
    }

    free(path_blue0FO);
    free(path_blue1FO);
    free(path_blue2FO);
    free(path_blue3FO);
    free(path_blue4FO);
    free(path_blue5FO);
    free(path_blue6FO);
    free(path_Deposit_blueFO);

    free(path_red0FO);
    free(path_red1FO);
    free(path_red2FO);
    free(path_red3FO);
    free(path_red4FO);
    free(path_red5FO);
    free(path_red6FO);
    free(path_Deposit_redFO); 

    free(player_blueFO);
    free(player_redFO);

    TTF_CloseFont(fontFO);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderFO);
    SDL_DestroyWindow(windowFO);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

