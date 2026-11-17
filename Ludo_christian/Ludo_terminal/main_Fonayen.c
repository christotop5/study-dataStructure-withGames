#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {
    char boardFO[32][32];

    point_type path_yellowFO = (point_type)check_mallocFO(60*sizeof(Point));
    point_type path_greenFO = (point_type)check_mallocFO(60*sizeof(Point));
    point_type path_redFO = (point_type)check_mallocFO(60*sizeof(Point));
    point_type path_blueFO = (point_type)check_mallocFO(60*sizeof(Point));

    point_type path_yellow_homeFO = (point_type )check_mallocFO(4 * sizeof(Point));
    point_type path_green_homeFO = (point_type )check_mallocFO(4 * sizeof(Point));
    point_type path_red_homeFO = (point_type )check_mallocFO(4 * sizeof(Point));
    point_type path_blue_homeFO = (point_type )check_mallocFO(4 * sizeof(Point));

    house_type house_GreenFO = (house_type)check_mallocFO(sizeof(house));
    house_type house_BlueFO = (house_type)check_mallocFO(sizeof(house));
    house_type house_YellowFO = (house_type)check_mallocFO(sizeof(house));
    house_type house_RedFO = (house_type)check_mallocFO(sizeof(house));

    house_type Ex_yellowFO[3] ={ house_BlueFO,house_GreenFO,house_RedFO};
    house_type Ex_greenFO[3] ={ house_BlueFO,house_YellowFO,house_RedFO};
    house_type Ex_redFO[3] ={ house_BlueFO,house_GreenFO,house_YellowFO};
    house_type Ex_blueFO[3] ={ house_YellowFO,house_GreenFO,house_RedFO};

    point_type  Ex_yellow_FO[3] ={(path_blueFO),(path_greenFO),(path_redFO)};
    point_type  Ex_green_FO[3] ={(path_blueFO),(path_yellowFO),(path_redFO)};
    point_type  Ex_red_FO[3] ={(path_blueFO),(path_greenFO),(path_yellowFO)};
    point_type  Ex_blue_FO[3] ={(path_yellowFO),(path_greenFO),(path_redFO)};

    INit_HousesFO(&house_YellowFO,&house_GreenFO,&house_RedFO,&house_BlueFO);
    init_pathFO(path_yellowFO,path_greenFO,path_redFO,path_blueFO, path_yellow_homeFO, path_green_homeFO, path_red_homeFO, path_blue_homeFO);
    init_boardFO(boardFO);
    render_all_seedsFO(boardFO, house_YellowFO, house_GreenFO, house_RedFO, house_BlueFO, path_yellow_homeFO, path_green_homeFO, path_red_homeFO, path_blue_homeFO,path_yellowFO, path_greenFO, path_redFO, path_blueFO);
    print_boardFO(boardFO);



    int NumberOfPlayersFO;
    do{
        printf("\nEnter the number of players ->: ");
        scanf("%d",&NumberOfPlayersFO);
    }while(NumberOfPlayersFO<2 && NumberOfPlayersFO>5);

    int seedtoplayFO = 0;
    int eventFO =1;
    int quit = 0;
    int diceValueFO;
    int currentPlayerFO = 0;

    while (!quit) {

        switch (eventFO) {
            case 0:
                quit = 1;
                break;
            case 1:{
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
                }currentPlayerFO =( seedtoplayFO % NumberOfPlayersFO);
                
                switch (currentPlayerFO) {
                    case 0:  // Yellow's turn
                        printf("Yellow\n");
                        if(!has_worn(house_YellowFO)){
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                            printf("*********************Yellow's turn*******************************");
                            printf("\nEnter \n\t1.Role dice \n\t0.exit: ");
                            scanf("%d",&eventFO);
                            diceValueFO = roll_diceFO();

                            handleSeedMovementFO(boardFO,house_YellowFO, path_yellowFO, diceValueFO,path_yellow_homeFO,0,Ex_yellowFO,Ex_yellow_FO);
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                        }
                        break;

                    case 1:  // Green's turn
                        printf("green\n");
                        if(!has_worn(house_GreenFO)){
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                            printf("*********************Greens's turn*******************************");
                            printf("\nEnter \n\t1.Role dice \n\t0.exit: ");
                            scanf("%d",&eventFO);
                            diceValueFO = roll_diceFO();

                            handleSeedMovementFO(boardFO,house_GreenFO, path_greenFO, diceValueFO,path_green_homeFO,1,Ex_greenFO,Ex_green_FO);
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                        }
                        break;

                    case 2:  // Red's turn
                        printf("red\n");
                        if(!has_worn(house_RedFO)){
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                            printf("*********************Red's turn*******************************");
                            printf("\nEnter \n\t1.Role dice \n\t0.exit: ");
                            scanf("%d",&eventFO);
                            diceValueFO = roll_diceFO();

                            handleSeedMovementFO(boardFO,house_RedFO, path_redFO, diceValueFO,path_red_homeFO,2,Ex_redFO,Ex_red_FO);
                            system("clear");
                            renderDiceResultFO(boardFO,diceValueFO);
                            print_boardFO(boardFO);
                        }
                        break;
                    case 3:  // Blue's turn
                        printf("blue\n");
                        if(!has_worn(house_BlueFO)){
                            system("clear");
                            print_boardFO(boardFO);
                            renderDiceResultFO(boardFO,diceValueFO);
                            printf("*********************Blue's turn*******************************");
                            printf("\nEnter \n\t1.Role dice \n\t0.exit: ");
                            scanf("%d",&eventFO);
                            diceValueFO = roll_diceFO();

                            handleSeedMovementFO(boardFO,house_BlueFO, path_blueFO, diceValueFO,path_blue_homeFO,3,Ex_blueFO,Ex_blue_FO);
                            system("clear");
                            print_boardFO(boardFO);
                            renderDiceResultFO(boardFO,diceValueFO);
                        }
                        break;
                    
                } 
            }
            break;        
        }
        
       
        renderDiceResultFO(boardFO, diceValueFO);
        init_boardFO(boardFO);
        render_all_seedsFO(boardFO, house_YellowFO, house_GreenFO, house_RedFO, house_BlueFO, path_yellow_homeFO, path_green_homeFO, path_red_homeFO, path_blue_homeFO,path_yellowFO, path_greenFO, path_redFO, path_blueFO);
        renderDiceResultFO(boardFO,diceValueFO);
        print_boardFO(boardFO);
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

  
    return 0;
}


