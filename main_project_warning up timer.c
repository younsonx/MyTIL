#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void volley_ball();
void basket_ball();
void running();
void weight();
void Exit_pro();
void HRmax();

// 시간에 따른 타이머 함수들
void timer_10s();
void timer_20s();
void timer_30s();
void timer_60s();

int num;

int main()
{
	printf("오늘 할 운동은?\n");
	printf("      1. 배구         \n");
	printf("      2. 농구         \n");
	printf("      3. 런닝         \n");
	printf(" 4. 웨이트 트레이닝   \n");

	scanf("%d", &num);

	if (num == 1)
	{
		volley_ball();
	}
	else if (num == 2)
	{
		basket_ball();
	}
	else if (num == 3)
	{
		running();
	}
	else if (num == 4)
	{
		weight();
	}
	else if (num == 5)
	{
		Exit_pro();
	}
}

void timer_10s()
{
	int countdown = 10;
	while (countdown > 0)
	{
		printf("%d", countdown);
		Sleep(1000);

		countdown--;
	}

}

void running()
{
	printf("런닝 루틴 시작하겠습니다.\n");
	printf("아무키나 눌러서 진행\n");
	getch();

	HRmax();

	printf("가벼운 조깅 실시(운동장 한 바퀴 권장)\n 조깅이 끝났으면 Enter누르기\n");
	getchar();

	printf("30m 왕복 달리기 실시\n");
}

void HRmax()
{
	int age;
	int hrmax;
	int a;
	printf("나이를 입력하세요: ");
	scanf("%d", &age);

	int hrmax = 220 - age;

	printf("당신의 최대 심박수는 %d\n 최대 심박수를 넘어가지 않게 주의 하세요!!", hrmax);
	printf("최대 심박수 보다 심박수가 높아진다면 종료키를 입력");

	a = getch();

	if (a == 27)
	{
		system("cls");

		exit(0);
	}
}
