#include "fonction_Fonayen.h"

void init_boardFO(char boardFO[32][32]) {
    // Clear the boardFO
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            boardFO[i][j] = ' ';
        }
    }

    // Initialize each player's home positions
    for (int i = 0; i < 31; i++) { 
		for(int j=0;j<31;j++){
			if(i==0 || j==0 || i==30 || j==30 ) boardFO[i][j] = '#';
			if( i==14||j==14||i==16||j==16 ) boardFO[i][j] = '*';
			if((i>=12)&&(i<18) && (j%2 == 0) ) boardFO[i][j] = '*';
			if((j>=12)&&(j<18) && (i%2 == 0)) boardFO[i][j] = '*';
			if((i==0 || j==0 || i==30 || j==30 || i==12||j==12||i==18||j==18)) boardFO[i][j] = '#';
		}
	}

	for (int i = 12; i <= 18; i++) { 
		for(int j=12;j <= 18;j++){
			 boardFO[i][j] = '#';
			
		}
	}

	for (int i = 2; i <= 10; i++) { 
		for(int j=2;j <= 10;j++){
			 if (i==2 ||j==2||i==10||j==10){boardFO[i][j] = '#';}
			
		}
	}

	for (int i = 20; i <= 28; i++) { 
		for(int j=20;j <= 28;j++){
			 if (i==20 ||j==20||i==28||j==28){boardFO[i][j] = '#';}
			
		}
	}

	for (int i = 20; i <= 28; i++) { 
		for(int j=2;j <= 10;j++){
			 if (i==20 ||j==2||i==28||j==10){boardFO[i][j] = '#';}
			
		}
	}

	for (int i = 2; i <= 10; i++) { 
		for(int j=20;j <= 28;j++){
			 if (i==2 ||j==20||i==10||j==28){boardFO[i][j] = '#';}
			
		}
	}

	boardFO[1][4] ='G';boardFO[1][5] ='R';boardFO[1][6] ='E';boardFO[1][7] ='E';boardFO[1][7] ='E';boardFO[1][8] ='N';
	boardFO[1][23] ='R';boardFO[1][24] ='E';boardFO[1][25] ='D';
	boardFO[19][4] ='Y';boardFO[19][5] ='E';boardFO[19][6] ='L';boardFO[19][7] ='L';boardFO[19][7] ='L';boardFO[19][8] ='O';boardFO[19][9] ='W';
	boardFO[19][23] ='B';boardFO[19][24] ='L';boardFO[19][25] ='U';boardFO[19][26] ='E';
}

void print_boardFO(char boardFO[32][32]){
    for (int row = 0; row < 31; row++) {
        for (int col = 0; col < 31; col++) {
            printf("%c ", boardFO[row][col]);
        }
        printf("\n");
    }
}

