#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {

    SDL_Point *path_yellowFO = (SDL_Point*)check_malloc(60 * sizeof(SDL_Point));
    SDL_Point *path_greenFO = (SDL_Point*)check_malloc(60 * sizeof(SDL_Point));
    SDL_Point *path_redFO = (SDL_Point*)check_malloc(60 * sizeof(SDL_Point));
    SDL_Point *path_blueFO = (SDL_Point*)check_malloc(60 * sizeof(SDL_Point));

    SDL_Point *path_yellow_homeFO = (SDL_Point*)check_malloc(4 * sizeof(SDL_Point));
    SDL_Point *path_green_homeFO = (SDL_Point*)check_malloc(4 * sizeof(SDL_Point));
    SDL_Point *path_red_homeFO = (SDL_Point*)check_malloc(4 * sizeof(SDL_Point));
    SDL_Point *path_blue_homeFO = (SDL_Point*)check_malloc(4 * sizeof(SDL_Point));

    Init_PathFO( path_yellow_homeFO, path_green_homeFO, path_red_homeFO, path_blue_homeFO, path_yellowFO, path_greenFO, path_redFO, path_blueFO);

    house_type house_GreenFO = (house_type)check_malloc(sizeof(house));
    house_type house_BlueFO = (house_type)check_malloc(sizeof(house));
    house_type house_YellowFO = (house_type)check_malloc(sizeof(house));
    house_type house_RedFO = (house_type)check_malloc(sizeof(house));

    house_type Ex_yellowFO[3] ={ house_BlueFO,house_GreenFO,house_RedFO};
    house_type Ex_greenFO[3] ={ house_BlueFO,house_YellowFO,house_RedFO};
    house_type Ex_redFO[3] ={ house_BlueFO,house_GreenFO,house_YellowFO};
    house_type Ex_blueFO[3] ={ house_YellowFO,house_GreenFO,house_RedFO};

    SDL_Point* Ex_yellow_FO[3] ={(path_blueFO),(path_greenFO),(path_redFO)};
    SDL_Point* Ex_green_FO[3] ={(path_blueFO),(path_yellowFO),(path_redFO)};
    SDL_Point* Ex_red_FO[3] ={(path_blueFO),(path_greenFO),(path_yellowFO)};
    SDL_Point* Ex_blue_FO[3] ={(path_yellowFO),(path_greenFO),(path_redFO)};

    int NumberOfPlayersFO;
    do{
        printf("Enter the number of players ->: ");
        scanf("%d",&NumberOfPlayersFO);
    }while(NumberOfPlayersFO<2 && NumberOfPlayersFO>5);

    
    INit_HousesFO(&house_YellowFO, &house_GreenFO, &house_RedFO, &house_BlueFO);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* windowFO= SDL_CreateWindow("CHRISTOTOP5 LUDO",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderFO = SDL_CreateRenderer(windowFO, -1, SDL_RENDERER_ACCELERATED);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderFO, "image.png");
    if (texture == NULL) {
        printf("Failed to load texture: %s\n", IMG_GetError());
    }

    TTF_Init();
    TTF_Font *fontFO = TTF_OpenFont("calibri.ttf", 100); 
   
    

    int seedtoplayFO = 0;
    SDL_Event eventFO;
    SDL_bool quit = SDL_FALSE;
    int diceValueFO = 0;
    int currentPlayerFO = 0;

    // Declare the dice button rectangle
    SDL_Rect diceButtonFO = {x_position + (General_size / 2) - cell_size,  y_position + (General_size / 2) - cell_size, 2 * cell_size, 2 * cell_size}; 
    SDL_Rect uppFO = {0,0,(2*x_position)+General_size,y_position};
    SDL_Rect lefFO = {0,0,x_position,(y_position*2)+General_size};
    SDL_Rect rightFO = {x_position+General_size,0,x_position,(y_position*2)+General_size};
    SDL_Rect downFO = {0,y_position+General_size,(x_position*2)+General_size,y_position};

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

                if (mouseXFO >= diceButtonFO.x && mouseXFO <= diceButtonFO.x + diceButtonFO.w &&  mouseYFO >= diceButtonFO.y && mouseYFO <= diceButtonFO.y + diceButtonFO.h) {
                    diceValueFO = roll_dice(); 

                    currentPlayerFO =( seedtoplayFO % NumberOfPlayersFO);
                    if(diceValueFO != 6) {
                        if(currentPlayerFO == 0 && has_worn(house_GreenFO)){
                            seedtoplayFO += 2;
                        }else if(currentPlayerFO ==1 && has_worn(house_RedFO) ){
                            seedtoplayFO +=2;
                        }else if(currentPlayerFO ==2 && has_worn(house_BlueFO)){
                            seedtoplayFO += 2;
                        }else if(currentPlayerFO == 3 && has_worn(house_YellowFO) ){
                            seedtoplayFO += 2;
                        }else {
                            seedtoplayFO++;
                        }
                    }
                    
                    printf("Rolled: %d\n", diceValueFO);
                
                    switch (currentPlayerFO) {
                        case 0:  // Yellow's turn
                            printf("Yellow\n");
                            if(!has_worn(house_YellowFO)){
                                handleSeedMovementFO(renderFO,house_YellowFO, path_yellowFO, diceValueFO,path_yellow_homeFO,fontFO,diceButtonFO,uppFO,lefFO,rightFO,downFO,0,Ex_yellowFO,Ex_yellow_FO);
                            }
                            break;

                        case 1:  // Green's turn
                        printf("green\n");
                        if(!has_worn(house_GreenFO)){
                            handleSeedMovementFO(renderFO,house_GreenFO, path_greenFO, diceValueFO,path_green_homeFO,fontFO,diceButtonFO,uppFO,lefFO,rightFO,downFO,1,Ex_greenFO,Ex_green_FO);
                        }
                            break;

                        case 2:  // Red's turn
                            printf("red\n");
                            if(!has_worn(house_RedFO)){
                                handleSeedMovementFO(renderFO,house_RedFO, path_redFO, diceValueFO,path_red_homeFO,fontFO,diceButtonFO,uppFO,lefFO,rightFO,downFO,2,Ex_redFO,Ex_red_FO);
                            }
                            break;
                        case 3:  // Blue's turn
                            printf("blue\n");
                            if(!has_worn(house_BlueFO)){
                                handleSeedMovementFO(renderFO,house_BlueFO, path_blueFO, diceValueFO,path_blue_homeFO,fontFO,diceButtonFO,uppFO,lefFO,rightFO,downFO,3,Ex_blueFO,Ex_blue_FO);
                            }
                            break;
                    }
                } 
            }
            break;        
        }
        
        SDL_SetRenderDrawColor(renderFO, 0, 0, 0, 255);
        SDL_RenderClear(renderFO);
        SDL_SetRenderDrawColor(renderFO, 115, 115, 50, 20);
        drow_bord(renderFO);

        drawDiceButtonFO(renderFO, uppFO,currentPlayerFO);
        drawDiceButtonFO(renderFO, lefFO,currentPlayerFO);
        drawDiceButtonFO(renderFO, rightFO,currentPlayerFO);
        drawDiceButtonFO(renderFO, downFO,currentPlayerFO);
        drawDiceButtonFO(renderFO, diceButtonFO,currentPlayerFO);
        renderDiceResultFO(renderFO, diceValueFO, fontFO);

        render_all_seedsFO(renderFO, house_YellowFO, house_GreenFO, house_RedFO, house_BlueFO, path_yellow_homeFO, path_green_homeFO, path_red_homeFO, path_blue_homeFO,path_yellowFO, path_greenFO, path_redFO, path_blueFO);

        SDL_RenderPresent(renderFO);

        
        printf("End\n");
        SDL_Delay(16);
    }


    free(path_yellowFO);
    free(path_greenFO);
    free(path_redFO);
    free(path_blueFO);

    free(path_yellow_homeFO);
    free(path_green_homeFO);
    free(path_red_homeFO);
    free(path_blue_homeFO);

    free(house_YellowFO);
    free(house_GreenFO);
    free(house_RedFO);
    free(house_BlueFO);

    TTF_CloseFont(fontFO);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderFO);
    SDL_DestroyWindow(windowFO);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}


