#include "fonction_Fonayen.h"

void drow_bord(SDL_Renderer *render){  
	
	SDL_Rect mid={
		.x = x_position +(2*(General_size/5)),
		.y = y_position +(2*(General_size/5)),
		.h = General_size/5,
		.w = General_size/5
	};
	SDL_Rect green_home={
		.x = x_position,
		.y = y_position,
		.h = 2 *(General_size/5),
		.w = 2 *(General_size/5)
	};
	SDL_Rect yellow_home={
		.x = x_position,
		.y = y_position +(3*(General_size/5)),
		.h = 2*(General_size/5),
		.w = 2*(General_size/5)
	};
	SDL_Rect red_home={
		.x = x_position+(3*(General_size/5)),
		.y = y_position +(3*(General_size/5)),
		.h = 2 *(General_size/5),
		.w = 2*(General_size/5)
	};
	SDL_Rect blue_home={
		.x = x_position+(3*(General_size/5)),
		.y = y_position,
		.h = 2 *(General_size/5),
		.w = 2*(General_size/5)
	};
	SDL_Rect Larg_rect ={
		.x = x_position,
		.y = y_position,
		.h = General_size,
		.w = General_size
	};
    
	SDL_RenderFillRect(render,&Larg_rect);
	SDL_SetRenderDrawColor(render,0,0,0,0);

       for(int i=0;i<=General_size;i+=(cell_size)){
        for(int j=0;j<=General_size;j+=cell_size){
            SDL_Rect smalls = {
                .x = x_position+(i),
                .y = y_position+(j),
                .h = cell_size,
                .w = cell_size,
            };
            if((j==7*(cell_size) && i>=(cell_size) && i<=5*(cell_size) )|| (j==6*(cell_size) && i==(cell_size) )){
                SDL_SetRenderDrawColor(render,0,255,0,255);
                SDL_RenderFillRect(render,&smalls);
                SDL_SetRenderDrawColor(render,0,0,0,255);
                SDL_RenderDrawRect(render,&smalls);
            }else if((j==7*(cell_size) && i>=9*(cell_size) && i<=13*(cell_size) )|| (j==8*(cell_size) && i==13*(cell_size) )){
                SDL_SetRenderDrawColor(render,0,0,255,255);
                SDL_RenderFillRect(render,&smalls);
                SDL_SetRenderDrawColor(render,0,0,0,255);
                SDL_RenderDrawRect(render,&smalls);
            }else if((j>=(cell_size) && i==  7*(cell_size) && j<=5*(cell_size) )|| (i==8*(cell_size) && j==(cell_size) )){
                SDL_SetRenderDrawColor(render,255,0,0,255);
                SDL_RenderFillRect(render,&smalls);
                SDL_SetRenderDrawColor(render,0,0,0,255);
                SDL_RenderDrawRect(render,&smalls);
            }else if((i==7*(cell_size) && j>=9*(cell_size) && j<=13*(cell_size) )|| (i==6*(cell_size) && j==13*(cell_size) )){
                SDL_SetRenderDrawColor(render,255,255,0,0);
                SDL_RenderFillRect(render,&smalls);
                SDL_SetRenderDrawColor(render,0,0,0,255);
                SDL_RenderDrawRect(render,&smalls);
            }else{
                SDL_SetRenderDrawColor(render,0,0,0,55);
                SDL_RenderDrawRect(render,&smalls);
            }
        }
    }
    
    SDL_SetRenderDrawColor(render,0,255,0,250);
	SDL_RenderFillRect(render,&green_home);
	SDL_SetRenderDrawColor(render,255,255,0,250);
	SDL_RenderFillRect(render,&yellow_home);
	SDL_SetRenderDrawColor(render,0,0,255,250);
	SDL_RenderFillRect(render,&red_home);
	SDL_SetRenderDrawColor(render,255,0,0,250);
	SDL_RenderFillRect(render,&blue_home);
	SDL_SetRenderDrawColor(render,0,0,0,255);
	SDL_RenderFillRect(render,&mid);
    SDL_SetRenderDrawColor(render,0,0,0,255);

    drawLargeCircle(render,x_position+3*(cell_size),y_position+3*(cell_size),General_size/6);    
    drawLargeCircle(render,x_position+12*(cell_size),y_position+12*(cell_size),General_size/6); 
    drawLargeCircle(render,x_position+12*(cell_size),y_position+3*(cell_size),General_size/6); 
    drawLargeCircle(render,x_position+3*(cell_size),y_position+12*(cell_size),General_size/6); 
    
}

