#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'Y';

void resetBoard();
void printboard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main(){
   char winner= ' ';
   resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0)
    {
    printboard();
    playerMove();
    winner=checkWinner();
     if (winner !=' '|| checkFreeSpaces () == 0){
      break;
     }

   computerMove();
    winner=checkWinner();
     if (winner !=' '|| checkFreeSpaces () == 0){
      break;
     }
     
    }
    printboard();
    printWinner(winner);
    
    return 0;
}

void resetBoard(){
 for (int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
 {
    Board[i][j]= ' ';
 }
 }
 
}
void printboard(){
 printf(" %c | %c | %c ",Board[0][0],Board[0][1],Board[0][2]);
 printf("\n---|---|---\n");
 printf(" %c | %c | %c ",Board[1][0],Board[1][1],Board[1][2]);
 printf("\n---|---|---\n");
 printf(" %c | %c | %c ",Board[2][0],Board[2][1],Board[2][2]);
 printf("\n---|---|---\n");
 printf("\n");
}
int checkFreeSpaces(){
    int freeSpaces = 9;
 for(int i=0; i<3 ;i++){
    for(int j=0; j<3 ;j++){
     if(Board[i][j] != ' ')
     freeSpaces --;
 }
 }
 return freeSpaces;
}
void playerMove(){
 int x;
 int y; 
do{ 
 printf("enter row #(1-3):");
 scanf("%d",&x);
 x--;
  printf("enter colum #(1-3):");
 scanf("%d",&y);
 y--;
 if (Board[x][y] !=' ')
 {
  printf("invalid move\n");
 }
 else{
   Board[x][y]= PLAYER;
    break;
 }
} while (Board[x][y] !=' ');

}
void computerMove(){
//  create seed based in curent time
srand(time(NULL));
int y;
int x;
if(checkFreeSpaces() > 0){
   do{
    x= rand() % 3;
   y=rand() % 3;
   }while (Board[x][y] !=' ');

Board[x][y] = COMPUTER;

}
else{
   printWinner(' ');
}

}
char checkWinner(){
for (int i = 0; i < 3; i++)
{   
   /* verified row */
  if (Board[i][0]==Board[i][2] && Board[i][0]==Board[i][2])
  {
  return Board[i][0];
  }
  }
  for (int i = 0; i < 3; i++)
 { 
  /* verified culumn */
  if (Board[0][i]==Board[1][i] && Board[0][i]==Board[2][i])
  {
  return Board[0][i];
  }
  }
  /* check diagnals*/
  if (Board[0][0]==Board[1][1] && Board[0][0]==Board[2][2])
  {
  return Board[0][0];
  }
  
    if (Board[0][2]==Board[1][1] && Board[0][2]==Board[2][0])
  {
  return Board[0][2];
  }
  return ' ';
}

void printWinner(char winner ){
    if(winner == PLAYER){
    printf("YOU WIN");}
    else if(winner == COMPUTER){
    printf("YOU LOSE");}
    else {
      printf("IT'S A TIE ");
    }
}
