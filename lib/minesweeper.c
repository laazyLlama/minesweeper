//-----------------------------------------------------------------------------
//Project Name:     minesweeper
//Description:      The classic game "Minesweeper" built in c
//-----------------------------------------------------------------------------
//Author:           laazyLlama
//Date Created:     24/12/2020
//Last Changes:     17/01/2021
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
//#define ANSI_COLOR_MAGENTA "\x1b[35m"
//#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void generate_board(int, int, int, char*);
void generate_surrounding_numbers(char*, char*);
void print_board(char*);
void print_horizontal_border();
void print_cell(char);

int main() {
  //generated board with all the values in it
  char board[10][10];
  //board, that contains the state currently visible to the player
  char currentBoard[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = '0';
      currentBoard[i][j] = '.';
    }
  }
  //0 = all spaces uncovered (win), 1 = there is at least 1 remaining space
  //    covered
  short coveredSpaces = 0;
  char userInput[3];

  //board layout:
  /*
   *      0   1   2   3   4   5   6   7   8   9
   *    +---+---+---+---+---+---+---+---+---+---+
   *  A | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  B | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  C | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  D | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  E | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  F | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  G | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  H | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  I | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   *  J | . | . | . | . | . | . | . | . | . | . |
   *    +---+---+---+---+---+---+---+---+---+---+
   */
  //none = " ", covered = ".", flag = "X", mine = "*", number = "1-8"

  while (1) {
    printf("  > ");
    if (fgets(userInput, 3, stdin) != NULL) {
      //TODO: get board position from the given input, check for validity and
      //      uncover the specified space
      //      !!!check if input was to long!!! (idk how tbh, but its late so..)
      puts(userInput);
      break;
    }
  }

  generate_board(0, 0, 10, &board[0][0]);

  coveredSpaces = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (currentBoard[i][j] == '.') {
        coveredSpaces = 1;
        //printf("1");
        break;
      }
    }
    if (coveredSpaces == 1) {
      //printf("2");
      break;
    }
  }

  print_board(&currentBoard[0][0]);

  return 0;
}

/**
 * Generates a minesweeper board with a guaranteed save position
 *
 * @param saveX The X coordinate of the guaranteed save position
 * @param saveY The Y coordinate of the guaranteed save position
 * @param count Number of bombs to generate
 * @param *cell a pointer to the first cell of the board
 *
 * @return always void
 */
void generate_board(int saveX, int saveY, int count, char *cell) {
  int x = 0;
  int y = 0;
  // Intialize rng using system time as seed
  srand((unsigned) time(0));

  for (int i = 0; i < count; i++) {
    // generate a random position to place a bomb
    x = rand() % 10;
    y = rand() % 10;
    // check if the currently selected cell is valid (it is not the save pos
    // and has no bomb in it)
    if ((*(cell + (x + y * 10)) != '*') && (x != saveX || y != saveY)) {
      // if the cell is valid generate a bomb and its surrounding numbers
      *(cell + (x + y * 10)) = '*';
      generate_surrounding_numbers(cell + (x + y * 10), cell);
    }
    // if not, decrease the counter, to try generating another, valid bomb
    else {
      i--;
    }
  }
  return;
}

/**
 * Generates the numbers that indicate the amount of bombs adjacent to the
 * current tile
 *
 * @param *bomb pointer to the cell, where the last bomb was generated
 * @param *start pointer to the first position in the array
 *
 * @return always void
 */
void generate_surrounding_numbers(char *bomb, char *start) {
//TODO: rewrite this bullshit to be understandable!!! at least it seems to
//      work for now :D ...
//HINT: maybe cheking for the rows should be done first, to be able to combine
//      all three rows, that need numbers, in a single if-statement?
  //numbers above bomb:
  //check if bomb isn't in top row
  if ((bomb - start) >= 10) {
    //check if bomb is in first column
    if (((bomb - start) % 10) == 0) {
      for (int i = -10; i <= -9; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
    //check if bomb is in last column
    else if (((bomb - start) % 10) == 9) {
      for (int i = -11; i <= -10; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
    else {
      for (int i = -11; i <= -9; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
  }

  //numbers to the right and left of the bomb:
  //check if bomb is in first column
  if (((bomb - start) % 10) == 0) {
    for (int i = 0; i <= 1; i++) {
      if (*(bomb + i) != '*') {
        (*(bomb + i))++;
      }
    }
  }
  //check if bomb is in last column
  else if (((bomb - start) % 10) == 9) {
    for (int i = -1; i <= 0; i++) {
      if (*(bomb + i) != '*') {
          (*(bomb + i))++;
      }
    }
  }
  else {
    for (int i = -1; i <= 1; i++) {
      if (*(bomb + i) != '*') {
        (*(bomb + i))++;
      }
    }
  }

  //numbers beneath the bomb:
  //check if bomb isn't in bottom row
  if ((bomb - start) < 90) {
    //check if bomb is in first column
    if (((bomb - start) % 10) == 0) {
      for (int i = 10; i <= 11; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
    //check if bomb is in last column
    else if (((bomb - start) % 10) == 9) {
      for (int i = 9; i <= 10; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
    else {
      for (int i = 9; i <= 11; i++) {
        if (*(bomb + i) != '*') {
          (*(bomb + i))++;
        }
      }
    }
  }
}

/**
 * Prints the minesweeper board in its current state
 *
 * @param *currentSymbol pointer to the symbol to print inside the current cell
 *
 * @return always void
 */
void print_board(char *currentSymbol) {
  printf("\n");
  printf("     0   1   2   3   4   5   6   7   8   9  \n");
  for (int i = 0; i < 10; i++) {
    print_horizontal_border();
    printf(" %c |", i + 65);
    for (int j = 0; j < 10; j++) {
      print_cell(*currentSymbol);
      currentSymbol++;
    }
    printf("\n");
  }
  print_horizontal_border();
  printf("\n");
  return;
}

/**
 * Prints the horizontal parts of the border of the minesweeper bard
 *
 * @return always void
 *
 * @note print_horizontal_border should only be called by print_board
 */
void print_horizontal_border() {
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  return;
}

/**
 * Prints a single cell of the minesweeper board
 *
 * @param symbol the symbol wich is displayed inside the printed cell
 *
 * @return always void
 */
void print_cell(char symbol) {
  switch (symbol) {
    case ' ':
      printf(" %c ", symbol);
      printf("|");
      break;
    case '.':
      printf(ANSI_COLOR_BLUE " %c ", symbol);
      printf(ANSI_COLOR_RESET "|");
      break;
    case 'X':
      printf(ANSI_COLOR_YELLOW " %c ", symbol);
      printf(ANSI_COLOR_RESET "|");
      break;
    case '*':
      printf(ANSI_COLOR_RED " %c ", symbol);
      printf(ANSI_COLOR_RESET "|");
      break;
    default:
      printf(ANSI_COLOR_GREEN " %c ", symbol);
      printf(ANSI_COLOR_RESET "|");
      break;
  }
  return;
}