void drawLargeCircle(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 100, 57, 62, 155); 
    circleRGBA(render, x, y, radius, 0, 0, 0, 255);  
}

void drawMiniCircleRed(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 255, 0, 0, 255);
    for(int v=0;v<4;v++){  
       circleRGBA(render, x-v, y+v, radius+v, 0, 0, 0, 255);
    } 
}

void drawMiniCircleGreen(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 0, 255, 0, 255);
    for(int v=0;v<4;v++){  
       circleRGBA(render, x+v, y+v, radius+v, 0, 0, 0, 255);
    } 
       
}

void drawMiniCircleYellow(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 255, 255, 0, 255);
    for(int v=0;v<4;v++){  
       circleRGBA(render, x+v, y+v, radius+v, 0, 0, 0, 255);
    }  
}

void drawMiniCircleBLue(SDL_Renderer *render, int x, int y, int radius) {
    filledCircleRGBA(render, x, y, radius, 0, 0, 255, 255);
    for(int v=0;v<4;v++){  
       circleRGBA(render, x-v, y+v, radius+v, 0, 0, 0, 255);
    }  
}

void* check_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void Init_PathFO(SDL_Point *path_yellow,SDL_Point *path_green,SDL_Point *path_red,SDL_Point *path_blue,SDL_Point *pathway_yellow,SDL_Point *pathway_green,SDL_Point *pathway_red,SDL_Point *pathway_blue){

    {
    pathway_yellow[50].x = x_position + (7*cell_size)+cell_center; pathway_yellow[50].y =y_position + (14*cell_size) + (cell_center);
    pathway_yellow[11].x = x_position + cell_center; pathway_yellow[11].y = y_position+(7*cell_size)+(cell_center);
    pathway_yellow[24].x = x_position + (7*cell_size)+(cell_center); pathway_yellow[24].y = y_position+cell_center ;
    pathway_yellow[37].x = x_position + (14*cell_size)+(cell_center); pathway_yellow[37].y = y_position+(7*cell_size)+cell_center;

    pathway_yellow[56].x = x_position +(cell_center); pathway_yellow[56].y = y_position + (General_size) +(cell_center);
    pathway_yellow[57].x = x_position +(cell_center*2); pathway_yellow[57].y = y_position + (General_size) +(cell_center);
    pathway_yellow[58].x = x_position +(cell_center*3); pathway_yellow[58].y = y_position + (General_size) +(cell_center);
    pathway_yellow[59].x = x_position +(cell_center*4); pathway_yellow[59].y = y_position + (General_size) +(cell_center);

    int a=13;
    for(int i=0;i<5;i++){
        pathway_yellow[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (a*cell_size)+cell_center;a--;

    }
    a=5;
    for(int i=5;i<11;i++){
        pathway_yellow[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a=0;
    for(int i=12;i<18;i++){
        pathway_yellow[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 5;
    for(int i=18;i<24;i++){
        pathway_yellow[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a = 0;
    for(int i=25;i<31;i++){
        pathway_yellow[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a=9;
    for(int i=31;i<37;i++){
        pathway_yellow[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 14;
    for(int i=38;i<44;i++){
        pathway_yellow[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a = 9;
    for(int i=44;i<50;i++){
        pathway_yellow[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_yellow[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a = 13;
    for(int i=51;i<56;i++){
        pathway_yellow[i].x = x_position+7*(cell_size)+seed_radus; pathway_yellow[i].y = y_position+a*(cell_size)+seed_radus,seed_radus; a--;}
    }

    {
    pathway_green[37].x = x_position + (7*cell_size)+cell_center; pathway_green[37].y =y_position + (14*cell_size) + (cell_center);
    pathway_green[50].x = x_position + cell_center; pathway_green[50].y = y_position+(7*cell_size)+(cell_center);
    pathway_green[11].x = x_position + (7*cell_size)+(cell_center); pathway_green[11].y = y_position+cell_center ;
    pathway_green[24].x = x_position + (14*cell_size)+(cell_center); pathway_green[24].y = y_position+(7*cell_size)+cell_center ;

    pathway_green[56].x = x_position +(cell_center); pathway_green[56].y = y_position -(cell_center);
    pathway_green[57].x = x_position +(cell_center*2); pathway_green[57].y = y_position -(cell_center);
    pathway_green[58].x = x_position +(cell_center*3); pathway_green[58].y = y_position -(cell_center);
    pathway_green[59].x = x_position +(cell_center*4); pathway_green[59].y = y_position -(cell_center);

    int a=14;
    for(int i=38;i<44;i++){
        pathway_green[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a=5;
    for(int i=44;i<50;i++){
        pathway_green[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a=1;
    for(int i=0;i<5;i++){
        pathway_green[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 5;
    for(int i=5;i<11;i++){
        pathway_green[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a = 0;
    for(int i=12;i<18;i++){
        pathway_green[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a=9;
    for(int i=18;i<24;i++){
        pathway_green[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 14;
    for(int i=25;i<31;i++){
        pathway_green[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a = 9;
    for(int i=31;i<37;i++){
       pathway_green[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_green[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a = 1;
    for(int i=51;i<56;i++){
        pathway_green[i].x = x_position+a*(cell_size)+seed_radus; pathway_green[i].y = y_position+7*(cell_size)+seed_radus; a++;}
    }

    {
    pathway_red[24].x = x_position + (7*cell_size)+cell_center; pathway_red[24].y =y_position + (14*cell_size) + (cell_center);
    pathway_red[37].x = x_position + cell_center; pathway_red[37].y = y_position+(7*cell_size)+(cell_center);
    pathway_red[50].x = x_position + (7*cell_size)+(cell_center); pathway_red[50].y = y_position+cell_center ;
    pathway_red[11].x = x_position + (14*cell_size)+(cell_center); pathway_red[11].y = y_position+(7*cell_size)+cell_center ;

    pathway_red[56].x =  x_position + (General_size) -(cell_center); pathway_red[56].y = y_position - (cell_center);
    pathway_red[57].x =  x_position + (General_size) -(cell_center*2); pathway_red[57].y = y_position - (cell_center);
    pathway_red[58].x =  x_position + (General_size) -(cell_center*3); pathway_red[58].y = y_position - (cell_center);
    pathway_red[59].x =  x_position + (General_size) -(cell_center*4); pathway_red[59].y = y_position - (cell_center);

    int a=14;
    for(int i=25;i<31;i++){
        pathway_red[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a=5;
    for(int i=31;i<37;i++){
        pathway_red[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a=0;
    for(int i=38;i<44;i++){
        pathway_red[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 5;
    for(int i=44;i<50;i++){
        pathway_red[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a = 1;
    for(int i=0;i<5;i++){
        pathway_red[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a=9;
    for(int i=5;i<11;i++){
        pathway_red[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 14;
    for(int i=12;i<18;i++){
        pathway_red[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a = 9;
    for(int i=18;i<24;i++){
       pathway_red[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_red[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    
    a = 1;
    for(int i=51;i<56;i++){
        pathway_red[i].x = x_position+7*(cell_size)+seed_radus; pathway_red[i].y = y_position+a*(cell_size)+seed_radus; a++;
    }}

    {
    pathway_blue[11].x = x_position + (7*cell_size)+cell_center; pathway_blue[11].y =y_position + (14*cell_size) + (cell_center);
    pathway_blue[24].x = x_position + cell_center; pathway_blue[24].y = y_position+(7*cell_size)+(cell_center);
    pathway_blue[37].x = x_position + (7*cell_size)+(cell_center); pathway_blue[37].y = y_position+cell_center ;
    pathway_blue[50].x = x_position + (14*cell_size)+(cell_center); pathway_blue[50].y = y_position+(7*cell_size)+cell_center ;

    pathway_blue[56].x =  x_position + (General_size) -(cell_center); pathway_blue[56].y = y_position + (General_size) +(cell_center);
    pathway_blue[57].x =  x_position + (General_size) -(cell_center*2); pathway_blue[57].y = y_position + (General_size) +(cell_center);
    pathway_blue[58].x =  x_position + (General_size) -(cell_center*3); pathway_blue[58].y = y_position + (General_size) +(cell_center);
    pathway_blue[59].x =  x_position + (General_size) -(cell_center*4); pathway_blue[59].y = y_position + (General_size) +(cell_center);

    int a=14;
    for(int i=12;i<18;i++){
        pathway_blue[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (a*cell_size)+cell_center;a--;

    }
    a=5;
    for(int i=18;i<24;i++){
        pathway_blue[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a=0;
    for(int i=25;i<31;i++){
        pathway_blue[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 5;
    for(int i=31;i<37;i++){
        pathway_blue[i].x = x_position + (6*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (a*cell_size)+cell_center;a--;
    }
    a = 0;
    for(int i=38;i<44;i++){
        pathway_blue[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    a=9;
    for(int i=44;i<50;i++){
        pathway_blue[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (6*cell_size)+cell_center;a++;
    }
    a = 13;
    for(int i=0;i<5;i++){
        pathway_blue[i].x = x_position + (a*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (8*cell_size)+cell_center;a--;
    }
    a = 9;
    for(int i=5;i<11;i++){
       pathway_blue[i].x = x_position + (8*cell_size)+(cell_center) ; pathway_blue[i].y = y_position + (a*cell_size)+cell_center;a++;
    }
    
    a = 13;
    for(int i=51;i<56;i++){
        pathway_blue[i].x = x_position+a*(cell_size)+seed_radus; pathway_blue[i].y = y_position+7*(cell_size)+seed_radus; a--;
    }
    }

    {
    int u=0;  
    for(int i =2;i<=4;i+=2){
        for(int j=11;j<=13;j+=2){
           path_yellow[u].x =x_position+(i*cell_size); path_yellow[u].y=y_position+(j*cell_size),seed_radus;u++;
        }
    }

    u=0;  
    for(int i =2;i<=4;i+=2){
        for(int j=2;j<=4;j+=2){
           path_green[u].x =x_position+(i*cell_size); path_green[u].y=y_position+(j*cell_size),seed_radus;u++;
        }
    }

    u=0;  
    for(int i =11;i<=13;i+=2){
        for(int j=2;j<=4;j+=2){
           path_red[u].x =x_position+(i*cell_size); path_red[u].y=y_position+(j*cell_size),seed_radus;u++;
        }
    }

    u=0;  
    for(int i =11;i<=13;i+=2){
        for(int j=11;j<=13;j+=2){
           path_blue[u].x =x_position+(i*cell_size); path_blue[u].y=y_position+(j*cell_size),seed_radus;u++;
        }
    }}

    return;
}

void INit_HousesFO(house_type *yellow,house_type *green,house_type *red,house_type *blue){
    (*blue)->colour = 4;
    (*red)->colour = 3;
    (*green)->colour =2;
    (*yellow)->colour =1;

    (*blue)->seedNumber = 4;
    (*red)->seedNumber = 4;
    (*green)->seedNumber = 4;
    (*yellow)->seedNumber = 4;

    (*yellow)->seed1.state = 0;
    (*yellow)->seed2.state = 0;
    (*yellow)->seed3.state = 0;
    (*yellow)->seed4.state = 0;

    (*green)->seed1.state = 0;
    (*green)->seed2.state = 0;
    (*green)->seed3.state = 0;
    (*green)->seed4.state = 0;

    (*red)->seed1.state = 0;
    (*red)->seed2.state = 0;
    (*red)->seed3.state = 0;
    (*red)->seed4.state = 0;

    (*blue)->seed1.state = 0;
    (*blue)->seed2.state = 0;
    (*blue)->seed3.state = 0;
    (*blue)->seed4.state = 0;
    
    (*red)->seed1.player = 2;
    (*red)->seed2.player = 2;
    (*red)->seed3.player = 2;
    (*red)->seed4.player = 2;

    (*yellow)->seed1.player =0;
    (*yellow)->seed2.player =0;
    (*yellow)->seed3.player =0;
    (*yellow)->seed4.player =0;

    (*blue)->seed1.player =3;
    (*blue)->seed2.player =3;
    (*blue)->seed3.player =3;
    (*blue)->seed4.player =3;

    (*green)->seed1.player =1;
    (*green)->seed2.player =1;
    (*green)->seed3.player =1;
    (*green)->seed4.player =1;

    (*green)->seed1.position =-1;
    (*green)->seed2.position =-1;
    (*green)->seed3.position =-1;
    (*green)->seed4.position =-1;

    (*yellow)->seed1.position =-1;
    (*yellow)->seed2.position =-1;
    (*yellow)->seed3.position =-1;
    (*yellow)->seed4.position =-1;

    (*blue)->seed1.position =-1;
    (*blue)->seed2.position =-1;
    (*blue)->seed3.position =-1;
    (*blue)->seed4.position =-1;

    (*red)->seed1.position =-1;
    (*red)->seed2.position =-1;
    (*red)->seed3.position =-1;
    (*red)->seed4.position =-1;
    

}

void move_seedFO(seed_type *player_token, int dice_value,house_type *other,SDL_Point **Homes,SDL_Point *thisHome) {
    if (player_token->state == 1 && ((*player_token).position + dice_value) < 56) {  
        (*player_token).position += dice_value;
  
        for(int i=0;i<3;i++){
            for(int se=0;se<4;se++){  
                switch (se){
                case 0:
                    if((thisHome)[(*player_token).position].x == (Homes[i])[(other[i])->seed1.position].x  && (thisHome)[(*player_token).position].y == (Homes[i])[(other[i])->seed1.position].y){
                        (other[i])->seed1.position =-1;
                        (other[i])->seed1.state =0;
                        other[i]->seedNumber++;
                        return;
                    }
                    break;
                case 1:
                    if((thisHome)[(*player_token).position].x == (Homes[i])[(other[i])->seed2.position].x && (thisHome)[(*player_token).position].y == (Homes[i])[(other[i])->seed2.position].y){
                        (other[i])->seed2.position =-1;
                        (other[i])->seed2.state =0;
                        other[i]->seedNumber++;
                        return;
                    }
                    break;
                case 2:
                    if((thisHome)[(*player_token).position].x == (Homes[i])[(other[i])->seed3.position].x && (thisHome)[(*player_token).position].y == (Homes[i])[(other[i])->seed3.position].y){
                        (other[i])->seed3.position =-1;
                        (other[i])->seed3.state =0;
                        other[i]->seedNumber++;
                        return;
                    }
                    break;
                case 3:
                    if((thisHome)[(*player_token).position].x == (Homes[i])[(other[i])->seed4.position].x  && (thisHome)[(*player_token).position].y == (Homes[i])[(other[i])->seed4.position].y){
                        (other[i])->seed4.position =-1;
                        (other[i])->seed4.state =0;
                        other[i]->seedNumber++;
                        return;
                    }
                    break;
                }
            }
        }

    }else if (((*player_token).position + dice_value) == 56){
        (*player_token).position = 56;
        (*player_token).state = 2;
    }else {
        (*player_token).position = (*player_token).position;
    }
}

int roll_dice(){
    srand(time(NULL));
    return (rand() % 6 )+1;
}

void render_all_seedsFO(SDL_Renderer *render, house_type house_YellowFO, house_type house_GreenFO, house_type house_RedFO, house_type house_BlueFO,  SDL_Point *home_yellow, SDL_Point *home_green,  SDL_Point *home_red, SDL_Point *home_blue, SDL_Point *path_yellow,SDL_Point *path_green, SDL_Point *path_red,SDL_Point *path_blue){
    house_type houses[4] = { house_YellowFO, house_GreenFO, house_RedFO, house_BlueFO };
    SDL_Point path[4] = {(*home_yellow),(*home_green),(*home_red),(*home_blue)};

    for (int player = 0; player < 4; player++) {
        seed_type *seed = NULL;

        switch (player) {
            case 0: seed = &(houses[player]->seed1);  render_seedFO(render, *seed, path_yellow, home_yellow[player]); break; // Yellow
            case 1: seed = &(houses[player]->seed1);  render_seedFO(render, *seed, path_green, home_green[0]);  break;// Green
            case 2: seed = &(houses[player]->seed1);  render_seedFO(render, *seed, path_red, home_red[0]);    break;// Red
            case 3: seed = &(houses[player]->seed1);  render_seedFO(render, *seed, path_blue, home_blue[0]);   break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed2); render_seedFO(render, *seed, path_yellow, home_yellow[1]);  break; // Yellow
            case 1: seed = &(houses[player]->seed2); render_seedFO(render, *seed, path_green, home_green[1]);   break;// Green
            case 2: seed = &(houses[player]->seed2); render_seedFO(render, *seed, path_red, home_red[1]);     break; // Red
            case 3: seed = &(houses[player]->seed2); render_seedFO(render, *seed, path_blue, home_blue[1]);    break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed3);  render_seedFO(render, *seed, path_yellow, home_yellow[2]);  break; // Yellow
            case 1: seed = &(houses[player]->seed3);  render_seedFO(render, *seed, path_green, home_green[2]);   break;// Green
            case 2: seed = &(houses[player]->seed3);  render_seedFO(render, *seed, path_red, home_red[2]);     break;// Red
            case 3: seed = &(houses[player]->seed3);  render_seedFO(render, *seed, path_blue, home_blue[2]);    break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed4);  render_seedFO(render, *seed, path_yellow, home_yellow[3]);  break; // Yellow
            case 1: seed = &(houses[player]->seed4);  render_seedFO(render, *seed, path_green, home_green[3]);   break;// Green
            case 2: seed = &(houses[player]->seed4);  render_seedFO(render, *seed, path_red, home_red[3]);     break;// Red
            case 3: seed = &(houses[player]->seed4);  render_seedFO(render, *seed, path_blue, home_blue[3]);    break;// Blue
        }
    }
}

void render_seedFO(SDL_Renderer *render, seed_type seed, SDL_Point *pathFO, SDL_Point homePathFO) {
    // Check if the seed is at home
    if (seed.state == 0) { // If at home
        // Render the seed at its home position
        switch (seed.player) {
            case 0: // Yellow player
                drawMiniCircleYellow(render, homePathFO.x, homePathFO.y, seed_radus);
                break;
            case 1: // Green player
                drawMiniCircleGreen(render, homePathFO.x, homePathFO.y, seed_radus);
                break;
            case 2: // Red player
                drawMiniCircleRed(render, homePathFO.x, homePathFO.y, seed_radus);
                break;
            case 3: // Blue player
                drawMiniCircleBLue(render, homePathFO.x, homePathFO.y, seed_radus);
                break;
        }
        
    } else { // Render the seed on the main path
        switch (seed.player) {
            case 0: drawMiniCircleYellow(render, pathFO[seed.position].x, pathFO[seed.position].y, seed_radus); break;  // Yellow
            case 1: drawMiniCircleGreen(render, pathFO[seed.position].x, pathFO[seed.position].y, seed_radus); break;  // Green
            case 2: drawMiniCircleRed(render, pathFO[seed.position].x, pathFO[seed.position].y, seed_radus); break;  // Red
            case 3: drawMiniCircleBLue(render, pathFO[seed.position].x, pathFO[seed.position].y, seed_radus); break;  // Blue
        }
    }
}

void drawDiceButtonFO(SDL_Renderer *renderFO,SDL_Rect diceButtonFO,int identifier ) {
    switch (identifier){
        case 0:
            SDL_SetRenderDrawColor(renderFO, 200, 200, 0, 90); 
            break;
        case 1:
            SDL_SetRenderDrawColor(renderFO, 0, 200, 0, 90); 
            break;
        case 2:
            SDL_SetRenderDrawColor(renderFO, 200, 0, 0, 90); 
            break;
        case 3:
            SDL_SetRenderDrawColor(renderFO, 0, 0, 200, 90); 
            break;
    }
    SDL_RenderFillRect(renderFO, &diceButtonFO);   
}

void renderDiceResultFO(SDL_Renderer *renderFO, int diceValueFO, TTF_Font *fontFO) {
    SDL_Color whiteFO = {255, 255, 255};
    char diceTextFO[3];
    sprintf(diceTextFO, "%d", diceValueFO);

    SDL_Surface *surfaceFO = TTF_RenderText_Solid(fontFO, diceTextFO, whiteFO);
    SDL_Texture *textureFO = SDL_CreateTextureFromSurface(renderFO, surfaceFO);

    SDL_Rect textRectFO = {x_position+(General_size/2)-cell_size, y_position+(General_size/2)-cell_size,2*cell_size,2*cell_size};   // Adjust for position and size
    SDL_RenderCopy(renderFO, textureFO, NULL, &textRectFO);

    SDL_FreeSurface(surfaceFO);
    SDL_DestroyTexture(textureFO);
}

int statFO(house_type *houseFO, int diceValueFO) {
    
    if (diceValueFO == 6) {
            return 1;
    }
    seed_type seedInHouse[4] ={
        (*houseFO)->seed1,
        (*houseFO)->seed2,
        (*houseFO)->seed3,
        (*houseFO)->seed4
    };
    for(int i=0;i<4;i++){
        if (seedInHouse[i].state ==1) return 1;
    }

    return 0;  // No seeds were moved, all are already active
}

void handleSeedMovementFO(SDL_Renderer *renderFO ,house_type house, SDL_Point* path, int diceValueFO,SDL_Point*pathHom, TTF_Font *fontFO,SDL_Rect diceButtonFO ,SDL_Rect up,SDL_Rect le,SDL_Rect ri,SDL_Rect dow,int player, house_type* others,SDL_Point **Homes) {
    if (!statFO(&house, diceValueFO)) {
        return;
    }
    
    SDL_Event eventFODesitionFO;
    SDL_bool seedMoved = SDL_FALSE;

    // Continuously wait for mouse eventFOs until a seed is moved
    while (!seedMoved) {
        SDL_WaitEvent(&eventFODesitionFO);

        drawDiceButtonFO(renderFO, diceButtonFO,player);
        drawDiceButtonFO(renderFO, up,player);
        drawDiceButtonFO(renderFO, le,player);
        drawDiceButtonFO(renderFO, ri,player);
        drawDiceButtonFO(renderFO, dow,player);
        renderDiceResultFO(renderFO, diceValueFO, fontFO);
        SDL_RenderPresent(renderFO);
        
        
        if (eventFODesitionFO.type == SDL_MOUSEBUTTONDOWN) {
            int mouseXFO = eventFODesitionFO.button.x;
            int mouseYFO = eventFODesitionFO.button.y;

            drawDiceButtonFO(renderFO, diceButtonFO,player);
            drawDiceButtonFO(renderFO, up,player);
            drawDiceButtonFO(renderFO, le,player);
            drawDiceButtonFO(renderFO, ri,player);
            drawDiceButtonFO(renderFO, dow,player);
            renderDiceResultFO(renderFO, diceValueFO, fontFO);
            SDL_RenderPresent(renderFO);

            if (diceValueFO !=6){
                int NumOfSeedValead = 0;
                // SDL_Point positions[4];
                
                // if(house->seed1.state == 1 && (house->seed1.position +diceValueFO)<57){
                //     positions[0] = path[house->seed1.position];
                //     NumOfSeedValead++;
                // }
                // if(house->seed2.state == 1 && (house->seed2.position +diceValueFO)<57){
                //     if(NumOfSeedValead == 0){ 
                //         positions[0] = path[house->seed2.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 1){
                //         positions[1] = path[house->seed2.position];
                //         NumOfSeedValead++;
                //     }
                // }
                // if(house->seed3.state == 1 && (house->seed3.position +diceValueFO)<57){
                //     if(NumOfSeedValead == 0){ 
                //         positions[0] = path[house->seed3.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 1){
                //         positions[1] = path[house->seed3.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 2){
                //         positions[2] = path[house->seed3.position];
                //         NumOfSeedValead++;
                //     }
                // }
                // if(house->seed4.state == 1 && (house->seed4.position +diceValueFO)<57){
                //     if(NumOfSeedValead == 0){ 
                //         positions[0] = path[house->seed4.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 1){
                //         positions[1] = path[house->seed4.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 2){
                //         positions[2] = path[house->seed4.position];
                //         NumOfSeedValead++;
                //     }else if(NumOfSeedValead == 3){
                //         positions[3] = path[house->seed4.position];
                //         NumOfSeedValead++;
                //     }
                // }
                SDL_Point positions[4] = {
                    path[house->seed1.position], 
                    path[house->seed2.position], 
                    path[house->seed3.position], 
                    path[house->seed4.position]
                };

                for (int i = 0; i < 4; i++) {
                    int seedPosX = positions[i].x - seed_radus;
                    int seedPosY = positions[i].y - seed_radus;

                    // Check if mouse click is within the bounds of the seed
                    if (mouseXFO >= seedPosX && mouseXFO <= seedPosX + (seed_radus*2) && mouseYFO >= seedPosY && mouseYFO <= seedPosY + (seed_radus*2)){
                        printf("// Move the selected seed");
                        switch (i) {
                            case 0: if(house->seed1.state == 1 && (house->seed1.position +diceValueFO)<57) {move_seedFO(&(house->seed1), diceValueFO,others, Homes,path); if(house->seed1.position == 56){house->seed1.position == 56;} seedMoved = SDL_TRUE; break;} break;
                            case 1: if(house->seed2.state == 1 && (house->seed2.position +diceValueFO)<57) {move_seedFO(&(house->seed2), diceValueFO,others, Homes,path); if(house->seed2.position == 56){house->seed2.position == 57;} seedMoved = SDL_TRUE; break;} break;
                            case 2: if(house->seed3.state == 1 && (house->seed3.position +diceValueFO)<57) {move_seedFO(&(house->seed3), diceValueFO,others, Homes,path); if(house->seed3.position == 56){house->seed3.position == 58;} seedMoved = SDL_TRUE; break;} break;
                            case 3: if(house->seed4.state == 1 && (house->seed4.position +diceValueFO)<57) {move_seedFO(&(house->seed4), diceValueFO,others, Homes,path); if(house->seed4.position == 56){house->seed4.position == 59;} seedMoved = SDL_TRUE; break;} break;
                        }
                        //seedMoved = SDL_TRUE; // Exit the loop after a successful move
                        break; // Exit for loop
                    }
                }
            }else {
                SDL_Point positionsH[4] = {
                    pathHom[0], 
                    pathHom[1], 
                    pathHom[2], 
                    pathHom[3]
                };
                SDL_Point positions[4] = {
                    path[house->seed1.position], 
                    path[house->seed2.position], 
                    path[house->seed3.position], 
                    path[house->seed4.position]
                };

                for (int i = 0; i < 4; i++) {
                    int seedPos1X = positionsH[i].x - cell_center;
                    int seedPos1Y = positionsH[i].y - cell_center;

                    int seedPosX = positions[i].x - seed_radus;
                    int seedPosY = positions[i].y - seed_radus;

                    // Check if mouse click is within the bounds of the seed
                    if(mouseXFO >= seedPosX && mouseXFO <= seedPosX + (seed_radus*2) && mouseYFO >= seedPosY && mouseYFO <= seedPosY + (seed_radus*2)){
                        printf("// Move the selected seed");
                        switch (i) {
                            case 0: move_seedFO(&(house->seed1), diceValueFO,others, Homes,path); if(house->seed1.position == 56){house->seed1.position == 56;}  break;
                            case 1: move_seedFO(&(house->seed2), diceValueFO,others, Homes,path); if(house->seed2.position == 56){house->seed2.position == 57;}  break;
                            case 2: move_seedFO(&(house->seed3), diceValueFO,others, Homes,path); if(house->seed3.position == 56){house->seed3.position == 58;}  break;
                            case 3: move_seedFO(&(house->seed4), diceValueFO,others, Homes,path); if(house->seed4.position == 56){house->seed4.position == 59;}  break;
                        }
                        seedMoved = SDL_TRUE; // Exit the loop after a successful move
                        break; // Exit for loop
                    }else if (mouseXFO >= seedPos1X && mouseXFO <= seedPos1X + (seed_radus*2) && mouseYFO >= seedPos1Y && mouseYFO <= seedPos1Y +  (seed_radus*2) ) {
                        // Move the selected seed
                        switch (i) {
                            case 0: remove_seedFO(&(house->seed1),others, Homes,path);  house->seedNumber--; break;
                            case 1: remove_seedFO(&(house->seed2),others, Homes,path);  house->seedNumber--; break;
                            case 2: remove_seedFO(&(house->seed3),others, Homes,path);  house->seedNumber--; break;
                            case 3: remove_seedFO(&(house->seed4),others, Homes,path);  house->seedNumber--; break;
                        }
                        seedMoved = SDL_TRUE; // Exit the loop after a successful move
                        break; // Exit for loop
                    }
                }    
            }
        }
    }
}

void remove_seedFO(seed_type *seed,house_type *other,SDL_Point **Homes,SDL_Point *thisHome){
    (*seed).state =1;
    (*seed).position =0;

    for(int i=0;i<3;i++){
        for(int se=0;se<4;se++){  
            switch (se){
            case 0:
                if((thisHome)[(*seed).position].x == (Homes[i])[(other[i])->seed1.position].x  && (thisHome)[(*seed).position].y == (Homes[i])[(other[i])->seed1.position].y){
                    (other[i])->seed1.position =-1;
                    (other[i])->seed1.state =0;
                    other[i]->seedNumber++;
                }
                break;
            case 1:
                if((thisHome)[(*seed).position].x == (Homes[i])[(other[i])->seed2.position].x && (thisHome)[(*seed).position].y == (Homes[i])[(other[i])->seed2.position].y){
                    (other[i])->seed2.position =-1;
                    (other[i])->seed2.state =0;
                    other[i]->seedNumber++;
                }
                break;
            case 2:
                if((thisHome)[(*seed).position].x == (Homes[i])[(other[i])->seed3.position].x && (thisHome)[(*seed).position].y == (Homes[i])[(other[i])->seed3.position].y){
                    (other[i])->seed3.position =-1;
                    (other[i])->seed3.state =0;
                    other[i]->seedNumber++;
                }
                break;
            case 3:
                if((thisHome)[(*seed).position].x == (Homes[i])[(other[i])->seed4.position].x  && (thisHome)[(*seed).position].y == (Homes[i])[(other[i])->seed4.position].y){
                    (other[i])->seed4.position =-1;
                    (other[i])->seed4.state =0;
                    other[i]->seedNumber++;
                }
                break;
            }
        }
    }
}

int has_worn(house_type houseFO){
    int counter = 0;

    if(houseFO->seed1.position >= 56 ){
        counter++;
    }
    if(houseFO->seed2.position >= 56 ){
        counter++;
    }
    if(houseFO->seed3.position >= 56 ){
        counter++;
    }
    if(houseFO->seed4.position >= 56 ){
        counter++;
    }
    return counter == 4;
}