void init_pathFO(point_type path_yellowFO,point_type path_greenFO,point_type path_redFO,point_type path_blueFO,point_type path_home_yellow,point_type path_home_green,point_type path_home_red,point_type path_home_blue){

	int a =0;
	{	
		for(int i=4;i<10;i += 4){
			for(int j=4; j<10;j += 4){
				path_home_green[a].x = i; path_home_green[a].y =j; a++;
			}
		}

		a =0;
		for(int i=4;i<10;i += 4){
			for(int j=22; j<27;j += 4){
				path_home_yellow[a].x = i; path_home_yellow[a].y =j; a++;
			}
		}

		a =0;
		for(int i=22;i<27;i += 4){
			for(int j=4; j<10;j += 4){
				path_home_red[a].x = i; path_home_red[a].y =j; a++;
			}
		}

		a =0;
		for(int i=22;i<27;i += 4){
			for(int j=22; j<27;j += 4){
				path_home_blue[a].x = i; path_home_blue[a].y =j; a++;
			}
		}
	}

	{
	path_yellowFO[50].x = 15;  path_yellowFO[50].y = 29;
	path_yellowFO[11].x = 1;  path_yellowFO[11].y = 15;
	path_yellowFO[24].x = 15;  path_yellowFO[24].y = 1;
	path_yellowFO[37].x = 29;  path_yellowFO[37].y = 15;

	a = 27;
	for(int i=0;i<5;i++){
		path_yellowFO[i].x = 13;  path_yellowFO[i].y = a; a -=2;
	}
	a = 11; 
	for(int i=5;i<11;i++){
		path_yellowFO[i].x = a;  path_yellowFO[i].y = 17; a -=2;
	}
	a=1;
	for(int i=12;i<18;i++){
		path_yellowFO[i].x = a;  path_yellowFO[i].y = 13; a +=2;
	}
	a=11;
	for(int i=18;i<24;i++){
		path_yellowFO[i].x = 13;  path_yellowFO[i].y = a; a -=2;
	}
	a=1;
	for(int i=25;i<31;i++){
		path_yellowFO[i].x = 17;  path_yellowFO[i].y = a; a +=2;
	}
	a=19;
	for(int i=31;i<37;i++){
		path_yellowFO[i].x = a;  path_yellowFO[i].y = 13; a +=2;
	}
	a=29;
	for(int i=38;i<44;i++){
		path_yellowFO[i].x = a;  path_yellowFO[i].y = 17; a -=2;
	}
	a=19;
	for(int i=44;i<50;i++){
		path_yellowFO[i].x = 17;  path_yellowFO[i].y = a; a +=2;
	}
	a=27;
	for(int i=51;i<56;i++){
		path_yellowFO[i].x = 15;  path_yellowFO[i].y = a; a -=2;
	}
	}

	{
	path_greenFO[37].x = 15;  path_greenFO[37].y = 29;
	path_greenFO[50].x = 1;  path_greenFO[50].y = 15;
	path_greenFO[11].x = 15;  path_greenFO[11].y = 1;
	path_greenFO[24].x = 29;  path_greenFO[24].y = 15;

	a = 29;
	for(int i=38;i<44;i++){
		path_greenFO[i].x = 13;  path_greenFO[i].y = a; a -=2;
	}
	a = 11; 
	for(int i=44;i<50;i++){
		path_greenFO[i].x = a;  path_greenFO[i].y = 17; a -=2;
	}
	a=3;
	for(int i=0;i<5;i++){
		path_greenFO[i].x = a;  path_greenFO[i].y = 13; a +=2;
	}
	a=11;
	for(int i=5;i<11;i++){
		path_greenFO[i].x = 13;  path_greenFO[i].y = a; a -=2;
	}
	a=1;
	for(int i=12;i<18;i++){
		path_greenFO[i].x = 17;  path_greenFO[i].y = a; a +=2;
	}
	a=19;
	for(int i=18;i<24;i++){
		path_greenFO[i].x = a;  path_greenFO[i].y = 13; a +=2;
	}
	a=29;
	for(int i=25;i<31;i++){
		path_greenFO[i].x = a;  path_greenFO[i].y = 17; a -=2;
	}
	a=19;
	for(int i=31;i<37;i++){
		path_greenFO[i].x = 17;  path_greenFO[i].y = a; a +=2;
	}
	a=3;
	for(int i=51;i<56;i++){
		path_greenFO[i].x = a;  path_greenFO[i].y = 15; a +=2;
	}
	}

	{
	path_redFO[24].x = 15;  path_redFO[24].y = 29;
	path_redFO[37].x = 1;  path_redFO[37].y = 15;
	path_redFO[50].x = 15;  path_redFO[50].y = 1;
	path_redFO[11].x = 29;  path_redFO[11].y = 15;

	a = 29;
	for(int i=25;i<31;i++){
		path_redFO[i].x = 13;  path_redFO[i].y = a; a -=2;
	}
	a = 11; 
	for(int i=31;i<37;i++){
		path_redFO[i].x = a;  path_redFO[i].y = 17; a -=2;
	}
	a=1;
	for(int i=38;i<44;i++){
		path_redFO[i].x = a;  path_redFO[i].y = 13; a +=2;
	}
	a=11;
	for(int i=44;i<50;i++){
		path_redFO[i].x = 13;  path_redFO[i].y = a; a -=2;
	}
	a=3;
	for(int i=0;i<5;i++){
		path_redFO[i].x = 17;  path_redFO[i].y = a; a +=2;
	}
	a=19;
	for(int i=5;i<11;i++){
		path_redFO[i].x = a;  path_redFO[i].y = 13; a +=2;
	}
	a=29;
	for(int i=12;i<18;i++){
		path_redFO[i].x = a;  path_redFO[i].y = 17; a -=2;
	}
	a=19;
	for(int i=18;i<24;i++){
		path_redFO[i].x = 17;  path_redFO[i].y = a; a +=2;
	}
	a=3;
	for(int i=51;i<56;i++){
		path_redFO[i].x = 15;  path_redFO[i].y = a; a +=2;
	}
	}

	{
	path_blueFO[11].x = 15;  path_blueFO[11].y = 29;
	path_blueFO[24].x = 1;  path_blueFO[24].y = 15;
	path_blueFO[37].x = 15;  path_blueFO[37].y = 1;
	path_blueFO[50].x = 29;  path_blueFO[50].y = 15;

	a = 29;
	for(int i=12;i<18;i++){
		path_blueFO[i].x = 13;  path_blueFO[i].y = a; a -=2;
	}
	a = 11; 
	for(int i=18;i<24;i++){
		path_blueFO[i].x = a;  path_blueFO[i].y = 17; a -=2;
	}
	a=1;
	for(int i=25;i<31;i++){
		path_blueFO[i].x = a;  path_blueFO[i].y = 13; a +=2;
	}
	a=11;
	for(int i=31;i<37;i++){
		path_blueFO[i].x = 13;  path_blueFO[i].y = a; a -=2;
	}
	a=1;
	for(int i=38;i<44;i++){
		path_blueFO[i].x = 17;  path_blueFO[i].y = a; a +=2;
	}
	a=19;
	for(int i=44;i<50;i++){
		path_blueFO[i].x = a;  path_blueFO[i].y = 13; a +=2;
	}
	a=27;
	for(int i=0;i<5;i++){
		path_blueFO[i].x = a;  path_blueFO[i].y = 17; a -=2;
	}
	a=19;
	for(int i=5;i<11;i++){
		path_blueFO[i].x = 17;  path_blueFO[i].y = a; a +=2;
	}
	a=27;
	for(int i=51;i<56;i++){
		path_blueFO[i].x = a;  path_blueFO[i].y = 15; a -=2;
	}
	}

}

