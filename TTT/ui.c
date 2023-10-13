#include "main.h"
#include "logic.h"
#include "ui.h"

void resetBoard() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      board[r][c] = ' ';
    }
  }
}
void printBoard() {
  printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}
void printWinner(char winner) {
  if (winner == 'X') {
    printf("How did you win, you aren't supposed to be able to win\n");
  } else if (winner == 'O') {
    printf("This is to be expected, you literally cannot beat this ai\n");
  } else {
    printf("Congrats, this is the best that is expected, drawing the bot!\n");
  }
}
