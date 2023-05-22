#include "game.h"



void menu1()
{
	printf("**************************\n");
	printf("*******1. 开始游戏 ********\n");
	printf("*******0. 退出游戏 *******\n");
	printf("**************************\n");
	printf("请输入你的选择：");
}

void game()
{
	//实际棋盘
	char layout[ROWS][LINES];
	//界面棋盘
	char show[ROWS][LINES];

	//初始化棋盘
	//数组在没有布置雷的时候，都是'0'
	Initial_board(layout, ROWS, LINES, '0');
	//show 数组在没有排查雷的时候，都是'*'
	Initial_board(show, ROWS, LINES, '*');

	//设置雷
	mine_laying(layout, ROW, LINE);

	//打印棋盘
	print_board(show, ROWS, LINES);
	print_board(layout, ROWS, LINES);

	//开始游戏
	playGame(layout, show, ROWS, LINES);
}

int main()
{
	//设置随机种子
	srand((unsigned int) time(NULL));
	int input = 1;
	while (input)
	{
		menu1();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	}
}