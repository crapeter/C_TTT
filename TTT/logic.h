#ifndef LOGIC_H 
#define LOGIC_H 

#include "main.h"

int checkFreeSpaces();
void playerMove();
void computerMove();
int minimax(char board[3][3], int depth, bool isMaximizing);
int evaluateBoard();
char checkWinner();

#endif //
