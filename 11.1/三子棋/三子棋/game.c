#include"game.h"

void Init_board(char board[rows][cols], int Rows, int Cols)
{
	int i=0;
	for(i=0; i<Rows; i++)
	{
		int j=0;
		for(j=0; j<Cols; j++)
		{
			board[i][j]=' ';
		}

	}
}
void Display_board( char board[rows][cols], int Rows, int Cols)
{
  int i = 0;
  
  for(i=0; i<rows; i++)
  {
	int j = 0;

	for(j=0; j<cols; j++)
	{
		printf(" %c ",board[i][j]);
		if(j<cols-1)
		printf("|");

	}
	printf("\n");
	if(i<rows-1)
	{
	for(j=0; j<cols; j++)
	{
		printf("---");
		if(j<cols-1)
		printf("|");
	}
	}
	printf("\n");
  }
}
  
 

  


void ComputerMove(char board[rows][cols],int Rows,int Cols)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		  printf("电脑走>:\n");
		  x = rand()%rows;
          y = rand()%cols;
          if(board[x][y] == ' ')
		 {
			board[x][y] = 'X';
			break;
		  }
	}
}
void PlayerMove(char board[rows][cols],int Rows,int Cols)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("请玩家输入坐标>:");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=rows && y>=1 && y<=cols)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '0';
				break;
			}
			else
			{
				printf("代码已被占用，请重新输入");
				
			}
		}
		else
		{
			printf("输入非法，请重新输入>:");
			
		}
			
	 }
}
char Is_Win(char board[rows][cols],int Rows,int Cols)
{
	int i = 0;
	for(i=0; i<rows; i++)
	{
	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
		board[i][0] != ' ')
		return board[i][0];
	}
	for(i=0; i<rows; i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
			board[0][i] != ' ')
			return board[0][i];
	}
	for(i=0; i<rows; i++)
	{
		if(board[0][1] == board[1][1] && board[1][1] == board[2][2] &&
			board[1][1] != ' ')
			return board [1][1];
	}
		for(i=0; i<rows; i++)
	{
		if(board[2][0] == board[1][1] && board[1][1] == board[0][2] &&
			board[1][1] != ' ')
			return board [1][1];
	}
	if(Is_Full(board,rows,cols))
	{
		return 'Q';
	}
	return ' ';
}
int Is_Full(char board[rows][cols],int Rows,int Cols)  
{
	int i = 0;
	int j = 0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			if(board[i][j] != ' ')
			return 1;
		}
	}
		return 0;
}