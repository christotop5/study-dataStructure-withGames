#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char playerName[10];
    int cases[7][15];
    int score;
}Player;

typedef struct{
    Player p1, p2;
}Board;

Board initBoard();
void displayBoard(Board b);
int countCases(Board b, int index, int id);
Board addToCase(Board b, int index, int id);
Board setCaseVide(Board b, int index, int id);
Board distribute(Board b, int index, int id);
Board prise(Board b, int index, int id, int id1);
int countPlayerPion(Board b, int id);
int testwin(Board b, int id);

#endif
