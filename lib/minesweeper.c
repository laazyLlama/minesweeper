//-----------------------------------------------------------------------------
//Project Name:     minesweeper/mineswee[er].c
//Description:      The classic game "Minesweeper" built in c
//-----------------------------------------------------------------------------
//Author:           laazyLlama
//Date Created:     24/12/2020
//Last Changes:     24/12/2020
//-----------------------------------------------------------------------------

#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_board();
void print_horizontal_border();
void print_cell(char);

int main() {
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

  print_board();

  return 0;
}

/**
 * Prints the minesweeper board in its current state
 *
 * @return always void
 */
void print_board() {
  printf("\n");
  printf("     0   1   2   3   4   5   6   7   8   9  \n");
  for (int i = 0; i < 10; i++) {
    print_horizontal_border();
    printf(" %c |", i + 65);
    for (int j = 0; j < 10; j++) {
      print_cell('.');
    }
    printf("\n");
  }
  print_horizontal_border();
  printf("\n");
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
}
