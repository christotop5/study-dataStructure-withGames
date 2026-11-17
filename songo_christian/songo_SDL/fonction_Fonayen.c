#include "fonction_Fonayen.h"

void draw_board(SDL_Renderer *render){  

    ellipseRGBA(render, x_position + (General_wight/2)  , y_position + (cell_size*7) ,  x_position,  y_position,  0,  0, 0, 0);

    ellipseRGBA(render,x_position  + (General_wight/2) ,y_position  +  (cell_size*38) , x_position,  y_position,  0,  0, 0, 0 );

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
    // for(int i=0;i<=General_wight;i+=(cell_size)){
    //     for(int j=0;j<=General_length;j+=cell_size){
    //         SDL_Rect smalls = {
    //             .x = x_position+(i),
    //             .y = y_position+(j),
    //             .h = cell_size,
    //             .w = cell_size,
    //         };
            
    //         SDL_SetRenderDrawColor(render,0,0,0,255);
    //         SDL_RenderDrawRect(render,&smalls);   
    //     }
    // }
    filledEllipseRGBA(render,  y_position + (cell_size*3) , x_position + (General_length/2)  ,  big_Ellipse_X_radius,  big_Ellipse_Y_radius,  255,  0, 0, 200);
    filledEllipseRGBA(render,   y_position + (cell_size*41),x_position + (General_length/2) , big_Ellipse_X_radius,  big_Ellipse_Y_radius,  0,  0, 255, 200);

    for(int i = 7;i<40;i+=5){
        filledEllipseRGBA(render, x_position + (cell_size*i),y_position + (General_length/6) , small_Ellipse_X_radius,  small_Ellipse_Y_radius,  0,  0, 255, 200);
        filledEllipseRGBA(render, x_position + (cell_size*i),y_position + ((General_length*2.5)/3), small_Ellipse_X_radius,  small_Ellipse_Y_radius,  255,  0, 0, 200);
    }

}

void drawLargeCircle(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 100, 57, 62, 155); 
    circleRGBA(render, x, y, radius, 0, 0, 0, 255);  
}

void draw_stone(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x+cell_center, y+cell_center, radius, 0, 0, 0, 220);
}

void* check_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void Init_PathFO(SDL_Point* path_blue0FO,SDL_Point* path_blue1FO,SDL_Point* path_blue2FO,SDL_Point* path_blue3FO,SDL_Point* path_blue4FO,SDL_Point* path_blue5FO,SDL_Point* path_blue6FO,SDL_Point* path_Deposit_blueFO,SDL_Point* path_red0FO,SDL_Point* path_red1FO,SDL_Point* path_red2FO,SDL_Point* path_red3FO,SDL_Point* path_red4FO,SDL_Point* path_red5FO,SDL_Point* path_red6FO,SDL_Point* path_Deposit_redFO){
    int a =0;
    for(int i = 5;i<=8;i++){
        for(int j =3;j<=6; j++){
            path_blue0FO[a].x = x_position + (cell_size*i); path_blue0FO[a].y =  y_position + (cell_size*j);  
            path_blue1FO[a].x = x_position + (cell_size*(i+5)); path_blue1FO[a].y =  y_position + (cell_size*j); 
            path_blue2FO[a].x = x_position + (cell_size*(i+10)); path_blue2FO[a].y =  y_position + (cell_size*j); 
            path_blue3FO[a].x = x_position + (cell_size*(i+15)); path_blue3FO[a].y =  y_position + (cell_size*j); 
            path_blue4FO[a].x = x_position + (cell_size*(i+20)); path_blue4FO[a].y =  y_position + (cell_size*j); 
            path_blue5FO[a].x = x_position + (cell_size*(i+25)); path_blue5FO[a].y =  y_position + (cell_size*j); 
            path_blue6FO[a].x = x_position + (cell_size*(i+30)); path_blue6FO[a].y =  y_position + (cell_size*j); 


            path_red6FO[a].x = x_position + (cell_size*i); path_red6FO[a].y =  y_position + (cell_size*(19+j));  
            path_red5FO[a].x = x_position + (cell_size*(i+5)); path_red5FO[a].y =  y_position + (cell_size*(19+j)); 
            path_red4FO[a].x = x_position + (cell_size*(i+10)); path_red4FO[a].y =  y_position + (cell_size*(19+j)); 
            path_red3FO[a].x = x_position + (cell_size*(i+15)); path_red3FO[a].y =  y_position + (cell_size*(19+j)); 
            path_red2FO[a].x = x_position + (cell_size*(i+20)); path_red2FO[a].y =  y_position + (cell_size*(19+j)); 
            path_red1FO[a].x = x_position + (cell_size*(i+25)); path_red1FO[a].y =  y_position + (cell_size*(19+j)); 
            path_red0FO[a].x = x_position + (cell_size*(i+30)); path_red0FO[a].y =  y_position + (cell_size*(19+j)); 
            
            
            a++; 
        }
    }
    a = 0;
    for(int i = 1;i<=5;i++){
        for(int j =8;j<=20; j++){
            path_Deposit_redFO[a].x = x_position + (cell_size*i); path_Deposit_redFO[a].y =  y_position + (cell_size*j);
            path_Deposit_blueFO[a].x = x_position + (cell_size*(i+38));path_Deposit_blueFO[a].y = y_position + (cell_size*(j));
            a++;
        }
    }  
    return;
}

