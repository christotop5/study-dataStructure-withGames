#ifndef FONCTION_FONAYEN
#define FONCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


    typedef struct node{
        char character;
        struct node *next;
    }node;
    typedef node* pile_type;

    pile_type creat_nodeFO(char c);
    void pushFO(char c, pile_type *pile);   // pour empiler
    char pullFO(pile_type *pile);          //pour dépiler
    char headFO(pile_type pile);         // pour le sommet de la pile
    int isEmptyTab(pile_type pile);     //pour savoir si la pile est vide
    int isPlentyTab(pile_type pile);   // pour savoir si la pile est pleine.
    char invers(char);             //pour returne linvers d'unn charactar special
    int iscorrect(char *);        //verifie si l'expresion et correct
    int found(char , char *);    //verifier si on trouve une caractair specioal
    void printPile(pile_type);     // print pile
    int simulate_pile_use(char *expresion); //simulation
        
#endif
