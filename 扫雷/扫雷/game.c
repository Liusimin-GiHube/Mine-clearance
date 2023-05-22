#include "game.h"

//δ����ǵ���
int unmarked_mine = total_mine;
//δ�Ų��������
int unmarked_coordinate = ((ROW) * (LINE));

//��ʼ������
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

//������
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

//��ӡ����
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

//�����
int determine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������ȷ��Ϊ�׵����꣺");
		scanf("%d %d", &x, &y);
		if (x < 1 || x>rows || y < 0 || y>lines)
			printf("�Ƿ���������������");
		else
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("�ɹ�\n");
					show[x][y] = '!';
					unmarked_mine--;
					print_board(show, ROWS, LINES);
					return 1;
				}
				else
				{
					printf("���ź���������\n");
					print_board(mine, ROWS, LINES);
					return 0;
				}
			}
			else
				printf("�Ѿ������������������:");
		}
	}
}

//ͳ����Χ�׵ĸ���
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

//�Ų���
int find_mine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		if (x < 1 || x>rows || y < 0 || y>lines)
			printf("�Ƿ���������������");
		else
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
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
				printf("�Ѿ������������������:");
		}
	}
}

//Ҫ�Ų��׻���ȷ���׵�����
void menu2()
{
	printf("**************************\n");
	printf("*******1. Ҫ�Ų������ ********\n");
	printf("*******0. ȷ���׵����� *******\n");
	printf("**************************\n");
	printf("���������ѡ��");
}

//��ʼ��Ϸ
void playGame(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines)
{
	int input = 1;
	//��ʼ��Ϸ
	//��������û���Ų飬��������û���Ų�ͼ���
	while (input)
	{
		//Ҫ�Ų��׻���ȷ���׵�����
		menu2();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			//1:�ɹ�ȷ����	0��ʧ�ܣ�������Ϸ
			input = determine(mine, show, ROWS, LINES);
			
			//δ�Ų��������
			unmarked_coordinate--;
			break;
		case 1:
			//1:�ɹ��Ų���		0��ʧ�ܣ�������Ϸ
			input = find_mine(mine, show, ROWS, LINES);
			unmarked_coordinate--;
			break;
		default:
			printf("����������������룺");
			break;
		}
		if (unmarked_mine == 0 || (unmarked_coordinate - (total_mine - unmarked_mine)) < 0)
		{
			printf("��ϲ��Ϸ�ɹ���");
			break;
		}
	}
}

