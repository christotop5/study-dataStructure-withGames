#include "fonction_Fonayen.h"

int main(){
    int c=10, turn =1;
    int id=1, index;
     Board b = initBoard();
    while(c > 0){

        system("clear");
        displayBoard(b);
        printf("\nPlayer %d plays\n ", id);
        printf("\nCase number : ");
        scanf("%d", &c);
        index = c;
        if(c >=0 && c<7){


            b = distribute(b, index, id);
            id=1+turn%2;
        }
        if(testwin(b, id)) break;
    }


    return 0;
}