void* check_mallocFO(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int roll_diceFO(){
    srand(time(NULL));
    return (rand() % 6 )+1;
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

	// (*yellow)->seed1.caracter = 'Y';
    // (*yellow)->seed2.caracter = 'V';
    // (*yellow)->seed3.caracter = 'S';
    // (*yellow)->seed4.position = 'L';

	// (*green)->seed1.caracter = 'G';
    // (*green)->seed2.caracter = 'W';
    // (*green)->seed3.caracter = 'P';
    // (*green)->seed4.position = 'T';

	// (*red)->seed1.caracter = 'R';
    // (*red)->seed2.caracter = 'Z';
    // (*red)->seed3.caracter = 'K';
    // (*red)->seed4.position = 'N';

	// (*blue)->seed1.caracter = 'B';
    // (*blue)->seed2.caracter = 'M';
    // (*blue)->seed3.caracter = 'X';
    // (*blue)->seed4.position = 'Q';
    

}

void move_seedFO(char boardFO[32][32],seed_type *player_token, int dice_value,house_type *other,Point **Homes,Point *thisHome) {
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

void drawRedFO(char boardFO[32][32], int x, int y){
	boardFO[y][x] = 'R';
}

void draweGreenFO(char boardFO[32][32], int x, int y){
	boardFO[y][x] = 'G';
}
   
void drawYellowFO( char boardFO[32][32], int x, int y){
	boardFO[y][x] = 'Y';
}
   
void drawBLueFO( char boardFO[32][32], int x, int y){
	boardFO[y][x] = 'B';
}

void render_seedFO(char boardFO[32][32], seed_type seed, Point *pathFO, Point homePathFO) {
    // Check if the seed is at home
    if (seed.state == 0) { // If at home
        // Render the seed at its home position
        switch (seed.player) {
            case 0: // Yellow player
                drawYellowFO(boardFO, homePathFO.x, homePathFO.y);
                break;
            case 1: // Green player
                draweGreenFO(boardFO, homePathFO.x, homePathFO.y);
                break;
            case 2: // Red player
                drawRedFO(boardFO, homePathFO.x, homePathFO.y);
                break;
            case 3: // Blue player
                drawBLueFO(boardFO, homePathFO.x, homePathFO.y);
                break;
        }
        
    } else { // Render the seed on the main path
        switch (seed.player) {
            case 0: drawYellowFO(boardFO, pathFO[seed.position].x, pathFO[seed.position].y); break;  // Yellow
            case 1: draweGreenFO(boardFO, pathFO[seed.position].x, pathFO[seed.position].y); break;  // Green
            case 2: drawRedFO(boardFO, pathFO[seed.position].x, pathFO[seed.position].y); break;  // Red
            case 3: drawBLueFO(boardFO, pathFO[seed.position].x, pathFO[seed.position].y); break;  // Blue
        }
    }
}

void render_all_seedsFO(char boardFO[32][32] , house_type house_YellowFO, house_type house_GreenFO, house_type house_RedFO, house_type house_BlueFO, Point *home_yellow, Point *home_green,Point *home_red,Point *home_blue, Point *path_yellow,Point *path_green, Point *path_red,Point *path_blue){
    house_type houses[4] = { house_YellowFO, house_GreenFO, house_RedFO, house_BlueFO };
    Point path[4] = {(*home_yellow),(*home_green),(*home_red),(*home_blue)};

    for (int player = 0; player < 4; player++) {
        seed_type *seed = NULL;

        switch (player) {
            case 0: seed = &(houses[player]->seed1);  render_seedFO(boardFO, *seed, path_yellow, home_yellow[player]); break; // Yellow
            case 1: seed = &(houses[player]->seed1);  render_seedFO(boardFO, *seed, path_green, home_green[0]);  break;// Green
            case 2: seed = &(houses[player]->seed1);  render_seedFO(boardFO, *seed, path_red, home_red[0]);    break;// Red
            case 3: seed = &(houses[player]->seed1);  render_seedFO(boardFO, *seed, path_blue, home_blue[0]);   break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed2); render_seedFO(boardFO, *seed, path_yellow, home_yellow[1]);  break; // Yellow
            case 1: seed = &(houses[player]->seed2); render_seedFO(boardFO, *seed, path_green, home_green[1]);   break;// Green
            case 2: seed = &(houses[player]->seed2); render_seedFO(boardFO, *seed, path_red, home_red[1]);     break; // Red
            case 3: seed = &(houses[player]->seed2); render_seedFO(boardFO, *seed, path_blue, home_blue[1]);    break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed3);  render_seedFO(boardFO, *seed, path_yellow, home_yellow[2]);  break; // Yellow
            case 1: seed = &(houses[player]->seed3);  render_seedFO(boardFO, *seed, path_green, home_green[2]);   break;// Green
            case 2: seed = &(houses[player]->seed3);  render_seedFO(boardFO, *seed, path_red, home_red[2]);     break;// Red
            case 3: seed = &(houses[player]->seed3);  render_seedFO(boardFO, *seed, path_blue, home_blue[2]);    break;// Blue
        }
        switch (player) {
            case 0: seed = &(houses[player]->seed4);  render_seedFO(boardFO, *seed, path_yellow, home_yellow[3]);  break; // Yellow
            case 1: seed = &(houses[player]->seed4);  render_seedFO(boardFO, *seed, path_green, home_green[3]);   break;// Green
            case 2: seed = &(houses[player]->seed4);  render_seedFO(boardFO, *seed, path_red, home_red[3]);     break;// Red
            case 3: seed = &(houses[player]->seed4);  render_seedFO(boardFO, *seed, path_blue, home_blue[3]);    break;// Blue
        }
    }
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

int can_MoveFO(house_type *houseFO, int diceValueFO){}

void handleSeedMovementFO(char boardFO[32][32] ,house_type house,Point* path, int diceValueFO,Point*pathHom ,int player, house_type* others,Point **Homes) {
    if (!statFO(&house, diceValueFO)) {
        return;
    }
    
	
    int desition1;
	int seedMoved = 0;

    system("clear");
    renderDiceResultFO(boardFO,diceValueFO);
    print_boardFO(boardFO);


    // Continuously wait for mouse eventFOs until a seed is moved
    do{

        system("clear");
        renderDiceResultFO(boardFO,diceValueFO);
        print_boardFO(boardFO);


        if(diceValueFO == 6){
            printf("\n \nEnter \n\t0.seed1->position =  %d: \n\t1.seed2->position =  %d: \n\t2.seed3->caracter = %d: \n\t4.seed3->position = %d:",house->seed1.position,house->seed2.position,house->seed3.position,house->seed4.position);
		    scanf("%d",&desition1);
        }else{
            if(house->seed1.state == 1 && (house->seed1.position +diceValueFO)<57){
                printf("\n \nEnter \n\t0.seed1->position =  %d: ",house->seed1.position);
            }
            if(house->seed2.state == 1 && (house->seed2.position +diceValueFO)<57){
                printf("\n \nEnter \n\t1.seed2->position =  %d: ",house->seed2.position);
            }
            if(house->seed3.state == 1 && (house->seed3.position +diceValueFO)<57){
                printf("\n \nEnter \n\t2.seed3->position =  %d: ",house->seed3.position);
            }
            if(house->seed4.state == 1 && (house->seed4.position +diceValueFO)<57){
                printf("\n \nEnter \n\t3.seed4->position =  %d: ",house->seed4.position);
            }
            scanf("%d",&desition1);
        }
        
        
        if (desition1 == 0||desition1 == 1||desition1 == 2||desition1 == 3){
            if (diceValueFO !=6){
                
                switch (desition1) {
                    case 0: move_seedFO(boardFO,&(house->seed1), diceValueFO,others, Homes,path); if(house->seed1.position == 56){house->seed1.position == 56;}  break;
                    case 1: move_seedFO(boardFO,&(house->seed2), diceValueFO,others, Homes,path); if(house->seed2.position == 56){house->seed2.position == 57;}  break;
                    case 2: move_seedFO(boardFO,&(house->seed3), diceValueFO,others, Homes,path); if(house->seed3.position == 56){house->seed3.position == 58;}  break;
                    case 3: move_seedFO(boardFO,&(house->seed4), diceValueFO,others, Homes,path); if(house->seed4.position == 56){house->seed4.position == 59;}  break;
                }
                seedMoved = 1; // Exit the loop after a successful move
                break; // Exit for loop
                
            }else{
				int desition2;
				printf("\nEnter \n\t0.remove seed \n\t1.move seed");
				scanf("%d",&desition2);
                
				if(desition2 == 1){
					printf("// Move the selected seed");
					switch (desition1) {
						case 0: move_seedFO(boardFO,&(house->seed1), diceValueFO,others, Homes,path); if(house->seed1.position == 56){house->seed1.position == 56;}  break;
						case 1: move_seedFO(boardFO,&(house->seed2), diceValueFO,others, Homes,path); if(house->seed2.position == 56){house->seed2.position == 57;}  break;
						case 2: move_seedFO(boardFO,&(house->seed3), diceValueFO,others, Homes,path); if(house->seed3.position == 56){house->seed3.position == 58;}  break;
						case 3: move_seedFO(boardFO,&(house->seed4), diceValueFO,others, Homes,path); if(house->seed4.position == 56){house->seed4.position == 59;}  break;
					}
					seedMoved = 1; // Exit the loop after a successful move
					break; // Exit for loop
				}else if(desition2 == 0){
					// Move the selected seed
					switch (desition1) {
						case 0: remove_seedFO(&(house->seed1),others, Homes,path);  house->seedNumber--; break;
						case 1: remove_seedFO(&(house->seed2),others, Homes,path);  house->seedNumber--; break;
						case 2: remove_seedFO(&(house->seed3),others, Homes,path);  house->seedNumber--; break;
						case 3: remove_seedFO(&(house->seed4),others, Homes,path);  house->seedNumber--; break;
					}
					seedMoved = 1; // Exit the loop after a successful move
					break; // Exit for loop
				}   
            }
        }
    }while (!seedMoved);
}

void remove_seedFO(seed_type *seed,house_type *other,Point **Homes,Point *thisHome){
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

void renderDiceResultFO(char boardFO[32][32], int diceValueFO) {
    char character = '0' + diceValueFO;

	boardFO[15][15] = character;
}
