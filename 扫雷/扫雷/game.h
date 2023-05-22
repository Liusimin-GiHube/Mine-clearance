#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʾ��������
#define ROW 9
#define LINE 9

//��������
#define ROWS ROW+2
#define LINES LINE+2

//�ܹ��׵ĸ���
#define total_mine 10

//��ʼ������
void Initial_board(char game[ROWS][LINES], int rows, int lines, char ret);

//������
void mine_laying(char game[ROWS][LINES], int rows, int lines);

//��ӡ����
void print_board(char game[ROWS][LINES], int rows, int lines);

//�����
int determine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);

//�Ų���
int find_mine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);

//ͳ����Χ�׵ĸ���
char count_mine(char mine[ROWS][LINES], int x, int y);

//��ʼ��Ϸ
void playGame(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);