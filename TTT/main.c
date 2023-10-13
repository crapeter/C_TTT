#include "main.h"
#include "logic.h"
#include "ui.h"

char board[3][3];
char test = 'T';

int main(int argc, char** argv) {
  char winner = ' ';
  char again;
 
  do {
    resetBoard();
    winner = ' ';
    again = ' ';

    while (winner == ' ' && checkFreeSpaces() != 0) {
      printBoard();

      playerMove();
      winner = checkWinner();
      if (winner != ' ' || checkFreeSpaces() == 0) {
        break;
      }
      computerMove();
      winner = checkWinner();
      if (winner != ' ' || checkFreeSpaces() == 0) {
        break;
      }
    }
    printBoard();
    printWinner(winner);
    while (1) {
      printf ("\nWould you like to play again (y/n): ");
      scanf(" %c", &again);
      again = tolower(again);
      if (again == 'y' || again == 'n') { 
        break; 
      } else {
        printf("Invalid input.");
      }
    }
  } while (again == 'y'); 
  printf("Type 'clear' to remove the game from the screen\n");
  return 0;
}
