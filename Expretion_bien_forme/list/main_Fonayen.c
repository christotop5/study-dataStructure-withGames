#include "fonction_Fonayen.h"

int main(int argc, char* argv[]) {
    int choice;
    do{
        system("clear");
        printf("Enter \n\t1.Load Data frome file and check correctness \n\t2.Input Data to verify correctness \n\t0.Exit:-- ");
        scanf("%d",&choice);
        if(choice == 1){
            char *expresionFO = (char*)malloc(sizeof(char));
            FILE* file = fopen("expresion.txt","r");
            if (file == NULL) {
                printf("Error: Could not open file.\n");
                return -1;
            }int i=0;
            while(fscanf(file,"%c",&expresionFO[i]) != EOF){
                i++;
                expresionFO = (char*)realloc(expresionFO,(i+1)*sizeof(char));
            }
            fclose(file);
            if(iscorrect(expresionFO )){
                printf("\n\t\tExpresion '%s' is correct\n",expresionFO);
                sleep(9);;
            }else{
                printf("\n\t\tExpresion '%s' is not correct\n",expresionFO);
                sleep(9);
            }
            free(expresionFO);
        }else if(choice == 2){
            char *expresionFO = (char*)malloc(50*sizeof(char));
            printf("\n\tEnter Expresion:--- ");
            
            scanf("%s",expresionFO);
            int check;
                system("clear");
                printf("Enter \n\t1.Simple verification \n\t2.pile Display");
                scanf("%d",&check);
                if(check == 1){
                    if(iscorrect(expresionFO )){
                        printf("\n\t\tExpresion %s is correct\n",expresionFO);
                        sleep(9);
                    }else{
                        printf("\n\t\tExpresion %s is not correct\n",expresionFO);
                        sleep(9);
                    }
                }else if(check == 2){
                    if(simulate_pile_use(expresionFO )){
                        printf("\n\t\tExpresion %s is correct\n",expresionFO);
                        sleep(9);
                    }else{
                        printf("\n\t\tExpresion %s is not correct\n",expresionFO);
                        sleep(9);
                    }
                }
        }        
    }while(choice != 0);
}




