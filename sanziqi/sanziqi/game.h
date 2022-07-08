#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void playergame(char board[ROW][COL], int row, int col);
void computergame(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
