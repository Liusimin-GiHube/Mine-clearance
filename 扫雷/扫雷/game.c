#include "game.h"

//未被标记的雷
int unmarked_mine = total_mine;
//未排查坐标个数
int unmarked_coordinate = ((ROW) * (LINE));

//初始化棋盘
void Initial_board(char game[ROWS][LINES], int rows, int lines, char ret)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			game[i][j] = ret;
		}
	}
}

//设置雷
void mine_laying(char game[ROWS][LINES], int row, int line)
{
	int count = total_mine;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % line + 1;
		if (game[x][y] == '0')
		{
			game[x][y] = '1';
			count--;
		}
	}
}

//打印棋盘
void print_board(char game[ROWS][LINES], int rows, int lines)
{
	for (int i = 0; i < rows-1; i++)
	{
		for (int j = 0; j < lines-1; j++)
		{
			if (i == 0)
			{
				printf("%d ", j);
			}
			else
			{
				if (j == 0)
					printf("%d ", i);
				else
					printf("%c ", game[i][j]);
			}
			
		}
		printf("\n");
	}
}

//标记雷
int determine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入确定为雷的坐标：");
		scanf("%d %d", &x, &y);
		if (x < 1 || x>rows || y < 0 || y>lines)
			printf("非法输入请重新输入");
		else
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("成功\n");
					show[x][y] = '!';
					unmarked_mine--;
					print_board(show, ROWS, LINES);
					return 1;
				}
				else
				{
					printf("很遗憾，不是雷\n");
					print_board(mine, ROWS, LINES);
					return 0;
				}
			}
			else
				printf("已经输入过，请重新输入:");
		}
	}
}

//统计周围雷的个数
char count_mine(char mine[ROWS][LINES], int x, int y)
{
	int sum = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			sum += (int)mine[i][j];
		}
	}
	//char a = sum + '0';
	return sum-8*'0';
}

//排查雷
int find_mine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要排查的坐标：");
		scanf("%d %d", &x, &y);
		if (x < 1 || x>rows || y < 0 || y>lines)
			printf("非法输入请重新输入");
		else
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					print_board(mine, ROWS, LINES);
					return 0;
				}
				else
				{
					show[x][y] = count_mine(mine, x, y);
					print_board(show, ROWS, LINES);
					return 1;
				}
			}
			else
				printf("已经输入过，请重新输入:");
		}
	}
}

//要排查雷还是确定雷的坐标
void menu2()
{
	printf("**************************\n");
	printf("*******1. 要排查的坐标 ********\n");
	printf("*******0. 确定雷的坐标 *******\n");
	printf("**************************\n");
	printf("请输入你的选择：");
}

//开始游戏
void playGame(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int input = 1;
	//开始游戏
	//当还有雷没有排查，或者坐标没有排查就继续
	while (input)
	{
		//要排查雷还是确定雷的坐标
		menu2();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			//1:成功确定雷	0：失败，结束游戏
			input = determine(mine, show, ROWS, LINES);
			
			//未排查坐标个数
			unmarked_coordinate--;
			break;
		case 1:
			//1:成功排查雷		0：失败，结束游戏
			input = find_mine(mine, show, ROWS, LINES);
			unmarked_coordinate--;
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
		if (unmarked_mine == 0 || (unmarked_coordinate - (total_mine - unmarked_mine)) < 0)
		{
			printf("恭喜游戏成功！");
			break;
		}
	}
}

