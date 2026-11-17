#ifndef FONCTION_FONAYEN
#define FONCTION_FONAYEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

    typedef struct{
        int x;
        int y
    }post;

    typedef char** plateau;
    void Init_BordFO(plateau TabFO);
    void Drow_BordFO(plateau TabFO);
    int Drow_xFO(plateau TabFO,int,int,post actual_stateFO[],char*);
    int Drow_oFO(plateau TabFO,int,int,post actual_stateFO[],char*);
    int is_evenFO(int);
    int has_wornFO(int stateFO[9],int,post actual_stateFO[] );
    int in_stateFO(int stateFO[9],int );
    void Init_actual_stateFO(post actual_stateFO[]);
    void Init_stateFO(int stateFO[]); 
    void directivesFO();
    int determin(int ,int );
 

#endif
