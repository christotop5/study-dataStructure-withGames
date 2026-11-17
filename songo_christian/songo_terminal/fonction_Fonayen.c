#include "fonction_Fonayen.h"

Board initBoard(){
    Board b;
    strcpy(b.p1.playerName, "Player 1");
    strcpy(b.p2.playerName, "Player 2");
    b.p1.score=0;
    b.p2.score = 0;
    for(int i=0; i<7; i++){
        for(int j=0; j<15; j++){
            if(j<5){
                b.p1.cases[i][j] = 1;
                b.p2.cases[i][j] = 1;
            }
            else {
                b.p1.cases[i][j] = 0;
                b.p2.cases[i][j] = 0;
            }

        }
    }
    return b;
}

void displayBoard(Board b){
    for(int i=0; i<3; i++){
        printf("|  ");
        for(int j=0; j<7; j++){
            for(int k=0; k<5; k++){
                if(b.p1.cases[j][k+(5*i)] ==1) printf("#");
                else printf(" ");
            }
            printf("    | ");
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------------------\n");
    for(int i=0; i<3; i++){
        printf("|  ");
        for(int j=0; j<7; j++){
            for(int k=0; k<5; k++){
                if(b.p2.cases[j][k+(5*i)] ==1) printf("#");
                else printf(" ");
            }
            printf("    | ");
        }
        printf("\n");
    }
    printf("%s score : %d\t %s score : %d\n", b.p1.playerName, b.p1.score, b.p2.playerName, b.p2.score);
}


int countCases(Board b, int index, int id){
    int count=0;
    for(int i=0; i<15; i++){
        if(id ==1){
            if(b.p1.cases[index][i] == 1){
                count++;
            }
            else break;
        }
        else if(id ==2){
            if(b.p2.cases[index][i] == 1){
                count++;
            }
            else break;
        }
    }

    return count;
}
Board addToCase(Board b, int index, int id){
    int pos = countCases(b, index, id);
    if(id == 1){
        b.p1.cases[index][pos] = 1;
    }
    else if(id ==2){
        b.p2.cases[index][pos] = 1;
    }
    return b;
}

Board setCaseVide(Board b, int index, int id){
    for(int i=0; i<15; i++){
        if(id ==1){
            if(b.p1.cases[index][i] == 1){
                b.p1.cases[index][i] =0;
            }
            else break;
        }
        else if(id ==2){
            if(b.p2.cases[index][i] == 1){
                b.p2.cases[index][i] =0;
            }
            else break;
        }
    }
    return b;
}

Board distribute(Board b, int index, int id){
    int count = countCases(b, index, id);
    int id1=id;
    b =setCaseVide(b, index, id);

    if(id == 2 && index <6) index++;
    else if(id == 1 && index >0) index --;
    for(int i=0; i<count; i++){
        if(id ==2){
            if(index<6){

                b = addToCase(b, index, id);
                index++;
            }
            else if(index == 6){
                b =addToCase(b, index, id);
                id=1;
            }

        }
        else if(id==1){
            if(index >0){
                b=addToCase(b, index, id);
                index--;
            }
            else if(index == 0){
                b=addToCase(b, index, id);
                id=2;
            }
        }

    }
    if(id == 1) b= prise(b, index, 2, id1);
    else if(id == 2) b= prise(b, index, 1, id1);
    return b;
}

Board prise(Board b, int index, int id, int id1){
    int count=countCases(b, index, id);
    if(count<=4 && count >=2){
        if(id == 1){
            if(id1 == 2) b.p2.score+=count;
            else b.p1.score+=count;
            b = setCaseVide(b, index, id);
            if(index +1<7) return prise(b, index+1, id, id1);
            else return b;
        }
        else if(id == 2){
            if(id1 == 1) b.p1.score+=count;
            else b.p2.score+=count;
            b = setCaseVide(b, index, id);
            if(index -1>0) return prise(b, index-1, id, id1);
            else return b;
        }
    }
    else return b;
}

int countPlayerPion(Board b, int id){
    int count =0;
    if(id == 1) count +=b.p1.score;
    else count +=b.p2.score;
    for(int i=0; i<7; i++){
        count+=countCases(b, i, id);
    }
    return count;

}

int testwin(Board b, int id){
    if(countPlayerPion(b, id) >35) return 1;
    return 0;
}
