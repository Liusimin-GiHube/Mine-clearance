#include "game.h"



void menu1()
{
	printf("**************************\n");
	printf("*******1. ��ʼ��Ϸ ********\n");
	printf("*******0. �˳���Ϸ *******\n");
	printf("**************************\n");
	printf("���������ѡ��");
}

void game()
{
	//ʵ������
	char layout[ROWS][LINES];
	//��������
	char show[ROWS][LINES];

	//��ʼ������
	//������û�в����׵�ʱ�򣬶���'0'
	Initial_board(layout, ROWS, LINES, '0');
	//show ������û���Ų��׵�ʱ�򣬶���'*'
	Initial_board(show, ROWS, LINES, '*');

	//������
	mine_laying(layout, ROW, LINE);

	//��ӡ����
	print_board(show, ROWS, LINES);
	print_board(layout, ROWS, LINES);

	//��ʼ��Ϸ
	playGame(layout, show, ROWS, LINES);
}

int main()
{
	//�����������
	srand((unsigned int) time(NULL));
	int input = 1;
	while (input)
	{
		menu1();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룺");
			break;
		}
	}
}