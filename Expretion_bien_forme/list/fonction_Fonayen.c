#include "fonction_Fonayen.h"

pile_type creat_nodeFO(char c){
    pile_type newPile = (pile_type)malloc(sizeof(node));
    if (!newPile) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newPile->character = c;
    newPile->next =NULL;

    return newPile;
}

// pour empiler
void pushFO(char c, pile_type *pile){
    pile_type newPile = creat_nodeFO(c);
    if((*pile) == NULL){
        (*pile) = newPile;
    }else{
        newPile->next = *pile;
        *pile = newPile;
    }
}

//pour dépiler
char pullFO(pile_type *pile){
    if((*pile) == NULL) return ' ';
    char ch = (*pile)->character;
    (*pile) = (*pile)->next;
    return ch;
}

// pour le sommet de la pile
char headFO(pile_type pile){
    if((pile) = NULL) return ' ';
    char ch = (pile)->character;
    return ch;
}  

  //pour savoir si la pile est vide
int isEmptyTab(pile_type pile){
    return (pile) == NULL;
}  

// pour savoir si la pile est pleine.
int isPlentyTab(pile_type pile){
    if((pile) = NULL) return 0;
    return 0;
}   

//pour returne linvers d'unn charactar special
char invers(char ch){
    switch (ch){
    case '{':
        return '}';
        break;
    case '(':
        return ')';
        break;
    case '[':
        return ']';
        break;
    case '<':
        return '>';
        break;
    default:
        return ' ';
        break;
    }
}  

//verifier si on trouve une caractair specioal
int found(char ch, char *string){
    for(int i = 0; i<4;i++){
        if(ch == string[i]) return 1;
    }return 0;
}    

//verifie si l'expresion et correct
int iscorrect(char *expresion){
    pile_type pile = NULL;
    char openers[5] = {'{','(','[','<'};
    char closers[5] = {'}',')',']','>'};
        
    int i = 0;
    while(expresion[i] != '\0' ){
        //scanf("%d",&correct);
        if(found(expresion[i],openers)){
            pushFO(expresion[i],&pile);
            
        }else if(found(expresion[i],closers)){
            if (isEmptyTab(pile)) return 0;
            char open_ch = pullFO(&pile);
            if(expresion[i] != invers(open_ch)) return 0;

        }i++;
    }
    if(isEmptyTab(pile))return 1;
    else return 0;
}  

 // print pile
void printPile(pile_type pile){
    printf("\n\t\tPile =");
    if(pile == NULL){
        printf("-> empty\n");
        return;
    }
    pile_type temp = pile;
    
    while(temp != NULL){
        printf(" %c ->",temp->character);
        temp = temp->next;
    }printf(" NULL ");
    return;
}  

int simulate_pile_use(char *expresion){
    pile_type pile = NULL;
    char openers[5] = {'{','(','[','<'};
    char closers[5] = {'}',')',']','>'};
        
    int i = 0;
    while(expresion[i] != '\0' ){
        //scanf("%d",&correct);
        if(found(expresion[i],openers)){
            pushFO(expresion[i],&pile);

            sleep(2);
            system("clear");
            printf("\n\t\tJust added\n");
            printPile(pile);
            printf("\n\t\t   OK\n");
            
        }else if(found(expresion[i],closers)){
            if ( isEmptyTab(pile)) return 0;
            char open_ch = pullFO(&pile);
            if(expresion[i] != invers(open_ch)) return 0;

            sleep(2);
            system("clear");
            printf("\n\t\tJust removed\n");
            printPile(pile);
            printf("\n\t\t   OK\n");
        }i++;
        
    }
    if(isEmptyTab(pile))return 1;
    else return 0;
}  



