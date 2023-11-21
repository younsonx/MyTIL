#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;

void Move();
void print();
void load();
void gotoxy();
void Boarder();
void Food();

struct coordinate
{
	int x, y, direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500], food, body[30];

int main()
{
	char key;

	print();
	system("cls");
	load();

	// 뱀의 초기 모양 설정하기
	length = 5;   
	head.x = 25;
	head.y = 20;
	head.direction = RIGHT;

	Boarder();

}

void print()
{
	printf("\twelcome to mini snake game.(계속 하려면 아무 키를 입력하세요)\n");
	getch();
	system("cls");
	printf("\tGame instrutions:\n");
	printf("\n -> 화살표를 통해 뱀을 움직이세요.\n\n -> 먹이를 먹을때 마다 몸의 길이가 증가하고 먹이를 먹으면 점수가 1씩 올라갑니다.\n\n -> 3개의 목숨이 주어지고, 벽에 부딫히면 목숨이 하나씩 사라집니다.\n\n -> 게임중 잠시 멈추고 싶으면 아무키를 누르면 됩니다.\n\n -> 게임을 나가고 싶으면 esc버튼을 누르면 됩니다.\n");
	printf("\n\nPress any key to play game...");
	if (getch() == 27)
		exit(0);
}

void gotoxy(int x, int y)
{
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y)
{
	HANDLE a;
	COORD b;
	fflush(stdout); // 버퍼를 지우는 역할
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, b);
}

void load()
{
	int row, col, r, c, q;
	gotoxy(36, 14);
	printf("L o a d i n g...");
	gotoxy(30, 15);
	for (r = 1; r <= 28; r++)
	{
		for (q = 0; q <= 100000000; q++);
		printf("%c", 178);
	}
}

void Boarder()
{
	system("cls");
	int i;
	GotoXY(food.x, food.y);
	printf("@");

	for (i = 10; i < 71; i++)
	{
		GotoXY(i, 10);
		printf("ㅡ");
		GotoXY(i, 30);
		printf("ㅡ");
	}
	for (i = 10; i < 31; i++)
	{
		GotoXY(10, i);
		printf("|");
		GotoXY(70, i);
		printf("|");
	}
}

void Food()
{
	if ()
}
