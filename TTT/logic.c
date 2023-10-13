#include "main.h"
#include "logic.h"
#include "ui.h"

int checkFreeSpaces() {
  int freeSpaces = 9;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] != ' ') {
        freeSpaces--;
      }
    }
  }
  return freeSpaces;
}
void playerMove() {
  int x, y;
  printf("%c", test); 
  do {
    printf("Enter the row #(1-3): ");
    scanf("%d", &x);
    if (x >= 4 || x < 1) {
      printf("Invalid input.\n");
      continue;
    }
    x--;
    printf("Enter the column #(1-3): ");
    scanf("%d", &y);
    if (y >= 4 || y < 1) {
      printf("Invalid input.\n");
      continue;
    }
    y--;

    if (board[x][y] != ' ') {
      printf("Invalid move\n");
    } else {
      board[x][y] = 'X';
      break;
    }
  } while (board[x][y] != ' ');
}
void computerMove() {
  int bestScore = -10000;
  int bestRowMove = -1;
  int bestColMove = -1;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] == ' ') {
        board[r][c] = 'O';
        int currentScore = minimax(board, 0, false);
        board[r][c] = ' ';
        if (currentScore > bestScore) {
          bestScore = currentScore;
          bestRowMove = r;
          bestColMove = c;
        }
      }
    }
  }
  printf("Best Row: %d\nBest Column: %d\n", bestRowMove, bestColMove);
  board[bestRowMove][bestColMove] = 'O';
}
int minimax(char board[3][3], int depth, bool isMaximizing) {
  char result = checkWinner();
  if (result != ' ') {
    return evaluateBoard();
  }
  if (checkFreeSpaces() == 0) {
    return 0;
  }
  if (isMaximizing) {
    int bestScore = -10000;
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 3; c++) {
        if (board[r][c] == ' ') {
          board[r][c] = 'O';
          int score = minimax(board, depth + 1, false);
          board[r][c] = ' ';
          bestScore = (score > bestScore) ? score: bestScore;
        }
      }
    }
    return bestScore;
  } else {
    int bestScore = 10000;
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 3; c++) {
        if (board[r][c] == ' ') {
          board[r][c] = 'X';
          int score = minimax(board, depth + 1, !isMaximizing);
          board[r][c] = ' ';
          bestScore = (score < bestScore) ? score: bestScore;
        }
      }
    }
    return bestScore;
  }
}
int evaluateBoard() {
  char winner = checkWinner();
  if (winner == 'O') {
    return 10;
  } else if (winner == 'X') {
    return -10;
  }
  return 0;
}
char checkWinner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
  }
  return ' ';
}
