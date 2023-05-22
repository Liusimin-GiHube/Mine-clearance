#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//显示界面棋盘
#define ROW 9
#define LINE 9

//隐藏棋盘
#define ROWS ROW+2
#define LINES LINE+2

//总共雷的个数
#define total_mine 10

//初始化棋盘
void Initial_board(char game[ROWS][LINES], int rows, int lines, char ret);

//设置雷
void mine_laying(char game[ROWS][LINES], int rows, int lines);

//打印棋盘
void print_board(char game[ROWS][LINES], int rows, int lines);

//标记雷
int determine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);

//排查雷
int find_mine(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);

//统计周围雷的个数
char count_mine(char mine[ROWS][LINES], int x, int y);

//开始游戏
void playGame(char mine[ROWS][LINES], char show[ROWS][LINES], int rows, int lines);