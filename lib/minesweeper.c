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
#define ANSI_COLOR_YELLW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
  //board layout:
  //none = " ", covered = ".", flag = "X", mine = "*", number = "1-8"
  printf("\n");
  printf("     0   1   2   3   4   5   6   7   8   9  \n");
  printf(ANSI_COLOR_RED"   +---+---+---+---+---+---+---+---+---+---+\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_BLUE" A | . | . | . | . | . | . | . | . | . | . |\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_CYAN"   +---+---+---+---+---+---+---+---+---+---+\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN" B | . | . | . | . | . | . | . | . | . | . |\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_YELLW"   +---+---+---+---+---+---+---+---+---+---+\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_MAGENTA" C | . | . | . | . | . | . | . | . | . | . |\n"ANSI_COLOR_RESET);
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" D | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" E | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" F | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" G | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" H | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" I | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf(" J | . | . | . | . | . | . | . | . | . | . |\n");
  printf("   +---+---+---+---+---+---+---+---+---+---+\n");
  printf("\n");

  return 0;
}
