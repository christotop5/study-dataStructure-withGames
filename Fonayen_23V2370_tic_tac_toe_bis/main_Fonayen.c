#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {
	int i,pointFO,choiceFO,point2FO,game_choiceFO;
	int stateFO[9];
	post actual_stateFO[9];
	plateau TabFO;
	char* player1FO;
	char* playerFO;
	char* playe21FO;

	playe21FO = (char*)malloc(12*sizeof(char));
	playerFO = (char*)malloc(12*sizeof(char));
	player1FO = (char*)malloc(12*sizeof(char));

	TabFO = (char **)malloc(13* sizeof(char *));
    if (TabFO == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 13; i++) {
        TabFO[i] = (char *)malloc(16* sizeof(char));
        if (TabFO[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

	system("clear");
	printf("Enter \n\t1.One playerFO \n\t2.Two playerFOs \t:");
	scanf("%d",&game_choiceFO);


	if(game_choiceFO == 2){
		system("clear");
		printf("player 1 Enter your name:");
		scanf("%s",player1FO);
		printf("player 2 Enter your name:");
		scanf("%s",playe21FO);

		
		do{
			i=0;		
			Init_stateFO(stateFO);
			Init_actual_stateFO(actual_stateFO);
			Init_BordFO(TabFO);
			system("clear");
			printf("\n\nEnter\t1. Play ticktato %s vs %s \n\t0.Exit\t:",player1FO,playe21FO);
			scanf("%d",&choiceFO);
			if(choiceFO){
				do{
					system("clear");
					if(is_evenFO(i)){
						Drow_BordFO(TabFO);
						printf("\n\n **---------------------------------------------------------**\n");
						directivesFO();
						printf("\n **---------------------------------------------------------**\n");
						printf("Enter number corespondiong to position for x: \n Enter number %s",player1FO);
						scanf("%d",&pointFO);
						printf("Enter number corespondiong to position for y: \n Enter number %s",player1FO);
						scanf("%d",&point2FO);
						pointFO = determin(pointFO,point2FO);
						if(!in_stateFO(stateFO,pointFO)){
							stateFO[i] = Drow_xFO(TabFO,pointFO,i,actual_stateFO,player1FO);
							if (i>=4){ 
								if(has_wornFO(stateFO[9],i,actual_stateFO)){
									system("clear");
									Drow_BordFO(TabFO);
									printf("\n\n *****----playerFO 1: %s Worn----*****\n",player1FO);
									sleep(2);		
									break;
								}
							}
							i++;
						}else {
							system("clear");
							printf("position already occupied\n") ;
							sleep(1);
						}
					}else{
						Drow_BordFO(TabFO);
						printf("\n\n **---------------------------------------------------------**\n");
						directivesFO();
						printf("\n **---------------------------------------------------------**\n");
						printf("Enter number corespondiong to position for x: \n Enter number %s",playe21FO);
						scanf("%d",&pointFO);
						printf("Enter number corespondiong to position for y: \n Enter number %s",playe21FO);
						scanf("%d",&point2FO);
						pointFO = determin(pointFO,point2FO);
						if(!in_stateFO(stateFO,pointFO) && pointFO>0 && pointFO<10){
							stateFO[i] = Drow_oFO(TabFO,pointFO,i,actual_stateFO,playe21FO);
							if (i>=5){ 
								if(has_wornFO(stateFO[9],i,actual_stateFO)){
									system("clear");
									Drow_BordFO(TabFO);
									printf("\n\n *****----playerFO 2 : %s Worn----*****",playe21FO);
									sleep(2);
									break;
									
								}
							}
							i++;
						}else {
							system("clear");
							printf("position already occupied try again\n") ;
							sleep(1);						
						}
					}
				if (i==9){
					system("clear");
					printf("\n\n**************---------------Draw--------------**************\n\n");
					sleep(1);
					break;
				}
				}while(i < 9);
			}
			
		}while( choiceFO != 0);
	
	
	}else if(game_choiceFO == 1){
		system("clear");
		printf("Enter your name:");
		scanf("%s",playerFO);
		
		do{
			i=0;		
			Init_stateFO(stateFO);
			Init_actual_stateFO(actual_stateFO);
			Init_BordFO(TabFO);
			system("clear");
			printf("\n\nEnter\t1. Play ticktato Pc vs %s \n\t0.Exit\t:",playerFO);
			scanf("%d",&choiceFO);
			if(choiceFO){
				do{
					system("clear");
					if(is_evenFO(i)){
						Drow_BordFO(TabFO);
						printf("\n\n **---------------------------------------------------------**\n");
						directivesFO();
						printf("\n **---------------------------------------------------------**\n");
						printf("Enter number corespondiong to position for x: \n Enter number %s",playerFO);
						scanf("%d",&pointFO);
						printf("Enter number corespondiong to position for y: \n Enter number %s",playerFO);
						scanf("%d",&point2FO);
						pointFO = determin(pointFO,point2FO);
						if(!in_stateFO(stateFO,pointFO)){
							stateFO[i] = Drow_xFO(TabFO,pointFO,i,actual_stateFO,playerFO);
							if (i>=4){ 
								if(has_wornFO(stateFO[9],i,actual_stateFO)){
									system("clear");
									Drow_BordFO(TabFO);
									printf("\n\n *****----playerFO 1: %s Worn----*****\n",playerFO);
									sleep(2);		
									break;
								}
							}
							i++;
						}else {
							system("clear");
							printf("position already occupied\n") ;
							sleep(1);
						}
					}else{
						srand(time(NULL));
						Drow_BordFO(TabFO);
						printf("\n\n **---------------------------------------------------------**\n");
						printf("\n Pc **------Working it out--------** ");
						pointFO =  (rand() % 9) + 1;
						printf("\n **---------------------------------------------------------**\n");
						sleep(2);
						if(!in_stateFO(stateFO,pointFO) && pointFO>0 && pointFO<10){
							stateFO[i] = Drow_oFO(TabFO,pointFO,i,actual_stateFO,"PC");
							if (i>=5){ 
								if(has_wornFO(stateFO[9],i,actual_stateFO)){
									system("clear");
									Drow_BordFO(TabFO);
									printf("\n\n *****----playerFO 2 : Pc Worn----*****");
									sleep(2);
									break;
									
								}
							}
							i++;
						}else {
							system("clear");
							printf("position already occupied try again\n") ;
							sleep(1);						
						}
					}
				if (i==9){
					system("clear");
					printf("\n\n**************---------------Draw--------------**************\n\n");
					sleep(1);
					break;
				}
				}while(i < 9);
			}
			
		}while( choiceFO != 0);
	}
    system("clear");
	printf("\n\n***************------------------HAVE_A_NICE_DAY----------------**************\n\n");
	sleep(1);
	return 0;
}