void Init_PlayerFO(player_type *player_blueFO,player_type *player_redFO){
    (*player_blueFO)->colour = 2;
    (*player_redFO)->colour = 1;

    (*player_blueFO)->number_captured_stones = 0;
    (*player_redFO)->number_captured_stones = 0;

    (*player_blueFO)->deposit.number_stones = 0;
    (*player_redFO)->deposit.number_stones = 0;

    (*player_blueFO)->deposit.player = 2;
    (*player_redFO)->deposit.player = 1;

    for(int i=0; i<7; i++){
        (*player_blueFO)->cas[i].number_stones = 5;
        (*player_redFO)->cas[i].number_stones = 5;

        (*player_blueFO)->cas[i].player = 2;
        (*player_redFO)->cas[i].player = 1;
    }
}

void render_stoneFO(SDL_Renderer *render, case_type cas, SDL_Point *pathFO){
    for(int i =0; i<cas.number_stones;i++){
        draw_stone(render,pathFO[i].x,pathFO[i].y,stone_radius);
    }    
}

void render_all_stonesFO(SDL_Renderer *render ,player_type *player_blueFO,player_type *player_redFO,SDL_Point* Table_Points[16]){
    render_stoneFO(render,(*player_blueFO)->deposit,Table_Points[7]);
    render_stoneFO(render,(*player_redFO)->deposit,Table_Points[15]);
    for(int i=0;i<7;i++){
        render_stoneFO(render,(*player_blueFO)->cas[i],Table_Points[i]);
        render_stoneFO(render,(*player_redFO)->cas[i],Table_Points[8+i]);
    }
}

void drawPlayerFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO,int identifier ) {
    switch (identifier){
        case 0:
            SDL_SetRenderDrawColor(renderFO, 0, 0, 250, 200);
            break;
        case 1:
            SDL_SetRenderDrawColor(renderFO, 250, 0, 0, 200);
            break;
        case 2:
            SDL_SetRenderDrawColor(renderFO, 0, 0, 255, 200);
            break;
    }
    SDL_RenderFillRect(renderFO, &diceButtonFO);
}

void renderPlayerFO(SDL_Renderer *renderFO, TTF_Font *fontFO , int identifier ) {
    SDL_Color whiteFO = {205, 205, 205};

    if(identifier == 0){

            SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, "Player1's Turn", whiteFO);
            SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

            SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size};   // Adjust for position and size
            SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

            SDL_FreeSurface(surfaceFO);
            SDL_DestroyTexture(textureFO);
            return;
    }else{
             SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, "Player2's Turn", whiteFO);
            SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

            SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size};   // Adjust for position and size
            SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

            SDL_FreeSurface(surfaceFO);
            SDL_DestroyTexture(textureFO);
            return;
    }
    
}

void move_stones(player_type current_player, player_type opponent_player, int start_pit) {
    int pit_index = start_pit + 1;

    while(pit_index < 7){
        if(current_player->cas[start_pit].number_stones == 0) break;
        current_player->cas[pit_index].number_stones++;
        current_player->cas[start_pit].number_stones--;    
        pit_index++;   
    }pit_index = 0;
                
    while(pit_index < 7){
        if(current_player->cas[start_pit].number_stones == 0) break;
        opponent_player->cas[pit_index].number_stones++ ;
        current_player->cas[start_pit].number_stones--;    
        pit_index++;   
    }pit_index = 0;

    while(pit_index < 7){
        if(current_player->cas[start_pit].number_stones == 0) break;
        current_player->cas[pit_index].number_stones++;
        current_player->cas[start_pit].number_stones--;    
        pit_index++;   
    }pit_index = 0;

    while(pit_index < 7){
        if(current_player->cas[start_pit].number_stones == 0) break;
        opponent_player->cas[pit_index].number_stones++ ;
        current_player->cas[start_pit].number_stones--;    
        pit_index++;   
    }pit_index = 0;

    while( pit_index < 7){
        if(current_player->cas[start_pit].number_stones == 0) break;
        current_player->cas[pit_index].number_stones++;
        current_player->cas[start_pit].number_stones--;    
        pit_index++;   
    }
        
    for(int i=0; i<7;i++){
        if(current_player->cas[i].number_stones==2 ){
            current_player->deposit.number_stones +=2;
            current_player->cas[i].number_stones = 0;
        }else if(current_player->cas[i].number_stones==3){
            current_player->deposit.number_stones +=3;
            current_player->cas[i].number_stones = 0;
        }else if(current_player->cas[i].number_stones==4){
            current_player->deposit.number_stones +=4;
            current_player->cas[i].number_stones = 0;
        }
        if(opponent_player->cas[i].number_stones==2){
            current_player->deposit.number_stones +=2;
            opponent_player->cas[i].number_stones =0;
        }else if(opponent_player->cas[i].number_stones==3){
            current_player->deposit.number_stones +=3;
            opponent_player->cas[i].number_stones =0;
        }else if(opponent_player->cas[i].number_stones==4){
            current_player->deposit.number_stones +=4;
            opponent_player->cas[i].number_stones =0;
        }
    }
}

int has_worn(player_type player1,player_type player2){
    if(player1->deposit.number_stones>35) return 2;
    if(player2->deposit.number_stones>35) return 1;
    return 0;
}
void display_Winner(SDL_Renderer *renderFO, TTF_Font *fontFO , int identifier  ){
    SDL_Color whiteFO = {205, 205, 205};

    if(identifier == 2){
            SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, "Player BLUE Worn", whiteFO);
            SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

            SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size};   // Adjust for position and size
            SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

            SDL_FreeSurface(surfaceFO);
            SDL_DestroyTexture(textureFO);
            return;
    }else if(identifier == 1){
            SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, "Player RED Worn", whiteFO);
            SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

            SDL_Rect textRectFO = {x_position+(General_wight/2)-(cell_size*15), y_position+(General_length/2)-(cell_size*4),29*cell_size,8*cell_size};   // Adjust for position and size
            SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

            SDL_FreeSurface(surfaceFO);
            SDL_DestroyTexture(textureFO);
            return;
    }
}









