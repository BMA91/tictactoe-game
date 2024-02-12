

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = 'O';
char player1[10];
char player2[10];
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void player2Move();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char response = ' ';
   printf("player 1 ara asmk: ");
   scanf("%s",&player1)  ;
   printf("player 2 ara asmk tcho: ");
   scanf("%s",&player2);
   do{
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
         printBoard();
         player2Move();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);
      if(winner==PLAYER)
      {
        printf("\n%s Would you like to take your revenge? (Y/N): ",player2);
      
        scanf(" %c", &response);
        response = toupper(response);
      }
      else
      {
        printf("\n%s Would you like to take your revenge? (Y/N): ",player1);
      
        scanf(" %c", &response);
        response = toupper(response);
      }
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;

   do
   {
      printf("dalt %s\nEnter row #(1-3): ",player1);
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');
   
}
void player2Move()
{
   int a;
   int b;

   do
   {
      printf("dalt %s\n",player2);
      printf("Enter row #(1-3): ");
      scanf("%d", &a);
      a--;
      printf("Enter column #(1-3): ");
      scanf("%d", &b);
      b--;

      if(board[a][b] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[a][b] = PLAYER2;
         break;
      }
   } while (board[a][b] != ' ');
   
}
char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      printf("%s CHIKOUR(a) AK(i) RBHT(i)!",player1);
   }
   else if(winner == PLAYER2)
   {
      printf("%s CHIKOUR(a) AK(i) RBHT(i)!",player2);
   }
   else{
      printf("IT'S A TIE!");
   }
}